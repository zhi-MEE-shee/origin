#include "Figure.h"

string Figure::getName() { return "Фигура"; }
int Figure::getQuantOfSides() { return quantOfSides; }

Figure::Figure(int sides) {
	quantOfSides = sides;
};

Figure::Figure() : Figure(0) {
	name = getName();
};
//
//bool Figure::check() {
//	return quantOfSides == 0 ? true : false;
//}

void Figure::print_info() {};

