#ifndef __MYU3_H__
#define __MYU3_H__

typedef struct{
	uint8_t buff[100];
	uint8_t flag;		//���յ����ݵı�־λ
	uint8_t len;
}TypeUsart3;
extern TypeUsart3 MyUsart3;

void USART3_init(u32 baud);                   //���ڳ�ʼ������
void usatr3_send_data(u8 c);                  //����һ���ֽڵĺ���
void uatr3_send_data(char * data,u8 len);  


#endif