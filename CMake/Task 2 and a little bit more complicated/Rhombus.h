#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram
{
protected:
	std::string getName() override;
public:
	Rhombus();
};

