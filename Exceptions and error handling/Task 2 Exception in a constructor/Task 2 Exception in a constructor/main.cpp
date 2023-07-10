#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Parallelogram.h"
#include "Rectangle_.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "Square.h"
#include <Windows.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	try {
		Triangle obj1;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl;
	}

	try {
		RightTriangle obj2;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}

	try {
		IsoscelesTriangle obj3;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}

	try {
		EquilateralTriangle obj4;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}


	try {
		Quadrangle obj5;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}

	try {
		Parallelogram obj6;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}
	
	try {
		Square obj7;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}

	try {
		Rhombus obj7;
	}
	catch (const domain_error& err) {
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl << endl;
	}


	return 0;
}

