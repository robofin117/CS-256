// CS256Midterm1jgfong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string> 
#include <iostream>
#include <vector>
using namespace std;

class Human {
	friend class Parent;
private:
	string name;
	int age;
	char sex;
	Human() {
		name = "";
		age = 0;
		sex = 'n';
	}

protected:
	Human(string designation, int ageNum, char sexChar) {
		name = designation;
		age = ageNum;
		sex = sexChar;
	}
public:
	void setName(string nick) {
		name = nick;
	}
	
	string getName() {
		return name;
	}

	void setAge(int number) {
		age = number;
	}

	int getAge() {
		return age;
	}

	void setSex(char input) {
		sex = input;
	}

	char getSex() {
		return sex;
	}

	virtual string work(string job) {
		return job;
	}
	
};


class Child : public Human {
private:
	Parent mom;
	Parent dad;

	Child() :Human("", 0, 'a') {

	};

public:
	Child(string n, int a, char s, Parent mother, Parent papa) : Human(n, a, s) {
		mom = mother;
		dad = papa;
	}


	friend Parent;
};

class Parent : public Human {
private:
	vector <Child> children;

public:
	Parent() :Human("", 0, 'n') {

	}

	Parent(string n, int a, char s) : Human(n, a, s) {

	}

	void setChild(Child kid) {
		children.push_back(kid);
	}

	Child getChild(int number) {
		return children[number];
	}
	friend Child;
};
int main()
{
	string student = "Student";
	string baby = "Play";
	Parent Homer("Homer", 36, 'M');
	Parent March("March", 34, 'F');
	Homer.setChild(Child("Lisa", 12, 'F', Homer, March));
	Homer.setChild(Child("Bart", 10, 'M', Homer, March));
	March.setChild(Child("Maggie", 3, 'F', Homer, March));

	cout <<"Name: "<< Homer.getName() << endl;
	cout << "Age: " << Homer.getAge() << endl;
	cout << "Sex: " << Homer.getSex() << endl;
	cout << "Work: " << Homer.work("Safety Inspector") << endl;
	cout << "=======================" << endl;
	cout << "Name: " << March.getName() << endl;
	cout << "Age: " << March.getAge() << endl;
	cout << "Sex: " << March.getSex() << endl;
	cout << "Work: " << March.work("Housewife") << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Name: " << Homer.getChild(i).getName() << endl;
		cout << "Age: " << Homer.getChild(i).getAge() << endl;
		cout << "Sex: " << Homer.getChild(i).getSex() << endl;
		if (i == 2) {
			cout << "Work: " << baby << endl;
		}
		else {
			cout << "Work: " << student << endl;
		}

	}


    return 0;
}

