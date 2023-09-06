#pragma once
#include "earth_vehicles.h"

class Camel : public Earth_vehicles
{
protected:
	
	std::string getName() override;

public:
	Camel();
	double getFull_race_time(int race_distance) override;

	std::string getRace_name() override;
};