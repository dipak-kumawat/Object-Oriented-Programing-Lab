/*
=========================================================================================
Assignment : OPERATOR OVERLOADING (Extra Assignment)
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement :
	Write a C++ program to perform String operations using Operator Overloading
	a) "=" String Equality Check
	b) "<=" String Copy
	c) "<<" Display String ( Using Friend Function )
	d) "*" String concatenation (e.g. S1="PICT", S2="SCTR", S3=S1*S2 i.e. s3="PICTSCTR").

==========================================================================================
*/

#include<iostream>
#include<cstring>
using namespace std;

class String{
  char *arr;
  
  public:
  String();
  String(char *arr2);
  String getArr();
  int operator=(String b);        
  void operator<=(String b);
  friend ostream& operator<<(ostream &myout, String& b);
  void operator*(String b);
};

String String :: getArr(){
  return (arr);
}

String :: String(){
}

String :: String(char arr2[]){
   arr = arr2;
}

int String :: operator=(String b){       //return 0 if Equal else something else
   return strcmp(arr,b.arr);
}

void String :: operator<=(String b){
   strcpy(arr, b.arr);
}

void String :: operator*(String b){
   strcat(arr, b.arr);
}

ostream& operator<<(ostream &myout, String &b){
  myout<<(b.arr);
  return myout;
}

void printMenu(){
   cout<<"\n\n<--------Operations Menu---------->";
   cout<<"\n1) String Equality";
   cout<<"\n2) Copying String 1 into String 2";
   cout<<"\n3) String concatenation s1, s2 in s1";
   cout<<"\n4) Exit";
}

void printBoth(String s1, String s2){
  cout<<"\nString 1: "<<s1;
  cout<<"\nString 2: "<<s2;
}

int main(){
  char *ptr1 = new char[50];
  cout<<"\nEnter the String One:";
  cin>>ptr1;

  char *ptr2 = new char[50];
  cout<<"\nEnter the String Two:";
  cin>>ptr2;

  int exit = 0;
  int ch;

  String s1(ptr1);
  String s2(ptr2);
  String s3;
  


  do{
    printMenu();
    cout<<"\nEnter Choices:";
    cin>>ch;
    
    switch(ch){
      case 1: cout<<"\nString Equality:";
              cout<<(((s1 = s2) == 0 )? "They Are equal":"They are not equal");
              break;

      case 2: cout<<"\nCopying String 1 into String 2!";
              s2<=s1;
              printBoth(s1, s2);
              break;
    
      case 3: cout<<"\nconcatenating string s1, s2 in s1";
              s1*s2;
              printBoth(s1, s2);
              break;
 
      case 4: exit = 1; 
              break;
              
    }
  }while(exit==0);
  
  return 0;
} 


/*

Enter the String One:PICT           

Enter the String Two:STCR


<--------Operations Menu---------->
1) String Equality
2) Copying String 1 into String 2
3) String concatenation s1, s2 in s1
4) Exit
Enter Choices:1

String Equality:They are not equal

<--------Operations Menu---------->
1) String Equality
2) Copying String 1 into String 2
3) String concatenation s1, s2 in s1
4) Exit
Enter Choices:2

Copying String 1 into String 2!
String 1: PICT
String 2: PICT

<--------Operations Menu---------->
1) String Equality
2) Copying String 1 into String 2
3) String concatenation s1, s2 in s1
4) Exit
Enter Choices:3

concatenating string s1, s2 in s1
String 1: PICTPICT
String 2: PICT

<--------Operations Menu---------->
1) String Equality
2) Copying String 1 into String 2
3) String concatenation s1, s2 in s1
4) Exit
Enter Choices:4

*/

