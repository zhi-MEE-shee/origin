#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

class Counter
{
private:
	int num;

public:
	Counter() {
		num = 0;
	}

	Counter( int num ) 
	{
		this->num = num;
	}

	int getNum() { return num; }
	void setNum(int num) {
		if (num > 0) { 
			this->num = num;
		}
	}
	int NumPlus() { return num++; }
	int NumMinus() { return num--; }


};

void check_answer(string answer,  Counter& counter ) {

	if (answer == "��") {
		int num;
		cout << "������� ��������� �������� ��������: ";
		cin >> num;
		counter.setNum(num);
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

