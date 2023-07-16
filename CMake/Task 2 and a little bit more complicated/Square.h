#pragma once
#include "Rectangle_.h"

class Square : public Rectangle_
{
protected:
	std::string getName() override;
public:
	Square();
};