#include <iostream>
#include <string>
using namespace std;

struct AdressInfo {

	string city;
	string street;
	int house_num;
	int �partment_num;
	int index_num;

};

void adress_printing(const AdressInfo& adress) {

	cout << "�����: " << adress.city << endl
		 << "�����: " << adress.street << endl
		 << "����� ����: " << adress.house_num << endl
		 << "����� ��������: " << adress.�partment_num << endl
		 << "������: " << adress.index_num << endl << endl;

}


int main() {

	setlocale(LC_ALL, "Russian");

	AdressInfo adress1{ "������", "�����", 12, 8, 123456 };
	AdressInfo adress2;
	adress2.city = "������";
	adress2.street = "�������";
	adress2.house_num = 32;
	adress2.�partment_num = 15;
	adress2.index_num = 169306;

	adress_printing(adress1);
	adress_printing(adress2);

	return 0;
}