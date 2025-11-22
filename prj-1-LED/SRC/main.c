#include "bsp_led.h"
void Delay(void){
	for(int i=0;i<1000;++i){
		for(int j=0;j<10000;++j);
	}
}

int main(void){
	
	LED_GPIO_Config();
	LED1_OFF;

	while(1){
		LED1_TOGGLE;		
		Delay();
	
	}
	
}
