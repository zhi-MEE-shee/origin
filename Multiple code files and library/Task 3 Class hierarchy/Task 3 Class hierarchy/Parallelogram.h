#pragma once
#include "Quadrangle.h"


class Parallelogram : public Quadrangle
{
protected:
	string getName() override;

	//конструктор прямоугольника
	Parallelogram(int a, int c);

	//конструктор ромба
	Parallelogram(int a, int A, int C);

public:
	Parallelogram();
};

