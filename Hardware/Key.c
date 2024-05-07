#include "stm32f10x.h"                  // Device header
#include "Delay.h"

//初始化Key键
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //配置成上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//设置返回的键值
uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) == Bit_RESET)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) == Bit_RESET);
		Delay_ms(20);
		KeyNum = 1;
	}
	return KeyNum;
}