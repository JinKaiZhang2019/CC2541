/******************************************************************************

 @file  simpleBLEPeripheral.c

 @brief This file contains the Simple BLE Peripheral sample application for use
        with the CC2540 Bluetooth Low Energy Protocol Stack.

 Group: WCS, BTS
 Target Device: CC2540, CC2541

 ******************************************************************************

 Copyright (c) 2010-2016, Texas Instruments Incorporated
 All rights reserved.

 IMPORTANT: Your use of this Software is limited to those specific rights
 granted under the terms of a software license agreement between the user
 who downloaded the software, his/her employer (which must be your employer)
 and Texas Instruments Incorporated (the "License"). You may not use this
 Software unless you agree to abide by the terms of the License. The License
 limits your use, and you acknowledge, that the Software may not be modified,
 copied or distributed unless embedded on a Texas Instruments microcontroller
 or used solely and exclusively in conjunction with a Texas Instruments radio
 frequency transceiver, which is integrated into your product. Other than for
 the foregoing purpose, you may not use, reproduce, copy, prepare derivative
 works of, modify, distribute, perform, display or sell this Software and/or
 its documentation for any purpose.

 YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
 NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
 LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
 INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
 OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
 OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

 Should you have any questions regarding your right to use this Software,
 contact Texas Instruments Incorporated at www.TI.com.

 ******************************************************************************
 Release Name: ble_sdk_1.4.2.2
 Release Date: 2016-06-09 06:57:10
 *****************************************************************************/

/*********************************************************************
 * INCLUDES
 */

#include "OSAL.h"
#include "OSAL_PwrMgr.h"
#include "hal_led.h"

#include "app.h"
#include <stdio.h>

uint8 App_TaskID = 0;

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

// How often to perform periodic event

// Length of bd addr as a string

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */
// GAP - SCAN RSP data (max size = 31 bytes)
;

// GAP - Advertisement data (max size = 31 bytes, though this is
// best kept short to conserve power while advertisting)
;


/*********************************************************************
 * LOCAL FUNCTIONS
 */


/*********************************************************************
 * PROFILE CALLBACKS
 */

// GAP Role Callbacks

// Simple GATT Profile Callbacks

/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn      SimpleBLEPeripheral_Init
 *
 * @brief   Initialization function for the Simple BLE Peripheral App Task.
 *          This is called during initialization and should contain
 *          any application specific initialization (ie. hardware
 *          initialization/setup, table initialization, power up
 *          notificaiton ... ).
 *
 * @param   task_id - the ID assigned by OSAL.  This ID should be
 *                    used to send messages and set timers.
 *
 * @return  none
 */
void App_Init( uint8 task_id )
{

    App_TaskID = task_id;

	// Setup a delayed profile startup
	osal_set_event( App_TaskID, SBP_START_DEVICE_EVT );
    osal_set_event(App_TaskID,SBP_PERIODIC_EVT);

}

/*********************************************************************
 * @fn      SimpleBLEPeripheral_ProcessEvent
 *
 * @brief   Simple BLE Peripheral Application Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id  - The OSAL assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed
 */
uint16 App_ProcessEvent( uint8 task_id, uint16 events )
{

	VOID task_id; // OSAL required parameter that isn't used in this function

	if ( events & SYS_EVENT_MSG )
	{
		// return unprocessed events
		return (events ^ SYS_EVENT_MSG);
	}

	if ( events & SBP_START_DEVICE_EVT )
	{
        printf("hello\n");
        
        HalLedBlink(1, 3, 50, 2000);
        osal_start_timerEx(App_TaskID,SBP_START_DEVICE_EVT,10000);
		return ( events ^ SBP_START_DEVICE_EVT );
	}

	if ( events & SBP_PERIODIC_EVT )
	{

        printf("event2\n");
        osal_start_timerEx(App_TaskID,SBP_PERIODIC_EVT,2000);
		return (events ^ SBP_PERIODIC_EVT);
	}

	// Discard unknown events
	return 0;
}
