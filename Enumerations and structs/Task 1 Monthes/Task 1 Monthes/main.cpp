#include <iostream>

using namespace std;

enum Monthes {

	������ = 1,
	�������,
	����,
	������,
	���,
	����,
	����,
	������,
	��������,
	�������,
	������,
	�������

};

// ������� ������� ����������� ���������� ���� ������
int print_month_num(int user_num) {


		switch (user_num) {

		case 0:
			 break;
		case 1:
			cout << "������" << endl; break;
		case 2: 
			cout << "�������" << endl;  break;
		case 3:
			cout << "����" << endl; break;
		case 4:
			cout << "������" << endl;  break;
		case 5:
			cout << "���" << endl;  break;
		case 6:
			cout << "����" << endl;  break;
		case 7:
			cout << "����" << endl;  break;
		case 8:
			cout << "������" << endl;  break;
		case 9:
			cout << "��������" << endl;  break;
		case 10:
			cout << "�������" << endl;  break;
		case 11:
			cout << "������" << endl;  break;
		case 12:
			cout << "�������" << endl;  break;
		default:
			cout << "������������ �����!" << endl; break;
		}
		return user_num;
}

void check_month() {

	int user_month{};
	cout << "������� ����� ������: ";
	cin >> user_month;

	Monthes month = { static_cast<Monthes>(user_month) };

	if (print_month_num(month) != 0) {
		check_month();
	}
	else {
		cout << "�� ��������!";
	}
}


int main() {

	setlocale(LC_ALL, "Russian");

	check_month();

	return 0;
}