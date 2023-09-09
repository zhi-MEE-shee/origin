#pragma once
#include "earth_vehicles.h"

class Speed_camel : public Earth_vehicles
{
protected:
	
	std::string getName() override;

public:
	Speed_camel();

	double getFull_race_time(int race_distance) override;

	std::string getRace_name() override;

	Vehicles_type getRace_type() override;
};