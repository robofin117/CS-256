// InClassAssignment5-08.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	int phone;
	
protected:
	PersonData(const string &lName, const string &fName, const string &ad, const string &cty, const string &ste, const int &zipCode, const int &pNumber) {
		lastName = lName;
		firstName = fName;
		address = ad;
		city = cty;
		state = ste;
		zip = zipCode;
		phone = pNumber;
		printf("PersonData Constructed\n");
	}

public:
	void setLastName(string input) {
		lastName = input;
	}

	string getLastName() {
		return lastName;
	}

	void setFirstName(string input) {
		firstName = input;
	}

	string getFirstName() {
		return firstName;
	}

	void setAddress(string input) {
		address = input;
	}

	string getAddress() {
		return address;
	}

	void setCity(string input) {
		city = input;
	}

	string getCity() {
		return city;
	}

	void setZip(int input) {
		zip = input;
	}

	int getZip() {
		return zip;
	}

	void setPhone(int input) {
		phone = input;
	}

	int getPhone() {
		return phone;
	}
};

class CustomerData:public PersonData {
private:
	int customerNumber;
	bool mailingList;

protected:
	CustomerData(string ln, string fn, string ad, string c, string sta, int z, int p):PersonData(ln,fn,ad,c,sta,z,p), customerNumber(0), mailingList(false) {
		printf("CustomerData Constructed.\n");
		//Not necessary. Should use default next time. CustomerData():customerNumber(0), mailingList(false);
	}

public:
	void setCustomerNumber(int input) {
		customerNumber = input;
	}

	int getCustomerNumber() {
		return customerNumber;
	}

	void setMailingList(bool input) {
		mailingList = input;
	}

	bool getMailingList() {
		return mailingList;
	}
};

class PreferredCustomer :public CustomerData {
private:
	double spent;
	double discount;
public:
	PreferredCustomer(string ln, string fn, string ad, string c, string sta, int z, int p) : CustomerData(ln, fn, ad, c, sta, z, p), spent(0) {
		printf("Preferred Customer Constructed\n");

	}


	void setSpending(int input) {
		spent = input;
	}

	void addSpending(int input) {
		if (input < 0) {
			cout << "No negatives" << endl;
			exit(1);
		}
		spent += input;
	}

	double purchasesAmount() {
		return spent;
	}

	void discountLevel() {
		if (spent >= 2000) {
			cout << "Discount Level now at Platinum" << endl;
			cout << "Setting Discount to 10%." << endl;
			discount = .1;
		}
		else if (spent >= 1500) {
			cout << "Discount Level now at Gold" << endl;
			cout << "Setting Discount to 7%" << endl;
			discount = .07;
		}
		else if (spent >= 1000) {
			cout << "Discount Level now at Silver" << endl;
			cout << "Setting Discount to 6%" << endl;
			discount = .06;
		}
		else if (spent >= 500) {
			cout << "Discount Level now at Bronze" << endl;
			cout << "Setting Discount to 5%" << endl;
			discount = .05;
		}
		else {

		}
	}


};

int main()
{
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	int zip;
	int phone;
	double purchase;

	cout << "Welcome to the Store. Please enter your information." << endl;

	cout << "Enter last name: ";
	cin >> lastName;
	cout << "\n Enter first name:";
	cin >> firstName;
	cout << "\n Enter address:";
	cin >> address;
	cout << "\n Enter City: ";
	cin >> city;
	cout << "\n Enter State:";
	cin >> state;
	cout << "\n Enter zip code: ";
	cin >> zip;
	cout << "\n Enter phone number: ";
	cin >> phone;

	PreferredCustomer customer1(lastName, firstName, address, city, state, zip, phone);

	cout << "\n How much did you purchase? (No negatives) ";
	cin >> purchase;
	customer1.addSpending(purchase);
	customer1.discountLevel();


	return 0;
}