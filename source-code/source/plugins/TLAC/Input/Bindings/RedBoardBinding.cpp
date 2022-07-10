#include "RedBoardBinding.h"

namespace TLAC::Input
{
	#define RedBoardInstanceCheckDefault(checkFunc) (RedBoard::InstanceInitialized() ? RedBoard::GetInstance()->checkFunc : false)

	RedBoardBinding::RedBoardBinding(RedBoardButton button) : Button(button)
	{
	}

	RedBoardBinding::~RedBoardBinding()
	{
	}

	bool RedBoardBinding::IsDown()
	{
		return RedBoardInstanceCheckDefault(IsDown(Button));
	}

	bool RedBoardBinding::IsTapped()
	{
		return RedBoardInstanceCheckDefault(IsTapped(Button));
	}

	bool RedBoardBinding::IsReleased()
	{
		return RedBoardInstanceCheckDefault(IsReleased(Button));
	}
}