#include "interface.h"

void num_asking_func(int& a, int& b) {

	cout << "������� ������ �����: " << endl;
	cin >> a;
	cout << "������� ������ �����: " << endl;
	cin >> b;
}

void output_menu(int& a, int& b) {

	int num{ 0 };
	cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
	cin >> num;

	switch (num) {
		case 1: 
			cout << a << " ���� " << b << " = " << sum(a, b) << endl; break;
		case 2: 
			cout << a << " ����� " << b << " = " << diff(a, b) << endl; break;
		case 3:
			cout << a << " ���������� �� " << b << " = " << multi(a, b) << endl; break;
		case 4:
			cout << a << " �������� �� " << b << " = " << divi(a, b) << endl; break;
		case 5:
			cout << a << " � ������� " << b << " = " << expo(a, b) << endl; break;
	}
};