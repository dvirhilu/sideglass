/*
* Register mappings for the Atmel SAM3X MCU
* For more information, refer to the Atmel SAM3x datasheet
* https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-11057-32-bit-Cortex-M3-Microcontroller-SAM3X-SAM3A_Datasheet.pdf
*/

// TODO - if we want this file to be more generic, rename it to regs.h

#ifndef REGS_H
#define REGS_H

/*
* ----------------------------------------------------------------------------------------------
* Peripheral Identifiers
* For more information, refer to secion 9 of the datasheet
* ----------------------------------------------------------------------------------------------
*/

#define PID_SUPC        0
#define PID_RSTC        1
#define PID_RTC         2
#define PID_RTT         3
#define PID_WDG         4
#define PID_PMC         5
#define PID_EEFC0       6
#define PID_EEFC1       7
#define PID_UART        8
#define PID_SMC_SDRAMC  9
#define PID_SDRAMC      10
#define PID_PIOA        11
#define PID_PIOB        12
#define PID_PIOC        13
#define PID_PIOD        14
#define PID_PIOE        15
#define PID_PIOF        16
#define PID_USART0      17
#define PID_USART1      18
#define PID_USART2      19
#define PID_USART3      20
#define PID_HSMCI       21
#define PID_TWI0        22
#define PID_TWI1        23
#define PID_SPI0        24
#define PID_SPI1        25
#define PID_SSC         26
#define PID_TC0         27
#define PID_TC1         28
#define PID_TC2         29
#define PID_TC3         30
#define PID_TC4         31
#define PID_TC5         32
#define PID_TC6         33
#define PID_TC7         34
#define PID_TC8         35
#define PID_PWM         36
#define PID_ADC         37
#define PID_DACC        38
#define PID_DMAC        39
#define PID_UOTGHS      40
#define PID_TRNG        41
#define PID_EMAC        42
#define PID_CAN0        43
#define PID_CAN1        44

// Macro to calculate register addresses
#define REG_ADDR(device, reg_name) (device##_BASE_ADDR + reg_name##_OFFSET)

/*
* ----------------------------------------------------------------------------------------------
* Parallel Input/Output Controller (PIO)
* 
* For more information on the PIO, refer to section 31 of the datasheet
* ----------------------------------------------------------------------------------------------
*/

// offsets for different PIO controllers
#define PIOA_BASE_ADDR 0x400E0E00
#define PIOB_BASE_ADDR 0x400E1000
#define PIOC_BASE_ADDR 0x400E1200
#define PIOD_BASE_ADDR 0x400E1400
#define PIOE_BASE_ADDR 0x400E1600
#define PIOF_BASE_ADDR 0x400E1800

// offset for different PIO Registers
#define PIO_PER_OFFSET    0x0000 // PIO enable register
#define PIO_PDR_OFFSET    0x0004 // PIO disable register
#define PIO_PSR_OFFSET    0x0008 // PIO status register
#define PIO_OER_OFFSET    0x0010 // output enable register
#define PIO_ODR_OFFSET    0x0014 // output disable register
#define PIO_OSR_OFFSET    0x0018 // output status register
#define PIO_IFER_OFFSET   0x0020 // glitch input filter enable  register
#define PIO_IFDR_OFFSET   0x0024 // glitch input filter disable register
#define PIO_IFSR_OFFSET   0x0028 // glitch input filter status register
#define PIO_SODR_OFFSET   0x0030 // set output data register
#define PIO_CODR_OFFSET   0x0034 // clear output data register
#define PIO_ODSR_OFFSET   0x0038 // output data status register
#define PIO_PDSR_OFFSET   0x003c // pin data status register
#define PIO_IER_OFFSET    0x0040 // interrupt enable register
#define PIO_IDR_OFFSET    0x0044 // interrupt disable register
#define PIO_IMR_OFFSET    0x0048 // interrupt mask register
#define PIO_ISR_OFFSET    0x004c // interrupt status register
#define PIO_MDER_OFFSET   0x0050 // multi-driver enable register
#define PIO_MDDR_OFFSET   0x0054 // multi-driver disable register
#define PIO_MDSR_OFFSET   0x0058 // multi-driver status register
#define PIO_PUDR_OFFSET   0x0060 // pull up disable register
#define PIO_PUER_OFFSET   0x0064 // pull up enable register
#define PIO_PUSR_OFFSET   0x0068 // pad pull up status register
#define PIO_ABSR_OFFSET   0x0070 // peripheral AB select register
#define PIO_SCIFSR_OFFSET 0x0080 // system clock glitch input filter select register
#define PIO_DIFSR_OFFSET  0x0084 // debouncing input filter select register
#define PIO_IFDGSR_OFFSET 0x0088 // glitch or debouncing input filter clock selection status register
#define PIO_SCDR_OFFSET   0x008c // slow clock divider debouncing register
#define PIO_OWER_OFFSET   0x00a0 // output write enable register
#define PIO_OWDR_OFFSET   0x00a4 // output write disable register
#define PIO_OWSR_OFFSET   0x00a8 // output write status  register
#define PIO_AIMER_OFFSET  0x00b0 // additional interrupt modes enable register
#define PIO_AIMDR_OFFSET  0x00b4 // additional interrupt modes disable register
#define PIO_AIMMR_OFFSET  0x00b8 // additional interrupt modes mask register
#define PIO_ESR_OFFSET    0x00c0 // edge select register
#define PIO_LSR_OFFSET    0x00c4 // level select register
#define PIO_ELSR_OFFSET   0x00c8 // edge/level status register
#define PIO_FELLSR_OFFSET 0x00d0 // falling edge/low level select register
#define PIO_REHLSR_OFFSET 0x00d4 // rising edge/high level select register
#define PIO_FRLHSR_OFFSET 0x00d8 // fall/rise - low/high status  register
#define PIO_LOCKSR_OFFSET 0x00e0 // lock status register
#define PIO_WPMR_OFFSET   0x00e4 // write protect mode register
#define PIO_WPSR_OFFSET   0x00e8 // write protect mode status register

/*
* ----------------------------------------------------------------------------------------------
*  Power Management Controller (PMC)
* 
* For more information on the PIO, refer to section 28 of the datasheet
* ----------------------------------------------------------------------------------------------
*/

#define PMC_BASE_ADDR     0x400e0600

#define PMC_PCER0_OFFSET  0x0010  //Peripheral Clock Enable Register 0

#endif