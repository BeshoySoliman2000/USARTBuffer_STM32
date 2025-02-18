/******************************************************/
/* Author    : Asmaa Hashim                           */
/* Date      : 8 Augest 2020                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_ISER0  *((u32*)0XE000E100)

#define NVIC_ISER1  *((u32*)0XE000E104)


#define NVIC_ICER0  *((u32*)0XE000E180)

#define NVIC_ICER1  *((u32*)0XE000E184)


#define NVIC_ISPR0  *((u32*)0XE000E200)

#define NVIC_ISPR1  *((u32*)0XE000E204)


#define NVIC_ICPR0  *((u32*)0XE000E280)

#define NVIC_ICPR1  *((u32*)0XE000E284)


#define NVIC_IABR0 *((u32*)0XE000E300)

#define NVIC_IABR1  *((u32*)0XE000E304)

#define NVIC_IPR     ((u8*)0XE000E400)

#define SCB_AIRCR   *((volatile u32*)0XE000ED0C)


#define MNVIC_GROUP_4_SUB_0 0X05FA0300
#define MNVIC_GROUP_3_SUB_1 0X05FA0400
#define MNVIC_GROUP_2_SUB_2 0X05FA0500
#define MNVIC_GROUP_1_SUB_3 0X05FA0600
#define MNVIC_GROUP_0_SUB_4 0X05FA0700




#endif /* NVIC_PRIVATE_H_ */
