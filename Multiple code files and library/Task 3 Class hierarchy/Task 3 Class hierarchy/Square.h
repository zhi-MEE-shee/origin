#pragma once
#include "Rectangle_.h"

class Square : public Rectangle_
{
protected:
	string getName() override;
public:
	Square();
};