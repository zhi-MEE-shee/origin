#include <iostream>
#include <functional>
#include <math.h>
#include <string>
#include <vector>


int main() {

	system("chcp 1251>nul");

	std::vector<double> angles {30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180};

	std::cout << "[Входные данные]: ";
	for (const auto& angle : angles) {
		std::cout << angle << ' ';
	}
	std::cout << std::endl;
	std::cout << "[Выходные данные]: ";
	std::cout << std::endl;

	std::string f_name1;
	std::string f_name2;

	std::function <void(double)> func;
	func = [f_name1 = "sin", f_name2 = "cos"](double i) mutable { std::cout << f_name1 << ": " << (f_name1 == "sin" ? sin(i) : (sin(i) / cos(i)) ) << ' '
																            << f_name2 << ": " << (f_name2 == "cos" ? cos(i) : (cos(i) / sin(i)) ) << ' '; };

	std::vector <std::function<void(double)>> functions;
	functions.push_back(func);
	

	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}



	return 0;
}