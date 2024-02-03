/* 
==============================================================================
Assignment : Weather Report
Name : Dipak Kumawat
class : FYMCA
Batch : B
Problem Statement : Create a class named WeatherReport that holds a dialy weather 
report with data members day_of_month, highTemp, lowTemp, amountRain, amountSnowfall. 
Use different types of constructors to initialize the object. Also include a function 
that prompts the user and sets values for each field so that you can overide the default values. 
Write a menu driven program in c++ with option to enter data and generate monthly report 
that displays average of each attribute (The constructor initialize the fields with default 
values : (99 for day_of_month, 999 for highTemp, -999 for lowTemp, and 0 for amountRain and amountSnowfall)
==============================================================================
*/  

#include<iostream>
#include <iomanip>
using namespace std;

int i=0;

class WeatherReport {
	int dayOfMonth;
	int highTemp;
	int lowTemp;
	int amountRain;
	int amountSnowfall;

	public:
		static double sum[4];
		static int n;

		WeatherReport(){
			dayOfMonth = 99;
			highTemp = 999;
			lowTemp = -999;
			amountRain = 0;
			amountSnowfall = 0;
		}

		WeatherReport(int dom, int ht, int lt){
			dayOfMonth = dom;
			highTemp = ht;
			lowTemp = lt;
		}

		WeatherReport(int dom, int ht, int lt, int ar, int as){
			dayOfMonth = dom;
			highTemp = ht;
			lowTemp = lt;
			amountRain = ar;
			amountSnowfall = as;
		}
		void update();
		void report();
		void displayRow(int);
		static void avg();
};

int WeatherReport :: n;
double WeatherReport :: sum[4];

void WeatherReport :: displayRow(int i){
	cout<<setw(3)<<i+1<<setw(20)<<dayOfMonth<<setw(20)<<highTemp<<setw(20)<<lowTemp<<setw(20)<<amountRain<<setw(20)<<amountSnowfall<<"\n";
}

void WeatherReport :: update(){
    n++;
	cout<<"Enter Day of Month : ";
	cin>>dayOfMonth;
	cout<<"High Temperature : ";
	cin>>highTemp;
	cout<<"Low Temperature : ";
	cin>>lowTemp;
	cout<<"Amount Rain : ";
	cin>>amountRain;
	cout<<"Amount SnowFall : ";
	cin>>amountSnowfall;
}

void WeatherReport :: report(){
	sum[0] += highTemp;
	sum[1] += lowTemp;
	sum[2] += amountRain;
	sum[3] += amountSnowfall;
}

void WeatherReport :: avg(){
	/* for(i=0;i<5;i++){
  		sum[i] = sum[i]/n;
	} */
	cout<<setw(7)<<"Average"<<setw(36)<<sum[0]/n<<setw(20)<<sum[1]/n<<setw(20)<<sum[2]/n<<setw(20)<<sum[3]/n<<"\n";
	cout<<"----------------------------------------------------------------------------------------------------------------\n";
}

void printMenu(){
	cout<<"1. Update values "<<"\n";
	cout<<"2. Exit"<<"\n";
}

void displayReport(WeatherReport mon[30]){
	 cout<<setw(60)<<"Monthly Report \n";
	 cout<<"---------------------------------------------------------------------------------------------------------------\n";
	 cout<<setw(7)<<"S.No. "<<setw(20)<<" dayOfMonth "<<setw(20)<<" highTemp "<<setw(20)<<" lowTemp "<<setw(20)<<" amountRain "<<setw(20)<<" amountSnowfall\n";
	 cout<<"---------------------------------------------------------------------------------------------------------------\n";
	 for(int i=0; i<30; i++){
	          mon[i].displayRow(i);
	 }
	 cout<<"----------------------------------------------------------------------------------------------------------------\n";
}

int main(){

	 WeatherReport month[30];
	 int choice, day;
	 displayReport(month);
	 int entry = 1;

	 while(entry==1){
		 printMenu();
		 cout<<"Enter Choice : "<<"\n";
		 cin>>choice;
		 switch(choice){
		   case 1 : cout<<"Enter updating day : \n";
			    cin>>day;
			    month[day-1].update();
                month[day-1].report();
		        displayReport(month);
                month[29].avg();
			    break;
            case 2: entry = 0;
		 }
	 }
	 return 0;
}

/*

                                            Monthly Report 
---------------------------------------------------------------------------------------------------------------
 S.No.          dayOfMonth            highTemp             lowTemp          amountRain      amountSnowfall
---------------------------------------------------------------------------------------------------------------
  1                  99                 999                -999                   0                   0
  2                  99                 999                -999                   0                   0
  3                  99                 999                -999                   0                   0
  4                  99                 999                -999                   0                   0
  5                  99                 999                -999                   0                   0
  6                  99                 999                -999                   0                   0
  7                  99                 999                -999                   0                   0
  8                  99                 999                -999                   0                   0
  9                  99                 999                -999                   0                   0
 10                  99                 999                -999                   0                   0
 11                  99                 999                -999                   0                   0
 12                  99                 999                -999                   0                   0
 13                  99                 999                -999                   0                   0
 14                  99                 999                -999                   0                   0
 15                  99                 999                -999                   0                   0
 16                  99                 999                -999                   0                   0
 17                  99                 999                -999                   0                   0
 18                  99                 999                -999                   0                   0
 19                  99                 999                -999                   0                   0
 20                  99                 999                -999                   0                   0
 21                  99                 999                -999                   0                   0
 22                  99                 999                -999                   0                   0
 23                  99                 999                -999                   0                   0
 24                  99                 999                -999                   0                   0
 25                  99                 999                -999                   0                   0
 26                  99                 999                -999                   0                   0
 27                  99                 999                -999                   0                   0
 28                  99                 999                -999                   0                   0
 29                  99                 999                -999                   0                   0
 30                  99                 999                -999                   0                   0
----------------------------------------------------------------------------------------------------------------
1. Update values 
2. Exit
Enter Choice : 
1
Enter updating day : 
30
Enter Day of Month : 34
High Temperature : 34
Low Temperature : 10
Amount Rain : 67
Amount SnowFall : 54
                                            Monthly Report 
---------------------------------------------------------------------------------------------------------------
 S.No.          dayOfMonth            highTemp             lowTemp          amountRain      amountSnowfall
---------------------------------------------------------------------------------------------------------------
  1                  99                 999                -999                   0                   0
  2                  99                 999                -999                   0                   0
  3                  99                 999                -999                   0                   0
  4                  99                 999                -999                   0                   0
  5                  99                 999                -999                   0                   0
  6                  99                 999                -999                   0                   0
  7                  99                 999                -999                   0                   0
  8                  99                 999                -999                   0                   0
  9                  99                 999                -999                   0                   0
 10                  99                 999                -999                   0                   0
 11                  99                 999                -999                   0                   0
 12                  99                 999                -999                   0                   0
 13                  99                 999                -999                   0                   0
 14                  99                 999                -999                   0                   0
 15                  99                 999                -999                   0                   0
 16                  99                 999                -999                   0                   0
 17                  99                 999                -999                   0                   0
 18                  99                 999                -999                   0                   0
 19                  99                 999                -999                   0                   0
 20                  99                 999                -999                   0                   0
 21                  99                 999                -999                   0                   0
 22                  99                 999                -999                   0                   0
 23                  99                 999                -999                   0                   0
 24                  99                 999                -999                   0                   0
 25                  99                 999                -999                   0                   0
 26                  99                 999                -999                   0                   0
 27                  99                 999                -999                   0                   0
 28                  99                 999                -999                   0                   0
 29                  99                 999                -999                   0                   0
 30                  34                  34                  10                  67                  54
----------------------------------------------------------------------------------------------------------------
Average                                  34                  10                  67                  54
----------------------------------------------------------------------------------------------------------------
1. Update values 
2. Exit
Enter Choice : 
1
Enter updating day : 
25
Enter Day of Month : 45
High Temperature : 67
Low Temperature : 12
Amount Rain : 56
Amount SnowFall : 43
                                            Monthly Report 
---------------------------------------------------------------------------------------------------------------
 S.No.          dayOfMonth            highTemp             lowTemp          amountRain      amountSnowfall
---------------------------------------------------------------------------------------------------------------
  1                  99                 999                -999                   0                   0
  2                  99                 999                -999                   0                   0
  3                  99                 999                -999                   0                   0
  4                  99                 999                -999                   0                   0
  5                  99                 999                -999                   0                   0
  6                  99                 999                -999                   0                   0
  7                  99                 999                -999                   0                   0
  8                  99                 999                -999                   0                   0
  9                  99                 999                -999                   0                   0
 10                  99                 999                -999                   0                   0
 11                  99                 999                -999                   0                   0
 12                  99                 999                -999                   0                   0
 13                  99                 999                -999                   0                   0
 14                  99                 999                -999                   0                   0
 15                  99                 999                -999                   0                   0
 16                  99                 999                -999                   0                   0
 17                  99                 999                -999                   0                   0
 18                  99                 999                -999                   0                   0
 19                  99                 999                -999                   0                   0
 20                  99                 999                -999                   0                   0
 21                  99                 999                -999                   0                   0
 22                  99                 999                -999                   0                   0
 23                  99                 999                -999                   0                   0
 24                  99                 999                -999                   0                   0
 25                  45                  67                  12                  56                  43
 26                  99                 999                -999                   0                   0
 27                  99                 999                -999                   0                   0
 28                  99                 999                -999                   0                   0
 29                  99                 999                -999                   0                   0
 30                  34                  34                  10                  67                  54
----------------------------------------------------------------------------------------------------------------
Average                                50.5                  11                61.5                48.5
----------------------------------------------------------------------------------------------------------------
1. Update values 
2. Exit
Enter Choice : 
1
Enter updating day : 
20
Enter Day of Month : 
34
High Temperature : 78
Low Temperature : 23
Amount Rain : 67
Amount SnowFall : 45
                                            Monthly Report 
---------------------------------------------------------------------------------------------------------------
 S.No.          dayOfMonth            highTemp             lowTemp          amountRain      amountSnowfall
---------------------------------------------------------------------------------------------------------------
  1                  99                 999                -999                   0                   0
  2                  99                 999                -999                   0                   0
  3                  99                 999                -999                   0                   0
  4                  99                 999                -999                   0                   0
  5                  99                 999                -999                   0                   0
  6                  99                 999                -999                   0                   0
  7                  99                 999                -999                   0                   0
  8                  99                 999                -999                   0                   0
  9                  99                 999                -999                   0                   0
 10                  99                 999                -999                   0                   0
 11                  99                 999                -999                   0                   0
 12                  99                 999                -999                   0                   0
 13                  99                 999                -999                   0                   0
 14                  99                 999                -999                   0                   0
 15                  99                 999                -999                   0                   0
 16                  99                 999                -999                   0                   0
 17                  99                 999                -999                   0                   0
 18                  99                 999                -999                   0                   0
 19                  99                 999                -999                   0                   0
 20                  34                  78                  23                  67                  45
 21                  99                 999                -999                   0                   0
 22                  99                 999                -999                   0                   0
 23                  99                 999                -999                   0                   0
 24                  99                 999                -999                   0                   0
 25                  45                  67                  12                  56                  43
 26                  99                 999                -999                   0                   0
 27                  99                 999                -999                   0                   0
 28                  99                 999                -999                   0                   0
 29                  99                 999                -999                   0                   0
 30                  34                  34                  10                  67                  54
----------------------------------------------------------------------------------------------------------------
Average                             59.6667                  15             63.3333             47.3333
----------------------------------------------------------------------------------------------------------------
1. Update values 
2. Exit
Enter Choice : 
2

*/
