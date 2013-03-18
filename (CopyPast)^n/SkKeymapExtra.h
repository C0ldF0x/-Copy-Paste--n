#ifndef SKKEYMAPEXTRA_H
#define SKKEYMAPEXTRA_H

/*	[ KeyStroke.h ]
 *	Contains extra codes to be ised internally by the application that have no use for Windows (undefined keys)
 */

#define VK_UNDEFKEY 0x07	// Specified that the key is undefined and no action should be sent
#define VK_EXITCODE 0x16	// App's exit code. Used by the detection loop to check when should be ended.
#define VK_C_CODE 0x43
#endif // SKKEYMAPEXTRA_H