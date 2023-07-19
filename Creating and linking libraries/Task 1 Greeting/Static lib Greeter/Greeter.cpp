#include "Greeter.h"


std::string Greeter::greet(std::string name)
{
	std::string greeting = "Здравствуйте, " + name + '!';
	return greeting;
}
