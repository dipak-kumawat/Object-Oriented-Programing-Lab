/*
=========================================================================================
Assignment : INHERITANCE USING VIRTUAL FUNCTION
Name : Dipak Kumawat
class : FYMCA
Batch : B
Roll No : 39

Problem Statement :
Create a base class shape with two double type values and member functions to
input the data and compute_area() for calculating area of figure.
Derive two classes’ triangle and rectangle. Make compute_area() as a virtual
function and redefine this function in the derived class to suit their requirements.
Write a program that accepts dimensions of triangle/rectangle and display
calculated area.
==========================================================================================
*/

#include<iostream>
using namespace std;

class Shape{
	double side1;
	double side2;
	double area;
	
        public:
        void setData();
        double getSide1();
        double getSide2();
        void setArea(double);
        double getArea();
        virtual void compute_area() = 0;
};

void Shape :: setData(){
	cin>>side1>>side2;
}

double Shape :: getSide1(){
	return side1;
}

double Shape :: getSide2(){
	return side2;
}

void Shape :: setArea(double a){
	area = a;
}

double Shape :: getArea(){
	return area;
}

class Triangle : public Shape{
	public:
	virtual void compute_area();
};

void Triangle :: compute_area(){
	cout<<"\nEnter base and height of Triangle :";
	setData();
	double area = 0.5 * getSide1() * getSide2();
	setArea(area);
	cout<<"\nThe Area of the Rectangle : "<<getArea();
}

class Rectangle : public Shape{
	public:
	virtual void compute_area(){
		cout<<"\nEnter length and breath of Rectangle :";
		setData();
		double area = getSide1() * getSide2();
		setArea(area);
		cout<<"\nThe Area of the Rectangle : "<<getArea();
	}
};

int main(){
   Shape *oShape;
   Triangle t;
   Rectangle r;
   
   oShape = &t;
   oShape->compute_area();
   
   oShape = &r;
   oShape->compute_area();
   
   return 0;  
}

/*

Enter base and height of Triangle :3 4     

The Area of the Rectangle : 6
Enter length and breath of Rectangle :3 4 

The Area of the Rectangle : 12

*/
