#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <Windows.h>



class ini_parser {
private:
	std::string file;
	//        им€ секции,          им€ ключа, значение параметра
	//std::map<std::string, std::pair<std::string, std::string>> ini;

	typedef std::map<std::string, std::string> inner_map;
	typedef std::map<std::string, inner_map> outer_map;
	outer_map ini;



public:

	ini_parser(const std::string& filename) : file(filename) {
		std::ifstream file (filename);
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file");
		}
		else {
			std::string section;
			std::string line;
			while (std::getline(file, line)) {
				line_reading(line, section);
			}

			file.close();
		}
		
	}

	~ini_parser() {};


	template<typename T>
	T get_value(const std::string& req_section, const std::string& req_key) {
		static_assert(sizeof(T) == -1, "not implemented type for get_value"); 
	} 


	void print() {

		for (outer_map::iterator it = ini.begin(); it != ini.end(); ++it)
		{
			inner_map& innerMap = it->second;
			std::cout << "Outer " << it->first << "\n";
			for (inner_map::iterator jt = innerMap.begin(); jt != innerMap.end(); ++jt)
			{
				std::cout << "    " << jt->first << ":" << jt->second << "\n";
			}
		}

	}



	private:
	std::string getvaluestring(const std::string& req_section, const std::string& req_key) {
		std::string str_value;

		if (auto i = ini.find(req_section); i != ini.end()) {
			if (auto j = i->second.find(req_key); j != i->second.end()) {
				str_value = j->second;
			}
			else {
				std::cout << "«апрашиваемый ключ отсутствует." << std::endl;
			}
		}
		else {
			std::cout << "«апрашиваема€ секци€ отсутствует." << std::endl;
		}

		return str_value;
	}
	
	void line_reading(std::string& section, const std::string& line) {
	
		std::stringstream ss(line);
		std::string str;
		ss >> std::ws >> str;
		if (!str.empty()) { 
			if (str[0] == '[' && str[str.length() - 1] == ']') {		/// ищем заголовок Section                  
				section = str.substr(1, str.length() - 2);  
				ini.insert(std::make_pair(section, inner_map()));
			}
			else {			
				size_t comm = str.find(';');						    /// ищем строки коментировани€ и игнорируем их
				if (comm != std::string::npos) {
					str = str.substr(0, comm);
				}
				size_t equal = str.find('=');							/// ищем знак '=' aka идентифицируем что строка содержит отношение ключ=значение
				if (equal != std::string::npos) {						//
					std::string key = str.substr(0, equal);				// возвращаем подстроку от pos == 0 до pos == equal 
					std::string value = str.substr(equal + 1);			// возвращаем подстроку от pos == equal + 1 до pos == size() 
					ini[section].insert(std::make_pair(key, value));

				}
			}
		}
	}

};


template<>
std::string ini_parser::get_value(const std::string& req_section, const std::string& req_key) {
	return getvaluestring(req_section, req_key);
}

template<>
int ini_parser::get_value(const std::string& req_section, const std::string& req_key) {
	std::string str_value = getvaluestring(req_section, req_key);
	int val = std::stoi(str_value);
	return val;
}


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ini_parser parser("to_read.ini");

	parser.print();

	auto value = parser.get_value<int>("Section2", "var3");

	std::cout << "value = " << value << std::endl;

	return 0;
}


