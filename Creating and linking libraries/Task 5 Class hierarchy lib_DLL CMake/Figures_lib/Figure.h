#pragma once

#ifdef FIGURESLIBRARYDYNAMIC
#define FIGURESLIBRARY_API __declspec(dllexport)
#else
#define FIGURESLIBRARY_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

namespace Figures {

	FIGURESLIBRARY_API class Figure
	{
	protected:
		std::string name;
		virtual std::string getName();

	public:
		virtual void print();
	};

}

