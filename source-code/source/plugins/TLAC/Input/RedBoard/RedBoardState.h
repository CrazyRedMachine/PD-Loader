#pragma once
#include "../../framework.h"

#define INPUT_REPORT_ID           0x01
#define REPORTID_LIGHT_OUTPUT_1   0x04
#define REPORTID_LIGHT_OUTPUT_2   0x05
#define REPORTID_LIGHT_OUTPUT_3   0x06
#define REPORTID_LIGHT_COMPRESSED 0x0B

#define DPAD_UP_MASK_ON 0x00
#define DPAD_UPRIGHT_MASK_ON 0x01
#define DPAD_RIGHT_MASK_ON 0x02
#define DPAD_DOWNRIGHT_MASK_ON 0x03
#define DPAD_DOWN_MASK_ON 0x04
#define DPAD_DOWNLEFT_MASK_ON 0x05
#define DPAD_LEFT_MASK_ON 0x06
#define DPAD_UPLEFT_MASK_ON 0x07
#define DPAD_NOTHING_MASK_ON 0x08

#define TRIANGLE 0x08 //X
#define SQUARE 0x01 //Y
#define CROSS 0x02 //B
#define CIRCLE 0x04 //A  
#define START   0x200
#define SERVICE 0x100
#define TEST	0x1000

namespace TLAC::Input
{
#pragma pack(1)
	struct RedBoardState
	{
		union {
			uint8_t state[9];
			struct split_s
			{
				uint8_t  report_id;
				uint16_t buttons; // 16 buttons; see JoystickButtons_t for bit mapping
				uint8_t  HAT;	// HAT switch; one nibble w/ unused nibble
				uint32_t axis;
				uint8_t  VendorSpec;
			} split;
		};
	};
}