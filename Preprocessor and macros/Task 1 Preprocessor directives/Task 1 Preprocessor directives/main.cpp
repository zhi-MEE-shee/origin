#include <iostream>
#include <Windows.h>
#define MODE 1

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


#if !defined(MODE)
#error MODE is required!
#endif

#if MODE == 0
		cout << "������� � ������ ����������." << endl;
	
#elif MODE == 1
#define ADD(a, b) (a)+(b)
		cout << "������� � ������ ������." << endl;
		int a, b;
		cout << "������� ����� 1: ";
		cin >> a;
		cout << "������� ����� 2: ";
		cin >> b;
		cout << "��������� ��������: " << ADD(a, b) << endl;
#else
		cout << "����������� �����. ���������� ������." << endl;
#endif

	return 0;
}