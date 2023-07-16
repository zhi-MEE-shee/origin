#include "Rhombus.h"


	std::string Rhombus::getName() { return "Ромб"; }

	Rhombus::Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};


