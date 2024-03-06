#include <stdint.h>
#include <stm32l0xx_it.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{

  uint32_t *psrc = &_sidata;
  uint32_t *pdst = &_sdata;

  while(pdst < &_edata)
  {
    *pdst = *psrc;
    ++psrc;
    ++pdst;
  }

  pdst = &_sbss;
  while(pdst < &_ebss)
  {
    *pdst = 0;
    ++pdst;
  }

  main();

  while(1);
}


uint32_t vector_table[] __attribute__ ((section(".isr_vector"))) =
{
  (uint32_t)&_estack,           /* Initial Stack Pointer */
  (uint32_t)&Reset_Handler,     /* Reset Handler */
  (uint32_t)&NMI_Handler,       /* NMI Handler */
  (uint32_t)&HardFault_Handler, /* Hard Fault Handler */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)&SVC_Handler,       /* SVCall Handler */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)&PendSV_Handler,    /* PendSV Handler */
  (uint32_t)&SysTick_Handler,   /* SysTick Handler */
  /* External Interrupts */
  (uint32_t)&Default_Handler,   /* Window Watchdog */
  (uint32_t)&Default_Handler,   /* PVD through EXTI Line detect */
  (uint32_t)&Default_Handler,   /* RTC through EXTI Line */
  (uint32_t)&Default_Handler,   /* FLASH */
  (uint32_t)&Default_Handler,   /* RCC */
  (uint32_t)&Default_Handler,   /* EXTI Line 0 and 1 */
  (uint32_t)&Default_Handler,   /* EXTI Line 2 and 3 */
  (uint32_t)&Default_Handler,   /* EXTI Line 4 to 15 */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)&Default_Handler,   /* DMA1 Channel 1 */
  (uint32_t)&Default_Handler,   /* DMA1 Channel 2 and Channel 3 */
  (uint32_t)&Default_Handler,   /* DMA1 Channel 4, Channel 5, Channel 6 and Channel 7 */
  (uint32_t)&Default_Handler,   /* ADC1, COMP1 */
  (uint32_t)&Default_Handler,   /* LPTIM1 */
  (uint32_t)&Default_Handler,   /* USART4/USART5 */
  (uint32_t)&Default_Handler,   /* TIM2 */
  (uint32_t)&Default_Handler,   /* TIM3 */
  (uint32_t)&Default_Handler,   /* TIM6 */
  (uint32_t)&Default_Handler,   /* TIM7 */
  (uint32_t)0,                  /* Reserved */
  (uint32_t)&Default_Handler,   /* TIM21 */
  (uint32_t)&Default_Handler,   /* I2C3 */
  (uint32_t)&Default_Handler,   /* TIM22 */
  (uint32_t)&Default_Handler,   /* I2C1 */
  (uint32_t)&Default_Handler,   /* I2C2 */
  (uint32_t)&Default_Handler,   /* SPI1 */
  (uint32_t)&Default_Handler,   /* SPI2 */
  (uint32_t)&Default_Handler,   /* USART1 */
  (uint32_t)&Default_Handler,   /* USART2 */
  (uint32_t)&Default_Handler,   /* LPUART1 */
};


