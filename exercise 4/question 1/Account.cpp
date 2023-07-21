/*Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 4
The program manages bank accounts and deals with errors using exception (try & catch).*/

#include "Account.h"
#include <string>
#include <iostream>
using namespace std;

int Account::sumWithdraw = 0; //initiating the static values.
int Account::sumDeposit = 0;

Account::Account()
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	email = "";
}

Account::Account(int ac, int cod, string nail)
{
	accountNumber = ac;
	if (cod < 1000 || cod> 9999)
		throw "ERROR: code must be of 4 digits!\n";
	code = cod;
	if (nail.find("@") == string::npos)
		throw "ERROR: email must contain @!";
	if (nail.find(".com") == string::npos && nail.find(".co.il") == string::npos)
		throw "ERROR: email must end at .com or .co.il!";
	email = nail;
}

void Account::withdraw(int nis)
{
	if (balance - nis < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS\n";
	balance -= nis;
}

void Account::deposit(int chek)
{
	if (chek > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
	balance += chek;
}

istream& operator >> (istream& in, Account& a)
{
	in >> a.accountNumber >> a.code >> a.email;
	if (a.code < 1000 || a.code> 9999)
	{
		throw "ERROR: code must be of 4 digits!";
	}
	if (a.email.find("@") == string::npos)
		throw "ERROR: email must contain @!";
	if (a.email.find(".com") == string::npos && a.email.find(".co.il") == string::npos)
		throw "ERROR: email must end at .com or .co.il!";
	a.balance = 0;
	return in;
}