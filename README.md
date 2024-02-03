# Object-Oriented-Programing-Lab
(In SEM 2) - OOPs Concepts - operator overloading, inheritance, exception handling, templates, files, virtual functions.

# Object-Oriented-Programming-Lab

![](https://img.shields.io/badge/Gaurav-Ghati-red)
![](https://img.shields.io/github/languages/top/dipak-kumawat/Object-Oriented-Programming-Lab)
![](https://img.shields.io/github/last-commit/dipak-kumawat/Object-Oriented-Programming-Lab)

# 1) CONSTRUCTOR AND DESTRUCTOR
	TITLE: WEATHER REPORT
		Create a class named weather report that holds a daily weather report with data
		member’s day_of_month, hightemp, lowtemp, amount_rain and amount_snow. The
		constructor initializes the fields with default values: 99 for day_of_month, 999 for
		hightemp,-999 for lowtemp and 0 for amount_rain and amount_snow. Include a
		function that prompts the user and sets values for each field so that you can
		override the default values. Write a program that creates a monthly report.
		
# 2) DYNAMIC MEMORY ALLOCATION USING NEW AND DELETE OPERATOR
	TITLE: LIBRARY OPERATIONS
		A Book shop maintains the inventory of books that are being sold at the shop. The
		list includes details such as title, author, publisher, price and available stock.
		Write a program in C++ which will have a class called books with suitable member
		functions for
			i) Add
			ii) Update
			iii) Search a book
			iv) Purchase a book (update the stock and display the total cost)
			v) Record number of successful/unsuccessful transactions 
				(use static data members to keep count of transactions)
 
# 3) OPERTOR OVERLOADING 
		1) COMPLEX NUMBER OPERATIONS
			Write a C++ program to design a class ‘Complex ‘with data members for real and
			imaginary part.
		2) STRING OPERATIONS
			Write a C++ program to perform String operations using Operator Overloading
				a) "=" String Equality Check
				b) "<=" String Copy
				c) "<<" Display String ( Using Friend Function )
				d) "*" String concatenation (e.g. S1="PICT", S2="SCTR", S3=S1*S2 i.e. s3="PICTSCTR").		

# 4) INHERITANCE
	TITLE: DATABASE
		Design a base class with name, date of birth, blood group and another base class
		consisting of the data members such as height and weight.
		Design one more base class consisting of the insurance policy number and contact
		address. The derived class contains the data members’ telephone numbers and
		driving license number.
		Write a menu driven program to carry out the following things:
			i)   Build a master table
			ii)  Display Record
			iii) Insert a record
			iv)  Delete record
			v)   Edit record
			vi)  Search for a record

# 5) MULTIPLE INHERITANCE
	TITLE: EMPLOYEE DATABASE
		Create employee bio-data using following classes
			i)   Personal record
			ii)  Professional record
			iii) Academic record
			Assume appropriate data members and member function to accept required
			data & print bio-data. Create bio-data using multiple inheritance using C++.

# 6) INHERITANCE USING VIRTUAL FUNCTION
	TITLE: FINDING AREA 
		Create a base class shape with two double type values and member functions to
		input the data and compute_area() for calculating area of figure.
		Derive two classes’ triangle and rectangle. Make compute_area() as a virtual
		function and redefine this function in the derived class to suit their requirements.
		Write a program that accepts dimensions of triangle/rectangle and display
		calculated area.


# 7) EXCEPTION HANDLING
	TITLE: DIVISION (DIVIDE BY ZERO EXCEPTION)
		Write a program in C++ which includes the code for following operations :
			i) A function to read two double type numbers from keyboard
			ii) A function to calculate the division of these two numbers
			iii) A try block to detect and throw an exception if the condition 
			     “divide-by-zero” occurs
			iv) Appropriate catch block to handle the exceptions thrown



# 8) GENERIC PROGRMMING : TEMPLATES
	TITLE: MATRIX OPERATIONS
		Write a program in C++ using function/class template to read two matrices of
		different data types such as integers and floating point values and perform simple
		arithmetic operations on these matrices separately and display it.


# 9) FILE OPERATIONS C++
	TITLE: DATABASE
		Design a base class consisting of the data members such as name of the student,
		roll number and subject. The derived class consists of the data member’s subject
		code, internal assessment and university examination marks. Construct a virtual
		base class for the item name of the student and roll number. The program should
		have the facilities. 
			i) Build a master table 
			ii) List a table 
			iii) Insert a new entry 
			iv)	Delete old entry 
			v) Edit an entry 
			vi) Search for a record 

# 10) SEQUNTIAL FILE OPERATIONS IN C++
	TITLE: STUDENT DATABASE
	Write a program in C++ to implement sequential file for students' database and perform 
	following operations on it
			i) Create
			ii) Display
			iii) Add
			iv) Delete
			v) Modify
		
