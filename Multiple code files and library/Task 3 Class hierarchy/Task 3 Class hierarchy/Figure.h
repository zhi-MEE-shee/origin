#pragma once
#include <iostream>
#include <string>
using namespace std;

class Figure
{
protected:
	string name;
	virtual string getName();

public:
	virtual void print();
};
