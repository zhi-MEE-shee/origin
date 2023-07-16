#pragma once
#include "Parallelogram.h"


class Rectangle_ : public Parallelogram
{
protected:
	std::string getName() override;

	//конструктор квадрата
	Rectangle_(int a);

public:
	Rectangle_();
};