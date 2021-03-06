// jgfongCS256HW4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdlib> // For rand and srand 
#include <ctime>

using namespace std;

void GameOf21();
void TicketCheck();
void ShipsInDock();

int main()
{
	cout << "Welcome to jgfong's CS256 HW4 Program." << endl;
	cout << "1.) Game Of 21 with d6s" << endl;
	cout << "2.) Parking Ticket Sim" << endl;
	cout << "3.) Ship, Cruise, Cargo Ship" << endl;
	int choice;

	cin >> choice;

	switch (choice) {
	case 1:
		cout << "1.) Game Of 21 with d6s" << endl;
		GameOf21();
		break;
	case 2:
		cout << "2.) Parking Ticket Sim" << endl;
		TicketCheck();
		break;
	case 3:
		cout << "3.) Ship, Cruise, Cargo Ship" << endl;
		ShipsInDock();
		break;
	default:
		cout << "Invalid input." << endl;
		break;
	}


	return 0;
}

//#1) Game of 21 with 6 sided dice.

class Die {
private:
	int sides;
	int value;
public:
	Die() {
		int numSides = 6;
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	Die(int numSides) {
		unsigned seed = time(0);
		srand(seed);
		sides = numSides;
		roll();
	}
	void roll() {
		const int MIN_VALUE = 1;
		value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;

	}
	int getSides() {
		return sides;
	}
	int getValue() {
		return value;
	}

};

void GameOf21() {
	int playerScore = 0;
	int comScore = 0;
	bool rollAgain = true;
	Die die1(6), die2(6);
	cout << "Welcome to Game of 21." << endl;
	cout << "The Player's d6 has been rolled." << endl;
	cout << "The Computer's d6 has been rolled." << endl;


	do {
		playerScore += die1.getValue();
		comScore += die2.getValue();
		string response;
		cout << "Results:" << endl;
		cout << "Die Rolled : " << die1.getValue() << endl;
		cout << ", Current Score: " << playerScore << endl;
		cout << "Do you wish to roll again? (Y/N): ";
		cin >> response;
		if (response == "N" || response == "n" || response == "No" || response == "no" || response == "NO") {
			rollAgain = false;
		}
		if (response == "Y" || response == "y" || response == "YES" || response == "Yes" || response == "yes") {
			die1.roll();
			die2.roll();
		}

	} while (playerScore <= 21 && rollAgain == true || comScore <= 21 && rollAgain == true);

	cout << "Scores:" << endl;
	if (playerScore > 21 || comScore >21) {
		if (playerScore > 21 && comScore <= 21) {
			cout << "Player is over 21. Computer Wins!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
		else if (comScore > 21 && comScore <= 21) {
			cout << "Computer is over 21. Player Wins!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
		else {
			cout << "Computer and Player are over 21. Draw!" << endl;
			cout << "Player: " << playerScore << " Computer: " << comScore << endl;
		}
	}
	else if (playerScore == comScore) {
		cout << "Player and Computer have same score. Draw!" << endl;
		cout << "Player: " << playerScore << " Computer: " << comScore << endl;
	}

	else{
		if (playerScore > comScore) {
			cout << "Player wins!" << endl;
		}
		else {
			cout << "Computer wins!" << endl;
		}
	cout << "Player: " << playerScore << " Computer: " << comScore << endl;
	}


}

//#2 ) Parking Ticket Simulator

class ParkedCar {
private:
	string make;
	string model;
	string color;
	int licenseNumber;
	int minutes;

public:
	ParkedCar() {
		make = "";
		model = ""; 
		color = "";
		licenseNumber = 0;
		minutes = 0;
	}

	ParkedCar(string name, string version, string tint, int num, int min) {
		make = name;
		model = version;
		color = tint;
		licenseNumber = num;
		minutes = min;
	}

	void setMake(string name) {
		make = name;
	}

	void setModel(string name) {
		model = name;
	}

	void setColor(string tint) {
		color = tint;
	}

	void setLicense(int number) {
		licenseNumber = number;
	}

	void setMinutes(int min) {
		minutes = min;
	}

	string getMake() {
		return make;
	}
	
	string getModel() {
		return model;
	}

	string getColor() {
		return color;
	}

	int getLicenseNum() {
		return licenseNumber;
	}

	int getMinutes() {
		return minutes;
	}

	friend class ParkingMeter;
	friend class ParkingTicket;
	friend class PoliceOfficer;
};

class ParkingMeter {
private:
	int purchasedMinutes;
public:
	ParkingMeter() {
		purchasedMinutes = 0;
	}
	ParkingMeter(int minutes) {
		purchasedMinutes = minutes;
	}
	int getPurchasedMinutes() {
		return purchasedMinutes;
	}
	void setPurchasedMinutes(int minutes) {
		purchasedMinutes = minutes;
	}
	string getMake(ParkedCar &car) {
		return car.getMake();
	}

	string getModel(ParkedCar &car) {
		return car.getModel();
	}

	string getColor(ParkedCar &car) {
		return car.getColor();
	}

	int getLicenseNum(ParkedCar &car) {
		return car.getLicenseNum();
	}

};


class PoliceOfficer {
private:
	string name;
	int badgeNumber;

public:
	PoliceOfficer() {
		name = "";
		badgeNumber = 0;
		cout << "Officer has been registered." << endl;
	}

	PoliceOfficer(string designation, int number) {
		name = designation;
		badgeNumber = number;
		cout << "Officer " << name << " is on the scene. " << endl;
		cout << "Badge Number: " << badgeNumber << endl;
	}

	string getName() {
		return name;
	}

	int getBadgeNum() {
		return badgeNumber;
	}

	bool checkTicket(ParkedCar &parked, ParkingMeter &meter) {
		bool needed = false;
		cout << "The parked car is being checked." << endl;
		cout << "The car is a " << parked.getColor() << " " << parked.getMake() << " " << parked.getModel() << endl;
		if (parked.getMinutes() > meter.getPurchasedMinutes()) {
			cout << "The parked car has been issued a ticket." << endl;
			needed = true;
			
		}
		else {
			cout << "Ticket was not issued to " << parked.getMake() << " " << parked.getModel() << " at parking spot." << endl;
		}
		return needed;
	}

};

class ParkingTicket {
private:
	float fine;
	ParkedCar markedcar;
	ParkingMeter meter;
	PoliceOfficer cop;

public:

	ParkingTicket() {
		fine = 0;
	}

	ParkingTicket(ParkedCar &mark, ParkingMeter &stand, PoliceOfficer &officer, int hours) {
		markedcar = mark;
		meter = stand;
		cop = officer;
		
		fine = (float)25.00 + ((hours - 1) * 10);
	}


	float getFine() {
		return fine;
	}
	void printTicket() {

		cout << "------------------------------" << endl;
		cout << "Ticket: " << endl;
		cout << "Car Manufacturer: " << markedcar.getMake()<< endl;
		cout << "Car Model: " << markedcar.getModel() << endl;
		cout << "Color: " << markedcar.getColor() << endl;
		cout << "Issuing Officer:" << cop.getName() << endl;
		cout << "Officer Badge Number: " << cop.getBadgeNum() << endl;
		cout << "Fine: $" << getFine() << endl;
		cout << "---------------------------------" << endl;
	}
};

void TicketCheck() {
	string make = "Hyundai";
	string model = "Tiburon";
	string color = "Blue";
	ParkedCar car(make, model, color, 7814352, 360);

	ParkingMeter meter(180);

	string name = "Harry Jenkins";
	PoliceOfficer Jenkins(name, 34915287);
	if (Jenkins.checkTicket(car, meter)) {
		int hoursOver = (int)abs((car.getMinutes() - meter.getPurchasedMinutes())/60);
		ParkingTicket issuedTicket(car, meter, Jenkins, hoursOver);
		issuedTicket.printTicket();
	}
	else {
		cout << "There are still minutes in the meter. No ticket has been issued." << endl;
	}

}

// #3) Ship, CruiseShip, CargoShip

class Ship {
private:
	string name;
	int yearBuilt;
	Ship() {

	}
protected:
	Ship(const string &designation,const int &year) {
		name = designation;
		yearBuilt = year;
		cout << "Ship "<< designation<< " has been registered." << endl;
		printf("Vessel has been built in %d. \n", getYear());
	}


public:

	void setName(string input) {
		name = input;
	}
	const string &getName() {
		return name;
	}
	void setYear(int input) {
		yearBuilt = input;
	}

	const int &getYear() {
		return yearBuilt;
	}

	virtual void print() = 0;
};

class CruiseShip : public Ship {
private: 
	int passengerNum;
public:
	CruiseShip(string name, int year, int passengers):Ship(name, year) {
		setName(name);
		setYear(year);
		passengerNum = passengers;
	}

	void setPassengers(int passengers) {
		passengerNum = passengers;
	}

	int getPassengers() {
		return passengerNum;
	}

	virtual void print() {
		cout << "Ship: " << getName() << endl;
		cout << "Passengers: " << getPassengers() << endl;
	}
};

class CargoShip : public Ship {
private:
	int tonnage;
public:
	CargoShip(string name, int year, int tons) : Ship(name, year) {
		tonnage = tons;
	}
	void setTonnage(int tons) {
		tonnage = tons;
	}
	int getTonnage() {
		return tonnage;
	}

	virtual void print() {
		cout << "Ship: " << getName() << endl;
		cout << "Tonnage: " << getTonnage() << endl;
	}

};

class Starship : public Ship {
private:
	int torpedos;
	bool phasersToStun;
	int registryNumber;
public:
	Starship(string name, int year,int ncc, int weapons, bool phasers) : Ship(name, year) {
		torpedos = weapons;
		phasersToStun = phasers;
		registryNumber = ncc;
	}

	void setPhasers(bool setting) {
		phasersToStun = setting;
	}

	bool phaserStatus() {
		return phasersToStun;
	}

	void loadTorpedos(int number) {
		torpedos = number;
	}

	int torpedoStatus() {
		return torpedos;
	}

	void setRegistryNum(int input) {
		registryNumber = input;
	}

	int getRegistryNum() {
		return registryNumber;
	}

	virtual void print() {
		cout << "Federation Starship: " << getName() << endl;
		cout << "Registry Number: NCC-" << getRegistryNum() << endl;
		cout << "Torpedo Count: " << torpedoStatus() << endl;
		cout << "Phaser set to stun: " << phaserStatus() << endl;
	}
};

void ShipsInDock() {
	const int number = 4;
	Ship *vessels[number] = {
		new CruiseShip("USS Philidelphia", 1934, 200),
		new CargoShip("USS Kobayashi Maru", 1982, 1500),
		new Starship("USS Enterprise",1966, 1701, 300, true),
		new Starship("USS Defiant", 1968, 1764, 20, false)
	};

	for (int i = 0; i < number; i++) {
		vessels[i]->print();
	}
}
