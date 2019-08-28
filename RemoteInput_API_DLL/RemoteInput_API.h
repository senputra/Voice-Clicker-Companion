#pragma once

// #define WINDOWS
#define MACOS

#ifndef REMOTEINPUT_API_H
#define REMOTEINPUT_API_H

// #ifdef REMOTEINPUTAPIDLL_EXPORTS
// #define REMOTEINPUT_API __declspec(dllexport)
// #else
// #define REMOTEINPUT_API __declspec(dllimport)
// #endif

#ifdef MACOS
#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#endif

#include <iostream>
#include <stdint.h>

class RemoteInputAPI
{

public:
	RemoteInputAPI();

	void execute(uint8_t *command);

private:
	uint8_t *command = nullptr;

	static const uint8_t INPUT_TYPE_KEYBOARD = 0;
	static const uint8_t INPUT_TYPE_MOUSE = 1;
	static const uint8_t MOUSE_ACTION_LEFT_CLICK = 2;
	static const uint8_t MOUSE_ACTION_RIGHT_CLICK = 3;
	static const uint8_t MOUSE_ACTION_MIDDLE_CLICK = 4;
	static const uint8_t MOUSE_ACTION_MOVE = 5;
	static const uint8_t MOUSE_ACTION_SCROLL = 6;
	static const uint8_t MOUSE_ACTION_LEFT_DOWN = 7;
	static const uint8_t MOUSE_ACTION_LEFT_UP = 8;
	static const uint8_t KEYBOARD_ACTION_KEYCHAR = 9;
	static const uint8_t KEYBOARD_ACTION_META = 10;
	static const uint8_t KEYBOARD_ACTION_EMOJI = 11;
	static const uint8_t KEYBOARD_ACTION_OTHERS = 12;

	int16_t lastXCoor = -1;
	int16_t lastYCoor = -1;
	int16_t newXCoor = -1;
	int16_t newYCoor = -1;

	int16_t lastXAverage = -1;
	int16_t lastYAverage = -1;
	int16_t newXAverage = -1;
	int16_t newYAverage = -1;

	static const bool VERBOSITY = false;

	static const int16_t SENSITIVITY = 2;

#ifdef MACOS
	void static PressKey(uint8_t ca);

	void static MouseMovements(CGEventType mouseType, int16_t x, int16_t y, CGMouseButton mouseButton);
	void static MouseScroll(CGEventSourceRef source, int16_t scrollCountX, int16_t scrollCountY);
#endif

#ifdef WINDOWS
	void static PressKeyUnicode(uint8_t ca, bool bExtended);

	//The input must be Windows Scancodes
	void static PressKeyOthers(uint8_t ca, bool bExtended);

	void static MouseMovements(uint32_t dwFlags, int16_t dx, int16_t dy, int16_t mouseData);
#endif
};

#endif