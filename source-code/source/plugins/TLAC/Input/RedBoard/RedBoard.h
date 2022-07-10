#pragma once
#include "../IInputDevice.h"
#include "RedBoardState.h"
#include "RedBoardButton.h"
#include <SetupAPI.h>
#include <initguid.h>
#include <usbiodef.h>
#include <winusb.h>

namespace TLAC::Input
{

	class RedBoard : public IInputDevice
	{
	public:
		RedBoard();
		~RedBoard();

		static bool TryInitializeInstance();

		bool Initialize();
		bool PollInput() override;
		bool SetLED();
		bool IsDown(RedBoardButton button);
		bool IsUp(RedBoardButton button);
		bool IsTapped(RedBoardButton button);
		bool IsReleased(RedBoardButton button);

		bool WasDown(RedBoardButton button);
		bool WasUp(RedBoardButton button);
		uint32_t GetSlider();
		static inline bool InstanceInitialized() { return instance != nullptr; };
		static inline RedBoard *GetInstance() { return instance; };
		static inline void DeleteInstance()
		{
			delete instance;
			instance = nullptr;
		};

	private:
		static RedBoard *instance;
		RedBoardState lastState;
		RedBoardState currentState;
		int *buttonLed = reinterpret_cast<int *>(0x14119b950);
		uint64_t *partionLed = reinterpret_cast<uint64_t *>(*(uint64_t *)0x140eda330 + 0xc9);
		uint64_t *sliderLedInit = reinterpret_cast<uint64_t *>((uint64_t *)0x14cc5dea8);
		UCHAR *sliderLedData = nullptr;
	};
}
