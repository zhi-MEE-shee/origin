#pragma once

class Counter
{
private:
	int num;

public:
	Counter();
	Counter(int num);

	int getNum();
	int NumPlus();
	int NumMinus();
};
