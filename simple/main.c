#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	
	gpio_set_pin_level( RX_LED, true );
	gpio_set_pin_level( TX_LED, false );
	

	/* Replace with your application code */
	while (1) {
		for (int i = 0; i < 100000; i++);
		gpio_toggle_pin_level( RX_LED );
		gpio_toggle_pin_level( TX_LED );
		
	}
}
