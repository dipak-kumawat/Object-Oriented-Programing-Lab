/*
=========================================================================================
Assignment : FILE OPERATIONS C++
Name : Dipak Kumawat
class : FYMCA
Batch : B
Roll No : 39

Problem Statement :
Design a base class consisting of the data members such as name of the student,
roll number and subject. The derived class consists of the data member’s subject
code, internal assessment and university examination marks. Construct a virtual
base class for the item name of the student and roll number. The program should
have the facilities. 

1) Build a master table 
2) List a table 
3) Insert a new entry 
4) Delete old entry 
5) Edit an entry 
6) Search for a record

==========================================================================================
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void create(string fname)
{
     cout<<"Inside create";
	ofstream wr;
	wr.open(fname);
	string s;
	cout<<"\nENTER THE CONTENT, TO STOP PRESS #\n";
	while(s!="#")
	{
		getline(cin,s);
		wr<<s;
		wr<<"\n";
	}
	wr.close();
}
void display(string fname)
{
	cout<<"Inside Display";
	ifstream fin;
	fin.open(fname);
	cout<<"\nReading from file\n";
	cout<<"Contents of file are:\n";
	string s;
	while(getline(fin,s))
	{
		cout<<s<<"\n";
	}
	fin.close();
}
int main()
{
	string f;
	cout<<"ENTER THE FILENAME OF THE FILE TO BE WRITTEN INTO (with .txt extension)\n";
	cin>>f;
	create(f);
	display(f);
	return 0;
}
