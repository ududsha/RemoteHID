#define WINVER 0x0500
#include <windows.h>

int main()
{
	// Pause for 5 seconds.
	Sleep(5000);

	// Create input event, generic keyboard event
	INPUT ip; // Input event
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwFlags = KEYEVENTF_UNICODE;
	ip.ki.wScan = 'd'; // Hardware scan code for key
	ip.ki.wVk = 0;
	ip.ki.dwExtraInfo = 0;

	for (int i = 0; i < 5;i++)
	{
		// Press the "A" Key
		ip.ki.wVk = 'A'; // Virtual key code for "a" key
		ip.ki.dwFlags = 0; // 0 key for key press

		SendInput(1, &ip, sizeof(INPUT));

		// Release the "A" key
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip, sizeof(INPUT));
	}
	

	// Exit normally
	return 0;
}