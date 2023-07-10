#pragma once
#include "Quadrangle.h"

class Square : public Quadrangle
{
protected:
	string getName() override;
	//bool check() override;
public:
	Square();
};