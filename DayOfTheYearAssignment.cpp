// DayOfTheYearAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;



class DayOfTheYear {
private:

	int day;
	int numDays;

public:
	DayOfTheYear(int dayNum);
	string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"  };
	void print();
	string selectedMonth;
};

DayOfTheYear::DayOfTheYear(int dayNum) {
	numDays = dayNum;
	if (dayNum <= 0) {
		cout << "Invalid day selection. Day must be from 1-365" << endl;
		exit(0);
	}
	else if (dayNum <= 31) {
		//January 1-31
		selectedMonth = month[0];
		day = dayNum;
	}
	else if (dayNum <= 59) {
		//February 1-28
		selectedMonth = month[1];
		day = dayNum - 31;
	}
	else if (dayNum<= 90) {
		//March 1-31
		selectedMonth = month[2];
		day = dayNum - (59);
	}
	else if (dayNum <= 120) {
		//April 1-30
		selectedMonth = month[3];
		day = dayNum - 90;
	}
	else if (dayNum<= 151){
		//May 1-31
		selectedMonth = month[4];
		day = dayNum - 120;
	}
	else if (dayNum<= 181) {
		//June 1-30
		selectedMonth = month[5];
		day = dayNum - 151;
	}
	else if (dayNum<= 212) {
		//July 1-31
		selectedMonth = month[6];
		day = dayNum - 181;
	}
	else if (dayNum<= 243) {
		//August 1-31
		selectedMonth = month[7];
		day = dayNum - 212;
	}
	else if (dayNum <= 273) {
		//September 1-30
		selectedMonth = month[8];
		day = dayNum - 243;
	}

	else if (dayNum <= 304) {
		//October 1-31
		selectedMonth = month[9];
		day = dayNum - 273;
	}
	else if (dayNum <= 334) {
		//November 1-30
		selectedMonth = month[10];
		day = dayNum - 304;

	}

	else if(dayNum <=365){
		selectedMonth = month[11];
		day = 365 - dayNum;
	}
	else {
		cout<< "Invalid day selection. Day must be from 1-365" << endl;
		exit(0);
	}
}

void DayOfTheYear::print() {
	cout << "Day " << numDays << " would be "  << selectedMonth << " " << day << "\n";
}

int main()
{
	int inputDay;
	cout << "Please input the day number: " << endl;
	cin >> inputDay;

	DayOfTheYear first(inputDay);
	first.print();


    return 0;
}

