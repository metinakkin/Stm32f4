#include "stm32f4xx.h"                  // Device header


void delay(uint32_t time)
{
  while(time)
	time--;	
}	


int main()
{
  GPIO_InitTypeDef GPIO_InitStructure;  //Structa ulasmak için degisken tanimladik
	uint8_t button_input;
	uint8_t sayac;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //GPIODya clock verdik,AHB1 hangi clock hattina bagli oldugu
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //GPIOAya clock verdik,AHB1 hangi clock hattina bagli oldugu
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 ;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure); // D portu Out olarak tanimlanmis
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_DOWN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure); // A portu Out olarak tanimlanmis
	while(1)
	{	
	 button_input= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
		
	if(	button_input)
	{
		delay(10000000);
		sayac++;
	}	
	if( (sayac % 8)==0)
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 );
				
	}
	if( (sayac % 8)==1) //Kirmizi
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12);
		GPIO_SetBits(GPIOD,GPIO_Pin_13 | GPIO_Pin_14);
		
	}
	if( (sayac % 8)==2) //Yesil
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_14);
		
	}
	if( (sayac % 8)==3) //Mavi
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
		GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13);
		
	}
	if( (sayac % 8)==4) //Sari
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13);
		GPIO_SetBits(GPIOD, GPIO_Pin_14 );
		
	}
	if( (sayac % 8)==5) //Mor
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_14 );
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
		
	}
	if( (sayac % 8)==6) //Turkuaz,Cyan
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_13 | GPIO_Pin_14);
		GPIO_SetBits(GPIOD,GPIO_Pin_12);
		
	}
	if( (sayac % 8)==7) //Beyaz
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
		
	}
	
}

}