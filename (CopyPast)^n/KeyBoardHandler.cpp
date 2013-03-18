#include "KeyBoardHandler.h"

using namespace std;
KeyBoardHandler::KeyBoardHandler()
{
	// Empty
}

KeyBoardHandler::~KeyBoardHandler()
{
	// Empty
}

bool KeyBoardHandler::detectKeyStroke(const KeyStroke &ks) const
{
	short mk = ks.getPrimaryKey();
	short m1 = ks.getModifier1();
	short m2 = ks.getModifier2();

	// This is kind of a mess right now, but it works well. Considering changing it.
	if(mk == VK_UNDEFKEY)
		return false;
	if(m1 == VK_UNDEFKEY)
		return (GETNORMSTATE(GetAsyncKeyState(mk)));
	else if(m2 == VK_UNDEFKEY)
	{
		if(GETNORMSTATE(GetAsyncKeyState(mk)))
			if(GETNORMSTATE(GetAsyncKeyState(m1)))
				return true;
	}
	else
	{
		if(GETNORMSTATE(GetAsyncKeyState(mk)))
			if(GETNORMSTATE(GetAsyncKeyState(m1)))
				if(GETNORMSTATE(GetAsyncKeyState(m2)))
					return true;
	}

	return false;
}

void KeyBoardHandler::addKeyStrokePair(KeyStroke* physical, KeyStroke* virt)
{
		keymap.insert(std::pair<KeyStroke*, KeyStroke*>(physical, virt));		
}

void KeyBoardHandler::sendKey(const KeyStroke &ks) const
{
	/* To simplify things, sendKey uses the same KeyStroke object but only sends the primary key,
	 * not the modifiers. This way, physical keystrokes and virtual keystrokes are compatible with each other
	 */
	short key = ks.getPrimaryKey();

	INPUT* input = new INPUT;
	memset(input, 0, sizeof(INPUT));

	input->type = INPUT_KEYBOARD;			// Set input type to keyboard
	input->ki.wVk = key;
	input->ki.dwFlags = 0;					// Set keystate as 0 (pressed)

	SendInput(1, input, sizeof(INPUT));
	input->ki.dwFlags = KEYEVENTF_KEYUP;	// Set keystate as unpressed
	SendInput(1, input, sizeof(INPUT));
}

void KeyBoardHandler::keystrokeScanner(int sleepTime)
{
	bool exit = false;
	Handler h;
	while(!exit)
	{
		
		if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_END))))
		{
			exit=true;
		}	
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_C_CODE))))
		{
			h.getText();
			//cout << *text;
			//addValueToData(text);
				
			
			
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD1))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(1).c_str());
			h.paste();
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD2))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(2).c_str());

		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD3))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(3).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD4))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(4).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD5))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(5).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD6))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(6).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD7))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(7).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD8))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(8).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD9))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(9).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_NUMPAD0))))
		{
			Beep(1000,2);
			Beep(1500,2);
			h.setText(h.getValueFromData(0).c_str());
		}
		else if(detectKeyStroke(*(new KeyStroke(VK_CONTROL, VK_MENU, VK_HOME))))
		{
			for (int i = 0; i < 10; i++)
			{
				cout << i << " - " <<h.values[i]<<endl;
			}		
		}

		Sleep(sleepTime);
		fflush(stdin); // not sure if this really helps in anything at all in fixing the "skip 1" bug
	
		
	}
	
}