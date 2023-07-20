#pragma once
#include <iostream>

#ifndef DYNAMIC_LIB_FAREWELL
	#define FAREWELL_LIB_API __declspec(dllexport)
#else
	#define FAREWELL_LIB_API __declspec(dllimport)
#endif //!DYNAMIC_LIB_FAREWELL


namespace Farewell{

	class Leaver
	{
	public:
		FAREWELL_LIB_API std::string leave(std::string name);
	};

}

