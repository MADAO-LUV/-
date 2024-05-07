#include "stm32f10x.h"                  // Device header

//1.ʱ����Ԫ
//2.oc����Ƚ�
//3.GPIO��ʼ��

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);   //����TIM4���ⲿʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//PB6-PB9 ����GPIOB���ⲿʱ��
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
//����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; //��0��ʼ���ϼ���
	TIM_TimeBaseInitStruct.TIM_Period = 100 - 1; //ARR��װֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = 36 - 1; //PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0; //�߼���ʱ�����еģ������ò�������
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;  //Ԥ��Ƶ DIV1��0Ԥ��Ƶ
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
	
	// OC ����Ƚ�  ��ʼ��OC�Ƚϵ�����
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	//OC1 ����Ƚ�ͨ����1
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //�Ըߵ�ƽΪ��Ч��ƽ
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR Ԥ��ֵ CNT �� CCR���бȽ�
	TIM_OC1Init(TIM4,&TIM_OCInitStruct);
	
	//oc2
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //�Ըߵ�ƽΪ��Ч��ƽ
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR Ԥ��ֵ CNT �� CCR���бȽ�
	TIM_OC2Init(TIM4,&TIM_OCInitStruct);
	
	//oc3
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //�Ըߵ�ƽΪ��Ч��ƽ
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR Ԥ��ֵ CNT �� CCR���бȽ�
	TIM_OC3Init(TIM4,&TIM_OCInitStruct);
	
	//oc4
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //�Ըߵ�ƽΪ��Ч��ƽ
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0; //CCR Ԥ��ֵ CNT �� CCR���бȽ�
	TIM_OC4Init(TIM4,&TIM_OCInitStruct);
	
	//����Ҫ�����л���ʱ��������ʱ���������ڶ��Ƚ϶̣�  T = 1 / F
//����Ա��Ҫͨ��Ԥ���ؼĴ�������Զ���װ�ؼĴ�������������ʱ�� ����
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	TIM_Cmd(TIM4,ENABLE);
}
