#include <iostream>

template <typename T>
class Matrix {
private:
	T** matrix;
	size_t cols;
	size_t rows;
	size_t i{ 0 };
public:
	Matrix(size_t _c, size_t _r) : cols(_c), rows(_r) {
		matrix = new T*[cols];
		for (i; i < cols; i++) {
			matrix[i] = new T[rows] {};
		}
	}
	~Matrix() {
		i = 0;
		for (i; i < cols; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;

	}

	T* operator[] (size_t i) {
		return matrix[i];
	}

	const T* operator[] (size_t i) const {
		return matrix[i];
	}

};


int main() {

	auto test = Matrix<double>(2, 3);
	test[0][1] = 4.6;
	test[1][2] = 9.3;
	std::cout << test[0][1] << std::endl;
	std::cout << test[1][2] << std::endl;
	auto test1 = Matrix<int>(2, 3);

	return 0;
}

