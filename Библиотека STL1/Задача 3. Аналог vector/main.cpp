#include <iostream>
#include <stdexcept>


template <typename T>
class MyVector {
private:
	T* ptr;
	unsigned int current;
	unsigned int cap;
public:
	MyVector<T>(int _c) : cap(_c) {
		current = 0;
		ptr = new T[cap];
		std::cout << "created" << std::endl;
	}

	~MyVector(){
		std::cout << "delited" << std::endl;
		current = 0;
		cap = 0;
		delete[]ptr;
	}

	MyVector(const MyVector& other) {
		this->current = other.current;
		this->cap = other.cap;
		ptr = new T[cap];

		for (unsigned int i = 0; i < current; i++) {
			ptr[i] = other.ptr[i];
		}
	};

	MyVector& operator=(const MyVector& other) {
		if (&other == this) {
			return *this;
		}
		delete[]this->ptr;
		this->current = other.current;
		this->cap = other.cap;
		ptr = new T[cap];

		for (unsigned int i = 0; i < current; i++) {
			ptr[i] = other.ptr[i];
		}
		return *this;
	};


	T at(int pos) {
		if (pos >= current) {
			throw std::out_of_range( "Invalid index" );
		}
		return ptr[pos];
	}

	void push_back(T val)
	{
		if (current == cap) {
			T* tmp = new T[cap + 4];
			for (int i = 0; i < cap; i++) {
				tmp[i] = ptr[i];
			}
			delete[] ptr;
			cap += 4;
			ptr = tmp;
		}
		ptr[current] = val;
		current++;
	}

	int size() {
		return current;
	}

	int capacity() {
		return cap;
	}

};


int main() {
	MyVector<int>my(10);
	my.push_back(1);
	my.push_back(6);
	std::cout << my.at(1) << ' ' << my.size() << ' ' << my.capacity() << std::endl;
	MyVector<int>my2(10);

	return 0;
}