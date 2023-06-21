#include <iostream>
using namespace std;

class Calculator
{
private:
	double num1;
	double num2;

public:

	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else

			cout << "Неверный ввод!\n";
			return false;
	}

	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else
			cout << "Неверный ввод!\n";
			return false;
	}

	double add() { return num1 + num2; }
	double multiply() { return num1 * num2; }
	double subtract_1_2() { return num1 - num2; }
	double subtract_2_1() { return num2 - num1; }
	double divide_1_2() { return num1 / num2; }
	double divide_2_1() { return num2 / num1; }

};

void print_Calc(Calculator& num3) {

	cout << "num1 + num2 = " << num3.add() << endl;
	cout << "num1 - num2 = " << num3.subtract_1_2() << endl;
	cout << "num2 - num1 = " << num3.subtract_2_1() << endl;
	cout << "num1 * num2 = " << num3.multiply() << endl;
	cout << "num1 / num2 = " << num3.divide_1_2() << endl;
	cout << "num2 / num2 = " << num3.divide_2_1() << endl;

}

void asking_for_nums(int& x, int& y, Calculator& pair) {

	do
	{
		cout << "Введите num1: ";
		cin >> x;

	} while (pair.set_num1(x) == false);
	
	do
	{
		cout << "Введите num2: ";
		cin >> y;

	} while (pair.set_num2(y) == false);

	print_Calc(pair);

	asking_for_nums(x, y, pair);
}



int main() {

	setlocale(LC_ALL, "Russian");


	Calculator pair;

	while (1) {

		int x{};
		int y{};
		asking_for_nums(x, y, pair);

	}

	return 0;
}