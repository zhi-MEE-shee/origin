#include "camel.h"

std::string Camel::getName() { return "Верблюд"; }

Camel::Camel()
{
	name = getName();
	speed = 10;
	mooving_time = 30;
	resting_time = 0;
	v_type = Vehicles_type::Ground;
};

Camel::~Camel() {};

double Camel::getFull_race_time(int race_distance) {

	double time = static_cast<double>(race_distance / speed);
	int num_breakes = time / mooving_time;

	if (num_breakes >= 1) {
		for (int i = 1; i <= num_breakes; ++i) {
			if (i == 1) {
				resting_time += 5;
			}
			else {
				resting_time += 8;
			}
		}
	}
	
	double full_race_time = time + resting_time;
	return full_race_time;
}

std::string Camel::getRace_name() { return name; }

Vehicles_type Camel::getRace_type() { return v_type; }