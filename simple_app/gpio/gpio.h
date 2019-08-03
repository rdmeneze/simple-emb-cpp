/*
 * gpio.h
 *
 * Created: 8/3/2019 2:52:55 PM
 *  Author: Rafael Dias
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <cstdint>
#include <hal_gpio.h>

template<	const uint8_t port,
			const uint8_t pin,
			const uint8_t dir,
			const uint8_t pull >
class gpio
{
	public:
		gpio()
		{
			::gpio_set_pin_level( port_pin, false );
			::gpio_set_pin_direction(port_pin, dir);
			::gpio_set_pin_function(port_pin, GPIO_PIN_FUNCTION_OFF);
			::gpio_toggle_port_level(port_pin, pull);
		}
	
		void set( bool value )
		{
			::gpio_set_pin_level( port_pin, value );
		}
		
		void set()
		{
			::gpio_set_pin_level( port_pin, true );
		}
		
		void clear()
		{
			::gpio_set_pin_level( port_pin, false );
		}
		
		void toggle()
		{
			bool val = gpio_get_pin_level( port_pin );
			::gpio_set_pin_level( port_pin, !val );			
		}
		
		bool value()
		{
			return gpio_get_pin_level( port_pin );
		}
		
	private:
		const std::uint8_t port_pin = GPIO(port, pin);
};
		




#endif /* GPIO_H_ */