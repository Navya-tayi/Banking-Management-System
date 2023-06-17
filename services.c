
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "prhead.h"
int neft_amount;
int upi_amount;
//int upi_password;

char fname[]={"Customer_Data.dat"};






void Create_New_Account()
{

    FILE *fp;
    int q;

    fp=fopen(fname,"a+");
    printf("\nEnter Account Number:");
    scanf("%d",&a1.Account_Number);

    printf("\nEnter your First Name:");
    scanf("%s",a1.Name);

     printf("\nEnter Phone Number(6 digit):");
    scanf("%d",&a1.Phone_Number);

   a1.IFSC_code=9000;

    printf("\nEnter Balance(Savings):Rs.");
    scanf("%d",&a1.Balance_Savings);

    printf("\nEnter Balance(Current):Rs.");
    scanf("%d",&a1.Balance_Current);

    printf("\nEnter UPI Password(4 digit PIN):");
    scanf("%d",&a1.UPI_Password);

    a1.Credit=0;

    fprintf(fp,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
    
    fclose(fp);
    printf("\n Account Created!!!\n");
    
    printf("\n\nSelect:\n1.View Account's details\n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);

    if(q==1)
    {
        Search_Account_details();
    }
    if(q==2)
    {
       Home();
       
    }
}





void NEFT2()
{


    int q;
    FILE *fp,*np;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");
     


    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {
                if(a1.Account_Number==trans_neft2.Account_Number)
                {
                    a1.Balance_Current=a1.Balance_Current+neft_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                   
                }

                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

        }

    fclose(fp);
    fclose(np);
    

    remove(fname);
    rename("Temp.dat",fname);

    printf("Rs.%d Amount received\n",neft_amount);

    

    printf("\n\nSelect:\n1.Transaction \n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);


    if(q==1)
    {
        Transaction();
    }
    if(q==2)
    {
       Home();
       
    } 
}





void NEFT1()
{


    int q;
    FILE *fp,*np,*gp;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");
    

    printf("\nEnter Your Account Number:");
    scanf("%d",&trans_neft1.Account_Number);
     printf("\nEnter Account Number to which you want to send:");
    scanf("%d",&trans_neft2.Account_Number);
    printf("\nHow much would you like to send?");
    scanf("%d",&neft_amount);

    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {
                if(a1.Account_Number==trans_neft1.Account_Number)
                {
                    a1.Balance_Current=a1.Balance_Current-neft_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                    
                }

                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

        }

    fclose(fp);
    fclose(np);
   

    remove(fname);
    rename("Temp.dat",fname);

    printf("Payment of Rs.%d successful\n",neft_amount);
    NEFT2();

    

   


}
void UPI2()
{


    int q;
    FILE *fp,*np;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");
    


    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {
            //if(a1.UPI_Password==upi_password)
            //{
                if(a1.Phone_Number==upi2.Phone_Number)
                {
                    a1.Balance_Current=a1.Balance_Current+upi_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                   
                }
            //}
                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

        }

    fclose(fp);
    fclose(np);
   

    remove(fname);
    rename("Temp.dat",fname);

    printf("Rs.%d Amount received\n",upi_amount);

  

         printf("\n\nSelect:\n1.Transaction \n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);


    if(q==1)
    {
        Transaction();
    }
    if(q==2)
    {
       Home();
       
    } 
}



void UPI1()
{


    int q,password;
    FILE *fp,*np;
    fp=fopen(fname,"r");
    np=fopen("Temp.dat","w");
  
    printf("\nEnter Your Phone Number:");
    scanf("%d",&upi1.Phone_Number);
   // printf("Enter your UPI Password:");
    //scanf("%d",&upi_password);

    
    printf("\nEnter Mobile Number to which you want to send:");
    scanf("%d",&upi2.Phone_Number);
    printf("\nHow much would you like to send?");
    scanf("%d",&upi_amount);    
        
        
        while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {       
            //if(a1.UPI_Password==upi_password)  
            //{
   
                if(a1.Phone_Number==upi1.Phone_Number)
                {
                    a1.Balance_Current=a1.Balance_Current-upi_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                } 
            //}
                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }
  
            

                
              
        }


    

    fclose(fp);
    fclose(np);
   

    remove(fname);
    rename("Temp.dat",fname);

    
   

    UPI2();
    
    
}


void encrypt()
   
   {char ch;
    FILE *fps,*fpt;
    
    fps = fopen("temp.txt", "r");
    
    fpt = fopen("encrypt.txt", "w");
   
    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch = ch+100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
  
    
}

void decrypt()
{
    char ch;
    FILE *fps, *fpt;
    
    fps = fopen("decrypt.txt", "w");

    fpt = fopen("encrypt.txt", "r");
    
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = ch-100;
        fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("Decrypted successfully");
}



void Search_Account_details()
{
    
     FILE *fp;
   int q;
    fp=fopen(fname,"r");
    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ACCOUNT DETAILS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
    printf("Enter the account number:");
    scanf("%d",&search.Account_Number); 
    printf("\n\n"); 


    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)
       {
            if(a1.Account_Number==search.Account_Number)
            {
            //printf("\nACC. NO.\tNAME\t\tDEPOSIT\n");
            printf("Account Number   :%d\n",a1.Account_Number);
            printf("First Name       :%s\n",a1.Name);
            printf("Phone Number     :%d\n",a1.Phone_Number);
            printf("IFSC Code        :%d\n",a1.IFSC_code);
            printf("Balance(savings) :Rs.%d\n",a1.Balance_Savings);
            printf("Balance(Current) :Rs.%d\n",a1.Balance_Current);
            printf("UPI_Password     :%d\n",a1.UPI_Password);
            printf("Credit amount    :Rs.%d\n",a1.Credit);
            }
            

          
           
       }



    fclose(fp);

    printf("\n\nSelect:\n1.View Account's details\n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);

    if(q==1)
    {
        Search_Account_details();
    }
    if(q==2)
    {
       Home();
       
    }
    
}




void Modify_Record()
{   int q;
    system("cls");
    int choice;
    FILE *fp,*np;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");

    printf("\nAccount number you want to edit:");
    scanf("%d",&change.Account_Number);


    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)
    {
        if(a1.Account_Number==change.Account_Number)
        {   
            printf("Which Information do you want to change?\n");
            printf("1.Phone_number\n");
            printf("2.UPI Password\nEnter your choice(1 or 2):");
            scanf("%d",&choice);

            if(choice==1)
            {
                printf("Enter the New Phone Number:");
                scanf("%d",&change.Phone_Number);
                fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,change.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
            }


            else if(choice==2)
                {
                printf("Enter the New UPI Password:");
                scanf("%d",&change.UPI_Password);
                fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,change.UPI_Password,a1.Credit);
            }

         


        }

        else
        {
              fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
        }


}

    fclose(fp);
    fclose(np);
    remove(fname);
    rename("Temp.dat",fname);

    printf("Record Modified!!!\n");

     printf("\n\nSelect:\n1.Modify Account's details again\n");
    printf("2.Search Account Details\n");
     printf("3.Main Menu\n");

    printf(" --->");
    scanf("%d",&q);

    if(q==1)
    {
        Modify_Record();
    }
    if(q==3)
    {
       Home();
       
    }

    if(q==2)
    {
        Search_Account_details();
    }
    
}



void credit()
{
    int q,credit_amount;
    FILE *fp,*np,*gp;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");
     gp=fopen("temp.txt","w");

    printf("\nEnter Your Account Number:");
    scanf("%d",&trans_cred.Account_Number);
    printf("\nHow much would you like to pay in credit:Rs.");
    scanf("%d",&credit_amount);

    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {
                if(a1.Account_Number==trans_cred.Account_Number)
                {
                    a1.Credit=a1.Credit+credit_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                    fprintf(gp,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

        }

    fclose(fp);
    fclose(np);
    fclose(gp);
    remove(fname);
    rename("Temp.dat",fname);

    printf("Rs.%d Credited\n",credit_amount);

    encrypt();

    printf("Pay your credit amount within a month to avoid a PENALTY!\n");

   int c;
    printf("Would you like to decrypt:\n 1.yes\n 2.no \n");
    scanf("%d",&c);
    if(c==1)
    {
        decrypt();
    }
    else
    {
         printf("\n\nSelect:\n1.Transaction \n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);

    if(q==1)
    {
        Transaction();
    }
    if(q==2)
    {
       Home();
       
    } 
    }


}



void debit()
{


    int q,debit_amount;
    FILE *fp,*np,*gp;
     fp=fopen(fname,"r");
     np=fopen("Temp.dat","w");
     gp=fopen("temp.txt","w");

    printf("\nEnter Your Account Number:");
    scanf("%d",&trans_deb.Account_Number);
    printf("\nHow much would you like to withdraw in debit:Rs.");
    scanf("%d",&debit_amount);

    while(fscanf(fp,"%d %s %d %d %d %d %d %d",&a1.Account_Number,a1.Name,&a1.Phone_Number,&a1.IFSC_code,&a1.Balance_Savings,&a1.Balance_Current,&a1.UPI_Password,&a1.Credit)!=EOF)

        {
                if(a1.Account_Number==trans_deb.Account_Number)
                {
                    a1.Balance_Current=a1.Balance_Current-debit_amount;
                    fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                    fprintf(gp,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

                else
                {
                     fprintf(np,"\n%d %s %d %d %d %d %d %d",a1.Account_Number,a1.Name,a1.Phone_Number,a1.IFSC_code,a1.Balance_Savings,a1.Balance_Current,a1.UPI_Password,a1.Credit);
                }

        }

    fclose(fp);
    fclose(np);
    fclose(gp);

    remove(fname);
    rename("Temp.dat",fname);

    printf("Rs.%d Debited\n",debit_amount);

    encrypt();

int c;
    printf("Would you like to decrypt:\n 1.yes\n 2.no \n");
    scanf("%d",&c);
    if(c==1)
    {
        decrypt();
    }
    else
    {
         printf("\n\nSelect:\n1.Transaction \n");
    printf("2.Main Menu\n");
    printf(" --->");
    scanf("%d",&q);

    if(q==1)
    {
        Transaction();
    }
    if(q==2)
    {
       Home();
       
    } 
    }


   


}




void Transaction()
{
    int q;
    system("cls");
    int choice;
    printf("Select Type Of Transaction:\n");
    
        printf("1.Credit\n");
        printf("2.Debit\n3.NEFT\n4.UPI\nEnter your Choice(1 or 2 or 3 or 4):");
        scanf("%d",&choice);

    if(choice==1)
    {
        credit();        
    }
    if(choice==2)
    {
        debit();
    }
    if(choice==3)
    {
        NEFT1();
    }
    if(choice==4)
    {
        UPI1();
    }
        

       
}







void Home()
{

    int ch;
    while(1)
    {
        system("cls");
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK OF PES UNIVERSITY\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
       

        
        printf("1.Create New Account\n");
        printf("2.Search Account Details\n");
        printf("3.Modify\n");
        printf("4.Transaction\n");        
        printf("0.Exit\n");
       printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

        printf("Please Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:Create_New_Account();
                break;
            case 2:Search_Account_details();
                break;

            case 3:Modify_Record();
                break;
            case 4: Transaction();
                break;
           
             case 0: exit(0);
                break;
             
          



        }
    }

}

