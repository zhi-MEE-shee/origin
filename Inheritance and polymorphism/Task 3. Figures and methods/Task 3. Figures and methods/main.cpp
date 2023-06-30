#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Figure
{
protected:

	string name;
	int quantOfSides;
	virtual string getName() { return "Фигура"; }
	int getQuantOfSides() { return quantOfSides; }

	
	Figure(int sides) {
		quantOfSides = sides;
	};

	virtual bool check() {
		return quantOfSides == 0 ? true : false;
	}
public:
	Figure() : Figure(0) {
		name = getName();
	};

	virtual void print_info() {
		cout << name << ": " << endl;
		if (check() == true) {
			cout << "Соответствует параметрам." << endl;
		}
		else { cout << "Не соответствует параметрам." << endl; }

		cout << "Количество сторон: " << getQuantOfSides() << endl;

	}


};

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;
	string getName() override { return "Треугольник"; }

	bool check() override {
		return A + B + C == 180 ? true : false;
	}

	void print_info() override {
		cout << endl;
		Figure::print_info();
		cout << "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << endl
			 << "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << endl;
	}


	//конструктор произвольного треугольника-ли?
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		
		quantOfSides = 3;
	}

	/*//конструктор прямоуголного треугольника
	Triangle(int a, int b, int c, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;

		C = 90;
	}
	//конструктор равнобедренного треугольника
	triangle(int a, int c, int a, int c) {
		this->a = a;
		b = a;
		this->c = c;
		this->a = a;
		b = a;
		this->c = c;
	}

	//конструктор равностороннего треугольника
	Triangle(int a, int A) {
		this->a = a;
		b = a;
		c = a;
		this->A = A;
		B = A;
		C = A;
	}*/


public:
	Triangle() : Triangle(10, 20, 30, 35, 100, 45) {
		name = getName();
	};

	int getSide_a() { return a; }
	int getSide_b() { return b; }
	int getSide_c() { return c; }

	int getAngle_A() { return A; }
	int getAngle_B() { return B; }
	int getAngle_C() { return C; }
};

class RightTriangle : public Triangle
{
protected:
	string getName() override { return "Прямой треугольник"; }
	bool check() override {
		return C == 90 ? true : false;
	}

public:
	RightTriangle() : Triangle(40, 20, 60, 30, 60, 90) {
		name = getName();
	};
};

class IsoscelesTriangle : public Triangle
{
protected:
	string getName() override { return "Равнобедренный треугольник"; }

	bool check() override {
		return A == C && a == c ? true : false;
	}

public:
	IsoscelesTriangle() : Triangle(30, 40, 20, 55, 50, 75) {
		name = getName();
	};
};

class EquilateralTriangle : public Triangle
{
protected:
	string getName() override { return "Равносторонний треугольник"; }

	bool check() override {
		return A == C && A == B && a == c && a == b? true : false;
	}

public:
	EquilateralTriangle() :Triangle(30, 30, 30, 60, 60, 60) {
		name = getName();
	};

};




class Quadrangle : public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	string getName() override { return "Четырёхугольник"; }

	bool check() override {
		return A + B + C + D == 360 ? true : false;
	}

	void print_info() override {
		cout << endl;
		Figure::print_info();
		cout << "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << ", d = " << getSide_d() << endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << ", D = " << getAngle_D() << endl;
	}

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

		quantOfSides = 4;
	}
	//
	////конструктор параллелограмма
	//Quadrangle(int a, int c, int A, int C) {
	//	this->a = a;
	//	b = a;
	//	this->c = c;
	//	d = c;
	//	this->A = A;
	//	B = A;
	//	this->C = C;
	//	D = C;
	//}

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

};



class Parallelogram : public Quadrangle
{
protected:
	string getName() override { return "Параллелограмм"; }

	bool check() override {
		return A == C && B == D && a == c && b == d ? true : false;
	}

	////конструктор прямоугольника
	//Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) {
	//	this->a = a;
	//	b = a;
	//	this->c = c;
	//	d = c;
	//	this->A = A;
	//	B = C = D = A = 90;
	//}

	////конструктор ромба
	//Parallelogram(int a, int A, int C) {
	//	this->a = a;
	//	b = c = d = a;
	//	this->A = A;
	//	B = A;
	//	this->C = C;
	//	D = C;
	//}

public:
	Parallelogram() :Quadrangle(40, 45, 55, 55, 120, 60, 125, 55) {
		name = getName();
	};
};



class Rectangle_ : public Quadrangle
{
protected:
	string getName() override { return "Прямоугольник"; }

	bool check() override {
		return a == c && b == d && A == 90 && A == B && B == C && C == D ? true : false;
	}

	//конструктор квадрата
	//Rectangle_(int a) {
	//	this->a = a;
	//	b = c = d = a;
	//	B = C = D = A = 90;
	//}

public:
	Rectangle_() :Quadrangle(55, 85, 55, 85, 90, 90, 90, 90) {
		name = getName();
	};
};


class Square : public Quadrangle
{
protected:
	string getName() override { return "Квадрат"; }
	bool check() override {
		return a == c && b == d && a == b && A == 90 && A == B && B == C && C == D ? true : false;
	}
public:
	Square() : Quadrangle(40, 40, 40, 40, 90, 90, 90, 90) {
		name = getName();
	}
};


class Rhombus : public Quadrangle
{
protected:
	string getName() override { return "Ромб"; }

	bool check() override {
		return a == c && b == d && a == b && A == C && B == D ? true : false;
	}

public:
	Rhombus() : Quadrangle(40, 50, 45, 40, 80, 100, 90, 90) {
		name = getName();
	};

};


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Figure obj1;
	Figure* ptr_obj = &obj1;
	ptr_obj->print_info();

	Triangle obj2;
	ptr_obj = &obj2;
	ptr_obj->print_info();

	RightTriangle obj3;
	ptr_obj = &obj3;
	ptr_obj->print_info();

	IsoscelesTriangle obj4;
	ptr_obj = &obj4;
	ptr_obj->print_info();

	EquilateralTriangle obj5;
	ptr_obj = &obj5;
	ptr_obj->print_info();


	Quadrangle obj6;
	ptr_obj = &obj6;
	ptr_obj->print_info();

	Parallelogram obj7;
	ptr_obj = &obj7;
	ptr_obj->print_info();

	Rectangle_ obj8;
	ptr_obj = &obj8;
	ptr_obj->print_info();

	Square obj9;
	ptr_obj = &obj9;
	ptr_obj->print_info();
	
	Rhombus obj10;
	ptr_obj = &obj10;
	ptr_obj->print_info();

	return 0;
}