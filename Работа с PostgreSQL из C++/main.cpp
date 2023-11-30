#include <iostream>
#include <pqxx/pqxx>
//#include <pqxx/transaction_base>
#include <Windows.h>
//#pragma execution_character_set("utf-8")

int main() {

	//	setlocale(LC_ALL, "Russian"); 
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try
	{
		pqxx::connection conn(
			"dbname=2_Task5 "
			"host=localhost "
			"port=5432 "
			"user=user03 "
			"password=user03 "
		);

		pqxx::transaction tx{conn};

		tx.transaction_base::exec(
			"CREATE TABLE public.client ("
			"id serial4 NOT NULL, "
			"first_name VARCHAR(40) NOT NULL, "
			"last_name VARCHAR(40) NOT NULL, "
			"email VARCHAR(80) UNIQUE NOT NULL, "
			"CONSTRAINT client_pk PRIMARY KEY(id));");

		tx.transaction_base::exec("CREATE TABLE public.phone_number ("
			"id serial PRIMARY KEY, "
			"phone VARCHAR(20) UNIQUE NOT NULL );");

		tx.transaction_base::exec(
			"CREATE TABLE client_phone ("
			"client_id INTEGER NOT NULL REFERENCES client(id), "
			"phone_number_id INTEGER NOT NULL REFERENCES phone_number(id), "	
			"PRIMARY KEY(client_id, phone_number_id));");
	
	
	
		std::string first_name = "Джек";
		std::string last_name = "Рассел";
		std::string email = "JR@gmail.com";

		std::string client_id = "INSERT INTO public.client (id, first_name, last_name, email) VALUES (DEFAULT,'" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "') RETURNING id;";
		pqxx::result c = tx.exec(client_id);
			if (c.size() == 1) {
				int id = c[0][0].as<int>();
				std::cout << "Добавлен клиент с номером ID: " << id << std::endl
						  << "Имя: " << first_name << " " << last_name << std::endl
						  << "email: " << email << std::endl;
			}
		
		std::string phone = "123456789"; 
		std::string p_id = "INSERT INTO public.phone_number (id, phone) VALUES(DEFAULT, '" + phone + "') RETURNING id;";
		pqxx::result r = tx.exec(p_id);

			if (r.size() == 1) { 
				int id = r[0][0].as<int>(); 
				std::cout << "Добавлен ID: " << id << std::endl
						  << "Для номера: " << phone << std::endl;
			}

		std::string cli_phone = "INSERT INTO client_phone (client_id, phone_number_id) VALUES(1, 1)";
		tx.exec(cli_phone);


		std::string new_first_name = "Том";
		std::string new_name = "UPDATE public.client SET first_name = '" + new_first_name +"' WHERE id = 1";
		tx.exec(new_name);
		std::cout << "Имя было изменено на: " << new_first_name << std::endl;


		auto collection = tx.query <std::string, std::string>("SELECT c.first_name, ph.phone FROM public.client c "
			"JOIN public.client_phone cp ON c.id = cp.client_id "
			"JOIN public.phone_number ph ON cp.phone_number_id = ph.id "
			"WHERE ph.id = 3 ");
		for (auto& record : collection) {
			std::string name = std::get<0>(record);
			std::string phone = std::get<1>(record);

			std::cout << name << "'s phone number is " << phone << std::endl;
		}



		pqxx::result d1 = tx.exec("DELETE FROM public.client_phone WHERE client_id = 1");
		pqxx::result d2 = tx.exec("DELETE FROM public.phone_number WHERE id = 1");
		pqxx::result d3 = tx.exec("DELETE FROM public.client WHERE first_name = 'Том'");


		tx.commit();

	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}