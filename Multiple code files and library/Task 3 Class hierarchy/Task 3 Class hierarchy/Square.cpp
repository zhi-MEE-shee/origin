#include "Square.h"

	string Square::getName() { return " вадрат"; }

	Square::Square() : Rectangle_(40) {
		name = getName();
	}
