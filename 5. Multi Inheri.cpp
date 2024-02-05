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

class Personal
{
	protected:	char name[50],bgrp[5];
				int d,m,y;

	public	:	Personal(char n[50], char b[5], int d0, int m0, int y0)
				{
					strcpy(name, n);
					strcpy(bgrp, b);
					d = d0;
					m = m0;
					y = y0;
				}
				void getData1(char a[50],char b[5],int &c,int &d,int &e);
};

void Personal::getData1(char a[50],char b[5],int &c,int &d,int &e)
{
	cin.ignore();
	cout<<"\nName : ";
	cin.getline(a,50);
	cout<<"Blood Group : ";
	cin>>b;
	cout<<"Date Of Birth :\n";
	do
	{
		cout<<"   Date  : ";
		cin>>c;
		if(c<1||c>31)
			cout<<"\nEnter CORRECT date..!!\n";
	}while(c<1||c>31);
	do
	{
		cout<<"   Month : ";
		cin>>d;
		if(d<1||d>12)
			cout<<"\nEnter CORRECT month..!!\n";
	}while(d<1||d>12);
	do
	{
		cout<<"   Year  : ";
		cin>>e;
		if(e<1900||e>2019)
			cout<<"\nEnter CORRECT year..!!\n";
	}while(e<1900||e>2019);
}

class Prof
{
	protected:	int wkexp;
				char lastCompany[50];

	public:		Prof(int wk, char lC[50])
				{
					wkexp = wk;
					strcpy(lastCompany, lC);
				}
				void getData2(int &f,char g[50]);
};

void Prof::getData2(int &f,char g[50])
{
	cout<<"Working Experience : ";
	cin>>f;
	cin.ignore();
	cout<<"Last Working Company : ";
	cin.getline(g,50);
}

class Academic
{
	protected:	char degClg[50];
				float Ptr;

	public:		Academic(char dC[50], float p)
				{
					strcpy(degClg, dC);
					Ptr = p;
				}
				void getData3(char h[50],int &i);
};

void Academic::getData3(char h[50],int &i)
{
	cout<<"Degree College Name : ";
	cin.getline(h,50);
	cout<<"Pointer Percentage : ";
	cin>>i;
}

class Person:public Personal,public Prof,public Academic
{
	public:		Person() : Personal("", "", 0, 0, 0), Prof(0, ""), Academic("", 0.0){}
				Person(char name1[50], char bgrp1[5], int d1, int m1, int y1, int wkexp1, char lastCompany1[50], char degClg1[50], float Ptr1) : Personal(name1, bgrp1, d1, m1, y1), Prof(wkexp1, lastCompany1), Academic(degClg1, Ptr1){}
				void getData(Person [],int);
				void showData(int);
};

void Person::getData(Person P0[max],int n)
{
	char a[50],b[5],g[50],h[50];
	int c,d,e,f,i;
	getData1(a,b,c,d,e);
	getData2(f,g);
	getData3(h,i);
	P0[n] = Person(a,b,c,d,e,f,g,h,i);
}

void Person::showData(int i)
{
	cout<<setw(7)<<std::left<<i+1;
	cout<<setw(20)<<name;
	cout<<setw(15)<<bgrp;
	cout<<setw(2)<<d<<"-"<<setw(2)<<m<<"-"<<setw(6)<<y;
	cout<<setw(9)<<wkexp;
	cout<<setw(20)<<lastCompany;
	cout<<setw(20)<<degClg;
	cout<<setw(9)<<Ptr<<"|"<<endl;
}

void tabHead()
{
	cout<<setw(7)<<std::left<<"Sr.No.";
	cout<<setw(20)<<"Name";
	cout<<setw(15)<<"Blood Group";
	cout<<setw(12)<<"D.O.B.";
	cout<<setw(9)<<"Work Exp.";
	cout<<setw(20)<<"Previous Company";
	cout<<setw(20)<<"Degree Clg Name";
	cout<<setw(9)<<"Pointer"<<endl;
}

int main()
{
	Person P[max];
	int i,n=0,ch;

	do
	{
		cout<<"\n<----------------Menu--------------->";
		cout<<"\n1) Build Master Table\n2) Display Records\n3) Insert Record\n4) Exit\nEnter your choice : ";
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
						P[i].getData(P,i);
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
							P[i].showData(i);
						ll
						cout<<endl;
					}
					break;

			case 3:	P[n].getData(P,n);
					n++;
					break;

			case 4:	break;

			default:cout<<"\nEnter valid choice (1-4 Only)...!!!\n";

		}
	}while(ch!=4);

	return 0;
}
