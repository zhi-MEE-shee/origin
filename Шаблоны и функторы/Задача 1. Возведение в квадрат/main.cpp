#include <iostream>
#include <vector>


template<typename T>
void power(T a, int b = 2) {
	auto res{ 1 };
	for (int i = 0; i < b; ++i) {
		res = res * a;
	}
	std::cout << "[OUT]: " << res << std::endl;
}

template<typename T>
void power(std::vector<T>& arr) {
	for (auto& it : arr) {
		it *= it;
	}
	std::cout << "[OUT]: ";
	for (const auto& it : arr) {
		std::cout << it << ' ';
	}
}

int main() {

	int num{ 4 }; 
	std::cout << "[IN]: " << num << std::endl;
	power(num);

	std::vector<int> arr {-1, 4, 8};
	std::cout << "[IN]: ";
	for (const auto& it : arr) {
		std::cout << it << ' ';
	}
	std::cout << std::endl;
	power(arr);

	return 0;
}