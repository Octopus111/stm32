#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "adc.h"


//ALIENTEK ̽����STM32F407������ ʵ��18
//ADCģ��ת��ʵ��-�⺯���汾  
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾ 
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
  int a=1;
	int b=0;
 	int adcx;
	u16 adcy;
	float temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	uart_init(9600);	//��ʼ�����ڲ�����Ϊ115200
	LED_Init();					//��ʼ��LED 
 	LCD_Init();         //��ʼ��LCD�ӿ�
	Adc_Init();         //��ʼ��ADC   
	while(1)
	{ 
		
		//adcx=Get_Adc_Average(ADC_Channel_5,2);//��ȡͨ��5��ת��ֵ��1��ȡƽ��
		adcx=4095;
		if(adcx > 256)
		{
		printf("%X",a);
		USART_SendData(USART1, 'A'); 
		printf("%X",a);
		USART_SendData(USART1, 'A'); 
		printf("%X",b);
		printf("%X",adcx);
		printf("%X",b);
		printf("%X\r\n",b);
		//temp=(float)adcx*(3.3/4096);          //��ȡ�����Ĵ�С����ʵ�ʵ�ѹֵ������3.1111
		//adcx=temp;  		//��ֵ����ָ�adcx��������ΪadcxΪu16����
		//printf("%d",adcx);
		//temp-=adcx;                           //���Ѿ���ʾ����������ȥ��������С�����֣�����3.1111-3=0.1111
		//temp*=1000;    		//С�����ֳ���1000�����磺0.1111��ת��Ϊ111.1���൱�ڱ�����λС����
	  //adcy=temp;
		//printf(".%d\r\n",adcy);
		}
    else
    {
		printf("%X",a);
		USART_SendData(USART1, 'A'); 
		printf("%X",a);
		USART_SendData(USART1, 'A'); 
		printf("%X",b);
		printf("%X",b);
			printf("%X",b);
		printf("%X",adcx);
		printf("%X",b);
		printf("%X\r\n",b);
    }		
	}

}



