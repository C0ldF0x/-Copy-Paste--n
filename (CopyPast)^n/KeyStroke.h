#ifndef KEYSTROKE_H
#define KEYSTROKE_H


/*	[ KeyStroke.h ]
 *	Object representation of a keystroke, composed by 1 key with 0..2 modifiers.
 *	Composed of 3 atributes of the type short, which will be used to store the virtual key codes
 *  The complete list of virtual key codes can be found here:
 *		http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx (as of March 2013)
 *	( Includes )
 *		- SkKeyMap.h	- Extra VirtualKey codes for program-specific operations (like exit)		
 *	( Classes )
 *		- KeyStroke
 */

#include "SkKeymapExtra.h"

class KeyStroke
{
private:
	short key;			// The main key
	short modifier1;	// the modifier (like CTRL)
	short modifier2;	// the second modifier (like ALT)

public:
	KeyStroke();

	KeyStroke(short keyid);
	KeyStroke(short modifierid, short keyid);
	KeyStroke(short modifierid1, short modifierid2, short keyid);
	~KeyStroke();

	short getPrimaryKey() const;
	short getModifier1() const;
	short getModifier2() const;

	bool operator== (const KeyStroke &ks) const;
};
#endif // KEYSTROKE_H