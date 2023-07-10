#pragma once
#include "Figure.h"

class Quadrangle : public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	string getName() override;

	//bool check() override;

	void print_info() override;

	//конструктор четфрехугольника
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

public:
	Quadrangle();

	int getSide_a();
	int getSide_b();
	int getSide_c();
	int getSide_d();
	int getAngle_A();
	int getAngle_B();
	int getAngle_C();
	int getAngle_D();

};