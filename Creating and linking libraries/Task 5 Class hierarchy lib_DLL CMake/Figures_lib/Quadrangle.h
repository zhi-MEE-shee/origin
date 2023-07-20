#pragma once
#include "Figure.h"

namespace Figures {

	FIGURESLIBRARY_API class Quadrangle : public Figure
	{
	private:
		std::string getName() override;
	protected:
		int a, b, c, d;
		int A, B, C, D;

		//конструктор четырехугольника
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

		//конструктор параллелограмма
		Quadrangle(int a, int c, int A, int C);

	public:
		Quadrangle();

		int getSide_a();
		int getSide_b();
		int getSide_c();
		int getSide_d();
		int getAngle_A();
		int getAngle_B();
		int getAngle_C();
		int getAngle_D();

		void print() override;
	};
}