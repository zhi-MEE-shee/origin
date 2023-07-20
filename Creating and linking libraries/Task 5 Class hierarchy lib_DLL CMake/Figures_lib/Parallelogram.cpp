#include "Parallelogram.h"

	std::string Figures::Parallelogram::getName() { return "Параллелограмм"; }

	//конструктор прямоугольника
	Figures::Parallelogram::Parallelogram(int a, int c) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = C = D = A = 90;
	}

	//конструктор ромба
	Figures::Parallelogram::Parallelogram(int a, int A, int C) {
		this->a = a;
		b = c = d = a;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}

	Figures::Parallelogram::Parallelogram() :Quadrangle(30, 55, 120, 60) {
		name = getName();
	};

