#include "bank.h"

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
	
	A.Deposit(-1);
	B.Withdraw(-1);

	// выведите информацию обо всех счетах и общий баланс

	myBank.PrintAllAccounts();
	myBank.PrintTotalBalance();

	return 0;
}