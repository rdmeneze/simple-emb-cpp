/*
 * test_app.cpp
 *
 * Created: 01/08/2019 13:46:20
 * Author : Rafael Dias
 */ 

#include <atmel_start.h>
#include <algorithm>
#include <array>
#include <numeric>
#include <stdint.h>

void foo( int val )
{
	delay_ms( val );
	
	__NOP();
}

int main(void)
{	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	delay_init(NULL);
	
	constexpr std::array<int, 10> vetor_int = {1,2,3,4,5,6,7,8,9,10};

	gpio_set_pin_level( RX_LED, false );
	gpio_set_pin_level( TX_LED, false );
	
	for( auto i : vetor_int  )	
	{
		foo(i);
	}
	
	auto f = std::find( vetor_int.begin(), vetor_int.end(), 8 );
	
	if ( vetor_int.end() != f )
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
