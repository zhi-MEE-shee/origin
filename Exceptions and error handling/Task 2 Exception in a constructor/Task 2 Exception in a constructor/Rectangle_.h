#pragma once
#include "Quadrangle.h"

class Rectangle_ : public Quadrangle
{
protected:
	string getName() override;

	//bool check() override;

public:
	Rectangle_();
};