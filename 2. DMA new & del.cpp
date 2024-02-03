/*
=========================================================================================
Assignment : DYNAMIC MEMORY ALLOCATION USING NEW AND DELETE OPERATOR
Name : Dipak Kumawat
class : FYMCA
Batch : B

Problem Statement : 
	A Book shop maintains the inventory of books that are being sold at the shop. The list includes details such as title, author, publisher, price and available stock. Write a program in C++ which will have a class called books with suitable member
	i)   Add
	ii)  Update
	iii) Search a book
	iv)  Purchase a book
	     (update the stock and display the total cost)
	v)   Record number of successful/unsuccessful transactions
	     (use static data members to keep count of transactions)
==========================================================================================
*/

#include<iostream>
#include<iomanip>
#include <string.h>

using namespace std;

#define MAX 50

class Book{
  char *title;
  char *author;
  char *publish;
  int *ava_stoke;
  float *prize;
  int *bookNo;
  static int st, ut;

  public :

  Book();
  void addBook();
  void purchaseBook();
  void updateBook();
  void displayBook();
  void trans();
  void utp();
  // ~Book();

  friend class Library;

};


class Library{

   Book books[MAX];

   public:
   int search(int n);
   void displayArr(int n);
   Book get(int index);
};

void displayMenu(){                                            //DONE
  cout<<"<<---------In Collection------------>>\n";
  cout<<" 1.  Add book \n";
  cout<<" 2.  Update Book \n";
  cout<<" 3.  search Book \n";
  cout<<" 4.  purchase Book \n";
  cout<<" 5.  Display Collection \n";
  cout<<" 6.  Display Menu \n";
  cout<<" 7.  Transaction details \n";
  cout<<" 8.  Exit \n";
}

Book :: Book(){                  //DONE
    title = new char[20];
    author = new char[20];
    publish = new char[20];
    prize = new float;
    ava_stoke = new int;
    bookNo = new int;
}

void Book :: utp(){
  ut++;
}

void Book :: trans(){             //DONE
  cout<<"\nSuccessfull transcations : "<<st;
  cout<<"\nUnsuccessfull transcations : "<<ut;
}

int Book :: st;
int Book :: ut;
int i = 0;

void Book :: purchaseBook(){               //DONE
  (*ava_stoke)--;
  cout<<"\nBook Purchased!";
  cout<<*ava_stoke;
  st++;
}

void Book::addBook(){                              //DONE
  cout<<"\nEnter Title of the Book:";
  cin>>title;
  cout<<"\nEnter Author of the Book:";
  cin>>author;
  cout<<"\nEnter publisher of the Book:";
  cin>>publish;
  cout<<"\nEnter Prize of the Book:";
  cin>>*prize;
  cout<<"\nEnter available stock of the Book:";
  cin>>*ava_stoke;
  cout<<"\nEnter book Number fo the Book:";
  cin>>*bookNo;
}

void Book :: displayBook(){
  cout<<"\n"<<title<<setw(10)<<(author)<<setw(10)<<(publish)<<setw(10)<<(*ava_stoke)<<setw(10)<<(*prize)<<setw(10)<<(*bookNo)<<"\n";  //DONE
}

void Book :: updateBook(){                     //DONE
   cout<<"\nWhich field you want to Update:\n1) Title\n2) Author\n3) Publisher\n4) Prize\n";
   int ch = 0;
   cout<<"\nEnter the Choice..";
   cin>>ch;
   switch(ch){
     case 1: cout<<"\nEnter Title:";
             cin>>title; 
             break;
     case 2: cout<<"\nEnter Author:";
             cin>>author;
             break;
     case 3: cout<<"\nEnter Publisher:";
             cin>>publish;
             break;
     case 4: cout<<"\nEnter Prize:";
             cin>>*prize;
             break;
   }
}


void Library :: displayArr(int n){              //DONE
  cout<<"\n--------------------------------------------------------------------------";
  cout<<"\nTitle"<<setw(10)<<"Author"<<setw(10)<<"Publisher"<<setw(10)<<"Avaiable stock"<<setw(10)<<"Prize"<<setw(10)<<"BookNo";
  cout<<"\n-------------------------------------------------------------------------";
  for(i=0; i<n; i++){
     books[i].displayBook();
  }
  cout<<"\n----------------------------------------------------------------------------";
}

int Library :: search(int n){                  //DONE
  int subChoice, found;
  cout<<"\n1. Search by book name";
  cout<<"\n2. Search by author of book";
  cout<<"\n3. Search by Book Number";
  cout<<"\nEnter Choice:";
  cin>>subChoice;
     switch(subChoice){
        case 1:  char name[MAX];
              cout<<"\nEnter Book Title: ";
              cin>>name;
            for(int i=0;i<n;i++){
              if(strcmp(name,books[i].title)==0){
              cout<<"\nBook Found!";
              cout<<"\n-------------------------------------------------------------------------";
              books[i].displayBook();
              cout<<"\n-------------------------------------------------------------------------";
              return i;
              }
            }
            cout<<"Book Not Found!!"; 
            return -1;
            
        case 2:char auName[MAX];
               cout<<"\nEnter Book Author: ";
               cin>>auName;
             for(int i=0;i<n;i++){
               if(strcmp(auName,books[i].author)==0){
               cout<<"\nBook Found!";
               cout<<"\n-------------------------------------------------------------------------";
               books[i].displayBook();
               cout<<"\n-------------------------------------------------------------------------";
               return i;
             }
            }
            cout<<"Book Not Found!!"; 
            return -1;
            
       case 3:  int BookID;
               cin>>BookID;
              for(int i=0;i<n;i++){
               if(*(books[i].bookNo)==BookID){
                 cout<<"\nBook Found!";
                 cout<<"\n-------------------------------------------------------------------------";
                 books[i].displayBook();
                 cout<<"\n-------------------------------------------------------------------------";
                 return i;
               }
             }
            cout<<"Book Not Found!!"; 
            return -1;
     }
  if(found==0){
    cout<<"\nBook Not Found!";
    return -1;
  }
}

Book Library :: get(int i){            //DONE
   return books[i];
}

int main(){
   int ch;
   int var = 0;           //
   static int num = 0;      //here num is total number of book present
   Library lib;
   int exit = 0;
   displayMenu();
   do{
     cout<<"\nENTER CHOICE(6 for display menu):";
     cin>>ch;
     switch(ch){
       case 1: lib.get(num).addBook();
               num++;
               break;

       case 2: var = lib.search(num);
               lib.get(var).updateBook();
               break;

       case 3: lib.search(num);
               break;

       case 4: var = lib.search(num);
               if(var==-1){
                  cout<<"\nCan't Purchase Book! Unscuccessfull transaction..";
                  lib.get(var).utp();
               }else{
                 lib.get(var).purchaseBook();
               }
               break;

       case 5: lib.displayArr(num);
               break;

       case 6: displayMenu();
               break;

       case 7: lib.get(var).trans();
               break;

       case 8: exit = 1;
               break;

       default: cout<<"Enter valid choice";
                break;
     }
   }while(exit==0);
   return 0;
}


/*

ENTER CHOICE :1

Enter Title of the Book:SuttelArt         

Enter Author of the Book:Chetan

Enter publisher of the Book:xyz

Enter Prize of the Book:123

Enter available stock of the Book:23

Enter book Number fo the Book:67890

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE:5

--------------------------------------------------------------------------
Title    Author PublisherAvaiable stock     Prize    BookNo
-------------------------------------------------------------------------
SuttelArt    Chetan       xyz        23       123     67890

----------------------------------------------------------------------------
<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE:1

Enter Title of the Book:JamesBond

Enter Author of the Book:BondFamily

Enter publisher of the Book:Abc

Enter Prize of the Book:234

Enter available stock of the Book:56

Enter book Number fo the Book:98765

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 


ENTER CHOICE :5

--------------------------------------------------------------------------
Title     Author   Publisher  Avaiable stock     Prize    BookNo
-------------------------------------------------------------------------
SuttelArt     Chetan       xyz                23        123      67890

JamesBond BondFamily       Abc        56       234     98765

----------------------------------------------------------------------------

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
8.  Exit

ENTER CHOICE :1

Enter Title of the Book:Don't     

Enter Author of the Book:Marry

Enter publisher of the Book:DFG

Enter Prize of the Book:345

Enter available stock of the Book:45

Enter book Number fo the Book:54789

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 


ENTER CHOICE :5

--------------------------------------------------------------------------
Title    Author  Publisher  Avaiable stock     Prize    BookNo
-------------------------------------------------------------------------
SuttelArt    Chetan       xyz        23       123     67890

JamesBond BondFamily       Abc        56       234     98765

Don't     Marry       DFG        45       345     54789

----------------------------------------------------------------------------
ENTER CHOICE :6
<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :2

1. Search by book name
2. Search by author of book
3. Search by Book Number
Enter Choice:1

Enter Book Title: SuttelArt

Book Found!
----------------------------------------------------------------------------------------------
SuttelArt    Chetan       xyz        23       123     67890

----------------------------------------------------------------------------------------------
Which field you want to Update:
1) Title
2) Author
3) Publisher
4) Prize

Enter the Choice..1

Enter Title:suddelArt

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 


ENTER CHOICE :5

--------------------------------------------------------------------------
Title    Author PublisherAvaiable stock     Prize    BookNo
-------------------------------------------------------------------------
suddelArt    Chetan       xyz        23       123     67890

JamesBondBondFamily       Abc        56       234     98765

Don't     Marry       DFG        45       345     54789


<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :2

1. Search by book name
2. Search by author of book
3. Search by Book Number
Enter Choice:3

Enter Book Number: 67890

Book Found!
----------------------------------------------------------------------------------------------
SuttelArt    Chetan       xyz        23       123     67890

----------------------------------------------------------------------------------------------
Which field you want to Update:
1) Title
2) Author
3) Publisher
4) Prize

Enter the Choice..1

Enter Title: james

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :3

1. Search by book name
2. Search by author of book
3. Search by Book Number
Enter Choice:1

Enter Book Title: james

Book Found!
----------------------------------------------------------------------------------------------
james    Chetan       xyz        23       123     67890

----------------------------------------------------------------------------------------------

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :3

1. Search by book name
2. Search by author of book
3. Search by Book Number
Enter Choice:3 
Book Number : 67890

Book Found!
----------------------------------------------------------------------------------------------
james    Chetan       xyz        23       123     67890

----------------------------------------------------------------------------------------------

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :5

--------------------------------------------------------------------------
Title    Author PublisherAvaiable stock     Prize    BookNo
-------------------------------------------------------------------------
james    Chetan       xyz        23       123     67890

JamesBondBondFamily       Abc        56       234     98765

Don't     Marry       DFG        45       345     54789

----------------------------------------------------------------------------

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
8.  Exit

ENTER CHOICE :4

1. Search by book name
2. Search by author of book
3. Search by Book Number
Enter Choice:1

Enter Book Title: james

Book Found!

----------------------------------------------------------------------------------------------
james       32s       xyz        23       123     67890

----------------------------------------------------------------------------------------------
Book Purchased!

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
8.  Exit

ENTER CHOICE :7

Successfull transcations : 1
Unsuccessfull transcations : 0

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :5

--------------------------------------------------------------------------
Title    Author PublisherAvaiable stock     Prize    BookNo
-------------------------------------------------------------------------
james       32s       xyz        23       123     67890

JamesBondBondFamily       Abc        56       234     98765

Don't     Marry       DFG        45       345     54789

----------------------------------------------------------------------------
<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :5

--------------------------------------------------------------------------
Title    Author PublisherAvaiable stock     Prize    BookNo
-------------------------------------------------------------------------
james       32s       xyz        23       123     67890

JamesBondBondFamily       Abc        56       234     98765

Don't     Marry       DFG        45       345     54789

----------------------------------------------------------------------------

<<---------In Collection------------>>
 1.  Add book 
 2.  Update Book 
 3.  search Book 
 4.  purchase Book 
 5.  Display Collection 
 6.  Display Menu 
 7.  Transaction details 
 8.  Exit 

ENTER CHOICE :8

*/
