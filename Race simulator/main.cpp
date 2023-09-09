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

struct race {

	std::string name;
	double result{ 0.0 };
};



void print_main_menu() {
	std::cout << "1. Гонка для наземного транспорта" << std::endl
			  << "2. Гонка для воздушного транспорта" << std::endl
			  << "3. Гонка для наземного и воздушного транспорта" << std::endl
			  << "Выберите тип гонки: ";
}

int race_aprooving() {
	int tmp {};
	print_main_menu();
	std::cin >> tmp;
	if (tmp <= 0 || tmp > 3) {
		std::cout << "Указанный тип гонки отсутвтвует!" << std::endl;
		return race_aprooving();
	}
	else
		return tmp;
}

Vehicles** create_race (int& race_type, int& size, std::string& name, Vehicles_type& type) {

	switch (race_type) {
	case 1: {
		size = 4;
		name = "Гонка для наземного транспорта. ";
		type = Vehicles_type::Ground;
		break; }
	case 2: {
		size = 3;
		name = "Гонка для воздушного транспорта. ";
		type = Vehicles_type::Air;
		break; }
	case 3: {
		size = 7;
		name = "Гонка для наземного и воздушного транспорта. ";
		break; }
	}
		
	return new Vehicles* [size] {};
}

void delete_race(Vehicles** race, const int& size) {

	for (int i = 0; i < size; ++i) {
		delete race[i];
	}
	delete[] race;
}

int distance_aprooving() {
	int tmp {};
	std::cout << "Укажите длину дистанции: ";
	std::cin >> tmp;
	if (tmp <= 0) {
		std::cout << "Вводимое значение должно быть положительной величиной!" << std::endl;
		return distance_aprooving();
	}
	else {
		return tmp;
	}
}

void print_rMembers(Vehicles** race_members, const int& vehicles_count) {
	if (vehicles_count >= 1) {
		std::cout << "Успешно зарегистрированные транспортные средства: ";
		for (int i = 0; i < vehicles_count; ++i) {
			std::cout << race_members[i]->getRace_name() << " ";
		}
		std::cout << std::endl;
	}
}

bool isRegistered(Vehicles** all_vehicles, Vehicles** race_members, const int& last_picked, int& vehicles_count) {

	if (vehicles_count >= 1) {
		for (int i = 0; i < vehicles_count; ++i) {
			 
			if (race_members[i] != all_vehicles[last_picked - 1]) {
					continue;
			}
			else
				std::cout << "Транспортное средство (" << race_members[i]->getRace_name() << ") " <<
				"не может быть зарегистрировано повторно!" << std::endl;
				return true;
			
		}
	}
	return false;
}

void registration(Vehicles** all_vehicles, Vehicles** race_members, const int& last_picked, int& vehicles_count, const int& size) {
	
	switch (last_picked) {
		case 1: {
			race_members[vehicles_count] = all_vehicles[0]; break;
		}
		case 2: {
			race_members[vehicles_count] = all_vehicles[1]; break;
		}
		case 3: {
			race_members[vehicles_count] = all_vehicles[2]; break;
		}
		case 4: {
			race_members[vehicles_count] = all_vehicles[3]; break;
		}
		case 5: {
			race_members[vehicles_count] = all_vehicles[4]; break;
		}
		case 6: {
			race_members[vehicles_count] = all_vehicles[5]; break;
		}
		case 7: {
			race_members[vehicles_count] = all_vehicles[6]; break;
		}
	}

	std::cout << "Транспортное средство (" << race_members[vehicles_count]->getRace_name() << ") успешно зарегистрировано!" << std::endl;
	if (vehicles_count <= size) {
		++vehicles_count;
	}
	

}
	

void sorting(struct race* racer, const int& vehicles_count) {


	for (int i = 0; i < vehicles_count; ++i) {
		for (int j = 0; j < vehicles_count - i - 1; j++) {
			if (racer[j].result > racer[j + 1].result) {
				
				race tmp = racer[j];
				racer[j] = racer[j + 1];
				racer[j + 1] = tmp;

			}
		}
	}
}


int main() {
	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//массив для вывода меню
	const int m_size = { 7 };
	Vehicles** all_vehicles = new Vehicles* [m_size] {};
	all_vehicles[0] = new Boots();
	all_vehicles[1] = new Broom();
	all_vehicles[2] = new Camel();
	all_vehicles[3] = new Centaur();
	all_vehicles[4] = new Eagle();
	all_vehicles[5] = new Speed_camel();
	all_vehicles[6] = new Carpet();
	
	
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

	int exit{ 0 };
	while (exit != 2) {


		Vehicles_type type;
		int race_type{ race_aprooving() };
		int size{ 0 };
		std::string race_name;
		Vehicles** race_members{ create_race(race_type, size, race_name, type) };
		

		int race_distance{ distance_aprooving() };
		system("cls");

		int mode{ 0 };            // переменная для выбора транспорта или старта гонки
		int vehicles_count{ 0 };  // переменная для счета зарегистрированных на гонку участников
		int last_picked{ 0 };       // последний выбранный участник

		do {
			if (vehicles_count < 2) {
				std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства." << std::endl;
				std::cout << "1. Зарегистрировать транспорт\n";
			}
			else {
				std::cout << "1. Зарегистрировать транспорт\n2. Начать гонку\n";
			}
			std::cout << "Выберите действие: ";
			std::cin >> mode;


			switch (mode) {
				case 1: {

					system("cls");
					std::cout << race_name << "Растояние: " << race_distance << std::endl;

					print_rMembers(race_members, vehicles_count);
					
					//вывод всех возможных транспортных средств
						for (int i = 0; i < m_size; ++i) {
							std::cout << i + 1 << ". " << all_vehicles[i]->getRace_name() << std::endl;
						}
					std::cout << "0. Закончить регистрацию\n";
					std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
					std::cin >> last_picked;
					if (last_picked != 0) {
						if (!isRegistered(all_vehicles, race_members, last_picked, vehicles_count)) {

							Vehicles_type checked_type;
							checked_type = all_vehicles[last_picked - 1]->getRace_type();

							if (race_type == 3) {
								registration(all_vehicles, race_members, last_picked, vehicles_count, size);
							}
							else if (type == checked_type) {
								registration(all_vehicles, race_members, last_picked, vehicles_count, size);
							}
							else {
								std::cout << "Попытка зарегистрировать неподходящий тип транспортного средства!" << std::endl;
							}
						}
						if (vehicles_count == size) {
							std::this_thread::sleep_for(std::chrono::milliseconds(1000));
							std::cout << "Пам пам пам! Все участники заняли свои места, а потому мы принудительно переходим к началу гонок!" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(3000));
							mode = 2;
						}
					}
					else if (last_picked == 0) {
						if (vehicles_count < 2) {
							std::cout << "Участников гонки недостаточно! Перейдите в меню регистрации транспорта." << std::endl;
							break;
						}
						else {
							mode = 2;
						}
					}
					break;
				}
				case 2: {
					if (vehicles_count < 2) {
						std::cout << "Участников гонки недостаточно! Перейдите в меню регистрации транспорта." << std::endl;
						mode = 0;
						break;
					}
					else { 
						std::this_thread::sleep_for(std::chrono::milliseconds(1000));
						std::cout << "3... 2... 1... Гонка началась!" << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(3000));
						break; }
				  }
				default: {
					std::cout << "Указанного действия нет в меню." << std::endl; break; }
			}
			

		} while (mode != 2);

	// создаем структуру для подсчета результатов
		struct race* racer = new race[vehicles_count]{};
		
			for (int i = 0; i < vehicles_count; ++i) {
				racer[i].name = race_members[i]->getRace_name();
				racer[i].result = race_members[i]->getFull_race_time(race_distance);
			}

		sorting(racer, vehicles_count);

		system("cls");
		std::cout << "Результаты гонки: " << std::endl;

		for (int i = 0; i < vehicles_count; ++i) {
			std::cout << i + 1 << ". " << racer[i].name << ". Время: " << racer[i].result << std::endl;
		}
		

		std::cout << std::endl 
			<< 1 << ". Провести ещё одну гонку" << std::endl
			<< 2 << ". Выйти" << std::endl;

		std::cin >> exit;

		delete[] race_members;
		delete[] racer;
		size = 0;
		vehicles_count = 0;
		race_name = {};
		system("cls");
	}


	delete_race(all_vehicles, m_size);
	return 0;
}


