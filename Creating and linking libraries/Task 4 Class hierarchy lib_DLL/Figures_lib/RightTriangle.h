#pragma once
#include "Triangle.h"

namespace Figures {

	class RightTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		RightTriangle();
	};
}