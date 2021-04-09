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

typedef signed   char   int8;     //!< Signed 8 bit integer
typedef unsigned char   uint8;    //!< Unsigned 8 bit integer

typedef signed   short  int16;    //!< Signed 16 bit integer
typedef unsigned short  uint16;   //!< Unsigned 16 bit integer

typedef signed   long   int32;    //!< Signed 32 bit integer
typedef unsigned long   uint32;   //!< Unsigned 32 bit integer

typedef unsigned char   bool;     //!< Boolean data type

typedef uint8           halDataAlign_t; //!< Used for byte alignment

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
#define MAXMEMHEAP  3072U
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#endif   /* ----- #ifndef __PORT_H__ ----- */
