#pragma once
#include "earth_vehicles.h"

class Boots : public Earth_vehicles
{
protected:
	std::string getName() override;

public:
	Boots();

	~Boots() override;

	double getFull_race_time (int race_distance) override;

	std::string getRace_name() override;

	Vehicles_type getRace_type() override;
};