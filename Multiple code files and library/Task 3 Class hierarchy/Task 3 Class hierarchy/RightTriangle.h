#pragma once
#include "Triangle.h"


class RightTriangle : public Triangle
{
protected:
	string getName() override;

public:
	RightTriangle();
};