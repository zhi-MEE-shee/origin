#pragma once
#include "Rectangle_.h"

namespace Figures {

	class Square : public Rectangle_
	{
	protected:
		std::string getName() override;
	public:
		Square();
	};
}