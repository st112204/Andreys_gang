#pragma once

#include <string>
#include <iostream>

class BankAccount
{

private:

	std::string accountNubmer;
	double balance;
	std::string accountHolder;

public:

	BankAccount();

	BankAccount(std::string number, double balance, std::string holder);

	~BankAccount();

	void Deposit(double amount);

	void Withdraw(double amount);

	std::string GetAccountNumber();

	double GetBalance();

	std::string GetAccountHolder();

	void PrintAccountInfo();

	BankAccount& operator=(const BankAccount& b);
};

class Bank
{

private:

	BankAccount** accounts;
	int size;

public:

	Bank();

	~Bank();

	void AddAccount(BankAccount& account);

	double GetTotalBalance();

	void PrintTotalBalance();

	void PrintAllAccounts();
};