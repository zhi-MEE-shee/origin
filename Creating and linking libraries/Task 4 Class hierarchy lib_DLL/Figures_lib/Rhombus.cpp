#include "Rhombus.h"


	std::string Figures::Rhombus::getName() { return "����"; }

	Figures::Rhombus::Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};


