#include "interface.h"
#include <Windows.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a{ 0 };
	int b{ 0 };

	num_asking_func(a, b);

	output_menu(a, b);

	return 0;
}