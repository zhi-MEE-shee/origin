#pragma once
#include "Parallelogram.h"

namespace Figures {

	class FIGURESLIBRARY_API Rhombus : public Parallelogram
	{
	protected:
		std::string getName() override;
	public:
		Rhombus();
	};
}

