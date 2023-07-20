#pragma once
#include "Triangle.h"

namespace Figures {

	FIGURESLIBRARY_API class RightTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		RightTriangle();
	};
}