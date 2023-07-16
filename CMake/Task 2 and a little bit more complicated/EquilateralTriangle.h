#pragma once
#include "Triangle.h"


class EquilateralTriangle : public Triangle
{
protected:
	std::string getName() override;

public:
	EquilateralTriangle();
};
