/**********************************************************************************************************************
 * \file sr04t_lib.h
 *
 * \author  Marco Aguilar
 *
 * \date Feb-03-2024
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *********************************************************************************************************************/

#ifndef SR04T_LIB_H
#define SR04T_LIB_H

#include <stdint.h>
#include <stm32l0xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OP_MODE_3


#ifdef OP_MODE_1
//code for OP_MODE1
#endif

#ifdef OP_MODE_2
//code for OP_MODE2
#endif

#ifdef OP_MODE_3
//code for OP_MODE3
uint16_t v_GetDistance(UART_HandleTypeDef *huart);
#endif

#ifdef __cplusplus
}
#endif

#endif
