#include "Square.h"

	std::string Square::getName() { return " вадрат"; }

	Square::Square() : Rectangle_(40) {
		name = getName();
	}
