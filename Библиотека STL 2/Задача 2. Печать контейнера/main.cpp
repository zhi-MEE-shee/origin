#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

template <typename T>
void print_container(T str) {
	std::for_each(str.begin(), str.end(), [](std::string it) { std::cout << it << ' '; });
	std::cout << std::endl;
};


int main() {

	// "f" старше чем "o" 
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); 

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); 

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); 

	return 0;
}