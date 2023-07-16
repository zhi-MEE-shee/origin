#pragma once
#include "Triangle.h"


class RightTriangle : public Triangle
{
protected:
	std::string getName() override;

public:
	RightTriangle();
};