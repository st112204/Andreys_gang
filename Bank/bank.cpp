#include "bank.h"

// BankAccount

	BankAccount::BankAccount()
	{
		accountNubmer = "";
		balance = 0;
		accountHolder = "";

		std::cout << "Default bank account CREATED" << "\n\n";
	}

	BankAccount::BankAccount(std::string number, double balance, std::string holder)
	{
		this->accountNubmer = number;
		this->balance = balance;
		this->accountHolder = holder;

		std::cout << "Bank account CREATED" << "\n";
		PrintAccountInfo();
	}

	BankAccount::~BankAccount() {};

	void BankAccount::Deposit(double amount)
	{
		if (amount >= 0)
		{
			balance += amount;
			std::cout
				<< "Account #" << this->accountNubmer << "\n"
				<< "Success deposit: " << amount << "\n\n";
		}
		else
		{
			std::cout
				<< "Account #" << this->accountNubmer << "\n"
				<< "Error: deposit should be positive" << "\n\n";
		}

		return;
	}

	void BankAccount::Withdraw(double amount)
	{
		if (amount >= 0)
		{
			if (balance < amount)
			{
				std::cout
					<< "Account #" << this->accountNubmer << "\n"
					<< "Balance: " << this->balance << "\n"
					<< "Not enough to withdraw: " << amount << "\n\n";
			}
			else
			{
				balance -= amount;
				std::cout
					<< "Account #" << this->accountNubmer << "\n"
					<< "Success withdrawal: " << amount << "\n\n";
			}
		}
		else
		{
			std::cout
				<< "Account #" << this->accountNubmer << "\n"
				<< "Error: withdrawal should be positive" << "\n\n";
		}

		return;
	}

	std::string BankAccount::GetAccountNumber()
	{
		return accountNubmer;
	}

	double BankAccount::GetBalance()
	{
		return balance;
	}

	std::string BankAccount::GetAccountHolder()
	{
		return accountHolder;
	}

	void BankAccount::PrintAccountInfo()
	{
		std::cout
			<< "Number: " << accountNubmer << "\n"
			<< "Balance: " << balance << "\n"
			<< "Holder: " << accountHolder << "\n\n";
	}

	BankAccount& BankAccount::operator=(const BankAccount& b)
	{
		if (this != &b)
		{
			accountNubmer = b.accountNubmer;
			balance = b.balance;
			accountHolder = b.accountHolder;
		}

		return *this;
	}


// Bank

Bank::Bank()
{
	accounts = nullptr;
	size = 0;

	std::cout << "Bank CREATED" << "\n\n";
}

Bank::~Bank()
{
	delete[] accounts;
}

void Bank::AddAccount(BankAccount& account)
{

	BankAccount** newAccounts = new BankAccount * [size + 1];
	for (int i = 0; i < size; ++i)
	{
		*(newAccounts + i) = *(accounts + i);
	}

	delete[] accounts;
	accounts = newAccounts;

	*(accounts + size) = &account;

	++size;

	std::cout
		<< "Account #" << account.GetAccountNumber() << "\n"
		<< "ADDED to bank" << "\n\n";

	return;
}

double Bank::GetTotalBalance()
{
	double totalBalance = 0;

	for (int i = 0; i < size; ++i)
	{
		totalBalance += (**(accounts + i)).GetBalance();
	}

	return totalBalance;
}

void Bank::PrintTotalBalance()
{
	std::cout
		<< "TOTAL BALANCE: " << GetTotalBalance() << "\n\n";
}

void Bank::PrintAllAccounts()
{
	std::cout
		<< "------------------" << "\n\n"
		<< "ALL ACCOUNTS :" << "\n\n";

	for (int i = 0; i < size; ++i)
		(**(accounts + i)).PrintAccountInfo();

	std::cout
		<< "------------------" << "\n\n";

	return;

}