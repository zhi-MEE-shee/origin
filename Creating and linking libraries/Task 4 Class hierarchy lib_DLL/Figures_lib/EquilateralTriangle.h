#pragma once
#include "Triangle.h"

namespace Figures {

	FIGURESLIBRARY_API class EquilateralTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		EquilateralTriangle();
	};
}
