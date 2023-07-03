#include "interface.h"

void num_asking_func(int& a, int& b) {

	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второй число: " << endl;
	cin >> b;
}

void output_menu(int& a, int& b) {

	int num{ 0 };
	cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	cin >> num;

	switch (num) {
		case 1: 
			cout << a << " плюс " << b << " = " << sum(a, b) << endl; break;
		case 2: 
			cout << a << " минус " << b << " = " << diff(a, b) << endl; break;
		case 3:
			cout << a << " умноженное на " << b << " = " << multi(a, b) << endl; break;
		case 4:
			cout << a << " деленное на " << b << " = " << divi(a, b) << endl; break;
		case 5:
			cout << a << " в степени " << b << " = " << expo(a, b) << endl; break;
	}
};