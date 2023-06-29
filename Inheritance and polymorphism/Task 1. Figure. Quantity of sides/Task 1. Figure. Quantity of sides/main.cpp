#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Figure
{

protected:
	int numOfSides;
	string name;

	virtual string getName() { return "Фигура"; }

public:

	Figure() {
		numOfSides = 0;
		name = getName();
	};
	
	int getNumOfSides() {return numOfSides;}

	void print() {
		cout << name << ": " << getNumOfSides() << endl;
	}
};

class Triangle : public Figure
{
protected:
	string getName() override { return "Трёхугольник"; }

public:
	Triangle() {
		numOfSides = 3;
		name = getName();
	};

};

class Quadrangle : public Figure
{
protected:
	string getName() override { return "Четырёхугольник"; }

public:
	Quadrangle() {
		numOfSides = 4;
		name = getName();
	};

};



int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure obj1;
	Triangle obj2;
	Quadrangle obj3;
	
	cout << "Количество сторон: " << endl;

	obj1.print();
	obj2.print();
	obj3.print();

	return 0;
}