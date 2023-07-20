#pragma once
#include "Triangle.h"

namespace Figures {

	class EquilateralTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		EquilateralTriangle();
	};
}
