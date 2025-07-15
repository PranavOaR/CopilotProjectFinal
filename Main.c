

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct Account {
    int acct_no;
    char name[100];
    char address[200];
    float balance;
};

// Structure for transaction details (BANKING.dat)
struct Transaction {
    int acct_no;
    char type[10];      // "cash" or "cheque"
    int dd, mm, yy;     // transaction date
    char trans;         // 'D' for deposit, 'W' for withdrawal
    float interest;     // can be 0 for now
    float amount;
    float balance;
};

// Function prototypes
void main_menu(); // pranav
void add_to_file(struct Transaction trans); // pranav
void new_account(); // shashank
void display_all_accounts(); // shashank
void display_account(); // vince
void transaction(); // vince
int found_account(int acc_no); // pradumna
float give_balance(int acc_no);// pradumna


int main() {
    printf("\n*** BANK RECONCILIATION SYSTEM - MVP ***\n");
    printf("========================================\n\n");
    
    main_menu();
    return 0;
}

void main_menu() {
    int choice;
    
    while(1) {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Open New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Display Individual Account\n");
        printf("4. Make Transaction\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                new_account();
                break;
            case 2:
                display_all_accounts();
                break;
            case 3:
                display_account();
                break;
            case 4:
                transaction();
                break;
            case 0:
                printf("\nThank you for using Bank Reconciliation System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

void new_account() {
    FILE *fp;
    struct Account acc;
    int last_acct_no = 5000; // Starting account number
    
    printf("\n=== OPEN NEW ACCOUNT ===\n");
    
    // Find the last account number
    fp = fopen("INITIAL.dat", "rb");
    if(fp != NULL) {
        while(fread(&acc, sizeof(struct Account), 1, fp)) {
            if(acc.acct_no > last_acct_no) {
                last_acct_no = acc.acct_no;
            }
        }
        fclose(fp);
    }
    
    // Generate new account number
    acc.acct_no = last_acct_no + 1;
    printf("New Account Number: %d\n", acc.acct_no);
    
    // Input and validate name
    do {
        printf("Enter name: ");
        getchar(); // consume newline
        fgets(acc.name, sizeof(acc.name), stdin);
        acc.name[strlen(acc.name)-1] = '\0'; // remove newline
        
        if(strlen(acc.name) == 0) {
            printf("Name cannot be left empty. Please try again.\n");
        }
    } while(strlen(acc.name) == 0);
    
    // Input and validate address
    do {
        printf("Enter address: ");
        fgets(acc.address, sizeof(acc.address), stdin);
        acc.address[strlen(acc.address)-1] = '\0'; // remove newline
        
        if(strlen(acc.address) == 0) {
            printf("Address cannot be blank! Please try again.\n");
        }
    } while(strlen(acc.address) == 0);
    
    // Input and validate initial balance
    do {
        printf("Enter initial deposit (minimum Rs.500): Rs.");
        scanf("%f", &acc.balance);
        
        if(acc.balance < 500) {
            printf("Initial deposit must be at least Rs.500! Please try again.\n");
        }
    } while(acc.balance < 500);
    
    // Save to INITIAL.dat
    fp = fopen("INITIAL.dat", "ab");
    if(fp == NULL) {
        printf("Error: Cannot create/open file!\n");
        return;
    }
    
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    
    printf("\nAccount created successfully!\n");
    printf("Account Number: %d\n", acc.acct_no);
    printf("Name: %s\n", acc.name);
    printf("Initial Balance: Rs.%.2f\n", acc.balance);
}

void display_all_accounts() {
    FILE *fp;
    struct Account acc;
    int count = 0;
    
    printf("\n=== ALL ACCOUNTS ===\n");
    
    fp = fopen("INITIAL.dat", "rb");
    if(fp == NULL) {
        printf("No accounts found or file doesn't exist!\n");
        return;
    }
    
    printf("%-10s %-20s %-30s %-10s\n", "Acct No", "Name", "Address", "Balance");
    printf("------------------------------------------------------------------------\n");
    
    while(fread(&acc, sizeof(struct Account), 1, fp)) {
        printf("%-10d %-20s %-30s Rs.%-10.2f\n", 
               acc.acct_no, acc.name, acc.address, acc.balance);
        count++;
    }
    
    fclose(fp);
    
    if(count == 0) {
        printf("No accounts found!\n");
    } else {
        printf("\nTotal accounts: %d\n", count);
    }
}

void display_account() {
    int acct_no;
    FILE *fp;
    struct Transaction trans;
    int found = 0;
    
    printf("\n=== INDIVIDUAL ACCOUNT STATEMENT ===\n");
    printf("Enter account number: ");
    scanf("%d", &acct_no);
    
    if(!found_account(acct_no)) {
        printf("Account not found!\n");
        return;
    }
    
    printf("\nAccount Number: %d\n", acct_no);
    printf("Current Balance: Rs.%.2f\n\n", give_balance(acct_no));
    
    // Display transaction history
    fp = fopen("BANKING.dat", "rb");
    if(fp == NULL) {
        printf("No transaction records found!\n");
        return;
    }
    
    printf("%-10s %-8s %-10s %-10s %-10s %-10s\n", 
           "Date", "Type", "Trans", "Amount", "Interest", "Balance");
    printf("--------------------------------------------------------------\n");
    
    while(fread(&trans, sizeof(struct Transaction), 1, fp)) {
        if(trans.acct_no == acct_no) {
            printf("%02d/%02d/%02d %-8s %-10c Rs.%-7.2f Rs.%-7.2f Rs.%-7.2f\n", 
                   trans.dd, trans.mm, trans.yy, trans.type, trans.trans,
                   trans.amount, trans.interest, trans.balance);
            found = 1;
        }
    }
    
    fclose(fp);
    
    if(!found) {
        printf("No transactions found for this account.\n");
    }
}

void transaction() {
    int acct_no;
    struct Transaction trans;
    time_t t;
    struct tm *tm_info;
    float current_balance;
    
    printf("\n=== MAKE TRANSACTION ===\n");
    printf("Enter account number: ");
    scanf("%d", &acct_no);
    
    if(!found_account(acct_no)) {
        printf("Account not found!\n");
        return;
    }
    
    // Get current system date
    time(&t);
    tm_info = localtime(&t);
    
    trans.acct_no = acct_no;
    trans.dd = tm_info->tm_mday;
    trans.mm = tm_info->tm_mon + 1;
    trans.yy = tm_info->tm_year + 1900;
    
    current_balance = give_balance(acct_no);
    printf("Current Balance: Rs.%.2f\n", current_balance);
    printf("Transaction Date: %02d/%02d/%d\n", trans.dd, trans.mm, trans.yy);
    
    // Input and validate transaction type
    do {
        printf("Enter transaction type (cash/cheque): ");
        scanf("%s", trans.type);
        
        if(strcmp(trans.type, "cash") != 0 && strcmp(trans.type, "cheque") != 0) {
            printf("Invalid type! Please enter 'cash' or 'cheque'.\n");
        }
    } while(strcmp(trans.type, "cash") != 0 && strcmp(trans.type, "cheque") != 0);
    
    // Input and validate transaction code
    do {
        printf("Enter transaction (D for Deposit, W for Withdrawal): ");
        scanf(" %c", &trans.trans);
        
        if(trans.trans != 'D' && trans.trans != 'W') {
            printf("Invalid transaction! Please enter 'D' or 'W'.\n");
        }
    } while(trans.trans != 'D' && trans.trans != 'W');
    
    printf("Enter amount: Rs.");
    scanf("%f", &trans.amount);
    
    // Calculate new balance
    if(trans.trans == 'D') {
        trans.balance = current_balance + trans.amount;
    } else {
        if(current_balance < trans.amount) {
            printf("Insufficient balance! Transaction cancelled.\n");
            return;
        }
        trans.balance = current_balance - trans.amount;
    }
    
    trans.interest = 0.0; // Set to 0 for MVP
    
    // Update balance in INITIAL.dat
    FILE *fp;
    struct Account acc;
    FILE *temp_fp;
    
    fp = fopen("INITIAL.dat", "rb");
    temp_fp = fopen("temp.dat", "wb");
    
    if(fp == NULL || temp_fp == NULL) {
        printf("Error updating account balance!\n");
        return;
    }
    
    while(fread(&acc, sizeof(struct Account), 1, fp)) {
        if(acc.acct_no == acct_no) {
            acc.balance = trans.balance;
        }
        fwrite(&acc, sizeof(struct Account), 1, temp_fp);
    }
    
    fclose(fp);
    fclose(temp_fp);
    
    remove("INITIAL.dat");
    rename("temp.dat", "INITIAL.dat");
    
    
    add_to_file(trans);
    
    printf("\nTransaction completed successfully!\n");
    printf("Transaction Type: %s\n", trans.type);
    printf("Amount: Rs.%.2f\n", trans.amount);
    printf("New Balance: Rs.%.2f\n", trans.balance);
}

int found_account(int acc_no) {
    FILE *fp;
    struct Account acc;
    
    fp = fopen("INITIAL.dat", "rb");
    if(fp == NULL) {
        return 0; // Account not found
    }
    
    while(fread(&acc, sizeof(struct Account), 1, fp)) {
        if(acc.acct_no == acc_no) {
            fclose(fp);
            return 1; // Account found
        }
    }
    
    fclose(fp);
    return 0; // Account not found
}

float give_balance(int acc_no) {
    FILE *fp;
    struct Account acc;
    
    fp = fopen("INITIAL.dat", "rb");
    if(fp == NULL) {
        return 0.0;
    }
    
    while(fread(&acc, sizeof(struct Account), 1, fp)) {
        if(acc.acct_no == acc_no) {
            fclose(fp);
            return acc.balance;
        }
    }
    
    fclose(fp);
    return 0.0;
}

void add_to_file(struct Transaction trans) {
    FILE *fp;
    
    fp = fopen("BANKING.dat", "ab");
    if(fp == NULL) {
        printf("Error: Cannot open transaction file!\n");
        return;
    }
    
    fwrite(&trans, sizeof(struct Transaction), 1, fp);
    fclose(fp);
}

/*
gcc Main.C -o BankingMVP.exe
*/
