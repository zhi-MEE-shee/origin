#include <iostream>
#include "Greeter.h"
#include <Windows.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string user_name;
	Greeter greet;
	std::cout << "¬ведите им€: ";
	std::cin >> user_name;

	std::cout << greet.greet(user_name);

	return 0;
}