#pragma once
#include "IInputBinding.h"
#include "../RedBoard/RedBoard.h"

namespace TLAC::Input
{
	class RedBoardBinding : public IInputBinding
	{
	public:
		RedBoardButton Button;

		RedBoardBinding(RedBoardButton button);
		~RedBoardBinding();

		bool IsDown() override;
		bool IsTapped() override;
		bool IsReleased() override;
	};
}