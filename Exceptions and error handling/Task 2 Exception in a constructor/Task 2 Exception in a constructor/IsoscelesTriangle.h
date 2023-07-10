#pragma once
#include "Triangle.h"


class IsoscelesTriangle : public Triangle
{
protected:
	string getName() override;

	//bool check() override;

public:
	IsoscelesTriangle();
};