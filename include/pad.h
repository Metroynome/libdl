/***************************************************
 * FILENAME :    pad.h
 * 
 * DESCRIPTION :
 *     Contains pad specific offsets and structures for Deadlocked.
 * 
 * NOTES :
 *     Each offset is determined per app id.
 *     This is to ensure compatibility between versions of Deadlocked/Gladiator.
 *     
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */

/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

#ifndef _LIBDL_PAD_H
#define _LIBDL_PAD_H

#include <tamtypes.h>
#include "common.h"

#define PAD_PORT_MAX        2
#define PAD_SLOT_MAX        4

#define PAD_LEFT            0x0080
#define PAD_DOWN            0x0040
#define PAD_RIGHT           0x0020
#define PAD_UP              0x0010
#define PAD_START           0x0008
#define PAD_R3              0x0004
#define PAD_L3              0x0002
#define PAD_SELECT          0x0001
#define PAD_SQUARE          0x8000
#define PAD_CROSS           0x4000
#define PAD_CIRCLE          0x2000
#define PAD_TRIANGLE        0x1000
#define PAD_R1              0x0800
#define PAD_L1              0x0400
#define PAD_R2              0x0200
#define PAD_L2              0x0100


typedef struct PAD { // 0x5c0
	union {
	/* 0x000 */ u128 pad_buf[16];
			struct {
				unsigned char ok;
				unsigned char mode;
				unsigned short btns;
				// joysticks
				unsigned char rjoy_h;
				unsigned char rjoy_v;
				unsigned char ljoy_h;
				unsigned char ljoy_v;
				// pressure mode
				unsigned char right_p;
				unsigned char left_p;
				unsigned char up_p;
				unsigned char down_p;
				unsigned char triangle_p;
				unsigned char circle_p;
				unsigned char cross_p;
				unsigned char square_p;
				unsigned char l1_p;
				unsigned char r1_p;
				unsigned char l2_p;
				unsigned char r2_p;
			} buffer;
	};
	/* 0x100 */ float analog[16];
	/* 0x140 */ float hudAnalog[16];
	/* 0x180 */ unsigned char profile[4];
	/* 0x184 */ unsigned char vib_profile[4];
	/* 0x188 */ unsigned char act_direct[4];
	/* 0x18c */ short int invalidTimer;
	/* 0x18e */ short int ringIndex;
	/* 0x190 */ int ringValidSize;
	/* 0x194 */ int socket;
	/* 0x198 */ int phase;
	/* 0x19c */ int state;
	/* 0x1a0 */ int bits;
	/* 0x1a4 */ int bitsOn;
	/* 0x1a8 */ int bitsOff;
	/* 0x1ac */ int bitsPrev;
	/* 0x1b0 */ int digitalBits;
	/* 0x1b4 */ int digitalBitsOn;
	/* 0x1b8 */ int digitalBitsOff;
	/* 0x1bc */ int digitalBitsPrev;
	/* 0x1c0 */ int hudBits;
	/* 0x1c4 */ int hudBitsOn;
	/* 0x1c8 */ int hudBitsOff;
	/* 0x1cc */ int hudDivert;
	/* 0x1d0 */ int handsOff;
	/* 0x1d4 */ int handsOffStick;
	/* 0x1d8 */ int useAnalog;
	/* 0x1dc */ int term_id;
	/* 0x1e0 */ int bitsOnRing[30];
	/* 0x258 */ float analogAngRing[30];
	/* 0x2d0 */ float analogMagRing[30];
	/* 0x348 */ int unmaskedBits;
	/* 0x34c */ int lagIndex;
	/* 0x350 */ int lagValidSize;
	/* 0x354 */ int bits_Lagged[7];
	/* 0x370 */ int digitalBits_Lagged[7];
	/* 0x38c */ float analog_Lagged[7][16];
	/* 0x54c */ u8 port;
	/* 0x54d */ u8 repeatDelay;
	/* 0x54e */ u8 repeatSpeed;
	/* 0x54f */ u8 repeatCounter;
	/* 0x550 */ u8 multi_tap_connected;
	/* 0x551 */ u8 disconnected;
	/* 0x552 */ u8 act_align[6];
	/* 0x558 */ u8 slot;
	/* 0x559 */ char initialized;
	/* 0x55c */ int rterm_id;
	/* 0x560 */ int id;
	/* 0x564 */ int exid;
	/* 0x568 */ int lagFrames;
	/* 0x56c */ void *RawPadInputCallback;
	/* 0x570 */ void *pCallbackData;
	/* 0x574 */ u8 rdata[32];
	/* 0x594 */ int ipad[10];
} PAD;

typedef struct padButtonStatus {
    unsigned char ok;
    unsigned char mode;
    unsigned short btns;
    // joysticks
    unsigned char rjoy_h;
    unsigned char rjoy_v;
    unsigned char ljoy_h;
    unsigned char ljoy_v;
    // pressure mode
    unsigned char right_p;
    unsigned char left_p;
    unsigned char up_p;
    unsigned char down_p;
    unsigned char triangle_p;
    unsigned char circle_p;
    unsigned char cross_p;
    unsigned char square_p;
    unsigned char l1_p;
    unsigned char r1_p;
    unsigned char l2_p;
    unsigned char r2_p;
} PadButtonStatus;

typedef struct PadHistory {
    u16 btns;
    u8 rjoy_h;
    u8 rjoy_v;
    u8 ljoy_h;
    u8 ljoy_v;
    short id;
} PadHistory;

struct pad_frame { // 0x2
	/* 0x0 */ unsigned char data[2];
};

typedef struct PadStream { // 0x1e0
	/* 0x000 */ short unsigned int button_bits[4];
	/* 0x008 */ short unsigned int analog_stick[4];
	/* 0x010 */ short unsigned int right_analog_stick[4];
	/* 0x018:0 */ unsigned char frames_with_btn_diffs : 4;
	/* 0x019 */ unsigned char btn_bit_diffs[32];
	/* 0x03c */ int cur_btn_bit_offset;
	/* 0x040 */ struct pad_frame prev_frame;
	/* 0x042 */ unsigned char pad_stream_buf[2][200];
	/* 0x1d4 */ int totalPadStreamBytes;
	/* 0x1d8 */ int curFrame;
	/* 0x1dc */ int padStreamReady;
} PadStream_t;

/*
 * NAME :    padGetButton
 * 
 * DESCRIPTION :
 *       Returns 1 when the user is pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetButton(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padGetAnyButton
 * 
 * DESCRIPTION :
 *       Returns 1 when the user is pressing any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetAnyButton(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padGetButtonDown
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the user starts pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetButtonDown(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padGetAnyButtonDown
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the user starts pressing any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetAnyButtonDown(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padGetButtonUp
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the user releases the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetButtonUp(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padGetAnyButtonUp
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the user releases any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int padGetAnyButtonUp(int localPlayerIndex, u16 buttonMask);

/*
 * NAME :    padResetInput
 * 
 * DESCRIPTION :
 *       Resets the given ports inputs.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          localPlayerIndex:           Which local player's controller to read.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void padResetInput(int localPlayerIndex);

/*
 * NAME :    padDisableInput
 * 
 * DESCRIPTION :
 *       Disables the pad input.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void padDisableInput(void);

/*
 * NAME :    padEnableInput
 * 
 * DESCRIPTION :
 *       Enables the pad input.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void padEnableInput(void);

/*
 * NAME :    padGetMappedPad
 * 
 * DESCRIPTION :
 *       Returns the remapped pad bits for the given player's pad.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int padGetMappedPad(int bits, int index);

#endif // _LIBDL_PAD_H
