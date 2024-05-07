#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

//机器人初始化
void Motor_Init(void)
{
	PWM_Init();
}


//控制小车轮子的速度,分别设置四个通道的RCC，每两个通道,控制一个轮子
void Motor_SetSpeed(uint8_t left_1,uint8_t left_2,uint8_t right_1,uint8_t right_2)
{
	TIM_SetCompare1(TIM4,left_1);
	TIM_SetCompare2(TIM4,left_2);
	TIM_SetCompare3(TIM4,right_1);
	TIM_SetCompare4(TIM4,right_2);
}

//车子向前开动
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
	Motor_SetSpeed(Speed,0,Speed,0); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
}

//车子后退
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
	Motor_SetSpeed(0,Speed,0,Speed); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
	
}

//车子左转
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
	Motor_SetSpeed(0,0,Speed,0); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
	
}

//车子左旋转
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
	Motor_SetSpeed(0,Speed,Speed,0); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
}

//车子右转
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
	Motor_SetSpeed(Speed,0,0,0); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
	
}

//车子右旋转
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
	Motor_SetSpeed(Speed,0,0,Speed); //可以从输出比较的图看出来
	Delay_ms(time);
//	Motor_SetSpeed(0,0,0,0); //最后车子停止运动
}

void Motor_Brake(uint16_t time)
{
	Motor_SetSpeed(0,0,0,0);
	Delay_ms(time);
}