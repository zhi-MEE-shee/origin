#include "carpet.h"

std::string Carpet:: getName() { return "Ковёр-самолёт"; }


Carpet::Carpet()
{
	name = getName();
	speed = 10;
	
};

double Carpet::getFull_race_time (int race_distance) {

	double distance = race_distance * getReduction_factor(race_distance);
	
	double time = distance / speed;
	return time;
}

double Carpet::getReduction_factor (int& distance) {

	if (distance < 1000) {
		return 1.0;
	}
	else if (distance > 1000 && distance < 5000) {
		return 1.0 - static_cast<double>(3 / 100);
	}
	else if (distance > 5000 && distance < 10000) {
		return 1.0 - static_cast<double>(10 / 100);
	}
	else if (distance > 10000) {
		return 1.0 - static_cast<double>(5 / 100);
	}

}

std::string Carpet::getRace_name() { return name; };