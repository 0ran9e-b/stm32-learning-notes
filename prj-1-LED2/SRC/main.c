#include "stm32f10x.h"

void LED_GPIO_Init(void){			//LED的GPIO配置
  GPIO_InitTypeDef gpio;			//定义一个GPIO初始化结构体
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	//开启GPIOB的RCC时钟
  //给初始化结构体的各个成员赋值
  gpio.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5;		//引脚号根据硬件实际连接进行赋值这里时PB0 PB1 PB5
  gpio.GPIO_Speed = GPIO_Speed_10MHz;		//运行速度暂无特殊要求
  gpio.GPIO_Mode = GPIO_Mode_Out_PP;		//设置GPIO的模式为GPIO_Mode_Out_PP输出模式
  
  GPIO_Init(GPIOB,&gpio);			//使用标准库函数对GPIOB传入初始化结构体的参数
  
  GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5);		//初始化设为高电平，即LED熄灭，根据实际连接电路进行设置
    
}
void Buzzer_GPIO_Init(void){
  GPIO_InitTypeDef gpio;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
  
  gpio.GPIO_Pin = GPIO_Pin_0 ;
  gpio.GPIO_Speed = GPIO_Speed_10MHz;
  gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  
  GPIO_Init(GPIOC,&gpio);
  
  GPIO_ResetBits(GPIOC,GPIO_Pin_0 );  
}

void delay(u32 t){
  u32 i,j;
  for(i=0;i<t;i++){
    for(j=0;j<1000;j++);
  }  
}
void LED_G_On(void){
  GPIO_ResetBits(GPIOB,GPIO_Pin_0 );
}
void LED_G_Off(void){
  GPIO_SetBits(GPIOB,GPIO_Pin_0 );
}

void LED_B_On(void){
  GPIO_ResetBits(GPIOB,GPIO_Pin_1 );
}
void LED_B_Off(void){
  GPIO_SetBits(GPIOB,GPIO_Pin_1 );
}

void LED_R_On(void){
  GPIO_ResetBits(GPIOB,GPIO_Pin_5 );
}
void LED_R_Off(void){
  GPIO_SetBits(GPIOB,GPIO_Pin_5 );
}


void BuzzerOn(void){
  GPIO_SetBits(GPIOC,GPIO_Pin_0);
}
void BuzzerOff(void){
  GPIO_ResetBits(GPIOC,GPIO_Pin_0);
}
int main(void){
  
  LED_GPIO_Init();
  Buzzer_GPIO_Init();
  while(1){
    LED_G_On();
   // BuzzerOn();
    delay(1000);
    LED_G_Off();
   // BuzzerOff();
    delay(1000);
		LED_B_On();
   // BuzzerOn();
    delay(1000);
    LED_B_Off();
   // BuzzerOff();
    delay(1000);
		LED_R_On();
   // BuzzerOn();
    delay(1000);
    LED_R_Off();
   // BuzzerOff();
    delay(1000);
  }
	
}
