#ifndef	__MY_STM32F4_UART_DRIVER_H__
#define __MY_STM32F4_UART_DRIVER_H__

#include <stdint.h>
#include "my_stm32f4_commons.h"

#define UART2_BASE (PERIPH_BASE + 0x4400U)

#define __IO volatile

typedef struct
{
  __IO uint32_t SR;  // Status register
  __IO uint32_t DR;  // Data register
  __IO uint32_t BRR; // Baudrate register
  __IO uint32_t CR1; // Control register 1
  __IO uint32_t CR2; // Control register 2
  __IO uint32_t CR3; // Control register 3
  __IO uint32_t GTPR; // Guard time and prescaler register
  
}UART_TypeDef;

#define UART2     ((UART_TypeDef *)UART2_BASE)

#endif
