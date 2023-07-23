#pragma once
#include "Triangle.h"

namespace Figures {

	class FIGURESLIBRARY_API RightTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		RightTriangle();
	};
}