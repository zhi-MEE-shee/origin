#pragma once
#include "vehicles.h"

class Air_vehicles : public Vehicles
{
protected:
	
	std::string getName() override;

public:
	double getFull_race_time(int race_distance) override;
	virtual double getReduction_factor (int& distance);

	std::string getRace_name() override;
};
