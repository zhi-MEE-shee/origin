#include "broom.h"

std::string Broom::getName() { return "Ковёр-самолёт"; }


Broom::Broom()
{
	name = getName();
	speed = 20;
	v_type = Vehicles_type::Air;
};

double Broom::getFull_race_time (int race_distance) {

	double distance = race_distance * getReduction_factor(race_distance);

	double time = distance / speed;
	return time;
}

double Broom::getReduction_factor (int& distance) {

	int tmp = distance / 1000;
	
	if (tmp == 0) {
		return 1.0;
	}
	else if (tmp > 0){
		return 1.0 - static_cast<double>(tmp / 100);
	}
}

std::string Broom::getRace_name() { return name; };

Vehicles_type Broom::getRace_type() { return v_type; }