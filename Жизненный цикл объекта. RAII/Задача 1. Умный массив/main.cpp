#include <iostream>
#include <exception>
class smart_array {
private:
	int* ptr;
	int size;
	int was_written{ 0 };
public:
	smart_array(int size) : size{size} {

		ptr = new int [size] { 0 };
	}

	smart_array(const smart_array&) = delete;                // запрещаем конструктор копирования
	smart_array& operator= (const smart_array&) = delete;    // удаляем оператор присваивания

	~smart_array() {
	//	std::cout << "smart_array delited";
		delete[] ptr;
	}

	int get_element(int num) { 
		if (num < 0 || num >= was_written) {
			throw std::exception("index isn't valid");
		}
		else
			return ptr[num]; 
	}

	void add_element(int num) {
		if (was_written == size) {
			throw std::exception("array is full");
		}
		else {
			ptr[was_written] = num;
			++was_written;
		}
	}


};



int main() {

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
	//	arr.add_element(16);
	//	std::cout << arr.get_element(6) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}