#include <iostream>
#include <exception>
#include<Windows.h>
using namespace std;

int function(string str, int forbidden_length) {
	if (str.length() != forbidden_length) {
		return str.length();
	}
	throw "bad_length";
}


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbidden_length{ 0 };
	string user_word;
	
	cout << "������� ��������� �����: ";
	cin >> forbidden_length;

	do {
		cout << "������� �����: ";
		cin >> user_word;

		try {
			int length{ function(user_word, forbidden_length) };
			cout << "����� ����� \"" << user_word << "\" ����� " << length << endl;
		}
		catch (const char* exit_condition) {
			cout << "�� ����� ����� ��������� �����! �� ��������!" << endl;
		}
	} while (user_word.length() != forbidden_length);
	
return 0;
}