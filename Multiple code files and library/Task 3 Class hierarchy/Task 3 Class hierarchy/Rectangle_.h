#pragma once
#include "Parallelogram.h"


class Rectangle_ : public Parallelogram
{
protected:
	string getName() override;

	//����������� ��������
	Rectangle_(int a);

public:
	Rectangle_();
};