/**
 ***************************************************************************************
 *
 *          \file:  tick.c
 *         \brief:
 *        Version:  1.0
 *        Created:  2021-04-09 19:38:22
 *       Revision:  none
 *
 ***************************************************************************************
 */

#include <pthread.h>
#include <stdint.h>
#include "tick.h"

static uint32_t tick = 0;

static struct timespec invert =
{
    .tv_sec = 0,
    .tv_nsec = 1000000,

};

static struct timespec rem;
/**
 **************************************  FUNCTION  *************************************
 *         \fn:  Tick_Tick
 *      \brief:
 *      \param:
 *     \return:
 * *************************************************************************************
 */
static void* Tick_Tick(void* p)
{
    (void)p;
    while(1)
    {
        nanosleep(&invert, &rem);
        tick++;
    }
    return NULL;
}		/* -----  end of static function Tick_Tick  ----- */

/**
 ***************************************************************************************
 *         \fn:  Tick_GetTick
 *      \brief:
 *      \param:
 *     \return:
 ***************************************************************************************
 */
uint32_t Tick_GetTick(void)
{
    return tick;
}		/* -----  end of function Tick_GetTick  ----- */

/**
 ***************************************************************************************
 *         \fn:  Tick_Init
 *      \brief:
 *      \param:
 *     \return:
 ***************************************************************************************
 */
void Tick_Init(void)
{
    pthread_t threadTick;
    pthread_create(&threadTick, NULL, Tick_Tick, NULL);
}		/* -----  end of function Tick_Init  ----- */

