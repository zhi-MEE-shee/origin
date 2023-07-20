#include "equilateraltriangle.h"
#include "isoscelestriangle.h"
#include "rhombus.h"
#include "righttriangle.h"
#include "square.h"

#include <Windows.h>


void print_info(Figures::Figure* obj) {
	obj->print();
}


int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	Figures::Triangle obj1;
	print_info(&obj1);

	Figures::RightTriangle obj2;
	print_info(&obj2);

	Figures::IsoscelesTriangle obj3;
	print_info(&obj3);

	Figures::EquilateralTriangle obj4;
	print_info(&obj4);

	Figures::Quadrangle obj5;
	print_info(&obj5);

	Figures::Parallelogram obj6;
	print_info(&obj6);

	Figures::Rectangle_ obj7;
	print_info(&obj7);

	Figures::Rhombus obj8;
	print_info(&obj8);

	Figures::Square obj9;
	print_info(&obj9);

	return 0;
}