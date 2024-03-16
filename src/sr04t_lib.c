#include <sr04t_lib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Size of Transmission buffer */
#define TXBUFFERSIZE   1
/* Size of Receiver buffer */
#define RXBUFFERSIZE   4
/* Buffer used for transmission */
uint8_t aTxBuffer[TXBUFFERSIZE] = {0x55};
/* Buffer used for receiver */
uint8_t aRxBuffer[RXBUFFERSIZE];

#ifdef OP_MODE_1
//code for OP_MODE1
#endif

#ifdef OP_MODE_2
//code for OP_MODE2
#endif

#ifdef OP_MODE_3
//code for OP_MODE3
uint16_t v_GetDistance(UART_HandleTypeDef *huart)
{
    uint16_t u_distance = 0u;
    HAL_UART_Transmit(huart, (uint8_t*)aTxBuffer, TXBUFFERSIZE, 5000);
    if(HAL_UART_Receive(huart, aRxBuffer, RXBUFFERSIZE, 100) == HAL_OK)
    {
      u_distance = ((uint16_t)aRxBuffer[1] << 8) | (uint16_t)aRxBuffer[2];
    }
    return u_distance;
}
#endif


#ifdef __cplusplus
}
#endif