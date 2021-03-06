/*
 * File      : bsp.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2013 RT-Thread Develop Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      first implementation
 */

#include <os/os.h>
#include <mcu/stm32f10x.h>
#include <bsp/bsp.h>
#include <bsp/usart.h>

//#include <stdint.h>
/**
 * @addtogroup STM32
 */

/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
    printk("\n\r Wrong parameter value detected on\r\n");
    printk("       file  %s\r\n", file);
    printk("       line  %d\r\n", line);

    while (1) ;
}

/**
 * This is the timer interrupt service routine.
 *
 */
void SysTick_Handler(void)
{
    os_isr_enter();

    os_tick_increase();

    os_isr_leave();
}

/**
 * This function will initial STM32 board.
 */
void bsp_init(void)
{
    /* Configure the SysTick */
    SysTick_Config(SystemCoreClock / OS_TICKS_PER_SEC);

    bsp_usart_init();
    console_output = bsp_usart_output;
}

/*@}*/
