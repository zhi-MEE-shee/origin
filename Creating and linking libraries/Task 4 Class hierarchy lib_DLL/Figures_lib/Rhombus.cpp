#include "Rhombus.h"


	std::string Figures::Rhombus::getName() { return "Ромб"; }

	Figures::Rhombus::Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};


