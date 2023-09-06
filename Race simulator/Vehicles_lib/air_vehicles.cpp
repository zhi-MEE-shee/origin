#include "air_vehicles.h"

std::string Air_vehicles::getName() { return "Воздушный транспорт";}

double Air_vehicles::getFull_race_time(int race_distance) { return 0; };

double Air_vehicles::getReduction_factor(int& distance) { return 0; };

std::string Air_vehicles::getRace_name() { return name; };