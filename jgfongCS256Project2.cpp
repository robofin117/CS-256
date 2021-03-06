// jgfongCS256Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

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
		monthlyServiceCharge = 0.0;
	}
protected:
	BankAccount(double bal, float interest) {
		balance = bal;
		annualInterestRate = interest;
		monthlyDeposits = 0;
		withdrawals = 0;
		monthlyServiceCharge = 0.0;
	}

public:
	virtual void deposit(double add) {
		balance += add;
		monthlyDeposits++;
		cout << "Number of deposits now: " << getMonthlyDeposits() << endl;
		printf("Balance has been updated. The balance is now $%.2f \n", balance);
	}

	virtual void withdraw(double subtract) {
		balance -= subtract;
		withdrawals++;
		cout << "Number of withdrawals now: " << getWithdrawals() << endl;
		printf("Balance has been updated. The balance is now $%.2f \n", balance);
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

		cout << "Monthly service charge has been processed.\n Withdrawals, deposits, and service charges have been reset." << endl;
	}

	double getBalance() {
		return balance;
	}

	int getWithdrawals() {
		return withdrawals;
	}

	int getMonthlyDeposits() {
		return monthlyDeposits;
	}

	double getServiceCharge() {
		return monthlyServiceCharge;
	}
	void setServiceCharge(double charge) {
			monthlyServiceCharge = charge;
			cout << "Monthly Service Charge set. Charge is now: $" << charge << endl;
	}

	void setBalance(double input) {
		balance = input;
		cout << "Balance has been set to $" << input << endl;
	}

	void subtractBalance(double subtract) {
		balance -= subtract;
		cout << "$" << subtract << " was subtracted from the balance." << endl;
	}

};

class SavingsAccount : public BankAccount {
private:
	bool status;

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
		if (status == false) {
			if ((getBalance() + add) > 25) {
				BankAccount::deposit(add);
				status = true;
			}
			else {
				BankAccount::deposit(add);
				cout << "Balance is still below active status. Account is still inactive." << endl;
			}
		}
		else {
			BankAccount::deposit(add);
		}

	}

	void monthlyProc() {
		cout << "Monthly Processing commenced." << endl;
		if (getWithdrawals() > 4) {
			int over = getWithdrawals() - 4;
			setServiceCharge(over);
		}
		cout << "Monthly Service Charge is: $" << getServiceCharge() << endl;
		BankAccount::monthlyProc();
		if (getBalance() < 25) {
			status = false;
			cout << "Account has fallen below $25. \n Account is inactive." << endl;
		}
	}

	void showAccount() {

		cout << "Savings Account" << endl;
		cout << "===================================" << endl;
		cout << "Balance: $" << getBalance() << endl;
		cout << "Withdrawals: " << getWithdrawals() << endl;
		cout << "Deposits: " << getMonthlyDeposits() << endl;
		cout << "Monthly Service Charge: $" << getServiceCharge() << endl;
		cout << "====================================\n\n" << endl;
	}

};

class CheckingAccount : public BankAccount {
private:

public:
	CheckingAccount(double bal, float interest) : BankAccount(bal, interest) {

	}

	void withdraw(double subtract) {
		if ((getBalance() - subtract) < 0) {

			if (getBalance() < 15) {
				BankAccount::subtractBalance(15.00);
				cout << "Warning. Account is in the negative." << endl;
			}
			else {
				BankAccount::subtractBalance(15.00);
				cout << "Withdrawal was not made. Withdrawal amount $"<< subtract<< " was over balance amount.\n" << endl;
			}

		}
		else {
			BankAccount::withdraw(subtract);
		}

	}

	void monthlyProc() {
		double charge = 5 + (getWithdrawals()*.10);
		cout << "Monthly service charge is: $" << charge << endl;
		setServiceCharge(charge);
		BankAccount::monthlyProc();

	}
	void showAccount() {

		cout << "Checking Account" << endl;
		cout << "===================================" << endl;
		cout << "Balance: $" << getBalance() << endl;
		cout << "Withdrawals: " << getWithdrawals() << endl;
		cout << "Deposits: " << getMonthlyDeposits() << endl;
		cout << "Monthly Service Charge: $" << getServiceCharge() << endl;
		cout << "====================================\n\n" << endl;
	}

};

int main()
{
	double balance1, balance2;
	float interest = .0275f;


	cout << "Welcome to the Banking Simulator." << endl;
	cout << "The current interest rate is at 2.75%" << endl;
	cout << "Please enter the balance of your Savings account: $";
	cin >> balance1;
	cout << "Please enter the balance of your Checking account: $";
	cin >> balance2;

	SavingsAccount account1(balance1, interest);
	CheckingAccount account2(balance2, interest);
	cout << "Checking and Savings accounts created." << endl;
	int input1, input2;
	double moneyAmount;


	do {
		cout << "----------------------------------------" << endl;
		cout << "Account Options" << endl;
		cout << "==================" << endl;
		cout << "1.) Withdraw" << endl;
		cout << "2.) Deposit" << endl;
		cout << "3.) Monthly Service" << endl;
		cout << "4.) Exit" << endl;
		cout << "Please enter your choice: ";
		cin >> input1;

		switch (input1) {
		case 1:
			cout << "Withdraw Option selected." << endl;
			cout << "----------------------------------------" << endl;
			cout << "Account Selection." << endl;
			cout << "==================" << endl;
			cout << "1.) Savings Account" << endl;
			cout << "2.) Checking Account" << endl;
			cout << "Please enter which account by number: " << endl;
			cin >> input2;
			cout << "----------------------------------------" << endl;
			if (input2 == 1) {
				cout << "Savings Account selected." << endl;
				cout << "Please enter the amount to withdraw: ";
				cin >> moneyAmount;
				cout << "\nProcessing......" << endl;
				account1.withdraw(moneyAmount);
			}
			else if (input2 == 2) {
				cout << "Checking Account selected." << endl;
				cout << "Please enter the amount to withdraw: ";
				cin >> moneyAmount;
				cout << "\nProcessing......" << endl;
				account2.withdraw(moneyAmount);
			}
			else {
				cout << "Invalid input. You must enter either 1 or 2 for selecting the account." << endl;
			}
			break;
		case 2:
			cout << "Deposit Option selected." << endl;
			cout << "----------------------------------------" << endl;
			cout << "Account Selection." << endl;
			cout << "==================" << endl;
			cout << "1.) Savings Account" << endl;
			cout << "2.) Checking Account" << endl;
			cout << "Please enter which account by number: " << endl;
			cin >> input2;
			cout << "----------------------------------------" << endl;
			if (input2 == 1) {
				cout << "Savings Account selected." << endl;
				cout << "Please enter the amount to deposit: ";
				cin >> moneyAmount;
				cout << "\nProcessing......" << endl;
				account1.deposit(moneyAmount);
			}
			else if (input2 == 2) {
				cout << "Checking Account selected." << endl;
				cout << "Please enter the amount to deposit: ";
				cin >> moneyAmount;
				cout << "\nProcessing......" << endl;
				account2.deposit(moneyAmount);
			}
			else {
				cout << "Invalid input. You must enter either 1 or 2 for selecting the account." << endl;
			}
			break;
		case 3:
			cout << "Monthly Processing Option selected." << endl;
			cout << "----------------------------------------" << endl;
			cout << "Account Selection." << endl;
			cout << "==================" << endl;
			cout << "1.) Savings Account" << endl;
			cout << "2.) Checking Account" << endl;
			cout << "Please enter which account by number: " << endl;
			cin >> input2;
			cout << "----------------------------------------" << endl;
			if (input2 == 1) {
				cout << "Savings Account selected." << endl;
				account1.monthlyProc();
				cout << "\nProcessing......" << endl;
				account1.showAccount();
			}
			else if (input2 == 2) {
				cout << "Checking Account selected." << endl;
				account2.monthlyProc();
				cout << "\nProcessing......" << endl;
				account2.showAccount();
			}
			else {
				cout << "Invalid input. You must enter either 1 or 2 for selecting the account." << endl;
			}
			break;

		case 4:
			cout << "Exiting Program." << endl;
			exit(0);
			break;
		default:
			break;
		}

	} while (input1 != 4);

	return 0;
}