#ifndef __MOTOR_H__
#define __MOTOR_H__

void Motor_Init(void);
void Motor_SetSpeed(uint8_t left_1,uint8_t left_2,uint8_t right_1,uint8_t right_2);
void Motor_Run(uint8_t Speed,uint16_t time);
void Motor_Back(uint8_t Speed,uint16_t time);
void Motor_TurnLeft(uint8_t Speed,uint16_t time);
void Motor_Spin_Left(uint8_t Speed,uint16_t time);
void Motor_TurnRight(uint8_t Speed,uint16_t time);
void Motor_Spin_Right(uint8_t Speed,uint16_t time);
void Motor_Brake(uint16_t time);

#endif
