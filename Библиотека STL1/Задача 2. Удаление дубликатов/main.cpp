#include <algorithm>
#include <iostream>
#include <set>


int main() {

	std::cout << "[IN]:" << std::endl;
	int size;
	std::cin >> size;

	std::set<int>st;
	while (size != 0) {
		int tmp;
		std::cin >> tmp;
		st.insert(tmp);
		--size;
	}
	std::cout << "[OUT]:" << std::endl;
	std::for_each(st.rbegin(), st.rend(), [](const int& n) { std::cout << n << std::endl; });


	return 0;
}