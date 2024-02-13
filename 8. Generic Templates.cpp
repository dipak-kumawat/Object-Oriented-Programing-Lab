/*
=========================================================================================
Assignment : GENERIC PROGRMMING : TEMPLATES
Name : Dipak Kumawat
class : FYMCA
Batch : B
Roll No : 39

Problem Statement :

Write a program in C++ using function/class template to read two matrices of
different data types such as integers and floating point values and perform simple
1arithmetic operations on these matrices separately and display it.and imaginary part. 
Provide default and parameterized constructors. 
Write a program to perform arithmetic operations of two complex numbers using operator overloading.

i. Addition and subtraction using friend functions.
ii. Multiplication and division using member functions.

==========================================================================================
*/

#include<iostream>
using namespace std;

template<class T> class Matrix{
private:
    T mat[50][50];
    int row;
    int col;
public:
    Matrix();
    Matrix(int, int);
    void insert(int, int);
    void display();

    template<class U>
    friend Matrix<U> operator+(Matrix<U>, Matrix<U>);

    template<class U>
    friend Matrix<U> operator*(Matrix<U>, Matrix<U>);
};

template<class T>
Matrix<T> :: Matrix(){
    row = 0;
    col = 0;
}

template<class T>
Matrix<T> :: Matrix(int row, int col){
    this->row = row;
    this->col = col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            mat[i][j] = 0;
        }
    }
}

template<class T>
void Matrix<T> :: insert(int row, int col){
    this->row = row;
    this->col = col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<"Enter Element["<< i <<"]"<<"["<< j <<"] : ";
            cin>>mat[i][j];
        }
    }
}

template<class T>
void Matrix<T> :: display(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

template <class U>
Matrix<U> operator+(Matrix<U> a, Matrix<U> b){
    Matrix<U> c(a.row, a.col);
    if(a.row == b.row && a.col == b.col){
        for(int i=0; i<a.row; i++){
            for(int j=0; j<a.col; j++){
                c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
            }
        }
    } else {
        cout<<"Can't Add\n";
    }
    return c;
}

template <class U>
Matrix<U> operator*(Matrix<U> a, Matrix<U> b){
    Matrix<U> c(a.row, b.col);
    if(a.col==b.row){
        for(int i=0; i<a.row; i++){
            for(int j=0; j<a.col; j++){
                for(int k=0; k<a.col; k++){
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
    } else {
        cout<<"Can't be multiplied with each other\n";
    }
    return c;
}

int main(){
    int r1, r2, c1, c2;
    cout<<"\nEnter no. of rows in first Matrix: ";
    cin>>r1;
    cout<<"\nEnter no. of col in first Matrix: ";
    cin>>c1;

    Matrix<int> a;
    a.insert(r1, c1);
    cout<<"\nMATRIX A :";
    a.display();

    cout<<"\nEnter no. of rows in Sec Matrix: ";
    cin>>r2;
    cout<<"\nEnter no. of col in Sec Matrix: ";
    cin>>c2;

    Matrix<int> b;
    b.insert(r2, c2);
    cout<<"\nMATRIX B :";
    b.display();

    cout<<"\nAddition is: \n";
    Matrix<int> c;
    c = a + b;
    c.display();

    cout<<"Multiplication is: \n";
    c = a * b;
    c.display();

    return 0;
}

/*

Enter number of rows:3
Enter Number of columns:3
Enter Row [0] Column [0] :1
Enter Row [0] Column [1] :2
Enter Row [0] Column [2] :3
Enter Row [1] Column [0] :4
Enter Row [1] Column [1] :5
Enter Row [1] Column [2] :6
Enter Row [2] Column [0] :7
Enter Row [2] Column [1] :8
Enter Row [2] Column [2] :9

Enter number of rows:3
Enter Number of columns:3
Enter Row [0] Column [0] :9
Enter Row [0] Column [1] :8
Enter Row [0] Column [2] :7
Enter Row [1] Column [0] :6
Enter Row [1] Column [1] :5
Enter Row [1] Column [2] :4
Enter Row [2] Column [0] :3
Enter Row [2] Column [1] :2
Enter Row [2] Column [2] :1

10 10 10 
10 10 10 
10 10 10

*/

