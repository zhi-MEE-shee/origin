#pragma once
#include <iostream>

#ifdef DYNAMIC_LIB_FAREWELL_EXPORTS
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

