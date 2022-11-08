# CS2BankingTermProjectPt1

Your task is to write an online customer account banking management system for 
Lawrence Tech Employee Credit Union.   The task of your C++ program is to 
support bank personnel to support the following customer functions: 
1.  Create a new checking account. 
2.  Remove an existing account. 
3.  Update name, address information for an existing customer. 
4.  Deposit transaction. 
5.  Withdrawal transaction. 
6.  Customer Inquiry. 
7.  List customer names and ids. 
8.  Exit the program. 
 
Functions to be supported in Part 1 should include the following (Note:  interest is 
not supported)  
        
• StartPgm() – A function that will initialize the program. 
 
• StopPgm() – A function that will terminate the program. 
 
• Menu() – This function displays the menu or welcome screen to perform 
different banking activities mentioned below. 
 
• NewCust() – This function creates a new customer account. It asks for 
some  personal and banking details of the customer such as name, date 
of birth, citizenship number (SSN), address and phone number. The 
transaction should allow the teller to enter the amount to deposit and 
choose one type of deposit account – saving or checking. 
 
• UpdCustInfo() – This function can used to change the address and/or 
phone number of a particular customer account. 
 
• Deposit() – With this function, the bank teller will record the deposit of 
money to a particular customer account.  
 
• Withdrawl() – With this function, the bank teller will record the 
withdraw of money from a particular customer account. 
 
• DelCust() – This function is for deleting a customer account. 
 
• ViewCustInfo() – This function displays the customer’s account number, 
name, date of birth, citizenship number, age, address, phone number, 
type of account, amount and date of the last deposit.  
 
• ListCustomers() – This function displays a list of customer names and 
Ids.  
File Processing 
In this bank management system project, file handling should be used.  When the 
program begins, the customer information is loaded into memory.  When the 
program terminates, the information is written out to the file. 
The format of the file should be viewable as an Excel spread sheet.  That is, the 
file type for input and output should be a .CSV file.  Presume that the initial file is 
empty. 
 
Welcome Screen: 
The welcome screen is listed below.  All other screens should include information 
with appropriate labels. 
 

                                Lawrence Tech Employee Credit Union        
 
                               ***** Welcome to the Main Menu *****     
 
                               1.  Create a new checking account. 
                               2.  Remove an existing account. 
                               3.  Update name, address information for an existing customer. 
                               4.  Deposit transaction. 
                               5.  Withdrawal transaction. 
                               6.  List information of an existing customer. 
                               7.  List customer names and ids. 
                               8.  Exit the program. 
 
                                Enter your choice: ___ 
                                
 
 Specific Requirements: 
• Project 1:    
o Use Object Oriented techniques (i.e. Classes) techniques and File 
I/O.   
o You may use Structs sparingly and you must justify your reason for 
using it.   
o Suggestion: use vectors.
