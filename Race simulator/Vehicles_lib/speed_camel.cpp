#include "speed_camel.h"

std::string Speed_camel::getName() { return "Верблюд-быстроход"; }

Speed_camel::Speed_camel()
{
	name = getName();
	speed = 40;
	mooving_time = 10;
	resting_time = 0;
	v_type = Vehicles_type::Ground;
}

Speed_camel::~Speed_camel() {};

double Speed_camel::getFull_race_time(int race_distance) {

	double time = static_cast<double>(race_distance / speed);
	int num_breakes = time / mooving_time;

	if (num_breakes >= 1) {
		for (int i = 1; i <= num_breakes; i++) {
			if (i == 1) {
				resting_time += 5;
			}
			else if (i == 2) {
				resting_time += 6.5;
			}
			else {
				resting_time += 8;
			}
		}
	}
	
	double full_race_time = time + resting_time;
	return full_race_time;
}

std::string Speed_camel::getRace_name() { return name; };

Vehicles_type Speed_camel::getRace_type() { return v_type; }