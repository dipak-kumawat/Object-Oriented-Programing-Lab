/*
=======================================================================
Assignment : EXCEPTION HANDLING
Name : Dipak Kumawat
class : FYMCA
Batch : B

Problem Statement :
	Write a program in C++ which includes the code for following operations :
		i. A function to read two double type numbers from keyboard
		ii. A function to calculate the division of these two numbers
		iii. A try block to detect and throw an exception if the condition “divide-by-zero” occurs
		iv. Appropriate catch block to handle the exceptions thrown
=======================================================================
*/


# include <iostream>
using namespace std;

class Div{
	double divident, divisor;
	
	public:
	void getdata(){
		cout << "Enter the divident: ";
		cin >> divident;
		cout << "Enter the divisor: ";
		cin >> divisor;
	}
	
	void disData(){
		cout << "Divident: " << divident << endl;
		cout << "Divisor: " << divisor << endl;
	}
	
	double cal(){
		if(divisor==0)
			throw divisor;
		else 
			return (divident/divisor);
	}
};


int main(){
	Div D;
	double d;
	
	D.getdata();
	D.disData();
	try{
		d = D.cal();
		cout << "Result : " << d;
	} catch(double e){
		cout << "Divisor Should Not be Zero!" << endl;
	}
}

/*

Enter the divident: 3
Enter the divisor: 4
Divident: 3
Divisor: 4
Result : 0.75

Enter the divident: 3
Enter the divisor: 0
Divident: 3
Divisor: 0
Divisor Should Not be Zero!

*/
