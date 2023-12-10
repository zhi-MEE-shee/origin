#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <Windows.h>



class ini_parser {
private:
	std::string file;
	//        им€ секции,          им€ ключа, значение параметра
	std::map<std::string, std::map<std::string, std::string>> ini;
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

		T val;
		std::string str_value;
		
		if (auto i = ini.find(req_section); i != ini.end()) {
			if (auto j = ini.find(req_key); j != ini.end()) {
				str_value = ini[req_section][req_key];
			}
			else {
				std::cout << "«апрашиваемый ключ отсутствует." << std::endl;
				//throw std::logic_error("Key not found");
			}
		}
		else {
			std::cout << "«апрашиваема€ секци€ отсутствует." << std::endl;
		}
		

		if (std::is_same<int, T>::value)
		{
			val = std::stoi(str_value);
		}
		else if (std::is_same<double, T>::value) {
			val = std::stod(str_value);
		}
		else {
			val = str_value;
		}

		return val;
	}


	


	void line_reading(std::string& section, const std::string& line) {
	
		std::stringstream ss(line);
		std::string str;
		ss >> std::ws >> str;
		if (!str.empty()) { 
			if (str[0] == '[' && str[str.length() - 1] == ']') {		/// ищем заголовок Section                  
				section = str.substr(1, str.length() - 2);                                   
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
					ini[section][key] = value;

				}
			}
		}
	}

};


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ini_parser parser("to_read.ini");
	auto value = parser.get_value<double>("Section1", "var2");

	std::cout << "value = " << value << std::endl;

	return 0;
}


