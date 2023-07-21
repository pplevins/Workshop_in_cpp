/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 4
The program manages bank accounts and deals with errors using exception (try & catch).*/

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Account
{
	int accountNumber;
	int code;
	float balance = 0;
	string email;

public:
	static int sumWithdraw;
	static int sumDeposit;
	Account();
	Account(int, int, string);
	int getAccountNumber() { return accountNumber; }
	int getCode() { return code; }
	float getBalance() { return balance; }
	string getEmail() { return email; }
	void withdraw(int);
	void deposit(int);
	static int getSumWithdraw() { return sumWithdraw; }
	static int getSumDeposit() { return sumDeposit; }
	friend istream& operator >> (istream& in, Account& a);
};