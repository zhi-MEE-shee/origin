#include "Farewell.h"


std::string Farewell::Leaver::leave(std::string name)
{
	std::string greeting = "До свиданья, " + name + '!';
	return greeting;
}
