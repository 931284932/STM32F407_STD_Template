#include "gpio.h"

void gpio_led_init(void)
{
	RCC->AHB1ENR |= 1 << 1; 		//����B��ʱ��
	
	GPIOB->MODER &= ~(3 << 4 * 2); 	//PB4λ������
	GPIOB->MODER |= 1 << 4 * 2;		//PB4ͨ�����ģʽ
	
	GPIOB->OTYPER &= ~(1 << 4);		//�������
	
	GPIOB->OSPEEDR &= ~(3 << 4*2);  //����
	GPIOB->OSPEEDR |= 2 << 4*2;		//50KHZ
	
	GPIOB->ODR &= ~(1 << 4);		//��ʼΪ�͵�ƽ
//	GPIOB->ODR |= 1 << 4;			//��ʼΪ�ߵ�ƽ
}
