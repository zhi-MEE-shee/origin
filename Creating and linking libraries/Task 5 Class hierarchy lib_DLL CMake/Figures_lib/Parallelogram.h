#pragma once
#include "Quadrangle.h"

namespace Figures {

	class Parallelogram : public Quadrangle
	{
	protected:
		std::string getName() override;

		//����������� ��������������
		Parallelogram(int a, int c);

		//����������� �����
		Parallelogram(int a, int A, int C);

	public:
		Parallelogram();
	};
}

