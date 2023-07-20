#include "Square.h"

	std::string Figures::Square::getName() { return " вадрат"; }

	Figures::Square::Square() : Rectangle_(40) {
		name = getName();
	}
