#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#pragma execution_character_set ("utf-8");

using namespace Wt::Dbo;

class Publisher; 
class Stock;
class Sale;

class Book {
public:
	std::string title = "";
	ptr<Publisher> publisher;
	collection<ptr<Stock>> stocks;

	template<class Action>
	void persist(Action& a)
	{
		field(a, title, "title");
		belongsTo(a, publisher, "publisher");
		hasMany(a, stocks, ManyToOne, "book");
	}
};


class Publisher {
public:
	std::string name = "";
	collection<ptr<Book>> books;

	template<typename Action>
	void persist(Action& a) {
		field(a, name, "name");
		hasMany(a, books, ManyToOne, "publisher");
	}
};

class Shop {
public:
	std::string name = "";
	collection<ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a) {
		field(a, name, "name");
		hasMany(a, stocks, ManyToOne, "shop");
	}
};

class Sale {
public:
	int price = 0;
	std::string sale_date = "";
	int count = 0;
	ptr<Stock> stock;

	template<typename Action>
	void persist(Action& a) {
		field(a, price, "price");
		field(a, sale_date, "sale_date");
		field(a, count, "count");
		belongsTo(a, stock, "stock");
	}
};


class Stock {
public:
	int count = 0;
	ptr<Book> book;
	ptr<Shop> shop;
	collection<ptr<Sale>> sale;

	template<typename Action>
	void persist(Action& a) {
		field(a, count, "count");
		belongsTo(a, book, "book");
		belongsTo(a, shop, "shop");
		hasMany(a, sale, ManyToOne, "stock");
	}
};




int main() {

	setlocale(LC_ALL, "RUSSIAN");
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);
	

	try{
		std::string connectionString = "dbname=ORM "
			                           "host = 127.0.0.1 "
			                           "port=5432 "
			                           "user=user03 "
			                           "password=user03";

		auto connection = std::make_unique<backend::Postgres>(connectionString);

		Session session;
		session.setConnection(std::move(connection));
		session.mapClass<Book>("book");
		session.mapClass<Publisher>("publisher");
		
		
		session.mapClass<Sale>("sale");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");
		
		try {
			session.createTables();
		}
		catch (...) {
		}
	
		Transaction t{ session };

		auto pub1 = std::unique_ptr<Publisher>(new Publisher{ "Symposium", {} });
		auto pub2 = std::unique_ptr<Publisher>(new Publisher{ "Enigma", {} });
		auto pub3 = std::unique_ptr<Publisher>(new Publisher{ "Progress", {} });
		auto publisher1 = session.add(std::move(pub1));
		auto publisher2 = session.add(std::move(pub2));
		auto publisher3 = session.add(std::move(pub3));

		auto b1 = std::unique_ptr<Book>(new Book{ "The Metamorphosis", {}, {} });
		auto b2 = std::unique_ptr<Book>(new Book{ "Voix de l'ami", {}, {} });
		auto b3 = std::unique_ptr<Book>(new Book{ "An essay on love and cruelty", {}, {} });
		auto book1 = session.add(std::move(b1));
		auto book2 = session.add(std::move(b2));
		auto book3 = session.add(std::move(b3));

		book1.modify()->publisher = publisher3;
		book2.modify()->publisher = publisher2;
		book3.modify()->publisher = publisher1;

		auto sh1 = std::unique_ptr<Shop>(new Shop{ "MDK", {} });
		auto sh2 = std::unique_ptr<Shop>(new Shop{ "Garage", {} });
		auto sh3 = std::unique_ptr<Shop>(new Shop{ "Flanster", {} });
		auto shop1 = session.add(std::move(sh1));
		auto shop2 = session.add(std::move(sh2));
		auto shop3 = session.add(std::move(sh3));

		auto st1 = std::unique_ptr<Stock>(new Stock{ 12, {}, {}, {} });
		auto st2 = std::unique_ptr<Stock>(new Stock{ 30, {}, {}, {} });
		auto st3 = std::unique_ptr<Stock>(new Stock{ 20, {}, {}, {} });
		auto st4 = std::unique_ptr<Stock>(new Stock{ 12, {}, {}, {} });
		auto stock1 = session.add(std::move(st1));
		auto stock2 = session.add(std::move(st2));
		auto stock3 = session.add(std::move(st3));
		auto stock4 = session.add(std::move(st4));
		stock1.modify()->book = book1;
		stock1.modify()->shop = shop2;
		stock2.modify()->book = book2;
		stock2.modify()->shop = shop3;
		stock3.modify()->book = book3;
		stock3.modify()->shop = shop1;
		stock4.modify()->book = book1;
		stock4.modify()->shop = shop3;

		auto sl1 = std::unique_ptr<Sale>(new Sale{ 580, "2024-01-16", 2, {} });
		auto sl2 = std::unique_ptr<Sale>(new Sale{ 800, "2023-09-11", 1, {} });
		auto sl3 = std::unique_ptr<Sale>(new Sale{ 1200, "2023-12-24", 4, {} });
		auto sl4 = std::unique_ptr<Sale>(new Sale{ 290, "2023-11-01", 1, {} });
		auto sale1 = session.add(std::move(sl1));
		auto sale2 = session.add(std::move(sl2));
		auto sale3 = session.add(std::move(sl3));
		auto sale4 = session.add(std::move(sl4));
		sale1.modify()->stock = stock2;
		sale2.modify()->stock = stock1;
		sale3.modify()->stock = stock3;
		sale4.modify()->stock = stock2;



		std::string publ;
		std::cout << "Indicate the name of the publisher: ";
		std::cin >> publ;
		
		// Enigma   Symposium   Progress

		ptr<Publisher> lf_pub = session.find<Publisher>().where("name=?").bind(publ);
		
		collection<ptr<Book>> books = session.find<Book>().where("publisher_id=?").bind(lf_pub.id());
		if (books.size() != 0) {
			for (const auto& book : books) {
				collection<ptr<Stock>> stocks = session.find<Stock>().where("book_id=?").bind(book.id());
				if (stocks.size() != 0) {
					std::cout << "\nBook(s) published by " << lf_pub->name << " could be purchased at the following store(s): " << std::endl;
					std::cout << stocks.size() << " store(s) were found:" << std::endl;
					for (const auto& stock : stocks) {
						std::cout << stock.get()->shop->name << std::endl; 
					}
				}
			}
		}
		else {
			std::cout << "Books published by " << lf_pub->name << " not found\n";
		}
		

		t.commit();
	
	}
	catch (const std::exception& ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}
}

