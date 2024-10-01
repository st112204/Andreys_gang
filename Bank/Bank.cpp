#include <string>
#include <iostream>

class BankAccount
{

private:
	
	std::string accountNubmer;
	double balance;
	std::string accountHolder;

public:

	BankAccount()
	{
		accountNubmer = "";
		balance = 0;
		accountHolder = "";
	}

	BankAccount(std::string number, double balance, std::string holder)
	{
		this->accountNubmer = number;
		this->balance = balance;
		this->accountHolder = holder;
	}

	~BankAccount() {};

	void Deposit(double amount)
	{
		balance += amount;
		return;
	}

	void Withdraw(double amount)
	{
		if (balance < amount)
		{
			std::cout << "The balance of account number " << accountNubmer << " is " << balance << ",\n"
				<< "which is not enough to withdraw " << amount << "\n\n";
		}
		else
		{
			balance -= amount;
			return;
		}
	}

	std::string GetAccountNumber()
	{
		return accountNubmer;
	}

	double GetBalance()
	{
		return balance;
	}

	std::string GetAccountHolder()
	{
		return accountHolder;
	}

	void PrintAccountInfo()
	{
		std::cout
			<< "Number: " << accountNubmer << "\n"
			<< "Balance: " << balance << "\n"
			<< "Holder: " << accountHolder << "\n\n";
	}

	BankAccount& operator=(const BankAccount& b)
	{
		if (this != &b)
		{
			accountNubmer = b.accountNubmer;
			balance = b.balance;
			accountHolder = b.accountHolder;
		}

		return *this;
	}
};

class Bank
{

private:

	BankAccount** accounts;
	int size;

public:

	Bank()
	{
		accounts = nullptr;
		size = 0;
	}

	~Bank()
	{
		delete[] accounts;
	}

	void AddAccount(BankAccount& account)
	{

		BankAccount** newAccounts = new BankAccount*[size + 1];
		for (int i = 0; i < size; ++i)
		{
			*(newAccounts + i) = *(accounts + i);
		}

		delete[] accounts;
		accounts = newAccounts;

		*(accounts + size) = &account;

		++size;

		return;
	}

	double GetTotalBalance()
	{
		double totalBalance = 0;

		for (int i = 0; i < size; ++i)
		{
			totalBalance += (**(accounts + i)).GetBalance();
		}

		return totalBalance;
	}

	void PrintAllAccounts()
	{
		std::cout << "All accounts : \n\n";

		for (int i = 0; i < size; ++i)
			(**(accounts + i)).PrintAccountInfo();

		return;
	}
};


int main()
{
	// создайте несколько объектов класса `BankAccount`

	BankAccount A("1", 100.11, "Aaa");
	BankAccount B("2", 100.11, "Bbb");
	BankAccount C("3", 100.11, "Ccc");

	// добавьте их в объект класса `Bank`

	Bank myBank;

	myBank.AddAccount(A);
	myBank.AddAccount(B);
	myBank.AddAccount(C);

	// выполните различные операции с счетами, такие как депозит и снятие средств
	
	A.Deposit(1000.1);
	B.Withdraw(50.1);
	C.Withdraw(200.1);

	// выведите информацию обо всех счетах и общий баланс

	myBank.PrintAllAccounts();
	std::cout << "Total balance: " << myBank.GetTotalBalance() << "\n\n";

	return 0;
}
