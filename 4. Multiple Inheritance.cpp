#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

#define max 50
#define ll line(143);

void line(int n)
{
	for(int i=0;i<n;i++)
		cout<<"-";
}

class Base1
{
	protected:	char name[50],bgrp[5];
				int d,m,y;

	public	:	void getData1();
};

void Base1::getData1()
{
	cin.ignore();
	cout<<"\nName : ";
	cin.getline(name,50);
	cout<<"Blood Group : ";
	cin>>bgrp;
	cout<<"Date Of Birth :\n";
	do
	{
		cout<<"   Date  : ";
		cin>>d;
		if(d<1||d>31)
			cout<<"\nEnter CORRECT date..!!\n";
	}while(d<1||d>31);
	do
	{
		cout<<"   Month : ";
		cin>>m;
		if(m<1||m>12)
			cout<<"\nEnter CORRECT month..!!\n";
	}while(m<1||m>12);
	do
	{
		cout<<"   Year  : ";
		cin>>y;
		if(y<1900||y>2019)
			cout<<"\nEnter CORRECT year..!!\n";
	}while(y<1900||y>2019);
}

class Base2
{
	protected:	int height,weight;

	public	:	void getData2();
};

void Base2::getData2()
{
	cout<<"Height : ";
	cin>>height;
	cout<<"Weight : ";
	cin>>weight;
}

class Base3
{
	protected:	long int polno;
				char add[50];

	public	:	void getData3();
};

void Base3::getData3()
{
	cin.ignore();
	cout<<"Address : ";
	cin.getline(add,50);
	cout<<"Insurance Policy No : ";
	cin>>polno;
}


class Derived:public Base1,public Base2,public Base3
{
	protected:	long long int teleno,dlno;

	public	:	void getData4();
				void display(int i);
				void searchData(Derived D[max],char sch[50],int n);
				void modify(int n);
				int deleteData(Derived D[max],int d,int n);
};

void Derived::getData4()
{
	getData1();
	getData2();
	getData3();
	cout<<"Telephone No : ";
	cin>>teleno;
	cout<<"Driving License No : ";
	cin>>dlno;
}

void Derived::display(int i)
{
	cout<<setw(7)<<std::left<<i+1;
	cout<<setw(20)<<name;
	cout<<setw(15)<<bgrp;
	cout<<setw(2)<<d<<"-"<<setw(2)<<m<<"-"<<setw(5)<<y;
	cout<<setw(8)<<height;
	cout<<setw(8)<<weight;
	cout<<setw(12)<<add;
	cout<<setw(17)<<polno;
	cout<<setw(18)<<teleno;
	cout<<setw(15)<<dlno<<endl;
}

void tabHead()
{
	cout<<setw(7)<<std::left<<"Sr.No.";
	cout<<setw(20)<<"Name";
	cout<<setw(15)<<"Blood Group";
	cout<<setw(12)<<"D.O.B.";
	cout<<setw(8)<<"Height";
	cout<<setw(8)<<"Weight";
	cout<<setw(12)<<"Address";
	cout<<setw(17)<<"Ins. Policy No.";
	cout<<setw(18)<<"Telephone No.";
	cout<<setw(15)<<"DL No."<<endl;
}

void Derived::searchData(Derived D[max],char sch[50],int n){
	int f=1;
	ll
	cout<<endl;
	tabHead();
	cout<<endl;
	ll
	for(int i=0;i<n;i++)
	{
		if(!strcmp(sch,D[i].name))
		{	D[i].display(i);
			f=0;
		}	
	}
	cout<<endl;
	ll
	cout<<endl;
	if(f)
		cout<<"\nData NOT Found..!!\n";
}

void Derived::modify(int n)
{
	int ch;
	do
	{
		cout<<"\n<-------------MODIFY MENU ------------->";
		cout<<"\n   What do u want to modify..??\n    1) Name\n    2) Blood Group\n    3) Date of Birth\n    4) Height\n    5) Weight\n    6) Address\n    7) Insurance Policy Number\n    8) Telephone Number\n    9) Driving License Number\n   10) Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cin.ignore();
					cout<<"\nName : ";
					cin.getline(name,50);	
					break;
					
			case 2:	cout<<"Blood Group : ";
					cin>>bgrp;
					break;
					
			case 3:	cout<<"Date Of Birth :\n   Date  : ";
					cin>>d;
					cout<<"   Month : ";
					cin>>m;
					cout<<"   Year  : ";
					cin>>y;
					break;
					
			case 4:	cout<<"Height : ";
					cin>>height;
					break;
					
			case 5:	cout<<"Weight : ";
					cin>>weight;
					break;
					
			case 6:	cin.ignore();
					cout<<"Address : ";
					cin.getline(add,50);
					break;
					
			case 7:	cout<<"Insurance Policy No : ";
					cin>>polno;
					break;
					
			case 8:	cout<<"Telephone No : ";
					cin>>teleno;
					break;
					
			case 9:	cout<<"Driving License No : ";
					cin>>dlno;
					break;
					
			case 10:break;
			
			default:cout<<"\nEnter VALID Choice..!!\n";
		}
	}while(ch!=10);
	
	cout<<"\nData Modified Successfully..!!\n";
}

int Derived::deleteData(Derived D[max],int d,int n)
{
	int i;
	for(i=d-1;i<n-1;i++)
	{
		D[i]=D[i+1];
	}
	n--;
	cout<<"\nData Deleted Successfully..!!\n";
	return n;
}

int main()
{
	Derived D[max];
	int i,n=0,ch,md;
	char sch[50];

	do
	{
		cout<<"\nMenu :\n1. Build Master Table\n2. Display Records\n3. Insert Record\n4. Search Record\n5. Edit Record\n6. Delete Record\n7. Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	do
					{
						cout<<"\nEnter No. of Records : ";
						cin>>n;
						if(n<0)
							cout<<"\nEnter VALID Nunber..!!\n";
						if(n>max)
							cout<<"\nMaximum number of records is "<<max<<" ONLY..!!\n";	
					}while(n>max || n<0);
					for(i=0;i<n;i++)
						D[i].getData4();
					break;

			case 2:	if(!n)
						cout<<"\nData Base EMPTY..!!\n";
					else
					{
						ll
						cout<<endl;
						tabHead();
						cout<<endl;
						ll
						for(i=0;i<n;i++)
							D[i].display(i);
						cout<<endl;
						ll
						cout<<endl;
					}
					break;

			case 3:	D[n].getData4();
					n++;
					break;

			case 4:	cin.ignore();
					if(!n)
						cout<<"\nData Base EMPTY..!!\n";
					else
					{
						cout<<"\nEnter Name to Search : ";
						cin.getline(sch,50);
						cout<<"\nSEARCH RESULT :\n";
						D[0].searchData(D,sch,n);
					}
					break;

			case 5:	cin.ignore();
					if(!n)
						cout<<"\nData Base EMPTY..!!\n";
					else
					{
						cout<<"\nEnter Name to Search : ";
						cin.getline(sch,50);
						cout<<"\nSEARCH RESULT :\n";
						D[0].searchData(D,sch,n);
						cout<<"\nEnter Sr.No. of Data to Modify : ";
						cin>>md;
						D[md-1].modify(n);
					}
					break;

			case 6:	cin.ignore();
					if(!n)
						cout<<"\nData Base EMPTY..!!\n";
					else
					{
						cout<<"\nEnter Name to Search : ";
						cin.getline(sch,50);
						cout<<"\nSEARCH RESULT :\n";
						D[0].searchData(D,sch,n);
						cout<<"\nEnter Sr.No. of Data to Delete : ";
						cin>>md;
						n=D[0].deleteData(D,md,n);
					}
					break;

			case 7:	break;

			default:cout<<"\nEnter VALID Choice..!!\n";
		}
	}while(ch!=7);
	return 0;
}
