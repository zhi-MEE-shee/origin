#include <fstream>
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

class Adresses
{
private:
	string city;
	string street;
	int house_num;
	int appartmnt_num;

public:
	Adresses(string city = "some", string street = "some", int house_num = 0, int appartmnt_num = 0)
	{
		this->city = city;
		this->street = street;
		this->house_num = house_num;
		this->appartmnt_num = appartmnt_num;
	}

	string stringToFile() {

		string to_output_file = city + ", " + street + ", " + to_string(house_num) + ", " + to_string(appartmnt_num);
		return to_output_file;
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file_to_read("in.txt");

	int size{};
	file_to_read >> size;

	string tmp_city;
	string tmp_street;
	int tmp_house_num;
	int tmp_appartmnt_num;

	Adresses* adress = new Adresses[size];

	for (int i = 0; i < size; ++i) {

		file_to_read >> tmp_city >> tmp_street >> tmp_house_num >> tmp_appartmnt_num;

		adress[i] = Adresses(tmp_city, tmp_street, tmp_house_num, tmp_appartmnt_num);
	}

	file_to_read.close();

	ofstream file_to_write_in("out.txt");

	file_to_write_in << size << endl;

	for (int i = size - 1; i >= 0; --i) {

		file_to_write_in << adress[i].stringToFile() << endl;

	}

	file_to_write_in.close();

	delete[] adress;
	return 0;
}