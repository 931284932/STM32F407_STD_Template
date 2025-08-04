#include "gpio.h"

void gpio_led_init(void)
{
	RCC->AHB1ENR |= 1 << 1; 		//开启B口时钟
	
	GPIOB->MODER &= ~(3 << 4 * 2); 	//PB4位置清零
	GPIOB->MODER |= 1 << 4 * 2;		//PB4通用输出模式
	
	GPIOB->OTYPER &= ~(1 << 4);		//推挽输出
	
	GPIOB->OSPEEDR &= ~(3 << 4*2);  //清零
	GPIOB->OSPEEDR |= 2 << 4*2;		//50KHZ
	
	GPIOB->ODR &= ~(1 << 4);		//初始为低电平
//	GPIOB->ODR |= 1 << 4;			//初始为高电平
}
