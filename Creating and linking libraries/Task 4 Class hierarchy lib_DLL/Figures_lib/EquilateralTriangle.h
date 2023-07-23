#pragma once
#include "Triangle.h"

namespace Figures {

	class FIGURESLIBRARY_API EquilateralTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		EquilateralTriangle();
	};
}
