#include "MyMath.h"

int sum(int a, int b) { return a + b; }

int diff(int a, int b) { return a - b; }

int multi(int a, int b) { return a * b; }

double divi(int a, int b) { return static_cast <double> (a) / b; }

long double expo(int a, int b) {

	long double exponent = a;
	if (a == 0) { return 0; }
	else if (b == 0) { return 1; }
	else if (a > 0 && b > 0) {

		for (int i = 1; i != b; ++i) {
			exponent *= a;
		}
	}
	else if (a > 0 && b < 0) 
	{
		b *= (-1);
		for (int i = 1; i != b; ++i) {
			exponent *= a;
		}
		exponent = 1 / exponent;
	}
	return exponent;
}