#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);

};
bool operator== (const Fraction& f1, const Fraction& f2) {
	return (f1.numerator_ == f2.numerator_ && f1.denominator_ == f2.denominator_);
}
bool operator!= (const Fraction& f1, const Fraction& f2) {
	return !(f1 == f2);
}

bool operator> (const Fraction& f1, const Fraction& f2) 
{
	int n1 = f1.numerator_ * f2.denominator_;
	int n2 = f2.numerator_ * f1.denominator_;	
	return n1 > n2;
}
bool operator<= (const Fraction& f1, const Fraction& f2) {
	return !(f1 > f2);
}

bool operator>= (const Fraction& f1, const Fraction& f2) 
{
	int tmp_n1 = f1.numerator_ * f2.denominator_;
	int tmp_n2 = f2.numerator_ * f1.denominator_;
	return tmp_n1 >= tmp_n2;
}
bool operator< (const Fraction& f1, const Fraction& f2) {
	return !(f1 >= f2);
}

int main()
{
	Fraction f1(6, 5);
	Fraction f2(2, 3);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';

	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';

	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';

	return 0;
}