/**
 ***************************************************************************************
 *
 *          \file:  port.h
 *         \brief:  
 *        Version:  1.0
 *        Created:  2021-04-09 10:02:37
 *       Revision:  none
 *
 ***************************************************************************************
 */

#ifndef __PORT_H__
#define __PORT_H__

#include <stdint.h>

#define HAL_ENABLE_INTERRUPTS() 
#define HAL_DISABLE_INTERRUPTS()
#define HAL_ENTER_CRITICAL_SECTION(_X_) do{ (void)_X_; }while(0);
#define HAL_EXIT_CRITICAL_SECTION(_X_) do{ (void)_X_; }while(0);

#define HAL_ASSERT(expr)                        st( if (!( expr )) halAssertHandler(); )
#define HAL_ASSERT_FORCED()                     halAssertHandler()
#define HAL_ASSERT_STATEMENT(statement)         st( statement )
#define HAL_ASSERT_DECLARATION(declaration)     declaration
#define halAssertHandler() while(1);
typedef uint8_t halIntState_t  ;
#define MAXMEMHEAP  100

#endif   /* ----- #ifndef __PORT_H__ ----- */
