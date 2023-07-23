#pragma once
#include "Figure.h"

namespace Figures {

	class FIGURESLIBRARY_API Triangle : public Figure
	{
	private:
		//конструктор произвольного треугольника
		Triangle(int a, int b, int c, int A, int B, int C);
	protected:
		int a, b, c;
		int A, B, C;
		std::string getName() override;

		//конструктор прямоуголного треугольника
		Triangle(int a, int b, int c, int A, int B);

		//конструктор равнобедренного треугольника
		Triangle(int a, int c, int A, int C);

		//конструктор равностороннего треугольника
		Triangle(int a, int A);


	public:

		Triangle();

		int getSide_a();
		int getSide_b();
		int getSide_c();

		int getAngle_A();
		int getAngle_B();
		int getAngle_C();

		std::string getNameForOutput();

		void print() override;
	};
}
