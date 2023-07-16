#include "Rectangle_.h"

	std::string Rectangle_::getName() { return "Прямоугольник"; }

	//конструктор квадрата
	Rectangle_::Rectangle_(int a) {
		this->a = a;
		b = c = d = a;
		B = C = D = A = 90;
	}

	Rectangle_::Rectangle_() :Parallelogram(55, 30) {
		name = getName();
	};
