#include <iostream>

template <typename T>
class Matrix {
private:
	int** matrix;
	T cols;
	T rows;
	T i{ 0 };
public:
	Matrix(int _c, int _r) : cols(_c), rows(_r) {
		matrix = new int*[cols];
		for (i; i < cols; i++) {
			matrix[i] = new int[rows] {};
		}
	}
	~Matrix() {
		i = 0;
		for (i; i < cols; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;

	}
// перегрузка для записи
	T* operator[] (T i) {
		return matrix[i];
	}
	
// перегрузка для чтения
// если закомментировать, то код работает так же
// потому не понимаю для чего const int& operator[] (T i) const необходим

	const T* operator[] (T i) const {
		return matrix[i];
	}
};
//
//void print(const Matrix<int>& m)
//{
//	std::cout << m[0][0];
//}

int main() {

	auto test = Matrix<int>(2, 3);
	test[0][1] = 4;
	test[1][2] = 9;
	std::cout << test[0][1] << std::endl;
	std::cout << test[1][2] << std::endl;

//	print(test);
}


/*
	

	int& operator() (T i, T j)
	{
		if (i >= rows || j >= cols)
			throw BadIndex("index out of range");
		return matrix[cols][rows];
	}

	int operator() (T i, T j) const
	{
		if (i >= rows || j >= cols)
			throw BadIndex("index out of range");
		return matrix[cols][rows];
	}


  test(2,3) = 4;
  std::cout << test(2,3);
*/