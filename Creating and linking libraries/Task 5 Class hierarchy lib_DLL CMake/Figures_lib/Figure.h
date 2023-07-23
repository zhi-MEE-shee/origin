#pragma once

#include <iostream>
#include <string>

namespace Figures {

	class Figure
	{
	protected:
		std::string name;
		virtual std::string getName();

	public:
		virtual void print();
	};

}

