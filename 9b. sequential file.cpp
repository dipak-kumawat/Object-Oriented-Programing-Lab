/*
=========================================================================================
Assignment : SEQUNTIAL FILE OPERATIONS IN C++
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement :
	Write a program in C++ to implement sequential file for students' database and perform following operations on it
	1) Create
	2) Display
	3) Add
	4) Delete
	5) Modify
==========================================================================================
*/

#include<iostream>
#include<fstream>
using namespace std;
class student
{
	char name[30];
	int roll;
	int age;
	float per;
public:
	student()
	{
		roll=0;
		age=0;
		per=0.0;
	}
	void create(int);
	void display();
	void insert(int);
	int Delete();
	int modify();
};

void student::create(int n)
{
	student temp;
	ofstream fout;
	fout.open("Database.txt");
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Age\n";
		cin>>temp.age;
		cout<<"Enter Percentage\n";
		cin>>temp.per;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}

void student::display()
{
	student temp;
	ifstream fin;
	fin.open("Database.txt");
	cout<<"Roll No\tName\tAge\tPercentage\n";
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		cout<<temp.roll<<"\t"<<temp.name<<"\t"<<temp.age<<"\t"<<temp.per<<"\n";
	}
	fin.close();
}

void student::insert(int n)
{
	student temp;
	ofstream fout;
	fout.open("Database.txt",ios::app);
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Age\n";
		cin>>temp.age;
		cout<<"Enter Percentage\n";
		cin>>temp.per;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}
int student::Delete()
{
	ifstream fin;
	ofstream fout;
	int roll,flag=0;
	cout<<"\nEnter Roll No to delete\n";
	cin>>roll;
	student temp;
	fin.open("Database.txt");
	fout.open("Database1.txt");
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		if(roll==temp.roll)
		{
			flag=1;
			continue;
		}
		else
		{
			fout.write((char*)&temp,sizeof(temp));
		}
	}
	fin.close();
	remove("Database.txt");
	rename("Database1.txt","Database.txt");
	fout.close();
	return flag;
}

int student::modify()
{
	ifstream fin;
	ofstream fout;
	int roll,x,flag=0;
	cout<<"\nEnter Roll No to modify\n";
	cin>>roll;
	student temp;
	fin.open("Database.txt");
	fout.open("Database1.txt");
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		if(roll==temp.roll)
		{	
			flag=1;
			do
			{
				cout<<"\nModify\n1.Name\n2.Age\n3.Percentage\n4.End\n";
				cin>>x;
				switch(x)
				{
					case 1:
					cout<<"\nEnter new Name\n";
					cin>>temp.name;
					break;
					case 2:
					cout<<"\nEnter new Age\n";
					cin>>temp.age;
					break;
					case 3:
					cout<<"\nEnter new Percentage\n";
					cin>>temp.per;
					break;
					case 4:
					break;
					default:
					cout<<"\nWrong value entered\n";
				}
			}while(x!=4);
			fout.write((char*)&temp,sizeof(temp));
		}
		else
		{
			fout.write((char*)&temp,sizeof(temp));
		}
	}
	fin.close();
	remove("Database.txt");
	rename("Database1.txt","Database.txt");
	fout.close();
	return flag;
}

int main()
{
	int n,ch,x,z=0;
	student obj;
	cout<<"\nEnter how many records you want to enter\n";
	cin>>n;
	do
	{
		cout<<"\nEnter\n1.Create\n2.Display\n3.Add\n4.Delete\n5.Modify\n6.End\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			obj.create(n);
			break;
			case 2:
			obj.display();
			break;
			case 3:
			cout<<"\nEnter how many records you want to Add\n";
			cin>>x;
			obj.insert(x);
			break;
			case 4:
			z=obj.Delete();
			if(z)
				cout<<"\nData has been deleted\n";
			else
				cout<<"\nRoll No not found\n";
			break;
			case 5:
			z=0;
			z=obj.modify();
			if(z)
				cout<<"\nData has been modified\n";
			else
				cout<<"\nRoll No not found\n";
			break;
			case 6:
			break;
			default:
			cout<<"\nWrong value entered\n";


		}
	}while(ch!=6);
	return 0;
}
