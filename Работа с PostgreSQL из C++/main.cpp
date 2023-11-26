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
/*
		tx.transaction_base::exec(
			"CREATE TABLE public.client ("
			"id serial4 NOT NULL, "
			"имя VARCHAR(40) NOT NULL, "
			"фамилия VARCHAR(40) NOT NULL, "
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
*/	

		conn.prepare("insert_client", "INSERT INTO client (имя, фамилия, email) VALUES ($1, $2, $3);");
		conn.prepare("insert_phone", "INSERT INTO client_phone (имя, фамилия, email) VALUES ($1, $2, $3);");

		tx.commit();

	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "hello!";

	return 0;
}