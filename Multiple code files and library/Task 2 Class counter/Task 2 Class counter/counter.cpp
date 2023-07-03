#include "counter.h"

Counter::Counter() { num = 0; }

Counter::Counter(int num) { this->num = num; }

int Counter::getNum() { return num; }
int Counter::NumPlus() { return ++num; }
int Counter::NumMinus() { return --num; }

