#include <iostream>
#include <pqxx/pqxx>
//#include <pqxx/transaction_base>
#include <Windows.h>
//#pragma execution_character_set("utf-8")

class DB_connection  {
public:
	pqxx::connection* conn;
	DB_connection() {
		conn = new pqxx::connection(
			"dbname=2_Task5 "
			"host=localhost "
			"port=5432 "
			"user=user03 "
			"password=user03 "
		);
	}
	~DB_connection() {
		delete conn;
	}

	void create_table(){
		pqxx::transaction tx{*conn};

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

		tx.commit();
	}

	int add_client(const std::string& first_name, const std::string& last_name, const std::string& email) {

		pqxx::transaction tx{*conn};

		std::string client_id = "INSERT INTO public.client (id, first_name, last_name, email) VALUES (DEFAULT,'" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "') RETURNING id;";
		pqxx::result c = tx.exec(client_id);
		int id{ 0 };
		if (c.size() == 1) {
			id = c[0][0].as<int>();
			std::cout << "Added client ID: " << id << std::endl
				<< "Name: " << first_name << " " << last_name << std::endl
				<< "email: " << email << std::endl;
		}
		tx.commit();
		return id;
	}

	int add_phone(const std::string& phone, const int& client_id) {

		pqxx::transaction tx{*conn};

		std::string p_id = "INSERT INTO public.phone_number (id, phone) VALUES(DEFAULT, '" + tx.esc(phone) + "') RETURNING id;";
		pqxx::result r = tx.exec(p_id);
		int id{ 0 };
		if (r.size() == 1) {
			id = r[0][0].as<int>();
			std::cout << "phone number : " << phone <<  " has ID " << id << std::endl;
		}
		tx.commit();

		add_ph_to_client(client_id, id);

		return id;
	}

	void name_update(const int& client_id, const std::string& new_name ) {
		
		conn->prepare("update", "UPDATE public.client SET first_name = $1 WHERE id = $2");

		pqxx::transaction tx{*conn};

		tx.exec_prepared("update", new_name, client_id);

		std::cout << "client with ID: " << client_id << " has name " << new_name << std::endl;

		tx.commit();
	}

	std::string get_name_by_id(const int& id) {

		pqxx::transaction tx{*conn};
		
		std::string last_name = tx.query_value <std::string> ("SELECT last_name FROM public.client WHERE id = " + std::to_string(id) + " ");
		std::cout << "The client you LF is " << last_name << std::endl;

		tx.commit();
		return last_name;
	}

	void client_serching(const std::string& last_name) {

		pqxx::transaction tx{*conn};

		auto collection = tx.query <std::string, std::string>("SELECT c.first_name, ph.phone FROM public.client c "
			"JOIN public.client_phone cp ON c.id = cp.client_id "
			"JOIN public.phone_number ph ON cp.phone_number_id = ph.id "
			"WHERE c.last_name = '" + tx.esc(last_name) + "' ");
		for (auto& record : collection) {
			std::string name = std::get<0>(record);
			std::string phone = std::get<1>(record);

			std::cout << name << "'s phone number is " << phone << std::endl;
		}

		tx.commit();
	}

	void delete_phone(const int& phone_id) {

		pqxx::transaction th{*conn};
		pqxx::result r1 = th.exec("DELETE FROM public.client_phone WHERE phone_number_id = " + std::to_string(phone_id) + " ");
		th.commit();

		pqxx::transaction tx{*conn};
		pqxx::result r2 = tx.exec("DELETE FROM public.phone_number WHERE id = " + std::to_string(phone_id) + " ");
		std::cout << "phone number was detited" << std::endl;
		tx.commit();

	}

	void delete_client(const int& client_id) {
		pqxx::transaction tx{*conn};
		pqxx::result r = tx.exec("DELETE FROM public.client WHERE id = " + std::to_string(client_id) + " ");
		std::cout << "client was detited as well" << std::endl;
		tx.commit();
	}


	private:

		void add_ph_to_client(const int& client_id, const int& phone_id) {

			conn->prepare("otm_client_phone", "INSERT INTO client_phone (client_id, phone_number_id) VALUES ($1, $2);");

			pqxx::transaction tx{*conn};

			tx.exec_prepared("otm_client_phone", client_id, phone_id);

			tx.commit();
		}
};


int main() {

	setlocale(LC_ALL, "Russian"); 
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 1000);



	DB_connection newDB;
	newDB.create_table();
	int client_id{ newDB.add_client("Jack", "Rassell", "JR@gmail.com") };
	int phone_id{ newDB.add_phone("123456789", client_id) };
	newDB.name_update(7, "Kurt");
	std::string last_name{ newDB.get_name_by_id(client_id)};
	newDB.client_serching(last_name);
	newDB.delete_phone(phone_id);
	newDB.delete_client(8);

	return 0;
}

