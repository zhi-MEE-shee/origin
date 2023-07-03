#include <iostream>
#include "counter.h"
#include <string>
#include<Windows.h>
using namespace std;


void check_answer(string answer, Counter& counter) {

	if (answer == "��") {
		int num;
		cout << "������� ��������� �������� ��������: ";
		cin >> num;
		counter = Counter(num);
	}
}

int contine_counting(string sign, Counter& counter) {

	cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
	cin >> sign;
	if (sign == "+") {
		counter.NumPlus();
	}
	else if (sign == "-") {
		counter.NumMinus();
	}
	else if (sign == "=") {
		cout << counter.getNum() << endl;
	}
	else if (sign == "�" || sign == "x") {
		cout << "�� ��������!";
		return 0;
	}
	contine_counting(sign, counter);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Counter counter;

	string answer;
	cout << "�� ������ ������� ��������� �������� �������� ? ������� �� ��� ��� : ";
	cin >> answer;
	check_answer(answer, counter);

	string sign;
	contine_counting(sign, counter);

	return 0;
}