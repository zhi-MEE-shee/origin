#pragma once
#include "Quadrangle.h"

namespace Figures {

	class Parallelogram : public Quadrangle
	{
	protected:
		std::string getName() override;

		//конструктор прямоугольника
		Parallelogram(int a, int c);

		//конструктор ромба
		Parallelogram(int a, int A, int C);

	public:
		Parallelogram();
	};
}

