// Included library
#include  "my_stm32f4_gpio_lib.h"
#include	"my_stm32f4_uart_lib.h"

// Initiate the structs
GPIO_InitTypeDef		myGPIO_InitSruct;
UART_TypeDef			myUART_InitStruct;
// Main function to execute the functions
int main(void){
	// Configures the initialization settings to use pin 5 of GPIOA as an output in Push-Pull mode
	myGPIO_InitSruct.Mode = GPIO_MODE_OUTPUT_PP;
 	myGPIO_InitSruct.Pin  = GPIO_PIN_5;
	myGPIO_InitSruct.Pull	= GPIO_NOPULL;
	
	// Enable clock for PortA
	__LIB_RCC_GPIOA_CLK_ENABLE();
	// Initate the Port with the settings we choose
	LIB_GPIO_Init(GPIOA,&myGPIO_InitSruct);
	// Ínitialize UART2 on port GPIOB
	UART2_init(GPIOB); 
	// configure and enable UART2
	UART2_enable(&myUART_InitStruct, 1);

	// Infinite loop that iterates between "high" and "low" status on the pin
	while(1){
	   for(int i =0;i< 900000;i++){}
		 LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);

	}
	// Reset configuration and disable UART2
   	UART2_disable(&myUART_InitStruct);
}
