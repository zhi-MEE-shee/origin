#include "centaur.h"

std::string Centaur::getName() { return "Кентавр"; }

Centaur::Centaur()
{
	name = getName();
	speed = 15;
	mooving_time = 8;
	resting_time = 0;
	v_type = Vehicles_type::Ground;
};

Centaur::~Centaur() {};

double Centaur::getFull_race_time(int race_distance) {

	double time = static_cast<double>(race_distance / speed);
	int num_breakes = time / mooving_time;

	if (num_breakes >= 1) {
		for (int i = 1; i <= num_breakes; i++) {
			resting_time += 2;
		}
	}
	
	double full_race_time = time + resting_time;
	return full_race_time;
}

std::string Centaur::getRace_name() { return name; }

Vehicles_type Centaur::getRace_type() { return v_type; }