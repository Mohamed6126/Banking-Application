#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    char account_number[50];
    char name[50];
    char mobile_number[20];
    char email[50];
    float balance;
    date date_opened;
} account;
login(){
    int flag=0,N=0;
    char x[50],n[100],y[50];
FILE *ptr;
ptr=fopen("users.txt","r");
printf("Enter your username:\n");
scanf("%s",&x);
printf("Enter your password: \n");
scanf("%s",&y);
while(fgets(n,100,ptr)!= NULL){
    N++;
}
fclose(ptr);
ptr=fopen("users.txt","r");
while(fgets(n,100,ptr)!= NULL){
    char* token=strtok(n,"\n");
    if(token!=NULL){
        char* tokenu=strtok(token," ");
        char* tokenp=strtok(NULL,"\n");
        if(!strcmp(x,tokenu)&&!strcmp(y,tokenp)){
            flag=1;break;
        }
        else flag=0;
    }
    };
if (!flag) {printf("Wrong username or password, please try again: \n");login();}
else
{
    printf("access granted\n");
}
}

int load(account* array){
    int i=0,j;
    char l[100];
FILE* ptr;
ptr=fopen("accounts.txt","r");
while(fgets(l,100,ptr)!=NULL)
{
    strcpy(array[i].account_number,strtok(l,","));
    strcpy(array[i].name,strtok(NULL,","));
    for (int j = 0; array[i].name[j] != '\0'; j++) {
    array[i].name[j] = tolower(array[i].name[j]);}
    array[i].name[0] = toupper(array[i].name[0]);
    int length = strlen(array[i].name);
    for (int m = 1; m < length; m++) {
        if (array[i].name[m - 1] == ' ')
        {
            array[i].name[m] = toupper(array[i].name[m]);
        }
    }

    strcpy(array[i].email,strtok(NULL,","));
    array[i].balance=atof(strtok(NULL,","));
    strcpy(array[i].mobile_number,strtok(NULL,","));
    array[i].date_opened.month=atoi(strtok(NULL,"-"));
    array[i].date_opened.year=atoi(strtok(NULL,"\n"));
    i++;
}
save(array,i);
return i;
}

print(account* array,int i){
printf("Account Number: %s\n",array[i].account_number);
printf("Name of client: %s\n",array[i].name);
printf("E-mail: %s\n",array[i].email);
printf("Balance: %0.2f $\n",array[i].balance);
printf("Mobile number: %s\n",array[i].mobile_number);
printf("Date Opened: ");
Print_month(array[i].date_opened.month);
printf(" - %d\n",array[i].date_opened.year);
printf("\n");
}

void Print_month(int i)
{
    char months[][15] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
    printf("%s",months[i-1]);
}

search(account *array, int n)
{
    printf("Enter the account number: ");
    char x[50],d[30];
    int flag = 0, l, i;
    scanf("%s", &x);
    for (i = 0; i < n; i++)
    {
        l = strcmp(array[i].account_number, x);
        if (l == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        print(array, i);
        menu(array,n);
        return;
    }
    else
    {
        printf("The account does not exist, please try again: \n");
        printf("do you want to continue : (yes or no) : ");
        scanf("%s",d);
        getchar();
        if (!strcmp(d,"yes"))
        {
            search(array, n);
            return;
        }
        else
        {
            printf("Redirecting to menu\n");
            menu(array, n);
            return;
        }
    }
}

advsearch(account array[],int n)
{
    int flag=0;
    printf("Enter key word: \n");
    char x[50];
    scanf("%s",x);
    x[0] = toupper(x[0]);
    for (int i = 0; i < n; i++)
    {
        char tempName[50];
        strcpy(tempName,array[i].name);
        char* token=strtok(tempName," ");
        while (token != NULL)
        {
            if (!strcmp(x,token))
            {
            print(array,i);flag=1;
            }
            token=strtok(NULL," ");
        }



}

if(!flag) {
    printf("Keyword not found, please try again: \n");
    advsearch(array,n);
}
menu(array,n);
return;
}
int convert(char str[]){
int d[12]={1,2,3,4,5,6,7,8,9,10,11,12};
char n[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
for(int i=0;i<12;i++){
    if(!strcmp(str,n[i])) {return d[i];}
}
}

void add(account *c,int*n)
{
    int k = *n;
    char ans4[50];
    char ans6[50];
    float ans7;
    time_t mytime;
		mytime = time(NULL);
		char* token= strtok(ctime(&mytime)," ");
		int i=1;
		while(token!=NULL){
        if(i==2) c[*n].date_opened.month= convert(token);
        else if(i==5) {c[*n].date_opened.year= atoi(token);}
         i++;
        token=strtok(NULL," ");}
    printf("please enter account number (it must be 10 digits):\n");
    gets(c[*n].account_number);
    int temp=0;
    for(int i=0; i<*n; i++)
    {
        if(strcmp(c[*n].account_number,c[i].account_number)==0)
        {
            temp=1;
            break ;
        }
    }
    if(temp==1 || strlen(c[*n].account_number) != 10 )
    {
        int x;
        printf("Invalid input!\n");
        printf("Enter a number from the following:\n");
        printf("1-Try again\n");
        printf("2-Back to menu\n");
        scanf("%d",&x);
        if (x == 1)
        {
            getchar();
            add(c,n);
            return;
        }
        else if(x == 2)
        {
            menu(c,k);
            return;
        }
        else{
                printf("Invalid Input...Redirecting to menu\n");
            menu(c,k);
            return;
        }


    }
    printf("enter the name (you should not use digits in the name:\n");
    gets(ans4);
    int temp2 = 1;
    for (int n = 0; n < strlen(ans4); n++)
    {
    if(isdigit(ans4[n]))
    {
        temp2 = 0;
        break;
    }
    }
    if (temp2 == 0)
    {
        int ans1;
        printf("INVALID NAME:\n");
        printf("You should not use digits in your name !\n");
        printf("Choose a number from the following:\n");
        printf("1-Try again\n");
        printf("2-Back to menu\n");
        scanf("%d",&ans1);
        if (ans1 == 1)
        {
            getchar();
            add(c,n);
            return;
        }
        else if (ans1 == 2)
        {
            menu(c,k);
            return;
        }
        else
        {
            printf("INVALID INPUT...Redirecting to menu\n");
            menu(c,k);
            return;
        }
    }
    else
    {
        strcpy(c[*n].name,ans4);
    }




    printf("enter the email(you must use @ in the email):\n");
    char check[50];
    int flag2 = 0;
         gets(check);
         int j = strlen(check);
         for (int m = 0; m < j; m++)
         {
             if(check[m] == '@')
             {
                   strcpy(c[*n].email,check);
                   flag2 = 1;
                   break;
                }}




         if (flag2 == 0)
         {

                 int ans1;
                 printf("INVALID EMAIL:\n");
                 printf("You should use '@' in your email !\n");
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     getchar();
                     add(c,n);
                 }
                 else if (ans1 == 2)
                 {
                     menu(c,k);
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(c,k);
                     return;
                 }


         }

    printf("enter the balance(it must be positive number):\n");
    if (scanf("%f",&ans7) == 1 && ans7 >= 0.0)
        {
             c[*n].balance = ans7;
        }

     else {
        int ans1;
        printf("Invalid input!\n");
        printf("You should input a positive number !\n");
        printf("Choose a number from the following:\n");
        printf("1-Try again\n");
        printf("2-Back to menu\n");
        scanf("%d",&ans1);
        if (ans1 == 1)
        {
            getchar();
            add(c,n);
            return;
        }
        else if (ans1 == 2)
        {
            menu(c,k);
            return;
        }
        else
        {
            printf("INVALID INPUT...Redirecting to menu\n");
            menu(c,k);
            return;
        }
    }

    printf("enter the mobile number(it must be 11 numbers):\n");
    getchar();
    gets(ans6);

             if (isdigit(ans6[0]) && strlen(ans6) == 11)
             {
                 strcpy(c[*n].mobile_number,ans6);
             }
             else{
                 int ans1;
                 printf("INVALID mobile number!\n");
                 printf("You should input 11 digits !\n");
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     getchar();
                     add(c,n);
                     return;
                 }
                 else if (ans1 == 2)
                 {
                     menu(c,k);
                     return;
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(c,k);
                     return;
                 }

             }





    printf("The account was added successfully!\n");
    char file_name[50];
    FILE*p;
    sprintf(file_name,"%s.txt",c[*n].account_number);
    p = fopen(file_name,"a");
    fclose(p);
    FILE* a;
    a=fopen("accounts.txt","a");
    fprintf(a,"\n%s,%s,%s,%0.2f,%s,%d-%d", c[*n].account_number, c[*n].name, c[*n].email, c[*n].balance, c[*n].mobile_number, c[*n].date_opened.month, c[*n].date_opened.year);
    (*n)++;
    fclose(a);
    int q = *n;
    load(c);
    menu(c,q);

}

void delete_account(account *array,int *n)
{
    FILE *t ;
    int q = *n;
    t=fopen("accounts.txt","w");
    char b[100];
    int temp=0,l=0,x;
    printf("Enter the account number:");
    scanf("%s",b);
    for(int i=0; i<(*n); i++)
    {
        if(strcmp(b,array[i].account_number)==0)
        {
            temp=1 ;
            l=i;
            break;
        }
    }


    if(temp==0)
    {
        printf("there is not account with this account number\n");
        printf("Enter number from the following:\n");
        printf("1-Try again\n");
        printf("2-Back to menu\n");
        scanf("%d",&x);
        if(x==1)
        {
            delete_account(array,n);
            return;
        }
        else if (x==2)
        {
            menu(array,q);
            return;
        }
        else
        {
            printf("INVALID INPUT...Redirecting to menu\n");
                     menu(array,q);
                     return;
        }

    }
    else if (temp==1)
    {
        if(array[l].balance!=0)
        {
            int v;
            printf("sorry i cannot delete this account because the balance is not 0\n");
            printf("Enter number from the following:\n");
            printf("1-Make a withdraw\n");
            printf("2-Back to menu\n");
            scanf("%d",&v);
            if (v == 1)
            {
                withdraw(array,q);
                return;
            }
            else if (v == 2)
            {
                menu(array,q);
                return;
            }
            else
            {
                printf("INVALID INPUT...Redirecting to menu\n");
                     menu(array,q);
                     return;
            }

        }
    }
    for(int i=0; i<*n; i++)
    {
        if(i==l)continue ;
        fprintf(t,"%s,%s,%s,%f,%s,%d-%d\n", array[i].account_number, array[i].name, array[i].email, array[i].balance, array[i].mobile_number, array[i].date_opened.month, array[i].date_opened.year);


    }

    (*n)--;
    q = *n;
    fclose(t);
    printf("The file was deleted successfully !\n");
    load(array);
    menu(array,q);
}
void modify(account a[],int size)
{
    int flag2 = 0,ans3,i,l,flag = 0;
    char ans4[50];
    char ans6[50];
    char ans[50];
    printf("Enter the account number:\n");
    scanf("%s",&ans);
    for (i = 0; i < size; i++)
    {
        if (!strcmp(a[i].account_number,ans))
        {
            flag = 1;
            l = i;
            break;
        }
        else
            flag = 0;


    }

    if (flag == 0)
    {
        int ans1;
        printf("INVALID INPUT!\n");
        printf("Choose a number from the following:\n");
        printf("1-Try again\n");
        printf("2-Back to menu\n");
        scanf("%d",&ans1);
        if (ans1 == 1)
        {
            modify(a,size);
            return;
        }
        else if (ans1 == 2)
        {
            menu(a,size);
            return;
        }
        else
        {
            printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);

            return;
        }
    }
    else
    {
     printf("Choose from the following to edit:\n");
     printf("1-name:\n");
     printf("2-email:\n");
     printf("3-mobile number:\n");
     scanf("%d",&ans3);
     if (ans3 == 1)
     {
         getchar();

         printf("Enter the name:\n");
         gets(ans4);
         for (int n = 0; n < strlen(ans4); n++)
         {
         if(!isalpha(ans4[n])&&ans4[n]!=' ')
         {
                 int ans1;
                 printf("INVALID NAME:\n");
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     getchar();
                     modify(a,size);
                     return;
                 }
                 else if (ans1 == 2)
                 {
                     menu(a,size);
                     return;
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);
                     return;
                 }
                 break;
         }
         }


        //int ans1;
       // printf("Are you sure :");
       // printf("\n1-yes\n");
       // printf("2-No\n");
      //  scanf("%d",&ans1);
       //getchar();
       // if (ans1 == 1)
        //{
            strcpy(a[l].name,ans4);
            printf("The account modified successfully !\n");
            save(a,size);
            menu(a,size);
            return;
       //}
       // else
         //   modify(a,size);
        //   return;




     }
     else if (ans3 == 2)
     {
         getchar();
         printf("Enter the email:\n");
         char check[50];
         gets(check);
         int j = strlen(check);
         for (int m = 0; m < j; m++)
         {
             if(check[m] == '@')
             {
                 //int ans1;
                 //printf("Are you sure :");
                 //printf("\n1-yes\n");
                // printf("2-No\n");
                // scanf("%d",&ans1);
              //  if (ans1 == 1)
               // {
                   strcpy(a[l].email,check);
                   flag2 = 1;
                   printf("The account modified successfully !\n");
                   save(a,size);
                   menu(a,size);
                   break;
                //}
              //  else
               //    modify(a,size);

             }
         }
         if (flag2 == 0)
         {

                 int ans1;
                 printf("INVALID EMAIL:\n");
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     modify(a,size);
                     return;
                 }
                 else if (ans1 == 2)
                 {
                     menu(a,size);
                     return;
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);
                     return;
                 }


         }

     }
     else if (ans3 == 3)
     {
         getchar();
         printf("Enter the mobile number:\n");
         gets(ans6);
         for (int n = 0; n < strlen(ans6); n++)
         {
             if (!isdigit(ans6[n]) || strlen(ans6) != 11)
             {
                 int ans1;
                 printf("INVALID mobile number:\n");
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     modify(a,size);
                     return;
                 }
                 else if (ans1 == 2)
                 {
                     menu(a,size);
                     return;
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);
                     return;
                 }
                 break;
             }

         }


        //int ans1;
       // printf("Are you sure :");
       // printf("\n1-yes\n");
       // printf("2-No\n");
       // scanf("%d",&ans1);
       // if (ans1 == 1)
       // {
            strcpy(a[l].mobile_number,ans6);
            printf("The account was modified successfully !\n");
            save(a,size);
            menu(a,size);
       // }
       // else
        //    modify(a,size);



     }
     else
     {
         printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);
                     return;
     }
   }

    load(a);

}
menu(account* array,int n){
    int x;
printf("Choose an option number from the following:\n");
printf("1-ADD\n2-Delete\n3-Modify\n4-Search\n5-Advanced search\n6-Withdraw\n7-Deposit\n8-Transfer\n9-Report\n10-Print\n11-Quit\n");
scanf("%d",&x);
getchar();
switch (x){
case 1: {add(array,&n);break;}
case 2: {delete_account(array,&n);break;}
case 3: {modify(array,n);break;}
case 4: {search(array,n);break;}
case 5: {advsearch(array,n);break;}
case 6: {withdraw(array,n);break;}
case 7: {deposit(array,n);break;}
case 8: {transfer(array,n);break;}
case 9: {Report(array,n);break;}
case 10: {Print(array,n);break;}
case 11: {printf("Program Ended!\n");exit(0);break;}
default: {printf("Invalid option, please try again: \n");menu(array,n); }
}
}

void Report(account a[],int size)
{
    int i = 0;
    int flag = 0;
    char t[200][200];
    char num[50];
    FILE *p;
    printf("Enter the account number:\n");
    scanf("%s",num);
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(num,a[i].account_number)){
                flag = 1;
                break;
        }
    }

    if (flag == 1){
        char file_name[50];
        sprintf(file_name,"%s.txt",num);
        p = fopen(file_name,"r");
        if (p != NULL)
        {

            while (!feof(p))
            {
              fgets(t[i],200,p);
              i++;
            }
            if (i < 6)
            {
                for (int j = i-1; j >= 0; j--)
                {
                     printf("%s\n",t[j]);
                }
                fclose(p);
                menu(a,size);

            }
            else
            {
                for (int j = i; j >= i-6; j--)
                {
                    printf("%s\n",t[j]);
                }
                fclose(p);
                menu(a,size);
                return;

            }

        }
        else
            printf("ERROR\n");

    }
    else{
        printf("Account not found\n");
                 int ans1;
                 printf("Choose a number from the following:\n");
                 printf("1-Try again\n");
                 printf("2-Back to menu\n");
                 scanf("%d",&ans1);
                 if (ans1 == 1)
                 {
                     Report(a,size);
                     return;
                 }
                 else if (ans1 == 2)
                 {
                     menu(a,size);
                     return;
                 }
                 else
                 {
                     printf("INVALID INPUT...Redirecting to menu\n");
                     menu(a,size);
                     return;
                 }
}
}

void Print(account* array,int n)
{
    int ans;
    printf("Enter number from the following:\n");
    printf("1-sort by name\n");
    printf("2-sort by date\n");
    printf("3-sort by balance\n");
    printf("4-Back to Menu\n");
    scanf("%d",&ans);
     switch(ans){
     case 1: {SortByName(array,n);menu(array,n);break;}
     case 2:{SortByDate(array,n);menu(array,n);break;}
     case 3:{SortByBalance(array,n);menu(array,n);}
     case 4: {menu(array,n);break;}
     default: {printf("Invalid input: Please try again\n");
     Print(array,n);}
     }
}
void SortByName(account* array,int n)
{
    int ans;
    printf("Enter number from the following:\n");
    printf("1-Sort from A to Z\n");
    printf("2-Sort from Z to A\n");
    printf("3-Back\n");
    printf("4-Quit\n");
    scanf("%d",&ans);
    if (ans == 1)
    {
        account temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (strcmp(array[j].name, array[j + 1].name) > 0)
                {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++) print(array,i);

    }
    else if (ans == 2)
    {
        account temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (strcmp(array[j].name, array[j + 1].name) < 0)
                {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++) print(array,i);
    }
    else if (ans == 3)
        Print(array,n);
    else if (ans == 4)
        menu(array,n);
    else
    {
        printf("INVALID INPUT (Enter '1' or '2' or '3' or '4') \n");
        SortByName(array,n);
}
}
void SortByDate(account a[],int size)
{
    int ans;
    printf("Enter number from the following:\n");
    printf("1-Ascending\n");
    printf("2-Descending\n");
    printf("3-Back\n");
    printf("4-Quit\n");
    scanf("%d",&ans);
    if (ans == 1)
    {
        account temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (a[j].date_opened.year > a[j + 1].date_opened.year || (a[j].date_opened.year == a[j + 1].date_opened.year && a[j].date_opened.month > a[j + 1].date_opened.month))
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(int i=0;i<size;i++) print(a,i);
    }
    else if (ans == 2)
    {
        account temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (a[j].date_opened.year < a[j + 1].date_opened.year || (a[j].date_opened.year == a[j + 1].date_opened.year && a[j].date_opened.month < a[j + 1].date_opened.month))
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(int i=0;i<size;i++) print(a,i);
    }
    else if (ans == 3)
        Print(a,size);
    else if (ans == 4)
        menu(a,size);
    else
    {
        printf("INVALID INPUT (Enter '1' or '2' or '3' or '4') \n");
        SortByDate(a,size);
}
}
void SortByBalance(account a[],int size)
{
    int ans;
    printf("1-Ascending\n");
    printf("2-Descending\n");
    printf("3-Back\n");
    printf("4-Quit\n");
    scanf("%d",&ans);
    if (ans == 1)
    {
        account temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (a[j].balance > a[j+1].balance)
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(int i=0;i<size;i++) print(a,i);
    }

    else if (ans == 2)
    {
        account temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (a[j].balance < a[j+1].balance)
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(int i=0;i<size;i++) print(a,i);
    }

    else if (ans == 3)
        Print(a,size);
    else if (ans == 4)
        menu(a,size);
    else
    {
        printf("INVALID INPUT (Enter '1' or '2' or '3' or '4') \n");
        SortByBalance(a,size);
}
}
void withdraw(account* array,int n){
    char input[50]; int option,i,test;
    printf("Enter the account number: "); scanf("%s",&input);
    for(i=0;i<n;i++){
        if(!strcmp(array[i].account_number,input)){ test=0; break;}
        else test=1;
    }
    if(test==1){printf("Error\nYou entered a wrong account number\n");
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu\n");
            scanf("%d",&option);
            if(option==1) withdraw(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}}
    else{
            float w;
    printf("Enter the amount you want to withdraw: "); scanf("%f",&w);
        if(w>10000)
            {
                printf("Error\nYou can withdraw only up to 10000\n");
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu");
            scanf("%d",&option);
            if(option==1) withdraw(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
        }
        else if (w>array[i].balance)
        {
            printf("ERROR ! you can withdraw only up to %f\n",array[i].balance);
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu");
            scanf("%d",&option);
            if(option==1) withdraw(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
        }
        else{ array[i].balance-=w; printf("Succesful.\nYou withdrawed: %.2f\nYour balance now is: %.2f\n",w,array[i].balance);
        save(array,n);

        char account_number[50];
        sprintf(account_number,"%s.txt",input);
        FILE *ptr;
        ptr = fopen(account_number,"a+");
        fprintf(ptr,"Withdrawal of %.2f Balance equals: %.2f\n",w,array[i].balance);
        fclose(ptr);

        printf("Choose a number from the following: \n");
            printf("1-Make another withdraw\n2-Quit to menu\n");
            scanf("%d",&option);
            if(option==1) withdraw(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
}
}
}

void deposit(account* array,int n){
    char input[50]; int i,test,option;
    printf("Enter the account number: "); scanf("%s",input);
    for(i=0;i<n;i++){
        if(!strcmp(array[i].account_number,input)){ test=0; break;}
        else test=1;
    }
    if(test==1){printf("Error\nYou entered a wrong account number\n");
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu\n");
            scanf("%d",&option);
            if(option==1) deposit(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}}
    else{
    float d;
    printf("Enter the amount you want to deposit: "); scanf("%f",&d);
        if(d>10000)
            {printf("Error\nYou can deposit only up to 10000\n");
            printf("Choose a number from the following: \n");
            printf("1-Make another deposit\n2-Quit to menu");
            scanf("%d",&option);
            if(option==1) deposit(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
        }
        else{ array[i].balance+=d; printf("Succesful.\nYou deposited: %.2f\nYour balance now is: %.2f\n",d,array[i].balance);
        save(array,n);

        char account_number[50];
        sprintf(account_number,"%s.txt",input);
        FILE *ptr;
        ptr = fopen(account_number,"a");
        fprintf(ptr,"Deposit of %.2f Balance equals: %.2f\n",d,array[i].balance);
        fclose(ptr);

        printf("Choose a number from the following: \n");
            printf("1-Make another deposit\n2-Quit to menu");
            scanf("%d",&option);
            if(option==1) deposit(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
}
}
}

void transfer(account* array,int n){
    char input1[50]; char input2[50]; int i,option; int j,test1,test2;
     printf("Enter the account number you want to transfer from: "); scanf("%s",&input1);
     printf("Enter the account number you want to transfer to: "); scanf("%s",&input2);
     for(i=0;i<n;i++){
        if(!strcmp(array[i].account_number,input1)) {test1=0; break;}
        else test1=1;
    }
    for(j=0;j<n;j++){
        if(!strcmp(array[j].account_number,input2)){ test2=0; break;}
        test2=1;
    }
    if(test1==1 || test2==1){
        printf("Error\nYou entered a wrong account number\n");
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu\n");
            scanf("%d",&option);
            if(option==1) transfer(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
    }
    else{
    float t;
    printf("Enter the amount you want to transfer: \n"); scanf("%f",&t);
       if(t>array[i].balance || t>10000)
            {printf("Error\nYou can transfer only up to 10000\n");
            printf("Choose a number from the following: \n");
            printf("1-Try again\n2-Quit to menu\n");
            scanf("%d",&option);
            if(option==1) transfer(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
        }
        else{ array[j].balance+=t; array[i].balance-=t; printf("Succesful.\nYou transfered: %.2f",t);
        save(array,n);

        char account_number1[50];
        sprintf(account_number1,"%s.txt",input1);
        FILE *ptr1;
        ptr1 = fopen(account_number1,"a");
        fprintf(ptr1,"Transfer of %.2f from %s to %s Balance equals: %.2f\n",t,array[i].account_number,array[j].account_number,array[i].balance);
        fclose(ptr1);

        char account_number2[50];
        sprintf(account_number2,"%s.txt",input2);
        FILE *ptr2;
        ptr2 = fopen(account_number2,"a");
        fprintf(ptr2,"Transfer of %.2f from %s to %s Balance equals: %.2f\n",t,array[j].account_number,array[i].account_number,array[j].balance);
        fclose(ptr2);


        printf("Choose a number from the following: \n");
            printf("1-Make another transfer\n2-Quit to menu");
            scanf("%d",&option);
            if(option==1) transfer(array,n);
            else if(option==2) menu(array,n);
            else {printf("Invalid Input....Redirecting to menu\n");menu(array,n);}
}
}
}
void save(account a[],int size)
{
    FILE *p;
    p = fopen("accounts.txt","w");
    if (p != NULL){
        for (int i = 0; i < size; i++)
        {
            if (i == size-1)
            {
                fprintf(p,"%s,%s,%s,%0.2f,%s,%d-%d",a[i].account_number,a[i].name,a[i].email,a[i].balance,a[i].mobile_number,a[i].date_opened.month,a[i].date_opened.year);
                break;
            }
            fprintf(p,"%s,%s,%s,%0.2f,%s,%d-%d\n",a[i].account_number,a[i].name,a[i].email,a[i].balance,a[i].mobile_number,a[i].date_opened.month,a[i].date_opened.year);
        }
    fclose(p);
    }
    else
        printf("ERROR\n");
}

int main()
{
    int n=login();
   account*array;
    array=malloc(500*sizeof(account));
    int m = load(array);
    menu(array,m);
return 0;
}
