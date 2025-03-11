#include <windows.h>
#include <iostream>

LRESULT CALLBACK LLKBDHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT *s = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
	
	switch(wParam) {
		case WM_KEYDOWN:
			//ToAscii(s->vkCode, s->scanCode, &c, 1); 
			char c = MapVirtualKey(s->vkCode, MAPVK_VK_TO_CHAR);
			std::cout << c;
			break;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main()
{
	HHOOK kbd = SetWindowsHookEx(WH_KEYBOARD_LL, &LLKBDHook, 0, 0);

	MSG message;
	while(GetMessage(&message, NULL, WM_KEYFIRST, WM_KEYLAST) > 0) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	UnhookWindowsHookEx(kbd);

	return 0;
}
