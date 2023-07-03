#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "Square.h"
#include <Windows.h>


void print_info(Figure* obj) {
	obj->print();
}


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Triangle obj1;
	print_info(&obj1);

	RightTriangle obj2;
	print_info(&obj2);

	IsoscelesTriangle obj3;
	print_info(&obj3);

	EquilateralTriangle obj4;
	print_info(&obj4);

	Quadrangle obj5;
	print_info(&obj5);

	Parallelogram obj6;
	print_info(&obj6);

	Rectangle_ obj7;
	print_info(&obj7);

	Rhombus obj8;
	print_info(&obj8);

	Square obj9;
	print_info(&obj9);

	return 0;
}