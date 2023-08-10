/**
 ******************************************************************************
 * @file           : USART_interface.h
 * @author         : Beshoy Soliman
 * @brief          : USART interface file
 ******************************************************************************
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_



typedef enum 
{
	USART1=0,
	USART2,
	USART3
}USART_T;


void MUSART_voidInit(USART_T USART_NUM, u32 Copy_u32Buadrate);
void MUSART_voidTransmitCharacter(USART_T USART_NUM, u8 Copy_u8Character);
void MUSART_u8RecieveCharacter(USART_T USART_NUM, u8 *Ptr_u8RecievedChar);
void MUSART_u8GetRecievedValue(USART_T USART_NUM, u8 *Ptr_u8RecievedChar);
void MUSART_voidEnableUSART_RecieveInterrupt(USART_T USART_NUM);
u16 MUSART_u8IsRecieveBufferAvailable(USART_T USART_NUM);
void MUSART_voidDisableUSART_RecieveInterrupt(USART_T USART_NUM);
void MUSART_voidTransmitnumber(USART_T USART_NUM, u16 Copy_u8Number);
void MUSART_voidTransmitstring(USART_T USART_NUM, u8 arr[]);
#endif
