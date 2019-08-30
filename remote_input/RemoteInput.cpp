#include "RemoteInput.h"

// InputEngine.cpp : Defines the exported functions for the DLL application.
//

#include <thread>

RemoteInput::RemoteInput()
{
}

#ifdef MACOS

void RemoteInput::PressKey(uint8_t ca)
{
	CGEventRef keyDown = CGEventCreateKeyboardEvent(
		NULL,
		ca,
		true);
	CGEventRef keyUp = CGEventCreateKeyboardEvent(
		NULL,
		ca,
		false);

	CGEventPost(kCGHIDEventTap, keyDown);
	CGEventPost(kCGHIDEventTap, keyUp);

	CFRelease(keyDown);
	CFRelease(keyUp);
}

void RemoteInput::MouseMovements(CGEventType mouseType, int16_t x, int16_t y, CGMouseButton mouseButton)
{
	CGEventRef mouse = CGEventCreateMouseEvent(
		NULL,
		mouseType,
		CGPointMake(x, y),
		mouseButton);

	CGEventPost(kCGHIDEventTap, mouse);
	CFRelease(mouse);
}

void RemoteInput::MouseScroll(CGEventSourceRef source, int16_t scrollCountX, int16_t scrollCountY)
{
	CGEventRef scroll = CGEventCreateScrollWheelEvent(
		source, kCGScrollEventUnitLine, 2, scrollCountX, scrollCountY);

	CGEventPost(kCGHIDEventTap, scroll);
	CFRelease(scroll);
}

void RemoteInput::execute(uint8_t *command)
{
	uint8_t inputType = command[0];
	uint8_t actionType = command[1];
	uint8_t dataLength = command[2];

	switch (inputType)
	{
		//Data is for mouse events
	case INPUT_TYPE_MOUSE:
		switch (actionType)
		{
		case MOUSE_ACTION_LEFT_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left click" << std::endl;
			MouseMovements(kCGEventLeftMouseDown, newXCoor, newYCoor, kCGMouseButtonLeft);
			MouseMovements(kCGEventLeftMouseUp, newXCoor, newYCoor, kCGMouseButtonLeft);
			break;
		case MOUSE_ACTION_RIGHT_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK right click" << std::endl;
			MouseMovements(kCGEventRightMouseDown, newXCoor, newYCoor, kCGMouseButtonRight);
			MouseMovements(kCGEventRightMouseUp, newXCoor, newYCoor, kCGMouseButtonRight);
			break;
		case MOUSE_ACTION_LEFT_DOWN:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left down" << std::endl;
			MouseMovements(kCGEventLeftMouseDown, newXCoor, newYCoor, kCGMouseButtonLeft);
			break;
		case MOUSE_ACTION_LEFT_UP:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left up" << std::endl;
			MouseMovements(kCGEventLeftMouseUp, newXCoor, newYCoor, kCGMouseButtonLeft);
			break;
		case MOUSE_ACTION_MIDDLE_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK middle click" << std::endl;
			// MouseMovements(kCGEventMiddleMouseUp, 0, 0, 0);
			// MouseMovements(MOUSEEVENTF_MIDDLEUP, 0, 0, 0);
			break;
		case MOUSE_ACTION_MOVE:
			if (dataLength == 4)
			{
				if (lastXCoor - lastYCoor == 0)
				{ //first time finger down // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
					lastXCoor = (command[3] << 8) + command[4];
					lastYCoor = (command[5] << 8) + command[6];
				}
				else
				{ //finger moves
					newXCoor = (command[3] << 8) + command[4];
					newYCoor = (command[5] << 8) + command[6];
					if (newXCoor - newYCoor == 0)
					{ // if both newXCoor and newYCoor are " -1 ", Doing newXCoor - newYCoor will be equal to 0
						lastXCoor = -1;
						lastYCoor = -1;
					}
					else
					{ //finger lifts, resetting all the condition
						if (VERBOSITY)
							printf("Received coordinate %d,%d \n", newXCoor, newYCoor);
						MouseScroll(NULL, newXCoor, newYCoor);
						lastXCoor = newXCoor;
						lastYCoor = newYCoor;
					}
				}
				//printf("Received coordinate\n");
				//std::cout << "move" << command[3] << " " << command[4];
				break;
			}

		case MOUSE_ACTION_SCROLL:
			if (dataLength == 4)
			{
				if (lastXAverage - lastYAverage == 0)
				{ //first time finger down // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
					lastXAverage = (command[3] << 8) + command[4];
					lastYAverage = (command[5] << 8) + command[6];
				}
				else
				{ //finger moves
					newXAverage = (command[3] << 8) + command[4];
					newYAverage = (command[5] << 8) + command[6];
					if (newXAverage - newYAverage == 0)
					{ // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
						lastXAverage = -1;
						lastYAverage = -1;
					}
					else
					{ //finger lifts, resetting all the condition
						if (VERBOSITY)
							printf("Received Scroll %d,%d \n", newXAverage - lastXAverage, newYAverage - lastYAverage);
						// MouseMovements(MOUSEEVENTF_WHEEL, 0, 0, newYAverage - lastYAverage);
						// MouseMovements(MOUSEEVENTF_HWHEEL, 0, 0, lastXAverage - newXAverage);
						lastXAverage = newXAverage;
						lastYAverage = newYAverage;
					}
				}
				//printf("Received coordinate\n");
				//std::cout << "move" << command[3] << " " << command[4];
				break;
			}
		}
		//Data is for keyboard events
	case INPUT_TYPE_KEYBOARD:
		switch (actionType)
		{
		case KEYBOARD_ACTION_EMOJI:
			break;
		case KEYBOARD_ACTION_KEYCHAR:
			PressKey(command[3]);
			break;
		case KEYBOARD_ACTION_META:
			break;
		case KEYBOARD_ACTION_OTHERS:
			PressKey(command[3]);
			break;
		};
	};
}

#endif

#ifdef WINDOWS
void RemoteInput::PressKeyUnicode(uint8_t ca, bool bExtended)
{
	//Structure for the keyboard event
	INPUT ip;
	//Set up the INPUT structure
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.wVk = 0;
	ip.ki.dwExtraInfo = 0;

	//Use Uniceode as the key event
	ip.ki.dwFlags = KEYEVENTF_UNICODE;
	ip.ki.wScan = ca; //Set a unicode character to use (A)

	SendInput(1, &ip, sizeof(INPUT));

	//Prepare a keyup event
	ip.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

//The input must be Windows Scancodes
void RemoteInput::PressKeyOthers(uint8_t ca, bool bExtended)
{
	//Structure for the keyboard event
	INPUT ip;
	//Set up the INPUT structure
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.wVk = ca; //We're doing scan codes instead
	ip.ki.dwExtraInfo = 0;

	//Use Uniceode as the key event
	ip.ki.dwFlags = 0;
	ip.ki.wScan = 0; //Set a unicode character to use (A)

	SendInput(1, &ip, sizeof(INPUT));

	//Prepare a keyup event
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

void RemoteInput::MouseMovements(DWORD dwFlags, int16_t dx, int16_t dy, int16_t mouseData)
{

	//Structuring for the mouse event
	INPUT ip;
	//Set up the INPUT structure
	ip.type = INPUT_MOUSE;
	ip.mi.dx = (dx == 1) ? dx : dx / SENSITIVITY;
	ip.mi.dy = (dy == 1) ? dy : dy / SENSITIVITY;
	ip.mi.dwExtraInfo = 0;
	ip.mi.mouseData = mouseData;
	ip.mi.time = 0;
	/**
	* If dwFlags contains MOUSEEVENTF_WHEEL, then mouseData specifies the amount of wheel movement.
	* A positive value indicates that the wheel was rotated forward, away from the user;
	* a negative value indicates that the wheel was rotated backward, toward the user.
	* One wheel click is defined as WHEEL_DELTA, which is 120.
	*
	* If dwFlags does not contain MOUSEEVENTF_WHEEL, MOUSEEVENTF_XDOWN, or MOUSEEVENTF_XUP, then mouseData should be zero.
	*
	* If dwFlags contains MOUSEEVENTF_XDOWN or MOUSEEVENTF_XUP, then mouseData specifies which X buttons were pressed or released.
	* This value may be any combination of the following flags
	*
	* Use MOUSEEVENTF_MOVE to move the cursor.
	**/
	ip.mi.dwFlags = dwFlags;

	SendInput(1, &ip, sizeof(INPUT));
}

void RemoteInput::execute(uint8_t *command)
{
	uint8_t inputType = command[0];
	uint8_t actionType = command[1];
	uint8_t dataLength = command[2];

	switch (inputType)
	{
		//Data is for mouse events
	case INPUT_TYPE_MOUSE:
		switch (actionType)
		{
		case MOUSE_ACTION_LEFT_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left click" << std::endl;
			MouseMovements(MOUSEEVENTF_LEFTDOWN, 0, 0, 0);
			MouseMovements(MOUSEEVENTF_LEFTUP, 0, 0, 0);
			break;
		case MOUSE_ACTION_RIGHT_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK right click" << std::endl;
			MouseMovements(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0);
			MouseMovements(MOUSEEVENTF_RIGHTUP, 0, 0, 0);
			break;
		case MOUSE_ACTION_LEFT_DOWN:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left down" << std::endl;
			MouseMovements(MOUSEEVENTF_LEFTDOWN, 0, 0, 0);
			break;
		case MOUSE_ACTION_LEFT_UP:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK left up" << std::endl;
			MouseMovements(MOUSEEVENTF_LEFTUP, 0, 0, 0);
			break;
		case MOUSE_ACTION_MIDDLE_CLICK:
			if (VERBOSITY)
				std::cout << "CLICKLCICKCLICK middle click" << std::endl;
			MouseMovements(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0);
			MouseMovements(MOUSEEVENTF_MIDDLEUP, 0, 0, 0);
			break;
		case MOUSE_ACTION_MOVE:
			if (dataLength == 4)
			{
				if (lastXCoor - lastYCoor == 0)
				{ //first time finger down // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
					lastXCoor = (command[3] << 8) + command[4];
					lastYCoor = (command[5] << 8) + command[6];
				}
				else
				{ //finger moves
					newXCoor = (command[3] << 8) + command[4];
					newYCoor = (command[5] << 8) + command[6];
					if (newXCoor - newYCoor == 0)
					{ // if both newXCoor and newYCoor are " -1 ", Doing newXCoor - newYCoor will be equal to 0
						lastXCoor = -1;
						lastYCoor = -1;
					}
					else
					{ //finger lifts, resetting all the condition
						if (VERBOSITY)
							printf("Received coordinate %d,%d \n", newXCoor - lastXCoor, newYCoor - lastYCoor);
						MouseMovements(MOUSEEVENTF_MOVE, newXCoor - lastXCoor, newYCoor - lastYCoor, 0);
						lastXCoor = newXCoor;
						lastYCoor = newYCoor;
					}
				}
				//printf("Received coordinate\n");
				//std::cout << "move" << command[3] << " " << command[4];
				break;
			}

		case MOUSE_ACTION_SCROLL:
			if (dataLength == 4)
			{
				if (lastXAverage - lastYAverage == 0)
				{ //first time finger down // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
					lastXAverage = (command[3] << 8) + command[4];
					lastYAverage = (command[5] << 8) + command[6];
				}
				else
				{ //finger moves
					newXAverage = (command[3] << 8) + command[4];
					newYAverage = (command[5] << 8) + command[6];
					if (newXAverage - newYAverage == 0)
					{ // if both newXAverage and newYAverage are " -1 ", Doing newXAverage - newYAverage will be equal to 0
						lastXAverage = -1;
						lastYAverage = -1;
					}
					else
					{ //finger lifts, resetting all the condition
						if (VERBOSITY)
							printf("Received Scroll %d,%d \n", newXAverage - lastXAverage, newYAverage - lastYAverage);
						MouseMovements(MOUSEEVENTF_WHEEL, 0, 0, newYAverage - lastYAverage);
						MouseMovements(MOUSEEVENTF_HWHEEL, 0, 0, lastXAverage - newXAverage);
						lastXAverage = newXAverage;
						lastYAverage = newYAverage;
					}
				}
				//printf("Received coordinate\n");
				//std::cout << "move" << command[3] << " " << command[4];
				break;
			}
		}
		//Data is for keyboard events
	case INPUT_TYPE_KEYBOARD:
		switch (actionType)
		{
		case KEYBOARD_ACTION_EMOJI:
			break;
		case KEYBOARD_ACTION_KEYCHAR:
			PressKeyUnicode(command[3], true);
			break;
		case KEYBOARD_ACTION_META:
			break;
		case KEYBOARD_ACTION_OTHERS:
			PressKeyOthers(command[3], true);
			break;
		};
	};
}

#endif
