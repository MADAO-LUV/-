#include "stm32f10x.h"                  // Device header

//1.时基单元
//2.oc输出比较
//3.GPIO初始化

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);   //开启TIM4的外部时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//PB6-PB9 开启GPIOB的外部时钟
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
//定义时基单元
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; //从0开始向上计数
	TIM_TimeBaseInitStruct.TIM_Period = 100 - 1; //ARR重装值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 36 - 1; //PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0; //高级定时器才有的，我们用不到这里
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;  //预分频 DIV1是0预分频
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
	
	// OC 输出比较  初始化OC比较的属性
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	//OC1 输出比较通道口1
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //以高电平为有效电平
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR 预期值 CNT 与 CCR进行比较
	TIM_OC1Init(TIM4,&TIM_OCInitStruct);
	
	//oc2
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //以高电平为有效电平
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR 预期值 CNT 与 CCR进行比较
	TIM_OC2Init(TIM4,&TIM_OCInitStruct);
	
	//oc3
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //以高电平为有效电平
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR 预期值 CNT 与 CCR进行比较
	TIM_OC3Init(TIM4,&TIM_OCInitStruct);
	
	//oc4
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //以高电平为有效电平
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR 预期值 CNT 与 CCR进行比较
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);
	
	//在需要不断切换定时器的周期时，而且周期都比较短，  T = 1 / F
//程序员需要通过预加载寄存器配合自动重装载寄存器，来操作定时器 缓存
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	TIM_Cmd(TIM4,ENABLE);
}
