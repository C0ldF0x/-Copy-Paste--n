#include "KeyStroke.h"

KeyStroke::KeyStroke()
{
	key = modifier1 = modifier2 = VK_UNDEFKEY;
}
KeyStroke::KeyStroke(short keyid)
{
	key = keyid;
	modifier1 = modifier2 = VK_UNDEFKEY;
}

KeyStroke::KeyStroke(short modifierid, short keyid)
{
	key  = keyid;
	modifier1 = modifierid;
	modifier2 = VK_UNDEFKEY;
}

KeyStroke::KeyStroke(short modifierid1, short modifierid2, short keyid)
{
	key  = keyid;
	modifier1 = modifierid1;
	modifier2 = modifierid2;
	if(modifier1 == VK_UNDEFKEY && modifier2 != VK_UNDEFKEY)
	{
		modifier1 = modifier2;
		modifier2 = VK_UNDEFKEY;
	}
}

KeyStroke::~KeyStroke()
{
	
}

short KeyStroke::getPrimaryKey() const { return key; }
short KeyStroke::getModifier1() const { return modifier1; }
short KeyStroke::getModifier2() const { return modifier2; }

bool KeyStroke::operator== (const KeyStroke &ks) const
{
	return (key == ks.key && modifier1 == ks.modifier1 && modifier2 == ks.modifier2);
}