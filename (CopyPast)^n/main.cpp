#include "KeyBoardHandler.h"




/* [ int WINAPI WinMain () ]
 * Main WinAPI call to start up. It does not create a console or GUI window. It runs in background.
 * For information about the parameters, visit:
 *	- http://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx (as of March 2013)
 */
int WINAPI WinMain(
					HINSTANCE hInstance, 
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int cmdShow)
					
{
	
	// Keyboard handler object that scans and send keystrokes
	KeyBoardHandler kbh;

	/* Keystroke pointers.
	 * kp_* means keystroke physical. The actual keys pressed
	 * kv_* means keystroke virtual. The keystroke sent to the OS
	 * This is just a prototype. It'll be more customizable.
	 *	-TODO import config from a file, rather than using hardcoded keystrokes.
	 */

	

	KeyStroke* kp_paste_slot_1 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD1);
	KeyStroke* kp_paste_slot_2 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD2);
	KeyStroke* kp_paste_slot_3 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD3);
	KeyStroke* kp_paste_slot_4 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD4);
	KeyStroke* kp_paste_slot_5 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD5);
	KeyStroke* kp_paste_slot_6 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD6);
	KeyStroke* kp_paste_slot_7 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD7);
	KeyStroke* kp_paste_slot_8 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD8);
	KeyStroke* kp_paste_slot_9 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD9);
	KeyStroke* kp_paste_slot_0 = new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD0);
	KeyStroke* kp_exit = new KeyStroke(VK_CONTROL, VK_MENU, VK_END);

	KeyStroke* kv_exit = new KeyStroke(VK_EXITCODE);

	kbh.addKeyStrokePair(kp_exit, kv_exit);

	AllocConsole();
	cout << "Ctrl+Alt+Home to see the list"<< endl;
	cout << "Ctrl+Alt+End to close the programm"<< endl;
	cout << "Ctrl+Alt+C to copy text to the list"<< endl;
	cout << "Ctrl+Alt+0...9 to paste the text that's in that position"<< endl;





	// BEEEEEEEEEEEEEEEEEEEEEEEEEP
	Beep(1500, 800);

	// Keyboard handler main detection function.
	kbh.keystrokeScanner(75);	

	// Not as cool BEEEEEEEEEEEEEEEEEEP
	Beep(750, 800);

	system("pause");
	return 0;
}

