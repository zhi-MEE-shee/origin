#include "Triangle.h"

	std::string Triangle::getName() { return "Треугольник"; }

	//конструктор произвольного треугольника
	Triangle::Triangle(int a, int b, int c, int A, int B, int C) {

		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = getName();
	}

	//конструктор прямоуголного треугольника
	Triangle::Triangle(int a, int b, int c, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;

		C = 90;
	}
	//конструктор равнобедренного треугольника
	Triangle::Triangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		this->A = A;
		B = A;
		this->C = C;
	}

	//конструктор равностороннего треугольника
	Triangle::Triangle(int a, int A) {
		this->a = a;
		b = a;
		c = a;
		this->A = A;
		B = A;
		C = A;
	}

	Triangle::Triangle() : Triangle(10, 20, 30, 35, 100, 45) {};

	int Triangle::getSide_a() { return a; }
	int Triangle::getSide_b() { return b; }
	int Triangle::getSide_c() { return c; }

	int Triangle::getAngle_A() { return A; }
	int Triangle::getAngle_B() { return B; }
	int Triangle::getAngle_C() { return C; }

	std::string Triangle::getNameForOutput() { return name; }

	void Triangle::print() {
		std::cout << name << ": " << std::endl
			<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << std::endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << std::endl << std::endl;
	}
