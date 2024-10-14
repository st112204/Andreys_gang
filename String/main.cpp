#include "string.h"

int main()
{
	String const hello("hello");
	std::cout << "\"hello\" : ";
	hello.output();

	String const hello2 = hello[0][5];
	std::cout << "\"hello\" : ";
	hello2.output();

	String const hello3 = hello[0][9];
	std::cout << "\"hello\" : ";
	hello3.output();

	String const hell = hello[0][4];
	std::cout << "\"hell\" : ";
	hell.output();

	String const ell = hello[1][4];
	std::cout << "\"ell\" : ";
	ell.output();

	String empty;
	std::cout << "\"\" : ";
	empty.output();

	String const empty2 = hello[2][2];
	std::cout << "\"\" : ";
	empty2.output();

	String const empty3 = hello[4][2];
	std::cout << "\"\" : ";
	empty3.output();

	return 0;
}