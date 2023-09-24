#include <iostream>
#include <exception>
class smart_array {
private:
	int* ptr;
	int size;
	int was_written{ 0 };
public:
	smart_array(int size) : size{ size } {

		ptr = new int [size] { 0 };
	}

	smart_array(const smart_array& new_arr) {
		size = new_arr.size;
		was_written = new_arr.was_written;
		ptr = new int[size];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = new_arr.ptr[i];
		}
	}

	~smart_array() {
	//	std::cout << "smart_array delited" << std::endl;
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

	
	smart_array& operator= (const smart_array& array)
	{
		if (this != &array) {                  
			size = array.size;
			was_written = array.was_written;
			ptr = new int[size];

			for (int i = 0; i < size; i++)
			{
				ptr[i] = array.ptr[i];
			}
			return *this;
		}
	}

};



int main() {

	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;

	return 0;
}