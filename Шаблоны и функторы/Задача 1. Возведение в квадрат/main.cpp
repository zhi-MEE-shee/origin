#include <iostream>
#include <vector>


template<typename T>
T power(T& a) {
	return a * a;
}

template<typename T>
T power(std::vector<T>& arr) {
	for (auto& it : arr) {
		it *= it;
	}
	return arr;
}

int main() {

	int num{ 4 }; 
	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << power(num) << std::endl;

	std::vector<int> arr {-1, 4, 8};
	std::cout << "[IN]: ";
	for (const auto& it : arr) {
		std::cout << it << ' ';
	}
	std::cout << std::endl;
	
	std::cout << "[OUT]: ";
	for (const auto& it : arr) {
		std::cout << power(it) << ' ';
	}


	return 0;
}