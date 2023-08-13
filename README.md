# GPIO_LED
 An application to controll the hardware on a STM32411xC with the purpose of controlling the IO pins on the board.

 The porject is made up off these files:
    - main.c - Main file to execute all of our functions. </n>
    - my_stm32f4_gpio_driver.h - Define the designations and functions that will be called by the driver.
    - my_stm32f4_uart_driver.h - Define UART designations and function.
    - my_stm32f4_gpio_lib.h - Define the hardware we will be making use of.
    - my_stm32f4_gpio_lib.c - Apply the functions.
    - my_stm32f4_uart_lib.h - Define UART funtions for communication with the UART
    - my_stm32f4_uart_lib.c - Implementation of the UART funtions.
