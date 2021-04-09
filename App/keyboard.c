#include "keyboard.h"


//key state
#define  KEY_STATE_INIT		0
#define  KEY_STATE_SHAKE 	1
#define  KEY_STATE_PRESS 	2
#define  KEY_state_RELASE	3


#define  N_KEY				0


/*
*scan key function,user reference
*/
pScanKey scan_key = NULL;

void key_init(pScanKey scanFunction)
{
	scan_key = scanFunction;
}


unsigned char key_driver(uint8 *key_value)
{

	static unsigned char key_state = KEY_STATE_INIT,key_time = 0;
	static unsigned char backup_key = N_KEY;
	unsigned char key_press;
	*key_value = N_KEY;
	if(scan_key == NULL)
	{
		return KEY_STATE_INIT;
	}
	else
	{
		key_press = scan_key(); //read IO value
	}
	
	switch(key_state)
	{
		case KEY_STATE_INIT: //key initial state 
		
			if(key_press != N_KEY) //key pressed ,change to shake and stable
			{
				key_state = KEY_STATE_SHAKE;
				backup_key = key_press;
			}
			break;
		
		case KEY_STATE_SHAKE: //key shake and stable
		
			if(key_press == backup_key) //key has pressed ,change to caluator key's time pressed ,but key value is N_KEY 
			{
				key_time = 0;
				key_state = KEY_STATE_PRESS;
			}
			else 
			{
				key_state = KEY_STATE_INIT;// press had pressed chang to initial state ,process shake
			}
		
		break;
		
		case KEY_STATE_PRESS:
			if(key_press == N_KEY)
			{
				*key_value = backup_key; //key has released ,single key return S_KEY
				key_state = KEY_STATE_INIT;
			}
			else if(++key_time >=  20) //key has been pressing ,time increas
			{
				key_state = KEY_state_RELASE; //change wait state that will to to initial state
				*key_value = backup_key + 2;
			}

		
		break;
		
		case KEY_state_RELASE://wait key release
			if(key_press == N_KEY)
			{
				key_state = KEY_STATE_INIT;//key had pressed change to initial state
			}
		break;
		
	}
	return key_state;
}


