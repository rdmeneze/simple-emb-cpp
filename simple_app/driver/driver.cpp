/*
 * driver.cpp
 *
 * Created: 8/5/2019 8:09:18 PM
 *  Author: Rafael Dias
 */ 




#include "driver.h"
#include "cpu.h"

void driver::init();

//static const gpio brd_led[(uint8_t)LED::NONE] = 
//{
	//[(uint32_t)LED::RX] = gpio( GPIO_PORTB, 3, GPIO_DIRECTION_OUT, GPIO_PULL_UP ),
	//[(uint32_t)LED::TX] = gpio( GPIO_PORTA, 27, GPIO_DIRECTION_OUT, GPIO_PULL_UP ),
	//[(uint32_t)LED::RED] = gpio( GPIO_PORTA, 17, GPIO_DIRECTION_OUT, GPIO_PULL_UP ),
//};


void driver::init()
{
	cpu::init();
}


//static const gpio* led( const LED led_info )
//{
	//return &brd_led[(uint32_t)led_info];	
//}
