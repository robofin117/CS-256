// NewDayOfTheYear.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


const string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class DayOfTheYear {

public:
	DayOfTheYear(int dayNum);
	DayOfTheYear(string chosenMonth, int dayNumber);
	int day;
	int numDays;	
	void print();
	string month;


	DayOfTheYear operator ++() {
		increaseDayNMonth();
		++day;
		++numDays;
		return *this;
	}
	DayOfTheYear operator ++(int) {
		DayOfTheYear temp = *this;
		increaseDayNMonth();
		day++;
		numDays++;
		
		return temp;
	}
	DayOfTheYear operator --() {

		--day;
		--numDays;
		decreaseDayNMonth();
		return *this;
	}
	DayOfTheYear operator --(int) {
		DayOfTheYear temp = *this;

		day--;
		numDays--;
		decreaseDayNMonth();
		return temp;
	}

	void operator = (const DayOfTheYear &right) {
		day = right.day;
		month = right.month;
	}

	void increaseDayNMonth() {
		if (month == months[0] && day == 31) {
			//January to February
			day = 0;
			month = months[1];
			
		}
		if (month == months[1] && day == 28) {
			//February to March
			day = 0;
			month = months[2];
			
		}
		if (month == months[2] && day == 31) {
			//March to April
			day = 0;
			month = months[3];
		}
		if (month == months[3] && day == 30) {
			//April to May
			day = 0;
			month = months[4];
		}		
		if (month == months[4] && day == 31) {
			//May to June
			day = 0;
			month = months[5];
		}
		if (month == months[5] && day == 30) {
			//June to July
			day = 0;
			month = months[6];
		}
		if (month == months[6] && day == 31) {
			//July to August
			day = 0;
			month = months[7];
		}
		if (month == months[7] && day == 31) {
			//August to September
			day = 0;
			month = months[8];
		}
		if (month == months[8] && day == 30) {
			//September to October
			day = 0;
			month = months[9];
		}
		if (month == months[9] && day == 31) {
			//October to November
			day = 0;
			month = months[10];
		}
		if (month == months[10] && day == 30) {
			//November to December
			day = 0;
			month = months[11];
		}
		if (month == months[11] && day == 31) {
			//December to January
			day = 0;
			month = months[0];
			numDays = 0;
		}
	}

	void decreaseDayNMonth() {
		if (month == months[0] && day == 0) {
			//January to December
			day = 31;
			month = months[11];
			numDays = 365;
		}
		if (month == months[1] && day == 0) {
			//February to January
			day = 31;
			month = months[0];
		}
		if (month == months[2] && day == 0) {
			//March to February
			day = 28;
			month = months[1];
		}
		if (month == months[3] && day == 0) {
			//April to March
			day = 31;
			month = months[2];
		}
		if (month == months[4] && day == 0) {
			//May to April
			day = 30;
			month = months[3];
		}
		if (month == months[5] && day == 0) {
			//June to May
			day = 31;
			month = months[4];
		}
		if (month == months[6] && day == 0) {
			//July to June
			day = 30;
			month = months[5];
		}
		if (month == months[7] && day == 0) {
			//August to July
			day = 31;
			month = months[6];
		}
		if (month == months[8] && day == 0) {
			//September to July
			day = 31;
			month = months[7];
		}
		if (month == months[9] && day == 0) {
			//October to September
			day = 30;
			month = months[8];
		}
		if (month == months[10] && day == 0) {
			//November to October
			day = 31;
			month = months[9];
		}
		if (month == months[11] && day == 0) {
			//December to November
			day = 30;
			month = months[10];
		}
	}
};

DayOfTheYear::DayOfTheYear(string chosenMonth, int dayNumber) {

	if (dayNumber < 0 || dayNumber > 31) {
		cout << "Invalid day selection. Day must be from 1-31" << endl;
		exit(0);
	}
	else if (dayNumber <= days[0] && chosenMonth == months[0]) {
		month = months[0];
		day = dayNumber;
		numDays = dayNumber;
	}
	else if (dayNumber <= days[1] && chosenMonth == months[1]) {
		month = months[1];
		day = dayNumber;
		numDays = 31 + dayNumber;
	}
	else if (dayNumber <= days[2] && chosenMonth == months[2]) {
		month = months[2];
		day = dayNumber;
		numDays = 59 + dayNumber;
	}
	else if (dayNumber <= days[3] && chosenMonth == months[3]) {
		month = months[3];
		day = dayNumber;
		numDays = 90 + dayNumber;
	}
	else if (dayNumber <= days[4] && chosenMonth == months[4]) {
		month = months[4];
		day = dayNumber;
		numDays = 120 + dayNumber;
	}
	else if (dayNumber <= days[5] && chosenMonth == months[5]) {
		month = months[5];
		day = dayNumber;
		numDays = 151 + dayNumber;
	}
	else if (dayNumber <= days[6] && chosenMonth == months[6]) {
		month = months[6];
		day = dayNumber;
		numDays = 181 + dayNumber;
	}
	else if (dayNumber <= days[7] && chosenMonth == months[7]) {
		month = months[7];
		day = dayNumber;
		numDays = 212 + dayNumber;
	}
	else if (dayNumber <= days[8] && chosenMonth == months[8]) {
		month = months[8];
		day = dayNumber;
		numDays = 243 + dayNumber;
	}
	else if (dayNumber <= days[9] && chosenMonth == months[9]) {
		month = months[9];
		day = dayNumber;
		numDays = 273 + dayNumber;
	}
	else if (dayNumber <= days[10] && chosenMonth == months[10]) {
		month = months[10];
		day = dayNumber;
		numDays = 304 + dayNumber;
	}
	else if (dayNumber <= days[11] && chosenMonth == months[11]) {
		month = months[11];
		day = dayNumber;
		numDays = 334 + dayNumber;
	}
	else {
		cout << "Month inputted is not accepted." << endl;
		cout << "Choose from January, February, March, April, May, June," << endl;
		cout<< "July, August, September, October, November, or December.";
		exit(0);
	}
}

DayOfTheYear::DayOfTheYear(int dayNum) {
	numDays = dayNum;
	if (dayNum <= 0) {
		cout << "Invalid day selection. Day must be from 1-365" << endl;
		exit(0);
	}
	else if (dayNum <= 31) {
		//January 1-31
		month = months[0];
		day = dayNum;
	}
	else if (dayNum <= 59) {
		//February 1-28
		month = months[1];
		day = dayNum - 31;
	}
	else if (dayNum <= 90) {
		//March 1-31
		month = months[2];
		day = dayNum - (59);
	}
	else if (dayNum <= 120) {
		//April 1-30
		month = months[3];
		day = dayNum - 90;
	}
	else if (dayNum <= 151) {
		//May 1-31
		month = months[4];
		day = dayNum - 120;
	}
	else if (dayNum <= 181) {
		//June 1-30
		month = months[5];
		day = dayNum - 151;
	}
	else if (dayNum <= 212) {
		//July 1-31
		month = months[6];
		day = dayNum - 181;
	}
	else if (dayNum <= 243) {
		//August 1-31
		month = months[7];
		day = dayNum - 212;
	}
	else if (dayNum <= 273) {
		//September 1-30
		month = months[8];
		day = dayNum - 243;
	}

	else if (dayNum <= 304) {
		//October 1-31
		month = months[9];
		day = dayNum - 273;
	}
	else if (dayNum <= 334) {
		//November 1-30
		month = months[10];
		day = dayNum - 304;

	}

	else if (dayNum <= 365) {
		month = months[11];
		day = dayNum - 334;
	}
	else {
		cout << "Invalid day selection. Day must be from 1-365" << endl;
		exit(0);
	}
}

void DayOfTheYear::print() {
	cout << "Day " << numDays << " would be " << month.c_str() << " " << day << "\n";
}




int main()
{
	int inputChoice;

	cout << "Welcome to Day and Month Converter." << endl;
	cout << "1.) Day Only" << endl;
	cout << "2.) Month and Day" << endl;
	cout << "Please enter your choice (1 or 2)" << endl;
	cin >> inputChoice;


	if (inputChoice == 1) {
		int inputDay;
		cout << "Please input the day number: " << endl;
		cin >> inputDay;

		DayOfTheYear first(inputDay);
		cout << "The current day is: ";
		first.print();

		first--;
		cout << "The previous day is: ";
		first.print();
	}
	else if (inputChoice == 2) {
		string newMonth;
		cout << "Choose from January, February, March, April, May, June," << endl;
		cout << "July, August, September, October, November, or December.";
		cout << "Please input the month:" << endl;
		cin >> newMonth;

		int inputDay;
		cout << "Please input the day number: " << endl;
		cin >> inputDay;

		DayOfTheYear second(newMonth, inputDay);
		cout << "The current day is: ";
		second.print();

		second++;
		cout << "The next day is: ";
		second.print();

	}
	else {
		cout << "That was not a valid choice." << endl;
		cout << "Please enter your choice (1 or 2)" << endl;
		cin >> inputChoice;
	}





	return 0;
}


