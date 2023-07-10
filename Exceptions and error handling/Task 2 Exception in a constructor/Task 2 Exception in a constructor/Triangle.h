#pragma once
#include "Figure.h"


class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;
	string getName() override;
//	bool check() override;

	//конструктор произвольного треугольника
	Triangle(int a, int b, int c, int A, int B, int C);
	

public:
	Triangle();

	int getSide_a();
	int getSide_b();
	int getSide_c();

	int getAngle_A();
	int getAngle_B();
	int getAngle_C();

	void print_info() override;
};
