#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "adc.h"


//ALIENTEK 探索者STM32F407开发板 实验18
//ADC模数转换实验-库函数版本  
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司 
//作者：正点原子 @ALIENTEK

int main(void)
{ 
  int a=1;
	int b=0;
 	int adcx;
	u16 adcy;
	float temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);    //初始化延时函数
	uart_init(9600);	//初始化串口波特率为115200
	LED_Init();					//初始化LED 
 	LCD_Init();         //初始化LCD接口
	Adc_Init();         //初始化ADC   
	while(1)
	{ 
		
		//adcx=Get_Adc_Average(ADC_Channel_5,2);//获取通道5的转换值，1次取平均
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
		//temp=(float)adcx*(3.3/4096);          //获取计算后的带小数的实际电压值，比如3.1111
		//adcx=temp;  		//赋值整数指鴄dcx变量，因为adcx为u16整形
		//printf("%d",adcx);
		//temp-=adcx;                           //把已经显示的整数部分去掉，留下小数部分，比如3.1111-3=0.1111
		//temp*=1000;    		//小数部分乘以1000，例如：0.1111就转换为111.1，相当于保留三位小数。
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



