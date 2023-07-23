#pragma once
#include "Triangle.h"

namespace Figures {

	class FIGURESLIBRARY_API IsoscelesTriangle : public Triangle
	{
	protected:
		std::string getName() override;

	public:
		IsoscelesTriangle();
	};
}