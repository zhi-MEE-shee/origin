#include "Rhombus.h"


	std::string Rhombus::getName() { return "����"; }

	Rhombus::Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};


