#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/I2C/I2C_private.h"
#include "../Inc/MCAL/I2C/I2C_config.h"
#include "../Inc/MCAL/I2C/I2C_interface.h"
void MI2C_MasterInit(void)
{
	I2C1->CR2 = 0x08;
	I2C1->CCR = 0x28;
	I2C1->TRISE = 0x09;
	SET_BIT(I2C1->CR1,0);
}

void MasterSendStartCondition(void)
{
	SET_BIT(I2C1->CR1,8);
	while(GET_BIT(I2C1->SR1,0)== 0)
	{
		
	}
}
void MI2C_MasterTransmitAddress(u8 address, DataDir Direction)
{
	u8 AddressWithDir = ((address << 1)|Direction);
	I2C1->DR = AddressWithDir;
	while(GET_BIT(I2C1->SR1,1)== 0)
	{
		
	}
}
void MI2C_MasterRecieve_OneByte(u16 *Data)
{
	while(GET_BIT(I2C1->SR1,6)== 0)
	{
		
	}
	*Data = I2C1->DR;
	CLR_BIT(I2C1->CR1,10);
}
void MasterSendStopCondition(void)
{
	SET_BIT(I2C1->CR1,9);
}
void Master_RecieveDataByte(u8 address, u16 *Data)
{
	MasterSendStartCondition();
	MI2C_MasterTransmitAddress(address, Read);
	MI2C_MasterRecieve_OneByte(&Data);
	MasterSendStopCondition();
}
