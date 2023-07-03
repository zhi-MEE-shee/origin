#include "Parallelogram.h"

	string Parallelogram::getName() { return "Параллелограмм"; }

	//конструктор прямоугольника
	Parallelogram::Parallelogram(int a, int c) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = C = D = A = 90;
	}

	//конструктор ромба
	Parallelogram::Parallelogram(int a, int A, int C) {
		this->a = a;
		b = c = d = a;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}

	Parallelogram::Parallelogram() :Quadrangle(30, 55, 120, 60) {
		name = getName();
	};

