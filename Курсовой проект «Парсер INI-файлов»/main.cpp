#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <Windows.h>



class ini_parser {
private:
	std::string file;
	//        ��� ������,          ��� �����, �������� ���������
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
	T get_value(const std::string& req_str) {
		
		std::string req_section;
		std::string req_key;
		T value;
		size_t dot = req_str.find('.');
		if (dot != std::string::npos) {
			req_section = req_str.substr(0, dot);
			req_key = req_str.substr(dot + 1);
		}
		if (auto i = ini.find(req_section); i != ini.end()) {
			if (auto j = ini.find(req_key); j != ini.end()) {
				value = ini[req_section][req_key];    
			}
			else {
				std::cout << "������������� ���� �����������." << std::endl;
				//throw std::logic_error("Key not found");
			}
		}
		else {
			std::cout << "������������� ������ �����������." << std::endl;
		}
		return value;
	}

	void line_reading(std::string& section, const std::string& line) {
	
		std::stringstream ss(line);
		std::string str;
		ss >> std::ws >> str;
		if (!str.empty()) { 
			if (str[0] == '[' && str[str.length() - 1] == ']') {		/// ���� ��������� Section                  
				section = str.substr(1, str.length() - 2);                                   
			}
			else {			
				size_t comm = str.find(';');						    /// ���� ������ �������������� � ���������� ��
				if (comm != std::string::npos) {
					str = str.substr(0, comm);
				}
				size_t equal = str.find('=');							/// ���� ���� '=' aka �������������� ��� ������ �������� ��������� ����=��������
				if (equal != std::string::npos) {						//
					std::string key = str.substr(0, equal);				// ���������� ��������� �� pos == 0 �� pos == equal 
					std::string value = str.substr(equal + 1);			// ���������� ��������� �� pos == equal + 1 �� pos == size() 
					ini[section][key] = value;

				}
			}
		}
	}



	//T& operator=(const std::string& str) {}


};


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ini_parser parser("to_read.ini");
	auto value = parser.get_value<double>("Section1.var2");

	//  �������� ����� ������� ����������� �������� value
	std::cout << "value = " << value << std::endl;

	return 0;
}


