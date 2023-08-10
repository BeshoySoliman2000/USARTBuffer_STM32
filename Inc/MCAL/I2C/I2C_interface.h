#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
typedef enum
{
	Write,
	Read
}DataDir;

void MI2C_MasterInit(void);

void Master_RecieveDataByte(u8 address, u16 *Data);
void MasterSendStartCondition(void);
void MI2C_MasterTransmitAddress(u8 address, DataDir Direction);
void MI2C_MasterRecieve_OneByte(u16 *Data);
void MasterSendStopCondition(void);
#endif
