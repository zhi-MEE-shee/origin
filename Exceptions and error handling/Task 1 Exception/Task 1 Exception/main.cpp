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
	
	cout << "Введите запретную длину: ";
	cin >> forbidden_length;

	do {
		cout << "Введите слово: ";
		cin >> user_word;

		try {
			int length{ function(user_word, forbidden_length) };
			cout << "Длина слова \"" << user_word << "\" равна " << length << endl;
		}
		catch (const char* exit_condition) {
			cout << "Вы ввели слово запретной длины! До свидания!" << endl;
		}
	} while (user_word.length() != forbidden_length);
	
return 0;
}