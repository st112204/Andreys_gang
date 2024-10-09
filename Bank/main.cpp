#include "bank.h"

int main()
{
	// �������� ��������� �������� ������ `BankAccount`

	BankAccount A("1", 100.11, "Aaa");
	BankAccount B("2", 100.11, "Bbb");
	BankAccount C("3", 100.11, "Ccc");

	// �������� �� � ������ ������ `Bank`

	Bank myBank;

	myBank.AddAccount(A);
	myBank.AddAccount(B);
	myBank.AddAccount(C);

	// ��������� ��������� �������� � �������, ����� ��� ������� � ������ �������

	A.Deposit(1000.1);
	B.Withdraw(50.1);

	C.Withdraw(200.1);
	
	A.Deposit(-1);
	B.Withdraw(-1);

	// �������� ���������� ��� ���� ������ � ����� ������

	myBank.PrintAllAccounts();
	myBank.PrintTotalBalance();

	return 0;
}