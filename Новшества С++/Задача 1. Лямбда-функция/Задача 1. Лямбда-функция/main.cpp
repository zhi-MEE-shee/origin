#include <algorithm>
#include <iostream>
#include <vector>


int main() {
	
	system("chcp 1251>nul");

	std::vector<int> nums {4, 7, 9, 14, 12 };

	std::cout << "Входные данные: ";
	std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << ' '; });
	std::cout << std::endl;
	std::cout << "Выходные данные: ";
	std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << (n % 2 == 1 ? n * 3 : n) << ' '; });
	std::cout << std::endl;

	return 0;
}