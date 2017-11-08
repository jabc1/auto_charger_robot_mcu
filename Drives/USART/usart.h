/*******************************************************************************
 * @name    : ����ͨ�ŵײ�����
 * @author  : ������
 * @web     : WWW.UCORTEX.COM
 * @version : V1.1
 * @date    : 2014-04-03
 * @MDK     : KEIL MDK4.72a & KEL MDK 5.10
 * @brief   : STM32���ڵ����ú�ʹ��
 * ---------------------------------------------------------------------------- 
 * @copyright
 *
 * UCORTEX��Ȩ���У�Υ�߱ؾ�������Դ�������Ҳο���ּ�ڽ���ѧϰ�ͽ�ʡ����ʱ�䣬
 * ������Ϊ�ο����ļ����ݣ��������Ĳ�Ʒֱ�ӻ����ܵ��ƻ������漰���������⣬��
 * �߲��е��κ����Ρ�����ʹ�ù����з��ֵ����⣬���������WWW.UCORTEX.COM��վ��
 * �������ǣ����ǻ�ǳ���л�����������⼰ʱ�о����������ơ����̵İ汾���£�����
 * ���ر�֪ͨ���������е�WWW.UCORTEX.COM�������°汾��лл��
 * ��������������UCORTEX������һ�����͵�Ȩ����
 * ----------------------------------------------------------------------------
 * @description
 * 
 * ע��ʹ�ñ����������ļ�ʱ����Ҫ��stm32f10x_it.c��д��Ӧ�Ĵ��ڽ����жϺ���
 * void USART1_IRQHandler(void)��
 *
 * COM1:
 * USART1_TX -> PA9
 * USART1_RX -> PA10
 * 
 * COM2:
 * USART2_TX -> PA2
 * USART2_RX -> PA3
 * 
 * COM3:
 * USART3_TX -> PB10
 * USART3_RX -> PB11
 *
 * LED -> PB12
 * KEY -> PA0
 *
 *-----------------------------------------------------------------------------
 * @history
 * ----------------------------------------------------------------------------
 * ����ʱ�䣺2014-04-03    �����ˣ�������
 * �汾��¼��V1.0
 * �������ݣ��½�
 * ----------------------------------------------------------------------------
 * ����ʱ�䣺2014-05-01    �����ˣ�������
 * �汾��¼��V1.1
 * �������ݣ�������DMA���䷽ʽ��֧��
 * ----------------------------------------------------------------------------
 *
 ******************************************************************************/

#ifndef __USART_H
#define __USART_H
#include "stm32f10x.h"
#include "remote.h"

#define COMn							3							//����STM32֧�ֵĴ�����	

//����print���ĸ���������������ʹ��printf����ע�͵���һ��
#define PRINTF_SUPPORT		UCORTEX_COM1	
#ifdef PRINTF_SUPPORT
#include <stdio.h>
#endif

//�Ƿ�ʹ�ô���DMA����
#define 	COM_DMA_TRANSFER		1 //�������Ҫ֧��DMA���붨��Ϊ0

#define COM_RX_LEN			128							//���ڽ��ջ��峤��
#if COM_RX_LEN
extern uint16_t COM_RX_STA;							//���ڽ���״̬��
extern uint8_t COM_RX_BUF[COM_RX_LEN];	//���ڽ��ջ���
#endif

/**
 * @brief ����COM PORT1�����ӵ�USART1
 */ 
#define UCORTEX_COM1								USART1
#define UCORTEX_COM1_CLK						RCC_APB2Periph_USART1
#define UCORTEX_COM1_TX_PIN					GPIO_Pin_9
#define UCORTEX_COM1_TX_GPIO_PORT		GPIOA
#define UCORTEX_COM1_TX_GPIO_CLK		RCC_APB2Periph_GPIOA
#define UCORTEX_COM1_RX_PIN					GPIO_Pin_10
#define UCORTEX_COM1_RX_GPIO_PORT		GPIOA
#define UCORTEX_COM1_RX_GPIO_CLK		RCC_APB2Periph_GPIOA
#define UCORTEX_COM1_IRQn						USART1_IRQn
#define UCORTEX_COM1_DR_Base				((uint32_t)0x40013804)
#define UCORTEX_COM1_DMA						((DMA_TypeDef*)DMA1)
#define UCORTEX_COM1_TX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel4)
#define UCORTEX_COM1_RX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel5)


/**
 * @brief ����COM PORT2�����ӵ�USART2
 */ 
#define UCORTEX_COM2								USART2
#define UCORTEX_COM2_CLK						RCC_APB1Periph_USART2
#define UCORTEX_COM2_TX_PIN					GPIO_Pin_2
#define UCORTEX_COM2_TX_GPIO_PORT		GPIOA
#define UCORTEX_COM2_TX_GPIO_CLK		RCC_APB2Periph_GPIOA
#define UCORTEX_COM2_RX_PIN					GPIO_Pin_3
#define UCORTEX_COM2_RX_GPIO_PORT		GPIOA
#define UCORTEX_COM2_RX_GPIO_CLK		RCC_APB2Periph_GPIOA
#define UCORTEX_COM2_IRQn						USART2_IRQn
#define UCORTEX_COM2_DR_Base				((uint32_t)0x40004404)
#define UCORTEX_COM2_DMA						((DMA_TypeDef*)DMA1)
#define UCORTEX_COM2_TX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel7)
#define UCORTEX_COM2_RX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel6)

/**
 * @brief ����COM PORT3�����ӵ�USART3
 */ 
#define UCORTEX_COM3								USART3
#define UCORTEX_COM3_CLK						RCC_APB1Periph_USART3
#define UCORTEX_COM3_TX_PIN					GPIO_Pin_10
#define UCORTEX_COM3_TX_GPIO_PORT		GPIOB
#define UCORTEX_COM3_TX_GPIO_CLK		RCC_APB2Periph_GPIOB
#define UCORTEX_COM3_RX_PIN					GPIO_Pin_11
#define UCORTEX_COM3_RX_GPIO_PORT		GPIOB
#define UCORTEX_COM3_RX_GPIO_CLK		RCC_APB2Periph_GPIOB
#define UCORTEX_COM3_IRQn						USART3_IRQn
#define UCORTEX_COM3_DR_Base				((uint32_t)0x40004804)
#define UCORTEX_COM3_DMA						((DMA_TypeDef*)DMA1)
#define UCORTEX_COM3_TX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel2)
#define UCORTEX_COM3_RX_DMA_CH			((DMA_Channel_TypeDef*)DMA1_Channel3)

//���崮�ڶ˿�
typedef enum 
{
  COM1 = 0,
  COM2 = 1,
	COM3 = 2
} COM_TypeDef;

void send_straight(void);
void send_left(void);
void send_right(void);

void COM_Init(COM_TypeDef COM, uint32_t BaudRate); //���ڳ�ʼ��

void COM_DMA_Polling_Init(COM_TypeDef COM, uint32_t MemoryBaseAddr, uint32_t BufferSize, uint32_t DMA_DIR);

void COM1_DMA_init(uint32_t BaudRate);

void reply_usart1(void);

#endif

/********************* (C) COPYRIGHT 2014 WWW.UCORTEX.COM **********END OF FILE**********/