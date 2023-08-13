#ifndef	__MY_STM32F4_COMMON__H__
#define __MY_STM32F4_COMMON__H__
#include <stdint.h>

#define PERIPH_BASE 0x40000000U
#define RCC         (PERIPH_BASE + 0x23800U)

#define __IO volatile

typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t PLLCFGR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
            uint32_t DUMMY1;
            uint32_t DUMMY2;
    __IO uint32_t APB1RSTR;
    __IO uint32_t APB2RSTR;
            uint32_t DUMMY3[2];
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
            uint32_t DUMMY4[2];
    __IO uint32_t APB1ENR;
    __IO uint32_t APB2ENR;
            uint32_t DUMMY5[2];
    __IO uint32_t AHB1LPENR;
    __IO uint32_t AHB2LPENR;
            uint32_t DUMMY6[2];
    __IO uint32_t APB1LPENR;
    __IO uint32_t APB2LPENR;
            uint32_t DUMMY7[2];
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
            uint32_t DUMMY8[2];
    __IO uint32_t SSCGR;
    __IO uint32_t PLLI2SCFGR;
            uint32_t DUMMY9;
    __IO uint32_t DCKCFGR;

}RCC_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_BASE)

#endif