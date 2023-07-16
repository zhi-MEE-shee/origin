#pragma once
#include "Triangle.h"


class IsoscelesTriangle : public Triangle
{
protected:
	std::string getName() override;

public:
	IsoscelesTriangle();
};