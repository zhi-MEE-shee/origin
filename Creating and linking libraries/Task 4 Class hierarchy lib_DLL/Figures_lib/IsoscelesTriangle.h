#pragma once
#include "Triangle.h"

namespace Figures {

	class IsoscelesTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		IsoscelesTriangle();
	};
}