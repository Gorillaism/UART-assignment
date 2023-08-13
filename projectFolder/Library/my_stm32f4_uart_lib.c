#include "my_stm32f4_uart_lib.h"

void UART2_init(GPIO_TypeDef* GPIOx)
{
  RCC->APB1ENR |= 0x20000; // Enable the USART2 clock
  RCC->AHB1ENR |= 0x01;    // Enable the GPIOA clock

  GPIOx->MODER &= ~0x00F0; // Clear bits 4-7 in the GPIOA MODER register
  GPIOx->MODER |= 0x00A0;  // Set bits 5 and 7 in the GPIOA MODER register to set the GPIO pins to alternate function mode

  GPIOx->AFR[0] &= ~0xFF00; // Clear bits 8-15 in the GPIOA alternate function register
  GPIOx->AFR[0] |= 0x7700;  // Configure GPIO pin 7 and 6 to use alternate function 7
}

void UART2_enable(UART_TypeDef* UART, int baudrate_option)
{
  UART2_setBBR(UART, baudrate_option);  // Set the baud rate (arg[1] = (1 = 9600, 2 = 115200)
  UART->CR1 = 0x000C;       // Configure control register 1
  UART->CR2 &= ~0x1800;     // Configure control register 2 (set stop bit to 1 bit)
  UART->CR3 &= ~0x0080;     // Configure control register 3 (disable hardware flow control)
  UART->CR1 |= 0x2000;      // Enable USART2
}

void UART2_disable(UART_TypeDef* UART)
{
  UART->CR1 &= ~0x2000;     // Disable USART2
}

void UART2_setBBR(UART_TypeDef* UART, int option)
{
  if (option == 1)
    UART->BRR = 0x0683; // baudrate 9600
  else if (option == 2)
    UART->BRR = 0x008B;  // baudrate 115200
}

int UART2_write(int ch)
{
  while (!(UART2->SR & 0x0080)) {} // Wait until the UART2 TDR (Transmit Data Register) is empty
                                   // It's checking the SR flag of TDR which is bit 7 also known as TXE (Transmit data register empty)

  UART2->DR = (ch & 0xFF); // Set the USART2 DR (Data Register) to a valid ASCII character (ch & 0xFF ensures it's a valid ASCII character)

  return ch; // return the character sent to USART2 module
}

int UART2_read(void)
{
  while (!(UART2->SR & 0x0020)) {} // Wait until the UART2 RDR (Read data register) is not empty
                                   // It's checking the SR flag of RDR which is bit 5 also known as RXNE (Read data register not empty)

  return UART2->DR; // return the character from the Data Register (DR)
}