#pragma once

#ifdef FIGURESLIBRARYDYNAMIC_EXPORTS
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

namespace Figures {

	class FIGURESLIBRARY_API Figure
	{
	protected:
		std::string name;
		virtual std::string getName();

	public:
		virtual void print();
	};

}

