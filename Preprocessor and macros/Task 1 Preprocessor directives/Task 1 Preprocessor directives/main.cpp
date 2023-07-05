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
		cout << "Работаю в режиме тренировки." << endl;
	
#elif MODE == 1
#define ADD(a, b) (a)+(b)
		cout << "Работаю в боевом режиме." << endl;
		int a, b;
		cout << "Введите число 1: ";
		cin >> a;
		cout << "Введите число 2: ";
		cin >> b;
		cout << "Результат сложения: " << ADD(a, b) << endl;
#else
		cout << "Неизвестный режим. Завершение работы." << endl;
#endif

	return 0;
}