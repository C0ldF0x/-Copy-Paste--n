#include "Handler.h"
#include <list>

Handler::Handler(){
	lastMoved=-1;
	values = new string[10];
	clearData();
}

void Handler::setText(const char* output)
{
	const size_t len = strlen(output) + 1;
	HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	

}

void Handler::getText()
{
	string text;
	
	if (OpenClipboard(NULL)) 
	{
		HANDLE clip;
		clip = GetClipboardData(CF_TEXT);
		
		 // lock and copy

		text = (LPSTR)GlobalLock(clip);
		GlobalUnlock(clip);
		CloseClipboard();
		addValueToData(text);

	}
	
}

void Handler::saveClipborad()
{
	
}

void Handler::restoreClipboard(){}


void Handler::clearData()
{
	values = new string[10];
}

void Handler::addValueToData(string &text)
{
	lastMoved++;
	if(lastMoved==10)
		lastMoved=0;
	values[lastMoved]=text;

	cout <<"(i) \""<< text << "\" copied"<<endl;
}

string Handler::getValueFromData(int i)
{
	return values[i];
}
//12345678910

void Handler::paste()
{
	// Create a generic keyboard event structure

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	
	Sleep(1000); // pause for 1 second
		// Press the "Ctrl" key
		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));
		
		// Press the "V" key
		ip.ki.wVk = 'V';
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		// Release the "V" key
		ip.ki.wVk = 'V';
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));

		// Release the "Ctrl" key
		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
		
		
	
}