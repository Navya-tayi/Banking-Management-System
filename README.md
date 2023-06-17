# Banking-Management-System
This project is the simulation of a banking management and transactions system using C.

Customers can:
1. Create a new account (All the customer data is stored in Customer_data.dat file)
2. View or search for their account details
3. Modify the account details such as phone number 
4. Perform transactions.

The transactions enabled are:
1. Credit - Amount will not be subtracted from your account, but the amount of credit that you owe the bank will be available in your records.
2. Debit - Amount will be subtracted from your account
3. NEFT - Amount will be transferred from yours to the recepient's account
4. UPI - First, a password must be entered to do the UPI payment. AfteR that, using the recepient's phone number the amount is transferred.

All the customer details and result after the transaction will be encrypted and will appear in encrypt.txt to protect anyone else from seeing and understanding the transaction. After the transaction, you will be given an option to decrypt the encrypted file, which converts it to the usual readable format in decrypt.txt. These files will be overwritten everytime a transaction is performed.

Many improvements can be made on this project such as adding two different components, one for the customer and one which only the bank can access for actions such as modifying the customer's details, viewing the decrypted files, etc.

To execute the project, download all the files into a folder and run only the make file using the following command:
mingw-32 -f prmake.mk

and ENJOY!




