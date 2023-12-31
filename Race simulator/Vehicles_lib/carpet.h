#pragma once
#include "air_vehicles.h"

class Carpet : public Air_vehicles
{
protected:
	
	std::string getName() override;

public:

	Carpet();

	~Carpet() override;

	double getFull_race_time (int race_distance) override;
	double getReduction_factor (int& distance) override;

	std::string getRace_name() override;

	Vehicles_type getRace_type() override;
};