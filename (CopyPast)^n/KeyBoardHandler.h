#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H
/* SoftKey: lightweight virtual keystroke emulator
 *	- Emulates a certain key by pressing another set of keys on the keyboard
 *	- Useful to emulate keys physicaly not present in the keyboard.
 *	- Low memory and CPU consuption is a key feature.
 *
 *	Developed by Pedro Leal (leadzor)
 *	March 2013
 */

/*	[ KeyBoardHandler.h ]
 *	Keyboard handler, responsible for detecting keystrokes and sending commands to the OS
 *	via WinAPI calls, using the GetAsyncKeyState() and SendInput() functions.
 *	( Includes )
 *		- stdafx.h		- precompiled header		
 *		- KeyStroke.h	- keystroke implementation description
 *		- <map>			- C++ STL's map implementation
 *	( Classes )
 *		- KeyBoardHandler
 *  ( Defines )
 *		- GETNORMSTATE(X) macro - GetAsyncKeyState returns a short with his most significant bit
 *			representing the state of a certain key (0 - up, 1 - down/pressed). This macro normalizes
 *			the output to either return true (1) or false(0), rather than the original return short,
 *			which was unconsistent (other bits from that original short carried other data. For more info see
 *			http://msdn.microsoft.com/en-us/library/windows/desktop/ms646293(v=vs.85).aspx (as of March 2013)
 */

#include "KeyStroke.h"
#include "stdafx.h"
#include <map>
#include "Handler.h"


#define GETNORMSTATE(X) X >> 16 & 0x0001

class KeyBoardHandler
{
private:
	std::map<KeyStroke*, KeyStroke*> keymap;

public:
	/*
	 * Default Constructor and Destructor
	 * They are empty as there are nothing ATM that requires
	 * creation tome initialization.
	 */
	KeyBoardHandler();
	~KeyBoardHandler();

	/* ( Method ) void addKeyStrokePair( KeyStroke* physical, KeyStroke* virt )
	 * Adds a pair of physical/virtual keystrokes to the keymap for later sequential detection.
	 * _IN_ KeyStroke* physical - the physical keystroke to be added
	 * _IN_ KeyStroke* virt		- the virtual keystroke to be added
	 * a std::pair<KeyStroke*, KeyStroke*> is created and added to the keymap
	 */
	void addKeyStrokePair(KeyStroke* physical, KeyStroke* virt);

	/* ( Method ) bool detectKeyStroke(const KeyStroke &ks)
	 * Detects if the specified keystroke is being pressed and return true if it is.
	 * _IN_ const KeyStroke &ks - The keystroke to be evaluated
	 * It uses the function GetAsyncKeyState() API call to get the physical key state (and not logic)
	 * More info on GetAsyncKeyState() here: http://msdn.microsoft.com/en-us/library/windows/desktop/ms646293(v=vs.85).aspx (March 2013)
	 */
	bool detectKeyStroke(const KeyStroke &ks) const;

	/* ( Method ) void sendKey(const KeyStroke &ks)
	 * Sends the specified keystroke to the OS. It does not send the key modifiers (CTRL, ALT, SHIFT) along with it,
	 * just the main key (like A, 9, F12, etc.)
	 * _IN_ const KeyStroke &ks - the keystroke to be sent
	 * It uses a SendInput() call to send the keystroke to the OS. 
	 * More info on SendInput() here: http://msdn.microsoft.com/en-us/library/windows/desktop/ms646310(v=vs.85).aspx (March 2013)
	 */
	void sendKey(const KeyStroke &ks) const;

	/* ( Method ) keyStrokeScanner(int sleeptime)
	 * A loop that cycles through the added keystrokes and constantly checks for pressing detection.
	 * If a certain keystroke is detected, he sends the member of the pair to the sendKey() method.
	 * _IN_ int sleeptime - The time in miliseconds in which the process will rest to avoid CPU time waste.
	 *	The lower the number, the more quickly it will detect changes in keystrokes. Do not set this too low, or 
	 *  CPU usage will increase.
	 *  Ensure an exit keystroke is added, othewhise this will be an infinite loop until the process is terminated.
	 */
	void keystrokeScanner(int sleeptime);
};
#endif // KEYBOARDHANDLER_H