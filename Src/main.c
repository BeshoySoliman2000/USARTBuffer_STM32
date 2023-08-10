/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Beshoy Soliman
 * @brief          : Main program body
 ******************************************************************************
 */

#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/MCAL/USART/USART_interface.h"
#include"../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../Inc/MCAL/RCC/RCC_interface.h"
#include	"../Inc/MCAL/SYSTIC/STK_interface.h"

int main(void)
{
	MRCC_voidInit();
	MSTK_voidInit 				  ();
	MRCC_voidPerClock_State(APB2 ,IOPA_PERIPHERAL ,PClock_enable );
	MRCC_voidPerClock_State(APB2, IOPB_PERIPHERAL, PClock_enable);

	MUSART_voidInit(USART2,9600);
	MNVIC_voidEnableInterrupt(USART22);
	MUSART_voidInit(USART1,9600);
	MNVIC_voidEnableInterrupt(USART11);
	MGPIO_voidSetPinDirection(GPIOA , PIN4  , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN5  , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN6  , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN7  , OUTPUT_SPEED_2MHZ_PP);
	for(u32 i=0 ; i<190000 ;i++)
	{
		asm("NOP");
	}
	MUSART_voidTransmitCharacter(USART2, 'a');
	for(u32 i=0 ; i<190000 ;i++)
	{
		asm("NOP");
	}
	MUSART_voidTransmitCharacter(USART2, 'b');
	for(u32 i=0 ; i<190000 ;i++)
	{
		asm("NOP");
	}
	MUSART_voidTransmitCharacter(USART2, 'c');
	for(u32 i=0 ; i<190000 ;i++)
	{
		asm("NOP");
	}
	MUSART_voidTransmitCharacter(USART2, 'd');
	u8 data;
	while(1)
	{
		MUSART_u8GetRecievedValue(USART1, &data);
		for(u32 i=0 ; i<790000 ;i++)
		{
			asm("NOP");
		}
		if(data == 'a')
		{
			MGPIO_voidSetPinValue    (GPIOA , PIN4  , GPIO_HIGH);
		}
		if(data == 'b')
		{
			MGPIO_voidSetPinValue    (GPIOA , PIN5  , GPIO_HIGH);
		}
		if(data == 'c')
		{
			MGPIO_voidSetPinValue    (GPIOA , PIN6  , GPIO_HIGH);
		}
		if(data == 'd')
		{
			MGPIO_voidSetPinValue    (GPIOA , PIN7  , GPIO_HIGH);
		}
	}
}
