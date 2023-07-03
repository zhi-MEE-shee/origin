#pragma once
#include "Triangle.h"


class EquilateralTriangle : public Triangle
{
protected:
	string getName() override;

public:
	EquilateralTriangle();
};
