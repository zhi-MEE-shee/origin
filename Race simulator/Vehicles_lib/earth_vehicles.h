#pragma once
#include "vehicles.h"

class Earth_vehicles : public Vehicles
{
protected:
	int mooving_time{};
	double resting_time{};
	std::string getName() override;
	
public:
	double getFull_race_time(int race_distance) override;

	std::string getRace_name() override;
	
	Vehicles_type getRace_type() override;
};