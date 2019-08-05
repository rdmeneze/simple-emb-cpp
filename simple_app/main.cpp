/*
 * test_app.cpp
 *
 * Created: 01/08/2019 13:46:20
 * Author : Rafael Dias
 */ 

//#include <atmel_start.h>
#include <array>
#include <algorithm>
#include <gpio.h>
#include <cpu.h>


void foo( int val )
{

}

int main(void)
{
	cpu::init();
	
	gpio led_rx( GPIO_PORTB, 3, GPIO_DIRECTION_OUT, GPIO_PULL_UP );
	
	
	/* Initializes MCU, drivers and middleware */
	//atmel_start_init();

	/* Replace with your application code */
	while (1) {
		for (int i = 0; i < 1000000; i++);		
		led_rx.set();
		for (int i = 0; i < 1000000; i++);
		led_rx.clear();
		
	}
}
