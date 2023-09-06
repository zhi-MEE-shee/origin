#pragma once
#include <string>

class Vehicles
{
protected:
	std::string name;
	int speed{};
	
public:
	
	virtual std::string getName();
	virtual double getFull_race_time(int race_distance);
	virtual std::string getRace_name();

};

