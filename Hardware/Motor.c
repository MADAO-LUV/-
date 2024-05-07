#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

//�����˳�ʼ��
void Motor_Init(void)
{
	PWM_Init();
}


//����С�����ӵ��ٶ�,�ֱ������ĸ�ͨ����RCC��ÿ����ͨ��,����һ������
void Motor_SetSpeed(uint8_t left_1,uint8_t left_2,uint8_t right_1,uint8_t right_2)
{
	TIM_SetCompare1(TIM4,left_1);
	TIM_SetCompare2(TIM4,left_2);
	TIM_SetCompare3(TIM4,right_1);
	TIM_SetCompare4(TIM4,right_2);
}

//������ǰ����
void Motor_Run(uint8_t Speed,uint16_t time)
{
	if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(Speed,0,Speed,0); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
}

//���Ӻ���
void Motor_Back(uint8_t Speed,uint16_t time)
{
	if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(0,Speed,0,Speed); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
	
}

//������ת
void Motor_TurnLeft(uint8_t Speed,uint16_t time)
{
	if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(0,0,Speed,0); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
	
}

//��������ת
void Motor_Spin_Left(uint8_t Speed,uint16_t time)
{
		if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(0,Speed,Speed,0); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
}

//������ת
void Motor_TurnRight(uint8_t Speed,uint16_t time)
{
	if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(Speed,0,0,0); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
	
}

//��������ת
void Motor_Spin_Right(uint8_t Speed,uint16_t time)
{
		if (Speed > 100)
	{
		Speed = 100;
	}
	else if (Speed < 0)
	{
		Speed = 0;
	}
	Motor_SetSpeed(Speed,0,0,Speed); //���Դ�����Ƚϵ�ͼ������
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //�����ֹͣ�˶�
}

void Motor_Brake(uint16_t time)
{
	Motor_SetSpeed(0,0,0,0);
	Delay_ms(time);
}