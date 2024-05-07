#ifndef __MYU3_H__
#define __MYU3_H__

typedef struct{
	uint8_t buff[100];
	uint8_t flag;		//接收到数据的标志位
	uint8_t len;
}TypeUsart3;
extern TypeUsart3 MyUsart3;

void USART3_init(u32 baud);                   //串口初始化函数
void usatr3_send_data(u8 c);                  //发送一个字节的函数
void uatr3_send_data(char * data,u8 len);  


#endif