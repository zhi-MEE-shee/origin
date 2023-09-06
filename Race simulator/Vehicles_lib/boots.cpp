#include "boots.h"

std::string Boots::getName() { return "Ботинки-вездеходы"; }

Boots::Boots()
{
	name = getName();
	speed = 6;
	mooving_time = 60;
	resting_time = 0;
};

double Boots::getFull_race_time( int race_distance) {

	double time = static_cast<double>(race_distance / speed);
	int num_breakes = time / mooving_time;

	if (num_breakes >= 1) {
		for (int i = 1; i <= num_breakes; ++i) {
			if (i == 1) {
				resting_time += 10;
			}
			else {
				resting_time += 5;
			}
		}
	}
	
	double full_race_time = time + resting_time;
	return full_race_time;
}

std::string Boots::getRace_name() { return name; };