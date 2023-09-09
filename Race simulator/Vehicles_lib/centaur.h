#pragma once
#include "earth_vehicles.h"

class Centaur : public Earth_vehicles
{
protected:
	std::string getName() override;

public:
	Centaur();

	double getFull_race_time(int race_distance) override;

	std::string getRace_name() override;

	Vehicles_type getRace_type() override;
};