//main.c
//authored by Jared Hull
//
//tasks 1 and 2 blink the ACT LED
//main initialises the devices and IP tasks

//#include <FreeRTOS.h>
//#include <task.h>

#include "interrupts.h"
#include "gpio.h"
#include "main.h"

//Only for debug, normally should not 
//   include private header

/* if there is space in the buffer, that is to_write<TX_BUF_LEN then this task add sum text to the buffer starting from head*/

/*
#define ABC_LEN 26
void tx_blabla_task() {
	int i = 0;
	char c = 0;
	portTickType dstep = 100;
	unsigned int set = 0;

	char chars[4] = {'A','a','\r','\n'};

	while(1){
		mini_uart_write(chars,4);
		chars[0] = 'A' + ((chars[0]-'A' + 1)% ABC_LEN);
		mini_uart_read(chars+1,1);
		vTaskDelay(300);
	}
}
*/

/*
void task1() {
	int i = 0;
	char c = 'A';
	portTickType dstep = 100;
	unsigned int set = 0;

	while(1) {

		if(int_rx_count >= 'A' && int_rx_count < 'H'){
			dstep = 50;
		}
		else if(int_rx_count >= 'H' && int_rx_count < 'N'){
			dstep = 100;
		}
		else if(int_rx_count >= 'N' && int_rx_count < 'U'){
			dstep = 200;
		}
		else{
			dstep = 400;
		}

		set = 1 - set;
		SetGpio(47, set);

		vTaskDelay(dstep);
	}
}
*/

int my_kernel_init(void) {

	SetGpioFunction(47, 1);			// RDY led

	//for some reason calling this function is necessary for the uart to work
	//initFB();

	SetGpio(47, 1);
	//videotest();

	DisableInterrupts();
	InitInterruptController();

	//uart_init();

	//ensure the IP and gateway match the router settings!
	//const unsigned char ucIPAddress[ 4 ] = {192, 168, 1, 42};
	//const unsigned char ucIPAddress[ 4 ] = {192, 168, 1, 9};
	//const unsigned char ucNetMask[ 4 ] = {255, 255, 255, 0};
	//const unsigned char ucGatewayAddress[ 4 ] = {192, 168, 1, 1};
	//const unsigned char ucDNSServerAddress[ 4 ] = {8, 8, 8, 8};
	//const unsigned char ucMACAddress[ 6 ] = {0xB8, 0x27, 0xEB, 0x19, 0xAD, 0xA7};
	//const unsigned char ucMACAddress[ 6 ] = {0xB8, 0x27, 0xEB, 0xa5, 0x35, 0xC1};
	//FreeRTOS_IPInit(ucIPAddress, ucNetMask, ucGatewayAddress, ucDNSServerAddress, ucMACAddress);

	//xTaskCreate(serverTask, "server", 128, NULL, 0, NULL);
	//xTaskCreate(serverListenTask, "server", 128, NULL, 0, NULL);

	//xTaskCreate(task1, "LED_0", 128, NULL, 1, NULL);
	//xTaskCreate(tx_blabla_task, "LED_1", 128, NULL, 1, NULL);

	//long write_delay = 100;
	//xTaskCreate(serial_writer_task, "LED_1", 128,(void*)write_delay , 1, NULL);
	//set to 0 for no debug, 1 for debug, or 2 for GCC instrumentation (if enabled in config)
	//loaded = 1;

	//vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}
