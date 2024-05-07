#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "Motor.h"
#include <string.h>
#include <stdio.h>
#include "Myu3.h"


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组分2组
//	Serial_Init();
	USART3_init(9600);
	Motor_Init();
	while(1)
	{
		if (MyUsart3.flag)
		{
			MyUsart3.flag = 0;
			if (strcmp((const char*)MyUsart3.buff,"ONA") == 0)
			{
				Motor_Run(80,100);
			}
			if (strcmp((const char*)MyUsart3.buff,"ONB") == 0)
			{
				Motor_Back(80,100);
			}
			if (strcmp((const char*)MyUsart3.buff,"ONC") == 0)
			{
				Motor_Spin_Left(80,100);
			}
			if (strcmp((const char*)MyUsart3.buff,"OND") == 0)
			{
				Motor_Spin_Right(80,100);
			}
			if (strcmp((const char*)MyUsart3.buff,"ONF") == 0)
			{
				Motor_Brake(100);
			}
			if (strcmp((const char*)MyUsart3.buff,"ONE") == 0)
			{
				Motor_Brake(100);
			}
		}
	}
	
}