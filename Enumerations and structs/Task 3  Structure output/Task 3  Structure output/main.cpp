#include <iostream>
#include <string>
using namespace std;

struct AdressInfo {

	string city;
	string street;
	int house_num;
	int àpartment_num;
	int index_num;

};

void adress_printing(const AdressInfo& adress) {

	cout << "Ãîðîä: " << adress.city << endl
		 << "Óëèöà: " << adress.street << endl
		 << "Íîìåð äîìà: " << adress.house_num << endl
		 << "Íîìåð êâàðòèðû: " << adress.àpartment_num << endl
		 << "Èíäåêñ: " << adress.index_num << endl << endl;

}


int main() {

	setlocale(LC_ALL, "Russian");

	AdressInfo adress1{ "Ìîñêâà", "Àðáàò", 12, 8, 123456 };
	AdressInfo adress2;
	adress2.city = "Èæåâñê";
	adress2.street = "Ãåðöèíà";
	adress2.house_num = 32;
	adress2.àpartment_num = 15;
	adress2.index_num = 169306;

	adress_printing(adress1);
	adress_printing(adress2);

	return 0;
}