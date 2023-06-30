#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Figure
{
protected:
	
	string name;
	virtual string getName() { return "Фигура"; }

};

class Triangle : public Figure
{
private:
	//конструктор произвольного треугольника-ли?
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = getName();
	}
protected:
	int a, b, c;
	int A, B, C;
	string getName() override { return "Треугольник"; }

	//конструктор прямоуголного треугольника
	Triangle(int a, int b, int c, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;

		C = 90;
	}
	//конструктор равнобедренного треугольника
	Triangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		this->A = A;
		B = A;
		this->C = C;
	}

	//конструктор равностороннего треугольника
	Triangle(int a, int A) {
		this->a = a;
		b = a;
		c = a;
		this->A = A;
		B = A;
		C = A;
	}


public:
	Triangle() : Triangle( 10, 20, 30, 35, 100, 45){};

	int getSide_a() { return a; }
	int getSide_b() { return b; }
	int getSide_c() { return c; }

	int getAngle_A() { return A; }
	int getAngle_B() { return B; }
	int getAngle_C() { return C; }

	string getNameForOutput() { return name; }
	//вынесла в отдельную функцию
	//void print() {
	//	cout << name << ": " << endl
	//		<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << endl
	//		<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << endl << endl;
	//}
};

class RightTriangle : public Triangle
{
protected:
	string getName() override { return "Прямой треугольник"; }

public:
	RightTriangle() : Triangle(40, 20, 60, 30, 60) {
		name = getName();
	};
};

class IsoscelesTriangle : public Triangle
{
protected:
	string getName() override { return "Равнобедренный треугольник"; }

public:
	IsoscelesTriangle() : Triangle(30, 20, 55, 70) {
		name = getName();
	};
};

class EquilateralTriangle : public Triangle
{
protected:
	string getName() override { return "Равносторонний треугольник"; }

public:
	EquilateralTriangle() :Triangle(30, 60) {
		name = getName();
	};

};

class Quadrangle : public Figure
{	
private:
	string getName() override { return "Четырёхугольник"; }
protected:
	int a, b, c, d;
	int A, B, C, D;
	
//конструктор четфрехугольника
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
//конструктор параллелограмма
	 Quadrangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}


public:
	Quadrangle() : Quadrangle(20, 10, 30, 40, 30, 35, 160, 80) {
		name = getName();
	};

	int getSide_a() { return a; }
	int getSide_b() { return b; }
	int getSide_c() { return c; }
	int getSide_d() { return d; }
	int getAngle_A() { return A; }
	int getAngle_B() { return B; }
	int getAngle_C() { return C; }
	int getAngle_D() { return D; }

	void print() {
		cout << name << ": " << endl
			<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << ", d = " << getSide_d() << endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << ", D = " << getAngle_D() << endl << endl;
	}
};

class Parallelogram : public Quadrangle
{
protected:
	string getName() override { return "Параллелограмм"; }

	//конструктор прямоугольника
	Parallelogram(int a, int c) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = C = D = A = 90;
	}

	//конструктор ромба
	Parallelogram(int a, int A, int C) {
		this->a = a;
		b = c = d = a;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}

public:
	Parallelogram() :Quadrangle(30, 55, 120, 60) {
		name = getName();
	};
};



class Rectangle_ : public Parallelogram
{
protected:
	string getName() override { return "Прямоугольник"; }

//конструктор квадрата
	Rectangle_(int a) {
		this->a = a;
		b = c = d = a;
		B = C = D = A = 90;
	}
	
public:
	Rectangle_() :Parallelogram(55, 30) {
		name = getName();
	};
};


class Square : public Rectangle_
{
protected:
	string getName() override { return "Квадрат"; }
public:
	Square() : Rectangle_(40) {
		name = getName();
	}
};


class Rhombus : public Parallelogram
{
protected:
	string getName() override { return "Ромб"; }
public:
	Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};

};


void print_info(Triangle* obj) {
	cout << obj->getNameForOutput() << ": " << endl
		<< "Стороны: a = " << obj->getSide_a() << ", b = " << obj->getSide_b() << ", c = " << obj->getSide_c() << endl
		<< "Углы: A = " << obj->getAngle_A() << ", B = " << obj->getAngle_B() << ", C = " << obj->getAngle_C() << endl << endl;

}


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	Triangle obj1;
	RightTriangle obj2;
	IsoscelesTriangle obj3;
	EquilateralTriangle obj4;
	print_info(&obj1);
	print_info(&obj2);
	print_info(&obj3);
	print_info(&obj4);

	Quadrangle obj5;
	Parallelogram obj6;
	Rectangle_ obj7;
	Rhombus obj8;
	Square obj9;
	obj5.print();
	obj6.print();
	obj7.print();
	obj8.print();
	obj9.print();


	return 0;
}