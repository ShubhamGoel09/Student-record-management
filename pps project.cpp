#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
struct student
{
	int roll;
	char name[30];
	char branch[30];
	int year;
	char phone[15];
	char father[30];
}record[30]={1,"AdityaSingh","CS",1,"9988998899","SherSingh",
2,"kush","IT",1,"9900220099","Alok",
3,"pushkar","CS",2,"9911991155","Mohan",
4,"Rahul","ECE",4,"9912345757","Naresh",
5,"tushar","IT",3,"9676762354","Jetu",
6,"Sagar","Civil",3,"7011422503","Vijay"};
int add()
{
	int a,i=0;
	char con='y';
	while(con=='y')
	{
		while(record[i].roll!=0)
		{
			i+=1;
		}
		printf("Enter the record you want to add\n");
		printf("Enter the roll no. ==> ");
		scanf("%d",&record[i].roll);
		printf("Enter the name ==> ");
		scanf("%s",&record[i].name);
		printf("Enter the branch ==> ");
		scanf("%s",&record[i].branch);
		printf("Enter the year ==> ");
		scanf("%d",&record[i].year);
		printf("Enter the phone number ==> ");
		scanf("%s",&record[i].phone);
		printf("Enter the father's name ==> ");
		scanf("%s",&record[i].father);
		printf("\nYour data is successfull saved press any key to continue.....");
		_getch();
		system("cls");
		printf("Press Y if you want to add  another record else N\n");
		scanf("%s",&con);
		system("cls");
	}
	
	return 0;
}
int view()
{
	int i;
	printf("The record :-\n");
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<30;i++)
	{
		if(record[i].roll!=0)
		{
			printf("|%-3d |%-12s |%-12s |%-3d |%-12s |%-12s |\n",record[i].roll,record[i].name,record[i].branch,record[i].year,record[i].phone,record[i].father);
			printf("-------------------------------------------------------------------\n");
		}
	}
	printf("\nPress any key to continue.....");
	getch();
	system("cls");
	return 0;
}
int search()
{
	int n,i,b=0;
	char con='y';
	while(con=='y')
	{
		printf("Enter the Roll No. ==>");
		scanf("%d",&n);
		for(i=0;i<30;i++)
		{
			if(n==record[i].roll)
			{
				printf("-------------------------------------------------------------------\n");
				printf("|%-3d |%-12s |%-12s |%-3d |%-12s |%-12s |\n",record[i].roll,record[i].name,record[i].branch,record[i].year,record[i].phone,record[i].father);
				b=b+1;					
			}
		}
		if(b==0)
			printf("No record found\n");
		else
			printf("-------------------------------------------------------------------\n");
		printf("\nYour data is successfull saved press any key to continue.....");
			_getch();
			system("cls");
			printf("Press Y if you want to add  another record else N\n");
			scanf("%s",&con);
			system("cls");
	}
}
int modify()
{
	int num,i,choice;
	char a='y';
	while(a=='y')
	{
	
		printf("Enter the Roll No. of the student whose data you want to change\n");
		scanf("%d",&num);
		for(i=0;i<30;i++)
		{
			if(record[i].roll==num)
			{
				break;
			}	
		}
		if(i==30)
		{
			printf("No record found\n");
		}
		else
		{
			
			printf("Enter the number which you want to change\n1. Roll No.\n2. Name\n3. Branch\n4. Year\n5. Phone Number\n6. Father's Name\n");
			scanf("%d",&choice);
		
			switch(choice)
			{
				case 1:
					printf("Enter the new roll number ==> ");
					scanf("%d",&record[i].roll);
					break;
				case 2:
					printf("Enter the new name ==> ");
					scanf("%s",&record[i].name);
					break;
				case 3:
					printf("Enter the new branch ==> ");
					scanf("%s",&record[i].branch);
					break;
				case 4:
					printf("Enter the new year ==> ");
					scanf("%d",&record[i].year);
					break;
				case 5:
					printf("Enter the new phone number ==> ");
					scanf("%d",&record[i].phone);
					break;
				case 6:
					printf("Enter the new father's name ==> ");
					scanf("%s",&record[i].father);
					break;
			}
			printf("\nYour data is successfull saved press any key to continue.....");
			_getch();
			system("cls");
			printf("You want to add modify another record press 'y' else 'N' for main menu\n");
			scanf("%s",&a);
			system("cls");
		}
	}
}
int del()
{
	int num,i;
	char choice='y';
	while(choice=='y')
	{	
		printf("Enter the Roll No. of the student whose data you want to delete\n");
		scanf("%d",&num);
		for(i=0;i<30;i++)
		{
			if(record[i].roll==num)
			{
				break;
			}	
		}
		if(i==30)
		{
			printf("No record found\n");
		}
		record[i].roll=0;
		record[i].name[30]=0;
		record[i].branch[30]='0';
		record[i].year=0;
		record[i].phone[15]=0;
		record[i].father[30]='0';
		printf("\nYour data is successfull saved press any key to continue.....");
		_getch();
		system("cls");
		printf("Press Y if you want to delete another record else N\n");
		scanf("%s",&choice);
		system("cls");
	}
}
int main()
{
	FILE *fp;
	fp=fopen("pps project extra file.cpp","w");
	int choice,i;
	char cont='y';
	printf("__STUDENT RECORD SYSTEM_\n\n\n");
	while(cont=='y')
	{
		printf("Enter number you want to choose\n1. Add records\n2. View records\n3. Search\n4. Modify\n5. Delete\n6. Exit\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				system("cls");
				add();
				break;
			case 2:
				system("cls");
				view();
				break;
			case 3:
				system("cls");
				search();
				break;
			case 4:
				system("cls");
				modify();
				break;
			case 5:
				system("cls");
				del();
				break;
			case 6:
				system("cls");
				fputs("The record :-\n",fp);
				fputs("-------------------------------------------------------------------\n",fp);
				for(i=0;i<30;i++)
				{
					if(record[i].roll!=0)
					{
						fprintf(fp,"|%-3d |%-12s |%-12s |%-3d |%-12s |%-12s |\n",record[i].roll,record[i].name,record[i].branch,record[i].year,record[i].phone,record[i].father);
						fputs("-------------------------------------------------------------------\n",fp);
					}
				}
				exit(1);
				break;
		}
	}
}
