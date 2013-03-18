#ifndef HANDLER_H
#define HANDLER_H
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <list>


using namespace std;


class Handler{
public:
	string * values;
	int lastMoved;
	Handler();
	void setText(const char* output);
	void getText();
	void saveClipborad();
	void restoreClipboard();
	void clearData();
	void addValueToData(string & text);
	string getValueFromData(int i);
	void paste();
};
#endif

