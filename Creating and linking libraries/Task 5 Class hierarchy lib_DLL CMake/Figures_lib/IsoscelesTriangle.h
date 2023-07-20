#pragma once
#include "Triangle.h"

namespace Figures {

	FIGURESLIBRARY_API class IsoscelesTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		IsoscelesTriangle();
	};
}