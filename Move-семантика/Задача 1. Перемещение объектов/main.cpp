#include <iostream>
#include <string>
#include <vector>

//template <typename T>
//void move_vectors(T& obj1, T& obj2) {
//	if (obj1 == obj2) { return; }
//
//	T temp;
//	for (auto& it : obj1) {
//		temp.push_back(std::move(it));
//	}
//	obj1.clear();
//
//	for (auto& it : obj2) {
//		obj1.push_back(std::move(it));
//	}
//	obj2.clear();
//
//	if (temp.size() != 0) {
//		for (auto& it : temp) {
//			obj2.push_back(std::move(it));
//		}
//	}
//}

template <typename T>
void move_vectors(T& obj1, T& obj2) {
	if (obj1 == obj2) { return; }

	T temp = std::move(obj1);
	obj1 = std::move(obj2);
	obj2 = std::move(temp);
}


int main() {

	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two = { "test_string3", "test_string4", "test_string2" };
	move_vectors(one, two);

	std::cout << "vector one has size: " << one.size() << std:: endl << "vector two has size: " << two.size();
}