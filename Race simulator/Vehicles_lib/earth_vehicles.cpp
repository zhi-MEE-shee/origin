#include "earth_vehicles.h"
Earth_vehicles::~Earth_vehicles() {};

std::string Earth_vehicles::getName() { return "�������� ���������"; }

double Earth_vehicles::getFull_race_time(int race_duration) { return 0; };

std::string Earth_vehicles::getRace_name() { return name; };

Vehicles_type Earth_vehicles::getRace_type() { return v_type; }