#include "eagle.h"

std::string Eagle::getName() { return "Îð¸ë"; }


Eagle::Eagle()
{
	name = getName();
	speed = 8;

};

double Eagle::getFull_race_time (int race_distance) {

	double distance = race_distance * getReduction_factor(race_distance);

	double time = distance / speed;
	return time;
}

double Eagle::getReduction_factor (int& distance) {

	return 1.0 - static_cast<double>(6 / 100);
}

std::string Eagle::getRace_name() { return name; };