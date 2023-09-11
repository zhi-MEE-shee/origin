#include <iostream>
#include <string>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}


int main() {

	std::variant<int, std::string, std::vector<int>> anknown_var;

	anknown_var = get_variant();

	if (std::holds_alternative<int>(anknown_var))
	{
		std::cout << std::get<int>(anknown_var) * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(anknown_var)) 
	{
		std::cout << std::get<std::string>(anknown_var) << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(anknown_var)) 
	{
		auto nums = std::get<std::vector<int>>(anknown_var);
			for (const auto& n : nums) {
				std::cout << n << ' ';
			};
	};

	return 0;
}