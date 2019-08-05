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

class gpio
{
	public:
		gpio( const enum gpio_port port, const uint8_t pin, const enum gpio_direction dir, const enum gpio_pull_mode pull )
		{
			port_pin = GPIO((uint8_t)port, pin);
			
			::gpio_set_pin_level( port_pin, false );
			::gpio_set_pin_direction(port_pin, dir);
			::gpio_set_pin_function(port_pin, GPIO_PIN_FUNCTION_OFF);
			::gpio_toggle_port_level((gpio_port)GPIO_PORT(port_pin), GPIO_PIN(port_pin));
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
		uint8_t port; 
		uint8_t pin; 
		uint8_t dir; 
		uint8_t pull;
	
		uint8_t port_pin;
};
		




#endif /* GPIO_H_ */