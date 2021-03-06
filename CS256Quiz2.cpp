// CS256Quiz2.cpp : Defines the entry point for the console application.
//
//Jonathan Fong 
//CS256
//010856599

#include "stdafx.h"
#include <iostream>

using namespace std;

double pi = 3.14159;
class Circle {
private:
	double radius;

public:
	Circle(double r);
	Circle();
	void setRadius(double rad);
	
	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();
};

Circle::Circle(double r) {
	radius = r;
}
Circle::Circle() {
	radius = 0.0;
}

void Circle::setRadius(double rad) {
	radius = rad;
}

double Circle::getRadius() {
	return radius;
}

double Circle::getArea() {
	return radius * radius * pi;
}

double Circle::getDiameter() {
	return radius * 2;
}

double Circle::getCircumference() {
	return 2 * pi*radius;
}



int main()
{
	double radius = 0;
	cout << "Welcome to Circle calculator " << endl;

	cout << "Please enter the circle's radius: " << endl;
	cin >> radius;

	cout << "Radius recorded as: " << radius << endl;

	Circle circle1(radius);

	cout << "The created circle's area is: " << circle1.getArea() << endl;
	cout << "The created circle's diameter is: " << circle1.getDiameter() << endl;
	cout << "The created circle's circumference is: " << circle1.getCircumference() << endl;


    return 0;
}

