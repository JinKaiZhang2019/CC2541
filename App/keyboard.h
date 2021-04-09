#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
#include "hal_mcu.h"
#include "hal_defs.h"
#include "hal_types.h"



typedef unsigned char (*pScanKey)(void);

void key_init(pScanKey scanFunction);

unsigned char key_driver(uint8 *key_value);



#endif
