#pragma once
#include <string>

enum class Vehicles_type {

	Air,
	Ground
};


class Vehicles
{
protected:
	std::string name;
	int speed{};
	Vehicles_type v_type;
public:
	virtual ~Vehicles();
	virtual std::string getName();
	virtual double getFull_race_time(int race_distance);
	virtual std::string getRace_name();
	virtual Vehicles_type getRace_type();
};

