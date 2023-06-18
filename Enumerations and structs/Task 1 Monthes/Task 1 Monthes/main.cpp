#include <iostream>

using namespace std;

enum Monthes {

	январь = 1,
	февраль,
	март,
	апрель,
	май,
	июнь,
	июль,
	август,
	сентябрь,
	октябрь,
	ноябрь,
	декабрь

};

// функция которая запрашивает рекурсивно ввод месяца
int print_month_num(int user_num) {


		switch (user_num) {

		case 0:
			 break;
		case 1:
			cout << "Январь" << endl; break;
		case 2: 
			cout << "Февраль" << endl;  break;
		case 3:
			cout << "Март" << endl; break;
		case 4:
			cout << "Апрель" << endl;  break;
		case 5:
			cout << "Май" << endl;  break;
		case 6:
			cout << "Июнь" << endl;  break;
		case 7:
			cout << "Июль" << endl;  break;
		case 8:
			cout << "Август" << endl;  break;
		case 9:
			cout << "Сентябрь" << endl;  break;
		case 10:
			cout << "Октябрь" << endl;  break;
		case 11:
			cout << "Ноябрь" << endl;  break;
		case 12:
			cout << "Декабрь" << endl;  break;
		default:
			cout << "Неправильный номер!" << endl; break;
		}
		return user_num;
}

void check_month() {

	int user_month{};
	cout << "Введите номер месяца: ";
	cin >> user_month;

	Monthes month = { static_cast<Monthes>(user_month) };

	if (print_month_num(month) != 0) {
		check_month();
	}
	else {
		cout << "До свиданья!";
	}
}


int main() {

	setlocale(LC_ALL, "Russian");

	check_month();

	return 0;
}