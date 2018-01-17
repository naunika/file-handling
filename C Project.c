#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *ptr,*tmp ;

struct student
{
    char name[30];
    int rno ;
    int cpi ;
};

void Enter_data()
{
    int n ,i;
    struct student *stu ;
    printf("\n Enter the number of students: ");
    scanf("%d",&n);
    stu=(struct student *)malloc(sizeof(struct student)*n);

    for(i=0;i<n;i++)
        {
            printf("\n Enter the Name of the Student %d : ",i+1);
            fflush(stdin);
            gets(stu[i].name);
            printf("Enter the Roll Number of the Student %d : ",i+1);
            scanf("%d",&stu[i].rno);
            printf("Enter the CPI of the Student %d : ",i+1);
            scanf("%d",&stu[i].cpi);
        }

    ptr=fopen("Student Structure.txt","ab");

for(i=0;i<n;i++)
    fwrite(&stu[i],sizeof(struct student),1,ptr);
fclose(ptr);
}

void sort_name()
{
    int size ,i,j;
    struct student *stu, temp;
    ptr=fopen("Student Structure.txt","rb");
    fseek(ptr,0,SEEK_END);
    size=ftell(ptr);
    stu=(struct student *)malloc(size);
    rewind(ptr);

    for(i=0;i<size/sizeof(struct student);i++)
        fread(&stu[i],sizeof(struct student),1,ptr);

    for(i=0;i<(size/sizeof(struct student)-1);i++)
      {
          for(j=i+1;j<size/sizeof(struct student);j++)
          {
              if(strcmp(stu[i].name,stu[j].name)>0)
              {
                  temp=stu[i];
                  stu[i]=stu[j];
                  stu[j]=temp ;
              }
          }
      }
    tmp=fopen("Name Sorted.txt","w");
    fprintf(tmp,"R.NO. \t\t NAME\t\t CPI \n");
    for(i=0;i<size/sizeof(struct student);i++)
        fprintf(tmp,"%d \t\t %s \t\t %d \n",stu[i].rno,stu[i].name,stu[i].cpi);

    fclose(tmp);
}

void sort_roll()
{
    int size ,i,j;
    struct student *stu,temp;
    ptr=fopen("Student Structure.txt","rb");
    fseek(ptr,0,SEEK_END);
    size=ftell(ptr);
    stu=(struct student *)malloc(size);
    rewind(ptr);
    for(i=0;i<size/sizeof(struct student);i++)
        fread(&stu[i],sizeof(struct student),1,ptr);

      for(i=0;i<(size/sizeof(struct student)-1);i++)
      {
          for(j=i+1;j<size/sizeof(struct student);j++)
          {
              if(stu[i].rno>stu[j].rno)
              {
                  temp=stu[i];
                  stu[i]=stu[j];
                  stu[j]=temp ;
              }
          }
      }
        tmp=fopen("Roll Number Sorted.txt","w");
        fprintf(tmp,"R.NO. \t\t NAME\t\t CPI \n");
        for(i=0;i<size/sizeof(struct student);i++)
            fprintf(tmp,"%d \t\t %s \t\t %d \n",stu[i].rno,stu[i].name,stu[i].cpi);

    fclose(tmp);
}

void sort_marks()
{
    int size ,i,j;
    struct student *stu,temp;
    ptr=fopen("Student Structure.txt","rb");
    fseek(ptr,0,SEEK_END);

    size=ftell(ptr);
    stu=(struct student *)malloc(size);
    rewind(ptr);
    for(i=0;i<size/sizeof(struct student);i++)
        fread(&stu[i],sizeof(struct student),1,tmp);

    for(i=0;i<(size/sizeof(struct student)-1);i++)
    {
        for(j=i+1;j<size/sizeof(struct student);j++)
        {
            if(stu[i].cpi>stu[j].cpi)
            {
            temp=stu[i];
            stu[i]=stu[j];
            stu[j]=temp;
            }
        }
    }

    tmp=fopen("CPI Sorted.txt","w");
    fprintf(tmp,"R.NO. \t\t NAME\t\t CPI \n");
    for(i=0;i<size/sizeof(struct student);i++)
        fprintf(tmp,"%d \t\t %s \t\t %d \n",stu[i].rno,stu[i].name,stu[i].cpi);

    fclose(tmp);
}

void print_records(int d)
{
    char ch;
    if(d==1)
    {
    ptr=fopen("Roll Number Sorted.txt","r");
         if(ptr==NULL)
        {
            printf("File does not Exist");
            return ;
        }
        else
            sort_name();
    }

    else if(d==2)
    {
        ptr=fopen("Roll Number Sorted.txt","r");
         if(ptr==NULL)
        {
            printf("File does not Exist");
            return ;
        }
        else
            sort_roll();
    }
    else
    {
        ptr=fopen("CPI Sorted.txt","r");
         if(ptr==NULL)
        {
            printf("File does not Exist");
            return ;
        }
        else
            sort_marks();
    }
    while((ch=fgetc(ptr))!=EOF)
        printf("%c",ch);

    fclose(ptr);
}

int main()
{
    int choice ,d;
    char sel;

    system("cls");
    printf("\n MAIN MENU");
    printf("\n 1. Add a New Record");
    printf("\n 2. Sort the records according to Name, Roll number and Marks");
    printf("\n 3. Print the Records");
    printf("\n 4. Exit");
    printf("\n Enter Your Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: Enter_data();
                break ;

        case 2: sort_name();
                sort_roll();
                sort_marks();
                printf("\n Sorting Successful!!!");
                break;

        case 3: printf("\n Print according to");
                printf("\n 1. Name");
                printf("\n 2. Roll Number");
                printf("\n 3. Marks");
                printf("\n Enter your choice: ");
                scanf("%d",&d);
                print_records(d);
                break;

        case 4 : exit(0);
                 break;
        default : printf("\n Wrong Option Entered. Please Try again!");
                  break;
        }

    return 0;
}
