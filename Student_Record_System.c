#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef struct date
{
    int dd,mm,yyyy;
}DATE;

typedef struct STUD
{
    int rollno;
    char firstName[10];
    char lastName[10];
    int marks[3];
    float average;
    DATE d;
}STUD;

int num;

int Menu();
int SortMenu();
void Login();

void AddStudent(STUD [MAX],int);
void DisplayRecords(STUD [MAX]);

void Sort(STUD [MAX]);
void SortByFirstName(STUD [MAX]);
void SortByLastName(STUD [MAX]);
void SortByRollNo(STUD [MAX]);
void SortByAverage(STUD [MAX]);
void SortByDOB(STUD [MAX]);

void Search(STUD [MAX]);
void Modify(STUD [MAX]);
void Delete(STUD [MAX]);

void SaveToFile(STUD [MAX]);
void RetriveData(STUD [MAX]);

void main()
{
    STUD s[MAX];
    int choice,no;
    RetriveData(s);
    Login();
    while(1)
    {
        choice=Menu();
        switch(choice)
        {
            case 1:
                printf("\n   Enter the no of Students:- ");
                scanf("%d",&no);
                AddStudent(s,no);
                break;

            case 2:
                DisplayRecords(s);
                break;

            case 3:
                Sort(s);
                break;

            case 4:
                Search(s);
                break;

            case 5:
                Modify(s);
                break;

            case 6:
                Delete(s);
                break;

            case 7:
                SaveToFile(s);
                break;

            case 0:
                exit(0);

            default:
                printf("\n  Enter correct Choice\n");
                getch();
                system("cls");
                break;
        }
    }
}

void Login()
{
    char userName[10],passWord[10];
    int flag;
    while(1)
    {
        flag=0;
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                                                                                                                                |\n");
        printf("|                                                                                        Student Record Management Database                                                                                      |\n");
        printf("|                                                                                                                                                                                                                |\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\n\n\n");
        printf("                                                                             ---------------------------------------------------                                                                                  \n");
        printf("                                                                             |                      Login                      |                                                                                  \n");
        printf("                                                                             ---------------------------------------------------                                                                                  \n");
        printf("\n                                                                             |   Enter Username:- ");
        gets(userName);
        printf("\n                                                                             |   Enter Password:- ");
        gets(passWord);
        if (strcmp(userName,"Aquasin"))
            flag=1;
        if (strcmp(passWord,"Aquasin"))
            flag=1;

        if(flag)
        {
            printf("\n                                                                             |   Password or Username Incorrect\n");
            system("pause");
            system("cls");
        }
        else
        {
            break;
        }
    }
    printf("\n\n\n                                                                             ------------------Welcome %s------------------\n",userName);
    system("pause");
    system("cls");
}

int Menu()
{
    int no;
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                                                                                                                                                                |\n");
    printf("|                                                                                        Student Record Management Database                                                                                      |\n");
    printf("|                                                                                                                                                                                                                |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("   ---------------------------------\n");
    printf("   |           - Menu -            |\n");
    printf("   ---------------------------------\n");
    printf("   |  1 : Enter Data of Student    |\n");
    printf("   ---------------------------------\n");
    printf("   |  2 : Display Data of Student  |\n");
    printf("   ---------------------------------\n");
    printf("   |  3 : Sort                     |\n");
    printf("   ---------------------------------\n");
    printf("   |  4 : Search                   |\n");
    printf("   ---------------------------------\n");
    printf("   |  5 : Modify                   |\n");
    printf("   ---------------------------------\n");
    printf("   |  6 : Delete                   |\n");
    printf("   ---------------------------------\n");
    printf("   |  7 : Save Students data       |\n");
    printf("   ---------------------------------\n");
    printf("   |  0 : Exit                     |\n");
    printf("   ---------------------------------\n");
    printf("\n   Give your choice:- ");
    scanf("%d",&no);
    return no;
}

int SortMenu()
{
    int no;
    printf("   ---------------------------------\n");
    printf("   |         - Sort Menu -         |\n");
    printf("   ---------------------------------\n");
    printf("   |  1 : Sort by First Name       |\n");
    printf("   ---------------------------------\n");
    printf("   |  2 : Sort by Last Name        |\n");
    printf("   ---------------------------------\n");
    printf("   |  3 : Sort by Roll No          |\n");
    printf("   ---------------------------------\n");
    printf("   |  4 : Sort by Average Marks    |\n");
    printf("   ---------------------------------\n");
    printf("   |  5 : Sort by Date Of Birth    |\n");
    printf("   ---------------------------------\n");
    printf("   |  0 : Exit from Sort Menu      |\n");
    printf("   ---------------------------------\n");
    printf("\n   Give your choice:- ");
    scanf("%d",&no);
    return no;
}

void AddStudent(STUD s[MAX],int no)
{
    for(int i=num;i<num+no;i++)
    {
        fflush(stdin);
        printf("\n   Enter details for Student %d",i+1);
        printf("\n   First Name:- ");
        gets(s[i].firstName);
        printf("   Last Name:- ");
        gets(s[i].lastName);
        printf("   Rollno:- ");
        scanf("%d",&s[i].rollno);
        printf("   Marks obtained in Maths, Science and English (Each out of 100):- ");
        scanf("%d %d %d",&s[i].marks[0],&s[i].marks[1],&s[i].marks[2]);
        s[i].average = (float)(s[i].marks[0]+s[i].marks[1]+s[i].marks[2])/3;
        printf("   Enter Date, Month and Year of Birth:- ");
        scanf("%d %d %d",&s[i].d.dd,&s[i].d.mm,&s[i].d.yyyy);
    }
    num=num+no;
    system("cls");
}

void DisplayRecords(STUD s[MAX])
{
    int i;
    printf("\n   --------------- ------------- ------------ ------------ ------------- --------------- --------------- --------------- --------------- ");
    printf("\n  | Record Number | Roll Number | First Name | Last  Name | Maths Marks | Science Marks | English Marks | Average Marks | Date Of Birth |");
    printf("\n   --------------- ------------- ------------ ------------ ------------- --------------- --------------- --------------- --------------- ");
    for(i=0;i<num;i++)
        printf("\n  |     %3d       |    %3d      | %10s | %10s |     %3d     |     %3d       |      %3d      |    %5.2f      |  %2d/%2d/%4d   |",i+1,s[i].rollno,s[i].firstName,s[i].lastName,s[i].marks[0],s[i].marks[1],s[i].marks[2],s[i].average,s[i].d.dd,s[i].d.mm,s[i].d.yyyy);
    printf("\n   --------------- ------------- ------------ ------------ ------------- --------------- --------------- --------------- --------------- ");
    printf("\n");
    getch();
    system("cls");
}

void swap(STUD *x,STUD *y)
{
    STUD temp = *x;
    *x = *y;
    *y = temp;
}

void Sort(STUD s[MAX])
{
    int choice;
    char choice2;
    system("cls");
    while(1)
    {
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                                                                                                                                                                |\n");
    printf("|                                                                                        Student Record Management Database                                                                                      |\n");
    printf("|                                                                                                                                                                                                                |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        choice=SortMenu();
        switch(choice)
        {
            case 1:
                SortByFirstName(s);
                break;

            case 2:
                SortByLastName(s);
                break;

            case 3:
                SortByRollNo(s);
                break;

            case 4:
                SortByAverage(s);
                break;

            case 5:
                SortByDOB(s);
                break;

            case 0:
                system("cls");
                return;

            default:
                printf("\n   Enter correct Choice\n");
                break;
        }
        fflush(stdin);
        printf("\n   Do you want to store sorted records? - ");
        scanf("%c",&choice2);
        if(choice2 =='y' || choice2 == 'Y')
            SaveToFile(s);
        else
            system("cls");
    }
}

void SortByFirstName(STUD s[MAX])
{
    int i, j;
    char choice;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (strcmp(s[j].firstName,s[j+1].firstName)>0)
              swap(&s[j],&s[j+1]);
        }
    }
    printf("\n   Records Sorted\n");
}

void SortByLastName(STUD s[MAX])
{
    int i, j;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (strcmp(s[j].lastName,s[j+1].lastName)>0)
              swap(&s[j],&s[j+1]);
        }
    }
    printf("\n   Records Sorted\n");
}

void SortByRollNo(STUD s[MAX])
{
    int i, j;
    STUD temp;
    for (i=1;i<num;i++)
    {
        temp = s[i];
        j=i-1;

        while(j>=0 && s[j].rollno>temp.rollno)
        {
            s[j+1] = s[j];
            j=j-1;
        }
        s[j+1] = temp;
    }
    printf("\n   Records Sorted\n");
}

void SortByAverage(STUD s[MAX])
{
    int i,j,pos;
    STUD temp;
    for (i = 0; i < num-1; i++)
    {
        pos=i;
        for (j = i+1;j<num;j++)
        {
            if (s[j].average < s[pos].average)
              pos=j;
        }
        if(pos!=i)
        {
            swap(&s[i],&s[pos]);
        }
    }
    printf("\n   Records Sorted\n");
}

void SortByDOB(STUD s[MAX])
{
    int i,j;
    for (i=0;i<num-1;i++)
    {
        for(j=0;j<num-1-i;j++)
        {
            if(s[j].d.yyyy>s[j+1].d.yyyy)
            {
                swap(&s[j],&s[j+1]);
            }
            if(s[j].d.yyyy == s[j+1].d.yyyy && s[j].d.mm>s[j+1].d.mm)
            {
                swap(&s[j],&s[j+1]);
            }
            if(s[j].d.yyyy == s[j+1].d.yyyy && s[j].d.mm == s[j+1].d.mm && s[j].d.dd>s[j+1].d.dd)
            {
                swap(&s[j],&s[j+1]);
            }
        }
    }
    printf("\n   Records Sorted\n");
}

void Search(STUD s[MAX])
{
    int no,j,flag=0;
    printf("\n   Enter the roll No of the student to search:- ");
    scanf("%d",&no);
    for(j=0;j<num;j++)
    {
        if(s[j].rollno==no)
        {
            printf("\n   Record Found...\n");
            printf("\n   First Name:- %s ",s[j].firstName);
            printf("\n   Last Name:- %s ",s[j].lastName);
            printf("\n   Rollno:- %d",s[j].rollno);
            printf("\n   Marks obtained in Maths, Science and English (Each out of 100):- %d %d %d",s[j].marks[0],s[j].marks[1],s[j].marks[2]);
            printf("\n   Average Marks Obtained:- %f",s[j].average);
            printf("\n   Date, Month and Year of Birth:- %d/%d/%d",s[j].d.dd,s[j].d.mm,s[j].d.yyyy);
            flag++;
            getch();
            system("cls");
            break;
        }
    }
    if(!flag)
    {
        printf("\n   Record with Roll No %d not found...",no);
        getch();
        system("cls");
    }
}

void Modify(STUD s[MAX])
{
    int no,j,flag=0;
    printf("\n   Enter the roll No of the student to modify:- ");
    scanf("%d",&no);
    for(j=0;j<num;j++)
    {
        if(s[j].rollno==no)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        fflush(stdin);
        printf("\n   Enter details for Student %d",j+1);
        printf("\n   First Name:- ");
        gets(s[j].firstName);
        printf("   Last Name:- ");
        gets(s[j].lastName);
        printf("   Rollno:- ");
        scanf("%d",&s[j].rollno);
        printf("   Marks obtained in Maths, Science and English (Each out of 100):- ");
        scanf("%d %d %d",&s[j].marks[0],&s[j].marks[1],&s[j].marks[2]);
        s[j].average = (float)(s[j].marks[0]+s[j].marks[1]+s[j].marks[2])/3;
        printf("   Enter Date, Month and Year of Birth:- ");
        scanf("%d %d %d",&s[j].d.dd,&s[j].d.mm,&s[j].d.yyyy);
        SaveToFile(s);
    }
    else
    {
        printf("\n   Record with Roll No %d not found...",no);
        getch();
        system("cls");
    }
}

void Delete(STUD s[MAX])
{
    int j,no,flag=0;
    printf("\n   Enter the roll No of the student to Delete:- ");
    scanf("%d",&no);
    for (j = 0; j < num; j++)
    {
        if (no == s[j].rollno)
        {
            flag++;
            for (int k = j; k < num-1; k++)
                s[k] = s[k + 1];
            num--;
            printf("\n   Record deleted successfully\n");
            break;
        }
    }
    if(flag)
        SaveToFile(s);
    else
    {
        printf("\n   Record with Roll No %d not found...",no);
        getch();
        system("cls");
    }
}

void SaveToFile(STUD s[MAX])
{
    FILE *fptr;
    fptr = fopen("recs.bin","wb");
    for(int i=0;i<num;i++)
    {
        fwrite(&s[i],sizeof(s[i]),1,fptr);
    }
    fclose(fptr);
    printf("   Records added Successfully...");
    getch();
    system("cls");
}

void RetriveData(STUD s[MAX])
{
    int line=0;
    FILE *fptr;

    fptr = fopen("recs.bin", "rb");
    if (fptr == NULL)
    {
        printf("   Could not open file");
        return;
    }
    while(getc(fptr) != EOF)
    {
        fseek(fptr,-1,SEEK_CUR);
        fread(&s[line],sizeof(s[line]),1,fptr);
        line++;
    }
    fclose(fptr);
    num=line;
}
