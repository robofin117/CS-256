// jgfongCS256Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    return 0;
}


class BankAccount {
private:
	double balance;
	int monthlyDeposits;
	int withdrawals;
	float annualInterestRate;
	double monthlyServiceCharge;
	BankAccount() {
		balance = 0.0;
		annualInterestRate = 0.0;
		monthlyDeposits = 0;
		withdrawals = 0;
	}
protected:
	BankAccount(double bal, float interest) {
		balance = bal;
		annualInterestRate = interest;
	}

public:
	virtual void deposit(double add) {
		balance += add;
		monthlyDeposits++;
		printf("Balance has been updated. The balance is now $%.2f", balance);
		//cout << "Balance has been updated. The balance is now $" << balance << endl;
	}

	virtual void withdraw(double subtract) {
		balance -= subtract;
		withdrawals++;
	}

	virtual void calcInt() {
		float monthlyInterestRate = annualInterestRate / 12;
		double monthlyInterest = monthlyInterestRate * balance;
		balance += monthlyInterest;
	}

	virtual void monthlyProc() {
		balance -= monthlyServiceCharge;
		calcInt();
		withdrawals = 0;
		monthlyDeposits = 0;
		monthlyServiceCharge = 0;
	}

	double getBalance() {
		return balance;
	}

	void setBalance(double input) {
		balance = input;
	}

};

class SavingsAccount : public BankAccount {
private:
	bool status;

protected:

public:
	SavingsAccount(double bal, float interest):BankAccount(bal, interest) {

		if (bal < 25) {
			status = false;
		}
		else {
			status = true;
		}
	}

	void withdraw(double subtract) {
		if (status) {
			BankAccount::withdraw(subtract);
		}
		else {
			cout << "Account is inactive. Withdrawal denied." << endl;
		}
	}

	void deposit(double add) {
		if (getBalance() < 25) {
			if ((getBalance() + add) > 25) {
				BankAccount::deposit(add);
			}
		}
	}

};

class CheckingAccount : public BankAccount {
private:

protected:

public:

};