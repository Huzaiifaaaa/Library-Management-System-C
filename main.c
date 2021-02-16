/*
      GROUP MEMBERS

      M.HUZAIFA
      ABDULLAH ANWAAR
      SYE SAFIULLAH SHAH
      SAAD-UR-REHMAN

      PROJECT DETAILS:

      1-THIS IS A SIMPLE LIBRARY MANAGEMENT SYSTEM.
      2-OPERATIONS YOU CAN PERFORM ARE:
            A-GET MEMBERSHIP
            B-BORROW OR RETURN A BOOK
            C-VIEW LIST OF BOOKS AVAILABLE
            D-GET DETAILS ABOUT BOOKS AVAILABLE
            E-USER CAN SEE THEIR DETAILS
            F-ADMIN CAN ADD OR DELETE BOOK

      3-BEFOR SEARCHING FOR DETAILS OF BOOK YOU MUST HAVE TO ADD BOOK IN RECORD IN ADMINISTRATION PART.
      4-WHILE ADDING BOOK DONOT LEAVE A SPACE BETWEEN WORDS E.G IF NAME OF BOOK IS "ANIMAL FARM" THEN WRITE IT AS "ANIMAL.FARM".
      5-USER NAME FOR ADMIN LOGIN IS  "ADMIN" & PASSWORD IS "@DMIN".


*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

//USER DEFINED FUNCTION DECLARATION(START)
void space()
{                                            //FUNCTION TYPE: TAKES NOTHING, RETURNS SOMETHING
    printf("\t\t\t\t\t\t\t\t    ");          //THIS FUNCTION PRINTS SPACE I.E USED TO PRINT TEXT IN MIDDLE OF SCREEN
}
void times()
{
    time_t t;                              //FUNCTION TYPE: TAKES NOTHING, RETURNS NOTHING
    time(&t);                              //THIS FUNCTION SIMPLY PRINTS PC TIME
    printf("\t\t  %s",ctime(&t));
}
int menu()
{
    int choice;
    system("cls");
    printf("\n\n");                        // FUNCTION TYPE: TAKES NOTHING , RETURNS SOMETHING
    space();                                // SIMPLY PRINTS THE MAIN MENU
    printf("WELCOME TO NUST LIBRARY\n");
    printf("\n\n\n");
    space();
    printf("MENU:\t\t");
    times();
    printf("\n\n");
    space();
    printf("1-GET MEMBERSHIP\n");
    space();
    printf("2-ALREADY A MEMBER?\n");
    space();
    printf("3-BOOKS WE HAVE\n");
    space();
    printf("4-BOOK DETAILS\n");
    space();
    printf("5-USER INFORMATION\n");
    space();
    printf("6-ADMINISTRATION\n");
    space();
    printf("7-EXIT");
    printf("\n\n");
    space();
    printf("Your Choice: ");
    scanf("%d",&choice);
    return choice;
}
int submenu()
{
    int choice;
    printf("\n\n");
    printf("\n\n");                            //FUNCTION TYPE: TAKES NOTHING, RETURNS SOMETHING
    space();                                   // PRINTS SUB-MENU AFTER LOGGING IN
    printf("SUB-MENU:\n");                     // GIVE OPTIONS TO BORROW OR RETURN A BOOK
    printf("\n\n");
    space();
    printf("1-Borrow A Book\n");
    space();
    printf("2-Return A Book\n");
    space();
    printf("3-Go Back");
    printf("\n\n");
    space();
    printf("Your Choice: ");
    scanf("%d",&choice);
    return choice;
}
int adminmenu()
{
    int choice;
    printf("\n\n");
    space();                                    //FUNCTION TYPE: TAKES NOTHING, RETURNS SOMETHING
    printf("ADMINISTRATION-MENU:");             // PRINTS ADMIN-MENU AFTER LOGGING IN TO ADMIN ACCOUNT
    times();
    printf("\n\n");
    space();
    printf("1-ADD BOOK\n");
    space();
    printf("2-DELETE BOOK\n");
    space();
    printf("3-GO BACK");
    printf("\n\n");
    space();
    printf("Your Choice: ");
    scanf("%d",&choice);
    return choice;
}
void exist()
{
    printf("\n\n");
    space();
    printf("User Does-not Exist!!\n");                //FUNCTION TYPE: TAKES NOTHING RETURNS NOTHING
    space();                                          //IF USER ACCOUNT DOESNOT EXISTS THIS FUNCTION IS CALLED
    printf("Please Get Membership!!\n");
    printf("\n\n");
    space();
    printf("Press Any Key To Continue!!");
    printf("\n\n");
    getchar();
    getchar();
}
void username()
{
    space();
    printf("User-name Not Available!!\n");
    space();                                         //FUNCTION TYPE: TAKES NOTHING RETURNS NOTHING
    printf("Try Another User-name!!\n");             // IF USER-NAME IS CURRENTLY BEING USED BY ANY OTHER USER THEN THIS FUNCTION US CALLED
    printf("\n\n");                                  //LOGIC:
    space();                                              //1-USER ENTERS THEIR DESIRED USERNAME
    printf("Press ENTER To RETRY!!\n");                   //2- AND FILE WITH THAT NAME IS OPENED
    getchar();                                            //3-IF FILE IS OPENED THEN USERNAME IS ALREADY TAKEN OTHERWISE IT IS AVAILABLE
    getchar();
}
void fileerror()
{
    space();
    printf("Error!! Information Not Saved!!\n");      //FUNCTION TYPE: TAKES NOTHING, RETURNS NOTHING
    space();                                          //PRINTED WHEN FILE NOT OPENED
    printf("Try Again!!\n");                          // IF FILE IS NOT OPENED THEN DATA IS NOT PRINTED IN FILE I.E DATA NOT SAVED
    space();
    printf("Press ENTER To Continue!!");
    getchar();
    getchar();
}
void wrong()
{
    printf("\n\n");
    space();                                       //FUNCTION TYPE: TAKES NOTHING, RETURNS NOTHING
    printf("Wrong User-name or Password!!\n");     // IF USER NAME OR PASSWORD ENTERED IS WRONG THEN THIS FUNCTION IS CALLED
    space();
    printf("Press ENTER To RETRY!!");
    getchar();
    getchar();
}
//USER DEFINED FUNCTION DECLARATION END
struct member
 {
    char fullname[30];
    long long int number;                           //STRUCTURE DATA TYPE
    char email[30];                                 // STORES USER DATA
    char username[15];
    char password[15];
    int borrowed;
};
struct book
{
    char bookname[30];
    char author[30];                                 //STRUCTURE DATA TYPE
    char language[30];                                // STORES BOOK DATA
    int publish;
    int pages;
    char edition[10];
    float ratings;
};
int main()                                             //MAIN FUNCTION STARTING
{
        int option;
        char name[20];                              //DATA TYPE AND VARIABLE DECLARATIONS
        char code[20];
        char bookname[30];
        struct member data;
        struct book info;
        data.borrowed=0;
        info.publish=0;
        info.pages=0;
        info.ratings=0;
        char adminname[7]="ADMIN";                    //ADMIN LOGIN USERNAME
        char adminpassword[10]="@DMIN";               //ADMIN LOGIN PASSWORD
        char c;
        int serialnumber;
        FILE*ptr;
        FILE*books;                                   //FILE POINTERS USED
        FILE*available;
        FILE*bookrecord;
        menu:
        option=menu();                                 //MAIN FUNCTION CALLED TO PRINT MENU, RETURNS CHOICE TO OPTION
        switch(option)                                 //SWITCH STATEMENT
        {
            case 1:                                     //CASE 1: GET MEMBERSHIP
                {
                    system("cls");
                    printf("\n\n");
                    space();
                    printf("SIGN-UP");
                    printf("\t\t");
                    times();
                    printf("\n\n");
                    space();
                    printf("Enter Name: ");
                    scanf("%s",&data.fullname);
                    space();
                    printf("Enter Contact Number: ");
                    scanf("%lld",&data.number);
                    space();
                    printf("Enter Email: ");
                    scanf("%s",&data.email);
                    member:
                    printf("\n\n\n");
                    space();
                    printf("Enter User-name: ");
                    scanf("%s",&data.username);
                    space();
                    printf("Re-enter User-name: ");
                    scanf("%s",&name);
                    printf("\n\n");
                    space();
                    printf("Enter Password: ");
                    scanf("%s",&data.password);
                    space();
                    printf("Re-enter Password: ");
                    scanf("%s",&code);
                    printf("\n");
                    ptr=fopen(data.username,"r");              //CHECKING WHETHER USER NAME IS AVAILABLE OR NOT
                    if(ptr!=0)
                        {
                            username();
                            goto member;
                            break;
                        }
                    else
                        {
                            if(strcmp(data.password,code)==0&&strcmp(data.username,name)==0)     //COMPARING USERNAME & PASSWORD
                                {
                                    printf("\n\n");
                                    space();
                                    printf("Account Created Successfully!!\n");
                                    printf("\n");
                                    space();
                                    printf("You are now MEMBER Of NUST LIBRARY!!\n");
                                    printf("\n");
                                    space();
                                    printf("Your Information Has Been Saved!!\n");
                                    printf("\n");
                                    space();
                                    printf("Press ENTER To Go To MENU!!\n");
                                }
                            else
                                {
                                    printf("\n");
                                    space();
                                    printf("Entered Credentials Does not Match!!\n");
                                    space();
                                    printf("Press Any Key To RE-ENTER!!");
                                    getchar();
                                    getchar();
                                    goto member;
                                    break;
                                }
                        }
                    ptr=fopen(data.username,"w");                     //CREATING FILE , FILE IS CREATED BY USER-NAME
                    if(ptr==NULL)
                        {
                            fileerror();
                            goto member;
                            break;
                        }
                    else
                        {
                            fprintf(ptr,"%s\n",data.fullname);          //PRINTING DATA IN FILE
                            fprintf(ptr,"%lld\n",data.number);
                            fprintf(ptr,"%s\n",data.email);
                            fprintf(ptr,"%s\n",data.username);
                            fprintf(ptr,"%s\n",data.password);
                            fprintf(ptr,"%d\n",data.borrowed);
                            fclose(ptr);
                        }
                    getchar();
                    getchar();
                    goto menu;
                    break;
            }
            case 2:                                      //LOGGING IN TO ACCOUNT
                {
                    error:
                    system("cls");
                    printf("\n\n");
                    space();
                    printf("WELCOME TO NUST LIBRARY\n");
                    printf("\n\n");
                    space();
                    printf("LOG-IN\t\t");
                    times();
                    printf("\n\n");
                    space();
                    printf("Enter User-name: ");
                    scanf("%s",&name);
                    space();
                    printf("Enter Password: ");
                    scanf("%s",&code);
                    ptr=fopen(name,"rb");                //OPENING USER FILE, IF FILE DOSE NOT OPENS THEN USER DOESNOT EXISTS
                    if(ptr==NULL)
                        {
                            exist();
                            goto menu;
                            break;
                        }
                    else
                        {
                            fscanf(ptr,"%s",&data.fullname);     //TAKING DATA FROM FILE AND STORING THEM IN VARIABLES
                            fscanf(ptr,"%lld",&data.number);
                            fscanf(ptr,"%s",&data.email);
                            fscanf(ptr,"%s",&data.username);
                            fscanf(ptr,"%s",&data.password);
                            fscanf(ptr,"%d",&data.borrowed);
                            fclose(ptr);
                            if(strcmp(data.password,code)==0&&strcmp(data.username,name)==0)          //COMPARING ENTERED PASWORD AND USERNAME WITH PASSWORD AND USERNAME CREATED WHILE CREATING ACCOUNT
                                {
                                    printf("\n\n");
                                    space();
                                    printf("Welcome--%s",strupr(data.fullname));
                                    printf("\n");
                                    submenu:
                                    option=submenu();           //PRINTING SUB MENU
                                    switch(option)
                                        {
                                            case 1:                     //BORROWNING A BOOK
                                                {
                                                    system("cls");
                                                    printf("\n\n");
                                                    printf("\n\n");
                                                    space();
                                                    printf("  S.No    NAME\t\t\t   AUTHOR\n\n");
                                                    available=fopen("AVAILABLE.txt","r");        //OPENING FILE WHICH STORES BOOK DATA
                                                    c=fgetc(available);                           //PRINTING FILE DATA
                                                    while (c!=EOF)
                                                        {
                                                            printf("%c",c);
                                                            c=fgetc(available);
                                                        }
                                                    fclose(available);
                                                    printf("\n\n");
                                                    space();
                                                    printf("Enter Serial Number Of Book: ");
                                                    scanf("%d",&serialnumber);
                                                    printf("\n\n");
                                                    space();
                                                    printf("Book Borrowed Successfully!!\n");
                                                    data.borrowed=data.borrowed+1;                   //IF BOOK BOROWED INCREASING BORRWED NUMBER BY 1
                                                    ptr=fopen(data.username,"w");                     //OPENING USER FILE TO SAVE DATA
                                                    if(ptr==NULL)
                                                        {
                                                            fileerror();
                                                            goto submenu;
                                                            break;
                                                        }
                                                    else
                                                        {
                                                            fprintf(ptr,"%s\n",data.fullname);       //PRINTING DATA IN FILE
                                                            fprintf(ptr,"%lld\n",data.number);
                                                            fprintf(ptr,"%s\n",data.email);
                                                            fprintf(ptr,"%s\n",data.username);
                                                            fprintf(ptr,"%s\n",data.password);
                                                            fprintf(ptr,"%d\n",data.borrowed);
                                                            fclose(ptr);
                                                        }
                                                    printf("\n\n");
                                                    space();
                                                    printf("Press ENTER To Go To SUB-MENU!!");
                                                    getchar();
                                                    getchar();
                                                    system("cls");
                                                    goto submenu;
                                                }
                                            case 2:                       //RETURNING A BOOK
                                                {
                                                    system("cls");
                                                    printf("\n\n");
                                                    printf("\n\n");
                                                    if(data.borrowed==0)        //IF NO BOOK IS BORROWED
                                                        {
                                                            printf("\n\n");
                                                            space();
                                                            printf("You Have Not Borrowed Any Book!!\n");
                                                            printf("\n\n");
                                                            space();
                                                            printf("Press ENTER To Go To SUB-MENU!!");
                                                            getchar();
                                                            getchar();
                                                            system("cls");
                                                            goto submenu;
                                                            break;
                                                        }
                                                    else
                                                        {
                                                            printf("\n\n");
                                                            space();
                                                            printf("Enter Name Of Book: ");
                                                            scanf("%s",&bookname);
                                                            printf("\n\n");
                                                            space();
                                                            printf("Book Returned Successfully!!");
                                                            data.borrowed=data.borrowed-1;         //IF BOOK RETURNED THEN DECREASING BORROWED NUMBER BY 1
                                                            ptr=fopen(data.username,"w");          //OPENING FILE TO PRINT DATA
                                                            if(ptr==NULL)
                                                                {
                                                                    fileerror();
                                                                    goto submenu;
                                                                    break;
                                                                }
                                                            else
                                                                {
                                                                    fprintf(ptr,"%s\n",data.fullname);     //PRINTING DATA IN FILE
                                                                    fprintf(ptr,"%lld\n",data.number);
                                                                    fprintf(ptr,"%s\n",data.email);
                                                                    fprintf(ptr,"%s\n",data.username);
                                                                    fprintf(ptr,"%s\n",data.password);
                                                                    fprintf(ptr,"%d\n",data.borrowed);
                                                                    fclose(ptr);
                                                                }
                                                            printf("\n\n");
                                                            space();
                                                            printf("Press ENTER To Go To SUB-MENU!!");
                                                            getchar();
                                                            getchar();

                                                        }
                                                        goto submenu;
                                                }
                                            case 3:
                                                {
                                                    goto menu;
                                                    break;
                                                }
                                            default:
                                                {
                                                    printf("\n\n");
                                                    space();
                                                    printf("Wrong Choice!!\n");
                                                    space();
                                                    printf("Please Choose Any Option Between 1 & 3!!\n");
                                                    printf("\n\n");
                                                    space();
                                                    printf("Press Enter To Continue!!\n");
                                                    getchar();
                                                    getchar();
                                                    goto submenu;
                                                    break;
                                                }
                                        }
                                    break;
                                }
                            else
                                {
                                    wrong();
                                    goto error;
                                    break;
                                }
                        }
                    goto submenu;
                    break;
                }
            case 3:                                        //TO SEE LIST OF BOOKS AVAILABLE
                {
                    available=fopen("AVAILABLE.txt","r");  //OPENING FILE IN READ MODE
                    if(books==NULL)                        //IF FILE NOT OPENED
                        {
                            printf("\n\n");
                            space();
                            printf("Unable To Load Data!!\n");
                            space();
                            printf("Press ENTER to Continue!!");
                            getchar();
                            getchar();
                            goto menu;
                            break;
                        }
                    else
                        {
                            printf("\n\n");
                            space();
                            printf("Books Available Are: ");
                            printf("\n\n");
                            space();
                            printf("  S.No    NAME\t\t\t   AUTHOR\n\n");
                            c=fgetc(available);
                            while (c != EOF)              //PRINTING FILE DATA
                                {
                                    printf("%c",c);
                                    c=fgetc(available);
                                }
                            fclose(available);
                            printf("\n\n\n\n");
                            space();
                            printf("Press ENTER To go to MENU!!");
                            getchar();
                            getchar();
                        }
                    goto menu;
                    break;
                }
            case 4:                                    //SEARCHING FOR BOOK DETAILS
                {
                    record:
                    printf("\n\n");
                    space();
                    printf("Enter Book Name: ");     //ENTER BOOK NAME, DONOT ENTER SPACE INSTEAD USE A DOT "."
                    scanf("%s",&bookname);
                    strupr(bookname);
                    bookrecord=fopen(bookname,"r");  //OPENING FILE
                    if(bookrecord==NULL)              // IF FILE IS NOT OPENED THEN BOOK IS NOT IN RECORD
                        {
                            printf("\n\n");
                            space();
                            printf("Book Not Found!!");
                            printf("\n\n");
                            space();
                            printf("Press ENTER To Continue!!");
                            getchar();
                            getchar();
                            goto menu;
                            break;
                        }
                    else
                        {
                            fscanf(bookrecord,"%s",&info.bookname);
                            fscanf(bookrecord,"%s",&info.author);         //TAKING BOOK DATA IN VARIABLES
                            fscanf(bookrecord,"%s",&info.language);
                            fscanf(bookrecord,"%d",&info.publish);
                            fscanf(bookrecord,"%d",&info.pages);
                            fscanf(bookrecord,"%s",&info.edition);
                            fscanf(bookrecord,"%f",&info.ratings);
                            fclose(bookrecord);
                            printf("\n\n");
                            space();
                            printf("Book Name: %s\n",info.bookname);
                            space();
                            printf("Author: %s\n",strupr(info.author));          //PRINTING DATA
                            printf("\n\n");
                            space();
                            printf("Language: %s\n",info.language);
                            space();
                            printf("Publish Year: %d\n",info.publish);
                            printf("\n\n");
                            space();
                            printf("Pages: %d\n",info.pages);
                            space();
                            printf("Edition: %s\n",info.edition);
                            printf("\n\n");
                            space();
                            printf("Good Read Ratings: %.2f\n",info.ratings);
                            printf("\n\n");
                            space();
                            printf("Press ENTER To Go To MENU!!");
                            getchar();
                            getchar();
                            goto menu;
                            break;
                        }
                    break;
                }
            case 5:             //USER INFORMATION
                {
                    info:
                    system("cls");
                    printf("\n\n");
                    space();
                    printf("WELCOME TO NUST LIBRARY\n");
                    printf("\n\n");
                    space();
                    printf("LOG-IN\t\t");
                    times();
                    printf("\n\n");
                    space();
                    printf("Enter User-name: ");
                    scanf("%s",&name);
                    space();
                    printf("Enter Password: ");
                    scanf("%s",&code);
                    ptr=fopen(name,"r");             //OPENING FILE
                    if(ptr==NULL)                    //IF FILE NOT OPENED THEN USER DONT EXIST
                        {
                            exist();
                            goto menu;
                            break;
                        }
                    else
                        {
                            fscanf(ptr,"%s",&data.fullname);                 //IF FILE IS OPENED THEN STORING FILE DATA IN VARIABLES
                            fscanf(ptr,"%lld",&data.number);
                            fscanf(ptr,"%s",&data.email);
                            fscanf(ptr,"%s",&data.username);
                            fscanf(ptr,"%s",&data.password);
                            fscanf(ptr,"%d",&data.borrowed);
                            fclose(ptr);
                            if(strcmp(data.password,code)==0&&strcmp(data.username,name)==0)
                                {
                                    printf("\n\n");
                                    space();
                                    printf("Welcome--%s\t",strupr(data.fullname));
                                    times();
                                    printf("\n\n");
                                    space();
                                    printf("NAME & CONTACT\n");
                                    printf("\n\n");
                                    space();
                                    printf("Name: %s\n",data.fullname);
                                    space();
                                    printf("Phone: %lld\n",data.number);
                                    space();
                                    printf("Email: %s\n",data.email);
                                    printf("\n\n");
                                    space();
                                    printf("USERNAME & PASSWORD\n");
                                    printf("\n\n");
                                    space();
                                    printf("Sensitive Information!!\n");
                                    getchar();
                                    getchar();
                                    space();
                                    printf("User-name: %s\n",data.username);
                                    space();
                                    printf("Password: %s\n",data.password);
                                    printf("\n\n");
                                    space();
                                    printf("BOOK INFORMATION\n");
                                    printf("\n\n");
                                    space();
                                    printf("Books Borrowed: %d",data.borrowed);
                                    printf("\n\n");
                                    space();
                                    printf("Press Any Key To Continue!!\n\n\n");
                                    getchar();
                                    getchar();
                                    goto menu;
                                    break;
                                }
                            else
                                {
                                    wrong();
                                    goto info;
                                    break;
                                }
                        }
                }
            case 6:                       //ADMIN LOGIN
                {
                    system("cls");
                    printf("\n\n");
                    space();
                    printf("WELCOME TO NUST LIBRARY\n");
                    printf("\n\n");
                    space();
                    printf("ADMINISTRATION LOG-IN");
                    times();
                    printf("\n\n");
                    space();
                    printf("Enter User-name: ");
                    scanf("%s",&name);
                    space();
                    printf("Enter Password: ");
                    scanf("%s",&code);
                    if(strcmp(adminpassword,code)==0&&strcmp(adminname,name)==0) //COMPARING ENTERED NAME AND PASSWORD WITH OUR DECLARED NAME AND PASSORDD
                        {
                            adminmenu:
                            option=adminmenu();
                            switch(option)
                                {
                                    case 1:          //ADDING BOOK IN RECORD
                                        {
                                            system("cls");
                                            printf("\n\n");
                                            space();
                                            printf("WELCOME TO NUST LIBRARY\n");
                                            printf("\n\n");
                                            space();
                                            printf("ADMINISTRATION LOG-IN");
                                            times();
                                            printf("\n\n");
                                            space();
                                            printf("Book Name: ");
                                            scanf("%s",info.bookname);
                                            bookrecord=fopen(strupr(info.bookname),"r");    //OPENING FILE
                                            if(bookrecord!=NULL)
                                                {
                                                    printf("\n\n");                           //IF FILE OPENS THEN BOOK IS ALREADY IN RECORD
                                                    space();
                                                    printf("Book Already In Record!!\n\n");
                                                    space();
                                                    printf("Press Enter To Continue!!");
                                                    getchar();
                                                    getchar();
                                                    system("cls");
                                                    fclose(bookrecord);
                                                    goto adminmenu;
                                                    break;
                                                }
                                            space();
                                            printf("Author: ");
                                            scanf("%s",&info.author);
                                            printf("\n\n");
                                            space();
                                            printf("Language: ");
                                            scanf("%s",&info.language);
                                            space();
                                            printf("Publish Year: ");
                                            scanf("%d",&info.publish);
                                            printf("\n\n");
                                            space();
                                            printf("Pages: ");
                                            scanf("%d",&info.pages);
                                            space();
                                            printf("Edition: ");
                                            scanf("%s",&info.edition);
                                            printf("\n\n");
                                            space();
                                            printf("Good Reads Ratings: ");
                                            scanf("%f",&info.ratings);
                                            bookrecord=fopen(strupr(info.bookname),"w");         //CREATING FILE
                                            if(bookrecord==NULL)
                                                {
                                                    fileerror();
                                                    goto adminmenu;
                                                    break;
                                                }
                                            else
                                                {
                                                    fprintf(bookrecord,"%s\n",info.bookname);       //PRINTING DATA IN FILE
                                                    fprintf(bookrecord,"%s\n",info.author);
                                                    fprintf(bookrecord,"%s\n",info.language);
                                                    fprintf(bookrecord,"%d\n",info.publish);
                                                    fprintf(bookrecord,"%d\n",info.pages);
                                                    fprintf(bookrecord,"%s\n",info.edition);
                                                    fprintf(bookrecord,"%f\n",info.ratings);
                                                    fclose(bookrecord);
                                                }
                                            printf("\n\n");
                                            space();
                                            printf("Record Saved!!");
                                            getchar();
                                            getchar();
                                            system("cls");
                                            goto adminmenu;
                                            break;
                                        }
                                    case 2:                                    //DELETING A BOOK
                                        {
                                            printf("\n\n");
                                            space();
                                            printf("Enter Name: ");           //DONOT ENTER SPACE, USE DOT "." INSTEAD
                                            scanf("%s",&bookname);
                                            if(remove(bookname)==0)                //USING REMOVE FUNCTION TO DELETE
                                                {
                                                    printf("\n\n");
                                                    space();
                                                    printf("Deleted Successfully!!");
                                                    printf("\n\n");
                                                    space();
                                                    printf("Press ENTER To Continue!!");
                                                    getchar();
                                                    getchar();
                                                    goto adminmenu;
                                                }
                                            else               //IF BOOK NOT DELETED THEN BOOK IS NOT FOUND
                                                {
                                                    printf("\n\n");
                                                    space();
                                                    printf("Book Not Found!!");
                                                    printf("\n\n");
                                                    space();
                                                    printf("Press ENTER To Continue!!");
                                                    getchar();
                                                    getchar();
                                                    system("cls");
                                                    goto adminmenu;
                                                    break;
                                                }

                                            break;
                                        }
                                    case 3:
                                        {
                                            goto menu;
                                            break;
                                        }
                                    default:
                                        {
                                            printf("\n\n");
                                            space();
                                            printf("Wrong Choice!!\n");
                                            space();
                                            printf("Please Choose Any Option Between 1 & 3!!\n");
                                            printf("\n\n");
                                            space();
                                            printf("Press Enter To Continue!!\n");
                                            getchar();
                                            getchar();
                                            goto adminmenu;
                                            break;
                                        }
                                }
                        }
                    else
                        {
                            printf("\n\n");
                            space();
                            printf("Wrong User Name Or Password!!");
                            printf("\n\n");
                            getchar();
                            getchar();
                            goto menu;
                            break;
                        }
                    break;
                }
            case 7:
                {
                    exit(1);
                    break;
                }
            default:
                {
                    printf("\n\n");
                    space();
                    printf("Wrong Choice!!\n");
                    space();
                    printf("Please Choose Any Option Between 1 & 7!!\n");
                    printf("\n\n");
                    space();
                    printf("Press Enter To Continue!!\n");
                    getchar();
                    getchar();
                    goto menu;
                    break;
                }
        }
        return 0;
}
