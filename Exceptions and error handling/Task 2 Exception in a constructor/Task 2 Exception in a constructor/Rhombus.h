#pragma once
#include "Quadrangle.h"

class Rhombus : public Quadrangle
{
protected:
	string getName() override;

	//bool check() override;

public:
	Rhombus();
};