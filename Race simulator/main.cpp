#include"boots.h"
#include"broom.h"
#include"camel.h"
#include"carpet.h"
#include"centaur.h"
#include"eagle.h"
#include"speed_camel.h"
#include<thread>
#include<iostream>
#include<Windows.h>

void print_main_menu() {
	std::cout << "1. ����� ��� ��������� ����������" << std::endl
			  << "2. ����� ��� ���������� ����������" << std::endl
			  << "3. ����� ��� ��������� � ���������� ����������" << std::endl
			  << "�������� ��� �����: ";
}

int race_aprooving() {
	int tmp {};
	print_main_menu();
	std::cin >> tmp;
	if (tmp <= 0 || tmp > 3) {
		std::cout << "��������� ��� ����� �����������!" << std::endl;
		return race_aprooving();
	}
	else
		return tmp;
}



double* create_race (int& choosing_race, int& size, std::string& name) {

	switch (choosing_race) {
		case 1: 
			size = 4;
			name = "����� ��� ��������� ����������. ";
			break;
		case 2:
			size = 3; 
			name = "����� ��� ���������� ����������. ";
			break;
		case 3: 
			size = 7; 
			name = "����� ��� ��������� � ���������� ����������. ";
			break;
	}
	double* tmp = new double [size] {};
		
	return tmp;
}

void delete_racers_names (std::string* race_members) {
	delete[] race_members;
}
void delete_race(double* race) {
	delete[] race;
}

int distance_aprooving() {
	int tmp {};
	std::cout << "������� ����� ���������: ";
	std::cin >> tmp;
	if (tmp <= 0) {
		std::cout << "�������� �������� ������ ���� ������������� ���������!" << std::endl;
		return distance_aprooving();
	}
	else {
		return tmp;
	}
}

bool isRegistered(std::string* race_members, std::string* vehicles_names, int& last_picked, int& vehicles_count) {

	if (vehicles_count >= 1) {
		for (int i = 0; i < vehicles_count; ++i) {
			if (race_members[i] == vehicles_names[last_picked]) {
				std::cout << "������������ �������� (" << race_members[i] << ") ��� ����������������!" << std::endl;
				return true;
			}
		}
	}
	return false;
}




void check_last_picked(double* race, std::string* race_members, int& last_picked, int& vehicles_count,
					const int& choosing_race, const int& race_distance) {
	

	if (choosing_race == 1) {
		if (last_picked == 1) {
			Boots* boots = new Boots();
			race_members[vehicles_count] = boots->getRace_name();
			race[vehicles_count] = boots->getFull_race_time(race_distance);

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else if (last_picked == 3) {
			Camel* camel = new Camel();
			race_members[vehicles_count] = camel->getRace_name();
			race[vehicles_count] = camel ->getFull_race_time(race_distance);

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else if (last_picked == 4) {
			Centaur* centaur = new Centaur();
			race_members[vehicles_count] = centaur->getRace_name();
			race[vehicles_count] = centaur->getFull_race_time(race_distance);

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else if (last_picked == 6) {
			Speed_camel* sCamel = new Speed_camel();                               // oh my, poor scamel!
			race_members[vehicles_count] = sCamel->getRace_name();
			race[vehicles_count] = sCamel->getFull_race_time(race_distance);

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else {
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
		}
			
	}
	else if (choosing_race == 2) {
		if (last_picked == 2) {
			Broom* broom = new Broom();
			race_members[vehicles_count] = broom->getRace_name();
			race[vehicles_count] = broom->getFull_race_time(race_distance);

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else if (last_picked == 5) {
			Eagle* eagle = new Eagle();
			race_members[vehicles_count] = eagle->getRace_name();
			race[vehicles_count] = eagle->getFull_race_time(race_distance);	

			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else if (last_picked == 7) {
			Carpet* carpet = new Carpet();
			race_members[vehicles_count] = carpet->getRace_name();
			race[vehicles_count] = carpet->getFull_race_time(race_distance);


			std::cout << "������������ �������� (" << race_members[vehicles_count] << ") ������� ����������������!" << std::endl;
			++vehicles_count;
		}
		else {
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
		}
		
	}
}
	

void sorting(double* race, std::string* race_members, const int& vehicles_count) {


	for (int i = 0; i < vehicles_count; ++i) {
		for (int j = vehicles_count - 1; j >= 0 ; j--) {
			if (race[j] > race[j - 1]) {
				double tmp = race[j];
				race[j] = race[j + 1];
				race[j + 1] = tmp;

				std::string sTmp = race_members[j];
				race_members[j] = race_members[j - 1];
				race_members[j + 1] = sTmp;

			}
		}
	}
}


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������ ��� ������ � ����
	std::string* vehicles_names = new std::string[8]{ "non", "������� - ���������",
													  "�����", "�������", "�������",
													  "���", "�������-���������",
													  "����-������" };


	std::cout << "����� ���������� � �������� ���������!" << std::endl;
	int exit{ 0 };
	while (exit != 2) {

		int choosing_race{ race_aprooving() };
		int size{ 0 };
		std::string race_name;
		double* race{ create_race(choosing_race, size, race_name) };
		std::string* race_members = new std::string[size]{};

		int race_distance{ distance_aprooving() };
		system("cls");

		int mode{ 0 };            // ���������� ��� ������ ���������� ��� ������ �����
		int vehicles_count{ 0 };  // ���������� ��� ����� ������������������ �� ����� ����������
		int last_picked{ 0 };       // ��������� ��������� ��������

		do {
			if (vehicles_count < 2) {
				std::cout << "������ ���� ����������������� ���� �� 2 ������������ ��������." << std::endl;
				std::cout << "1. ���������������� ���������\n";
			}
			else {
				std::cout << "1. ���������������� ���������\n2. ������ �����\n";
			}
			std::cout << "�������� ��������: ";
			std::cin >> mode;


			if (mode < 1 && mode > 2) {
				std::cout << "���������� �������� ��� � ����." << std::endl;
			}
			else if (mode == 1) {

				system("cls");
				std::cout << race_name << "���������: " << race_distance << std::endl;

				if (vehicles_count >= 1) {
					std::cout << "������� ������������������ ������������ ��������: ";
					for (int i = 0; i < vehicles_count; ++i) {
						std::cout << race_members[i] << " ";
					}
					std::cout << std::endl;
				}
				//����� ���� ��������� ������������ �������
				for (int i = 1; i < 8; ++i) {
					std::cout << i << ". " << vehicles_names[i] << std::endl;
				}
				std::cout << "0. ��������� �����������\n";
				std::cout << "�������� ��������� ��� 0 ��� ��������� �����������: ";
				std::cin >> last_picked;
				if (last_picked != 0) {
					if (!isRegistered(race_members, vehicles_names, last_picked, vehicles_count)) {
						check_last_picked(race, race_members, last_picked, vehicles_count, choosing_race, race_distance);
						if (vehicles_count == size) {
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
							std::cout << "��� ��� ���! ��� ��������� ������ ���� �����, � ������ �� ������������� ��������� � ������ �����!" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(1000));
							mode = 2;
						}
					}
				}
				else if (last_picked == 0){
					if (vehicles_count < 2) {
						std::cout << "���������� ����� ������������! ��������� � ���� ����������� ����������." << std::endl;
						break;
					}
					else {
						mode = 2;
					}
				}

			}
			if (mode == 2) {
				if (vehicles_count < 2) {
					std::cout << "���������� ����� ������������! ��������� � ���� ����������� ����������." << std::endl;
					mode = 0;
				}
				else {
					sorting(race, race_members, vehicles_count);
				}
			}

		} while (mode != 2);

		system("cls");
		std::cout << "���������� �����: " << std::endl;

		for (int i = 0; i < vehicles_count; ++i) {
			std::cout << i + 1 << ". " << race_members[i] << ". �����: " << race[i] << std::endl;
		}


		std::cout << std::endl 
			<< 1 << ". �������� ��� ���� �����" << std::endl
			<< 2 << ". �����" << std::endl;

		std::cin >> exit;

		delete[] race;
		delete[] race_members;
		size = 0;
		race_name = {};
	}

	return 0;
}


/*

/*


*/

