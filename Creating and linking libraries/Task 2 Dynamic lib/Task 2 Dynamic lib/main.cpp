#include "Farewell.h"
#include <Windows.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string user_name;
	Farewell::Leaver leaver;
	std::cout << "¬ведите им€: ";
	std::cin >> user_name;

	std::cout << leaver.leave(user_name);

	return 0;
}