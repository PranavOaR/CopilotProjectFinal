# Banking System - Detailed Testing Sheet

## System Overview
**System Name:** Bank Reconciliation System - MVP  
**Language:** C  
**Data Files:** INITIAL.dat (account data), BANKING.dat (transaction data)  
**Date:** July 15, 2025  

## Test Environment Setup
- **Compiler:** GCC  
- **OS:** Windows  
- **Data Files Location:** output/ directory  
- **Executable:** Main.exe  

---

## 1. FUNCTIONAL TESTING

### 1.1 Account Management Tests

#### Test Case 1.1.1: Create New Account - Valid Data
**Test ID:** TC_ACC_001  
**Objective:** Verify successful account creation with valid data  
**Preconditions:** System is running  
**Test Steps:**
1. Select option 1 (Open New Account)
2. Enter valid name (e.g., "John Doe")
3. Enter valid address (e.g., "123 Main St, City")
4. Enter valid initial deposit (≥ Rs.500, e.g., Rs.1000)

**Expected Result:**
- Account number auto-generated (starting from 5001)
- Account saved to INITIAL.dat
- Success message displayed
- Account details confirmed

**Test Data:**
- Name: "John Doe"
- Address: "123 Main St, City"
- Initial Deposit: Rs.1000

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________  
**Notes:** ________________

#### Test Case 1.1.2: Create New Account - Empty Name
**Test ID:** TC_ACC_002  
**Objective:** Verify system handles empty name input  
**Test Steps:**
1. Select option 1 (Open New Account)
2. Press Enter without entering name
3. Observe system response

**Expected Result:**
- Error message: "Name cannot be left empty. Please try again."
- System prompts for name again

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.1.3: Create New Account - Empty Address
**Test ID:** TC_ACC_003  
**Objective:** Verify system handles empty address input  
**Test Steps:**
1. Select option 1 (Open New Account)
2. Enter valid name
3. Press Enter without entering address
4. Observe system response

**Expected Result:**
- Error message: "Address cannot be blank! Please try again."
- System prompts for address again

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.1.4: Create New Account - Insufficient Initial Deposit
**Test ID:** TC_ACC_004  
**Objective:** Verify minimum deposit validation  
**Test Steps:**
1. Select option 1 (Open New Account)
2. Enter valid name and address
3. Enter initial deposit < Rs.500 (e.g., Rs.400)
4. Observe system response

**Expected Result:**
- Error message: "Initial deposit must be at least Rs.500! Please try again."
- System prompts for deposit again

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.1.5: Account Number Auto-Generation
**Test ID:** TC_ACC_005  
**Objective:** Verify sequential account number generation  
**Test Steps:**
1. Create first account and note account number
2. Create second account and note account number
3. Verify sequence

**Expected Result:**
- First account: 5001 (if no existing accounts)
- Second account: 5002
- Sequential numbering maintained

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 1.2 Display Account Tests

#### Test Case 1.2.1: Display All Accounts - With Data
**Test ID:** TC_DISP_001  
**Objective:** Verify display of all accounts when data exists  
**Preconditions:** At least one account exists  
**Test Steps:**
1. Select option 2 (Display All Accounts)
2. Observe output

**Expected Result:**
- Table format with headers: Acct No, Name, Address, Balance
- All accounts displayed with correct formatting
- Total account count shown

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.2.2: Display All Accounts - No Data
**Test ID:** TC_DISP_002  
**Objective:** Verify display when no accounts exist  
**Preconditions:** No accounts in system (fresh start)  
**Test Steps:**
1. Select option 2 (Display All Accounts)
2. Observe output

**Expected Result:**
- Message: "No accounts found or file doesn't exist!"

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.2.3: Display Individual Account - Valid Account
**Test ID:** TC_DISP_003  
**Objective:** Verify individual account display with valid account number  
**Preconditions:** Account exists with known account number  
**Test Steps:**
1. Select option 3 (Display Individual Account)
2. Enter valid account number
3. Observe output

**Expected Result:**
- Account number displayed
- Current balance shown
- Transaction history table with headers
- All transactions for the account listed

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.2.4: Display Individual Account - Invalid Account
**Test ID:** TC_DISP_004  
**Objective:** Verify handling of invalid account number  
**Test Steps:**
1. Select option 3 (Display Individual Account)
2. Enter non-existent account number (e.g., 9999)
3. Observe output

**Expected Result:**
- Message: "Account not found!"

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 1.3 Transaction Tests

#### Test Case 1.3.1: Valid Deposit Transaction
**Test ID:** TC_TRANS_001  
**Objective:** Verify successful deposit transaction  
**Preconditions:** Account exists with known number  
**Test Steps:**
1. Select option 4 (Make Transaction)
2. Enter valid account number
3. Enter transaction type: "cash"
4. Enter transaction code: "D"
5. Enter amount: Rs.500
6. Observe results

**Expected Result:**
- Current balance displayed
- Transaction date auto-populated
- New balance = old balance + deposit amount
- Transaction saved to BANKING.dat
- Account balance updated in INITIAL.dat
- Success message displayed

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.3.2: Valid Withdrawal Transaction
**Test ID:** TC_TRANS_002  
**Objective:** Verify successful withdrawal transaction  
**Preconditions:** Account exists with sufficient balance  
**Test Steps:**
1. Select option 4 (Make Transaction)
2. Enter valid account number
3. Enter transaction type: "cheque"
4. Enter transaction code: "W"
5. Enter amount less than current balance
6. Observe results

**Expected Result:**
- Current balance displayed
- New balance = old balance - withdrawal amount
- Transaction saved to BANKING.dat
- Account balance updated in INITIAL.dat
- Success message displayed

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.3.3: Insufficient Balance Withdrawal
**Test ID:** TC_TRANS_003  
**Objective:** Verify handling of insufficient balance  
**Preconditions:** Account exists with known balance  
**Test Steps:**
1. Select option 4 (Make Transaction)
2. Enter valid account number
3. Enter transaction type: "cash"
4. Enter transaction code: "W"
5. Enter amount greater than current balance
6. Observe results

**Expected Result:**
- Message: "Insufficient balance! Transaction cancelled."
- No transaction recorded
- Account balance unchanged

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.3.4: Invalid Transaction Type
**Test ID:** TC_TRANS_004  
**Objective:** Verify validation of transaction type  
**Test Steps:**
1. Select option 4 (Make Transaction)
2. Enter valid account number
3. Enter invalid transaction type (e.g., "credit")
4. Observe system response

**Expected Result:**
- Error message: "Invalid type! Please enter 'cash' or 'cheque'."
- System prompts for valid input

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.3.5: Invalid Transaction Code
**Test ID:** TC_TRANS_005  
**Objective:** Verify validation of transaction code  
**Test Steps:**
1. Select option 4 (Make Transaction)
2. Enter valid account number
3. Enter valid transaction type
4. Enter invalid transaction code (e.g., "X")
5. Observe system response

**Expected Result:**
- Error message: "Invalid transaction! Please enter 'D' or 'W'."
- System prompts for valid input

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.3.6: Date Auto-Population
**Test ID:** TC_TRANS_006  
**Objective:** Verify automatic date population  
**Test Steps:**
1. Perform any valid transaction
2. Check transaction date displayed
3. Verify against system date

**Expected Result:**
- Transaction date matches current system date
- Date format: DD/MM/YYYY

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 1.4 Navigation and Menu Tests

#### Test Case 1.4.1: Main Menu Display
**Test ID:** TC_MENU_001  
**Objective:** Verify main menu display and options  
**Test Steps:**
1. Run the application
2. Observe main menu

**Expected Result:**
- Title: "BANK RECONCILIATION SYSTEM - MVP"
- Menu options 1-4 and 0 displayed correctly
- Clean formatting

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.4.2: Invalid Menu Choice
**Test ID:** TC_MENU_002  
**Objective:** Verify handling of invalid menu selection  
**Test Steps:**
1. Enter invalid choice (e.g., 5, -1, or letter)
2. Observe system response

**Expected Result:**
- Message: "Invalid choice! Please try again."
- Menu redisplayed

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 1.4.3: Exit Application
**Test ID:** TC_MENU_003  
**Objective:** Verify proper application exit  
**Test Steps:**
1. Select option 0 (Exit)
2. Observe system response

**Expected Result:**
- Message: "Thank you for using Bank Reconciliation System!"
- Application terminates cleanly

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 2. DATA INTEGRITY TESTING

### 2.1 File Operations Tests

#### Test Case 2.1.1: INITIAL.dat File Creation
**Test ID:** TC_DATA_001  
**Objective:** Verify INITIAL.dat file creation and structure  
**Test Steps:**
1. Delete INITIAL.dat if exists
2. Create new account
3. Check file creation and content

**Expected Result:**
- INITIAL.dat file created
- Account data properly stored
- File can be read by system

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 2.1.2: BANKING.dat File Creation
**Test ID:** TC_DATA_002  
**Objective:** Verify BANKING.dat file creation and structure  
**Test Steps:**
1. Delete BANKING.dat if exists
2. Perform transaction
3. Check file creation and content

**Expected Result:**
- BANKING.dat file created
- Transaction data properly stored
- File can be read by system

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 2.1.3: Balance Consistency
**Test ID:** TC_DATA_003  
**Objective:** Verify balance consistency between files  
**Test Steps:**
1. Create account with initial balance
2. Perform multiple transactions
3. Check balance in INITIAL.dat matches last transaction balance

**Expected Result:**
- Balance in INITIAL.dat equals final transaction balance
- No discrepancies between files

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 2.2 Concurrent Access Tests

#### Test Case 2.2.1: Multiple Account Creation
**Test ID:** TC_CONC_001  
**Objective:** Verify system handles multiple account creation  
**Test Steps:**
1. Create multiple accounts in sequence
2. Verify each account gets unique number
3. Check all accounts are properly stored

**Expected Result:**
- Sequential account numbers
- All accounts properly stored
- No data corruption

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 3. BOUNDARY VALUE TESTING

### 3.1 Input Validation Tests

#### Test Case 3.1.1: Maximum Name Length
**Test ID:** TC_BOUND_001  
**Objective:** Test maximum name length handling  
**Test Steps:**
1. Enter name with 99 characters (within limit)
2. Enter name with 100+ characters (exceeding limit)
3. Observe behavior

**Expected Result:**
- 99 characters: Accepted
- 100+ characters: Handled gracefully (truncated or rejected)

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 3.1.2: Maximum Address Length
**Test ID:** TC_BOUND_002  
**Objective:** Test maximum address length handling  
**Test Steps:**
1. Enter address with 199 characters (within limit)
2. Enter address with 200+ characters (exceeding limit)
3. Observe behavior

**Expected Result:**
- 199 characters: Accepted
- 200+ characters: Handled gracefully

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 3.1.3: Minimum Deposit Boundary
**Test ID:** TC_BOUND_003  
**Objective:** Test minimum deposit boundary values  
**Test Steps:**
1. Enter deposit of Rs.499.99
2. Enter deposit of Rs.500.00
3. Enter deposit of Rs.500.01
4. Observe behavior

**Expected Result:**
- Rs.499.99: Rejected
- Rs.500.00: Accepted
- Rs.500.01: Accepted

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 3.1.4: Large Transaction Amounts
**Test ID:** TC_BOUND_004  
**Objective:** Test handling of large transaction amounts  
**Test Steps:**
1. Test deposit of Rs.999,999.99
2. Test withdrawal of maximum available balance
3. Observe system behavior

**Expected Result:**
- Large amounts handled correctly
- No overflow errors
- Proper formatting maintained

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 4. ERROR HANDLING TESTING

### 4.1 File Error Tests

#### Test Case 4.1.1: File Permission Errors
**Test ID:** TC_ERROR_001  
**Objective:** Test handling of file permission errors  
**Test Steps:**
1. Make INITIAL.dat read-only
2. Try to create new account
3. Observe error handling

**Expected Result:**
- Appropriate error message displayed
- System doesn't crash
- Graceful recovery

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 4.1.2: Disk Space Full
**Test ID:** TC_ERROR_002  
**Objective:** Test handling when disk space is full  
**Test Steps:**
1. Simulate disk full condition
2. Try to create account or transaction
3. Observe error handling

**Expected Result:**
- Appropriate error message
- No data corruption
- System remains stable

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 4.1.3: Corrupted Data Files
**Test ID:** TC_ERROR_003  
**Objective:** Test handling of corrupted data files  
**Test Steps:**
1. Corrupt INITIAL.dat file
2. Try to access account data
3. Observe system behavior

**Expected Result:**
- Error detected and reported
- System doesn't crash
- Recovery mechanism available

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 4.2 Input Error Tests

#### Test Case 4.2.1: Non-Numeric Account Number
**Test ID:** TC_ERROR_004  
**Objective:** Test handling of non-numeric account input  
**Test Steps:**
1. Enter letters instead of account number
2. Observe system response

**Expected Result:**
- Input validation error
- System prompts for valid input
- No crash

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 4.2.2: Non-Numeric Amount
**Test ID:** TC_ERROR_005  
**Objective:** Test handling of non-numeric amount input  
**Test Steps:**
1. Enter letters instead of amount
2. Observe system response

**Expected Result:**
- Input validation error
- System prompts for valid input
- No crash

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 5. PERFORMANCE TESTING

### 5.1 Response Time Tests

#### Test Case 5.1.1: Account Creation Speed
**Test ID:** TC_PERF_001  
**Objective:** Measure account creation response time  
**Test Steps:**
1. Record start time
2. Create account with valid data
3. Record end time
4. Calculate duration

**Expected Result:**
- Account creation completes within 2 seconds
- Acceptable response time maintained

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 5.1.2: Transaction Processing Speed
**Test ID:** TC_PERF_002  
**Objective:** Measure transaction processing time  
**Test Steps:**
1. Record start time
2. Process transaction
3. Record end time
4. Calculate duration

**Expected Result:**
- Transaction processing completes within 3 seconds
- File updates are efficient

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

### 5.2 Load Tests

#### Test Case 5.2.1: Multiple Account Handling
**Test ID:** TC_LOAD_001  
**Objective:** Test system with multiple accounts  
**Test Steps:**
1. Create 100 accounts
2. Perform operations on various accounts
3. Monitor performance

**Expected Result:**
- System handles multiple accounts efficiently
- No significant performance degradation
- All operations remain responsive

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 6. SECURITY TESTING

### 6.1 Data Security Tests

#### Test Case 6.1.1: File Access Control
**Test ID:** TC_SEC_001  
**Objective:** Verify data file access control  
**Test Steps:**
1. Check file permissions on INITIAL.dat and BANKING.dat
2. Verify only authorized access
3. Test file protection mechanisms

**Expected Result:**
- Data files properly protected
- No unauthorized access possible
- Appropriate file permissions set

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 6.1.2: Buffer Overflow Protection
**Test ID:** TC_SEC_002  
**Objective:** Test protection against buffer overflow  
**Test Steps:**
1. Enter extremely long strings for name/address
2. Monitor system behavior
3. Check for memory corruption

**Expected Result:**
- System handles long inputs gracefully
- No buffer overflow vulnerabilities
- Memory protection maintained

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 7. USABILITY TESTING

### 7.1 User Interface Tests

#### Test Case 7.1.1: Menu Navigation
**Test ID:** TC_UI_001  
**Objective:** Evaluate menu navigation usability  
**Test Steps:**
1. Navigate through all menu options
2. Evaluate clarity and ease of use
3. Check for consistent formatting

**Expected Result:**
- Menu options clearly labeled
- Navigation is intuitive
- Consistent formatting throughout

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 7.1.2: Error Message Clarity
**Test ID:** TC_UI_002  
**Objective:** Evaluate error message clarity  
**Test Steps:**
1. Generate various error conditions
2. Evaluate message clarity and helpfulness
3. Check for user-friendly language

**Expected Result:**
- Error messages are clear and helpful
- Appropriate guidance provided
- Professional language used

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 8. REGRESSION TESTING

### 8.1 Core Function Tests

#### Test Case 8.1.1: Basic Operations After Changes
**Test ID:** TC_REG_001  
**Objective:** Verify basic operations still work after any code changes  
**Test Steps:**
1. Create account
2. Display account
3. Perform transaction
4. Display updated account

**Expected Result:**
- All basic operations function correctly
- No regression in core functionality
- Data integrity maintained

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 9. INTEGRATION TESTING

### 9.1 Module Integration Tests

#### Test Case 9.1.1: Account-Transaction Integration
**Test ID:** TC_INT_001  
**Objective:** Test integration between account and transaction modules  
**Test Steps:**
1. Create account
2. Perform transaction
3. Verify balance update in both files
4. Display account with transaction history

**Expected Result:**
- Account and transaction data properly linked
- Balance consistency maintained
- Transaction history correctly displayed

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 9.1.2: File System Integration
**Test ID:** TC_INT_002  
**Objective:** Test integration with file system operations  
**Test Steps:**
1. Perform operations that create/modify files
2. Verify file operations complete successfully
3. Check data persistence

**Expected Result:**
- File operations integrate smoothly
- Data persists correctly
- No file system conflicts

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## 10. ACCEPTANCE TESTING

### 10.1 Business Requirements Tests

#### Test Case 10.1.1: Account Management Requirements
**Test ID:** TC_ACC_001  
**Objective:** Verify account management meets business requirements  
**Test Steps:**
1. Create accounts with various valid data
2. Verify auto-generated account numbers
3. Confirm minimum balance requirements
4. Test account display functionality

**Expected Result:**
- All account management requirements satisfied
- Business rules properly implemented
- User requirements met

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

#### Test Case 10.1.2: Transaction Processing Requirements
**Test ID:** TC_ACC_002  
**Objective:** Verify transaction processing meets business requirements  
**Test Steps:**
1. Test deposit and withdrawal operations
2. Verify balance calculations
3. Confirm transaction recording
4. Test insufficient balance handling

**Expected Result:**
- Transaction processing meets business needs
- Accurate balance calculations
- Proper transaction logging

**Status:** [ ] Pass [ ] Fail  
**Actual Result:** ________________

---

## TEST EXECUTION SUMMARY

### Overall Test Results
- **Total Test Cases:** 50
- **Passed:** ___
- **Failed:** ___
- **Blocked:** ___
- **Not Executed:** ___

### Critical Issues Found
1. ________________________
2. ________________________
3. ________________________

### Recommendations
1. ________________________
2. ________________________
3. ________________________

### Test Environment Details
- **Test Date:** ____________
- **Tester:** ____________
- **System Version:** ____________
- **Test Duration:** ____________

### Sign-off
- **Test Lead:** ____________ **Date:** ____________
- **Development Lead:** ____________ **Date:** ____________
- **Project Manager:** ____________ **Date:** ____________

---

## APPENDICES

### Appendix A: Test Data Sets
```
Account Test Data:
- Valid Names: "John Doe", "Jane Smith", "Robert Johnson"
- Valid Addresses: "123 Main St", "456 Oak Ave", "789 Pine Rd"
- Valid Deposits: Rs.500, Rs.1000, Rs.5000
- Invalid Deposits: Rs.400, Rs.100, Rs.0

Transaction Test Data:
- Valid Types: "cash", "cheque"
- Valid Codes: "D", "W"
- Valid Amounts: Rs.100, Rs.500, Rs.1000
```

### Appendix B: Error Code Reference
```
File Errors:
- Cannot create/open file
- File permission denied
- Disk space full

Input Errors:
- Invalid menu choice
- Empty required fields
- Invalid data types
- Boundary violations
```

### Appendix C: Performance Benchmarks
```
Expected Response Times:
- Account Creation: < 2 seconds
- Transaction Processing: < 3 seconds
- Display Operations: < 1 second
- File Operations: < 1 second
```

### Appendix D: Security Checklist
```
- [ ] File permissions properly set
- [ ] Input validation implemented
- [ ] Buffer overflow protection
- [ ] Data integrity checks
- [ ] Error handling security
```

---

**Document Version:** 1.0  
**Last Updated:** July 15, 2025  
**Next Review Date:** ____________
