#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram
{
protected:
	string getName() override;
public:
	Rhombus();
};

