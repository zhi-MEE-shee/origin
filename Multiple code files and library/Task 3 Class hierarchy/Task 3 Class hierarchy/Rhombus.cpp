#include "Rhombus.h"


	string Rhombus::getName() { return "����"; }

	Rhombus::Rhombus() :Parallelogram(45, 60, 140) {
		name = getName();
	};


