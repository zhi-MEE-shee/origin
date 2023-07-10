#pragma once
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
protected:
	string getName() override;

	//bool check() override;

public:
	Parallelogram();
};
