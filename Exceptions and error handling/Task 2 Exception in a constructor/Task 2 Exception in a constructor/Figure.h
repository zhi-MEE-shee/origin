#pragma once
#include <iostream>
#include <string>

using namespace std;

class Figure
{
protected:
	string name;
	int quantOfSides;

	Figure(int sides);

	virtual string getName();
	int getQuantOfSides();
//	virtual bool check();

public:
	Figure();
	virtual void print_info();
};
