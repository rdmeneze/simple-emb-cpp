/*
 * test_app.cpp
 *
 * Created: 01/08/2019 13:46:20
 * Author : Rafael Dias
 */ 

#include <atmel_start.h>
#include <array>
#include <algorithm>


void foo( int val )
{
	delay_ms( val );
	
	__NOP();
}

int main(void)
{
	constexpr std::array<int, 10> array_val = {1,2,3,4,5,6,7,8,9,0};
	
	delay_init(NULL);
	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	gpio_set_pin_level( RX_LED, false );
	gpio_set_pin_level( TX_LED, false );
	
	for( auto i : array_val  )	
	{
		foo(i);
	}
	
	auto f = std::find( array_val.begin(), array_val.end(), 1 );
	
	if ( array_val.end() != f )
	{
		gpio_toggle_pin_level( RX_LED );
	}
	
	

	/* Replace with your application code */
	while (1) {
		for (int i = 0; i < 1000000; i++);
		gpio_toggle_pin_level( RX_LED );
		gpio_toggle_pin_level( TX_LED );
		
	}
}
