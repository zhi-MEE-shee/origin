#include "Square.h"

	std::string Figures::Square::getName() { return "�������"; }

	Figures::Square::Square() : Rectangle_(40) {
		name = getName();
	}
