/*
=========================================================================================
Assignment : OPERATOR OVERLOADING
Name : Dipak Kumawat
class : FYMCA
Batch : B
Roll No : 39

Problem Statement :
	Write a C++ program to design a class 'Complex' with data members for real and imaginary part. Provide default and parameterized constructors. Write a program to perform arithmetic operations of two complex numbers using operator overloading.
	i. Addition and subtraction using friend functions.
	ii. Multiplication and division using member functions.
==========================================================================================
*/

#include<iostream>
using namespace std;

class Complex{
  
  float real;
  float img;

  public:
  Complex(float, float);
  void print();
  friend Complex operator+(Complex a,Complex b);
  friend Complex operator-(Complex a,Complex b);
  Complex operator*(Complex a);
  Complex operator/(Complex a);
};


Complex :: Complex(float x, float y){
  real = x;
  img = y;
}

void Complex :: print(){
  cout<<"\nReal = "<<real<<"\nImaginary = "<<img<<endl;
}

Complex operator+(Complex a, Complex b){
  Complex c(0,0);
  c.real = a.real + b.real;
  c.img = a.img + b.img; 
  return c;
}

Complex operator-(Complex a, Complex b){
  Complex c(0,0);
  c.real = a.real - b.real;
  c.img = a.img - b.img; 
  return c;
}

Complex Complex :: operator*(Complex a){
  Complex c(0,0);
  c.real = (real * a.real) - (img * a.img);
  c.img = (real * a.img) + (a.real * img); 
  return c;
}


Complex Complex :: operator/(Complex a){
  Complex c(0,0);
  c.real = ((real * a.real) + (img * a.img)) / ((a.real * a.real) + (a.img * a.img));
  c.img =  ((a.real * img)-(real * a.img))/ ((a.real * a.real) + (a.img * a.img)); 
  return c;
}

int main(){
  int m, n;
  cout<<"Enter value of a1 and b1 for first Complex Value:";
  cin>>m>>n;  
  Complex c1(m,n);

  cout<<"Enter value of a1 and b1 for first Complex Value:";
  cin>>m>>n;
  Complex c2(m,n);

  Complex c3(0,0);
 
  cout<<"\nInitial Value of C3:";
  c3.print();
  
  cout<<"\nAfter Addition:";
  c3 = c1 + c2;
  c3.print();
  
  cout<<"\nAfter Subtraction:";
  c3 = c1 - c2;
  c3.print();
  
  cout<<"\nAfter Multiplication:";
  c3 = c1 * c2;
  c3.print();
  
  cout<<"\nAfter Division:";
  c3 = c1 / c2;
  c3.print();
  
  return 0;
}
/*

Enter value of a1 and b1 for first Complex Value:3 4
Enter value of a1 and b1 for first Complex Value:4 5

Initial Value of C3:
Real = 0
Imaginary = 0

After Addition:
Real = 7
Imaginary = 9

After Subtraction:
Real = -1
Imaginary = -1

After Multiplication:
Real = -8
Imaginary = 31

After Division:
Real = 0.780488
Imaginary = 0.0243902

*/


