struct Account
{
    int Account_Number;
    char Name[50];
    int Phone_Number;
    int IFSC_code;
    int Balance_Savings;
    int Balance_Current;
    char UPI_Handle[50];
    int UPI_Password;
    int Credit;
};

struct Account a1;
struct Account search;
struct Account change;
struct Account trans_deb;
struct Account trans_cred; 
struct Account trans_neft1;
struct Account trans_neft2;
struct Account upi1;
struct Account upi2;


void Home();
void Modify_Record();
void Transaction();
void Search_Account_details();
void Create_New_Account();
void credit();
void debit();
void encrypt();
void decrypt();
void NEFT1();
void NEFT2();
void UPI1();
void UPI2();
