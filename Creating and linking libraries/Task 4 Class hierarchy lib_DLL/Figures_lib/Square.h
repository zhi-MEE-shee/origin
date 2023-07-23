#pragma once
#include "Rectangle_.h"

namespace Figures {

	class FIGURESLIBRARY_API Square : public Rectangle_
	{
	protected:
		std::string getName() override;
	public:
		Square();
	};
}