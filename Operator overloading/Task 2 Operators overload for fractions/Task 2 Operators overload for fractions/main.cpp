#include <iostream>
#include <Windows.h>

using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator = 0, int denominator = 1)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		fractionReduction();
	}

	int setNumerator(int numerator_) {
		this->numerator_ = numerator_;
	}

	Fraction& operator++() {
		++numerator_;
		++denominator_;
		return *this;
	}
	Fraction& operator--() {
		--numerator_;
		--denominator_;
		return *this;
	}

	Fraction& operator++(int) {
		Fraction fraction = *this;
		++(*this);
		return fraction;
	}
	Fraction& operator--(int) {
		Fraction fraction = *this;
		--(*this);
		return fraction;
	}

	Fraction operator+ () const {
			return +Fraction{ numerator_, denominator_ };
	}
	
	Fraction operator- () const {
			return Fraction{ -numerator_, -denominator_ };
	}



	friend ostream& operator<< (ostream& out, const Fraction& fraction);
	friend istream& operator>> (istream& in, Fraction& fraction);
//	friend Fraction operator+ (Fraction& f1, Fraction& f2);
//	friend Fraction operator- (Fraction& f1, Fraction& f2);
//	friend Fraction operator* (Fraction& f1, Fraction& f2);
//	friend Fraction operator/ (Fraction& f1, Fraction& f2);
//
//	Fraction operator+ ( Fraction& f2){
//		return  Fraction(numerator_ + f2.numerator_, denominator_ + f2.denominator_);
//	}
	Fraction operator+ (Fraction other) {
		return  Fraction(numerator_ + other.numerator_, denominator_ + other.denominator_);
	}
	Fraction operator- ( Fraction other) {
		return  Fraction(numerator_ - other.numerator_, denominator_ - other.denominator_);
	}

	Fraction operator* (Fraction other) {
		return  Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
	}
	Fraction operator/ ( Fraction other) {
		return  Fraction{numerator_ * other.denominator_, denominator_ * other.numerator_ };
	}
	//ищем общий делитель
	int commonDivisor(int numerator_, int denominator_) {

		return (denominator_ == 0) ? (numerator_ > 0 ? numerator_ : -numerator_)
									: commonDivisor(denominator_, numerator_ % denominator_);
	}
	//делим числитель и знаменатель на общий делитель
	void fractionReduction() {
		if (numerator_ != 0 && denominator_ != 0) {
			int commonDivisor{ Fraction::commonDivisor(numerator_, denominator_) };
			numerator_ /= commonDivisor;
			denominator_ /= commonDivisor;
		}
	}
};

ostream& operator<< (ostream& out, const Fraction& fraction) {
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

istream& operator>> (istream& in, Fraction& fraction) {
	cout << "¬ведите числитель дроби: ";
	in >> fraction.numerator_;
	cout << "¬ведите знаменатель дроби: ";
	in >> fraction.denominator_;

	fraction.fractionReduction();
	return in;
}
/*
Fraction operator+ (Fraction& f1, Fraction& f2) {
	return Fraction{ f1.numerator_ + f2.numerator_, f1.denominator_ + f2.denominator_ };
}
Fraction operator- (Fraction& f1, Fraction& f2) {
	return Fraction{ f1.numerator_ - f2.numerator_, f1.denominator_ - f2.denominator_ };
}
Fraction operator* (Fraction& f1, Fraction& f2) {
	return Fraction{ f1.numerator_ * f2.numerator_, f1.denominator_ * f2.denominator_ };
}
Fraction operator/ (Fraction& f1, Fraction& f2) {
	return Fraction{ f1.numerator_ * f2.denominator_, f1.denominator_ * f2.numerator_ };
}*/


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1{};
	Fraction f2{};
	cin >> f1;
	cin >> f2;
	

	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << "++" << f1 << " * " << f2 << " = " << (++f1) * f2 << endl;
	cout << "«начение дроби 1 = " << f1 << endl;
	cout << f1 << "-- / " << f2 << " = " << (f1--) / f2 << endl;
	cout << "«начение дроби 1 = " << f1 << endl;

	return 0;
}