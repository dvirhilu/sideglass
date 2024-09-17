#include <stdint.h>

/*
* ----------------------------------------------------------------------------------------------
* Vector Table Addresses
* For more information, refer to secion 10.6.4 of the datasheet
* 
* Note that the base address can change using the VTOR but
* we will not be doing so for this project.
* ----------------------------------------------------------------------------------------------
*/
#define INIT_STACK_PTR 0x0000
#define RESET          0x0004
#define HARD_FAULT     0x000c
#define MEM_MGMT_FAULT 0x0010
#define BUS_FAULT      0x0014
#define USG_FAULT      0x0018
#define SVCALL         0x002c
#define PENDSV         0x0038
#define SYSTICK        0x003c
#define IRQ0           0x0040
#define IRQ1           0x0044
#define IRQ2           0x0048
#define IRQ3           0x004c
#define IRQ4           0x0050
#define IRQ5           0x0054
#define IRQ6           0x0058
#define IRQ7           0x005c
#define IRQ8           0x0060
#define IRQ9           0x0064
#define IRQ10          0x0068
#define IRQ11          0x006c
#define IRQ12          0x0070
#define IRQ13          0x0074
#define IRQ14          0x0078
#define IRQ15          0x007c
#define IRQ16          0x0080
#define IRQ17          0x0084
#define IRQ18          0x0088
#define IRQ19          0x008c
#define IRQ20          0x0090
#define IRQ21          0x0094
#define IRQ22          0x0098
#define IRQ23          0x009c
#define IRQ24          0x00a0
#define IRQ25          0x00a4
#define IRQ26          0x00a8
#define IRQ27          0x00ac
#define IRQ28          0x00b0
#define IRQ29          0x00b4

/*
* ----------------------------------------------------------------------------------------------
* Initial Stack Pointer Calculation
* Refer to section 7.2 in the datasheet for RAM address mapping
* ----------------------------------------------------------------------------------------------
*/
#define SRAM_START     0x20070000
#define SRAM_SIZE      0x00018000 // 64KB (SRAM0) + 32KB (SRAM1)
#define SRAM_END       (SRAM_START+SRAM_SIZE-1)
#define INIT_STACK_PTR SRAM_END 

/*
* ----------------------------------------------------------------------------------------------
* Handler Function Defs
* ----------------------------------------------------------------------------------------------
*/

void ResetHandler(void);
// These will get replaced by the DefaultHandler alias
// 'weak' attribute allows programmer to override these function implementations 
// later in the main source files
void HardFaultHandler(void)     __attribute__((weak, alias("DefaultHandler")));
void MemMgmtFaultHandler(void)  __attribute__((weak, alias("DefaultHandler")));
void BusFaultHandler(void)      __attribute__((weak, alias("DefaultHandler")));
void UsgFaultHandler(void)      __attribute__((weak, alias("DefaultHandler")));
void SVCallHandler(void)        __attribute__((weak, alias("DefaultHandler")));
void PendSVHandler(void)        __attribute__((weak, alias("DefaultHandler")));
void SystickHandler(void)       __attribute__((weak, alias("DefaultHandler")));

/*
* ----------------------------------------------------------------------------------------------
* Vector Table Array
* ----------------------------------------------------------------------------------------------
*/
__attribute__((section(".vector_table")))
uint32_t vectors[] = {
    INIT_STACK_PTR,
    (uint32_t)&ResetHandler,
    0,                              // Reserved
    (uint32_t)&HardFaultHandler,
    (uint32_t)&MemMgmtFaultHandler,
    (uint32_t)&BusFaultHandler,
    (uint32_t)&UsgFaultHandler,
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    (uint32_t)&SVCallHandler,
    0,                              // Reserved for Debug
    0,                              // Reserved
    (uint32_t)&PendSVHandler,
    (uint32_t)&SystickHandler
};

// Dummy function
void DefaultHandler(void) {
    while(1);
}

// First handler that gets called upon device reset
void ResetHandler() {
    // copy .data section to SRAM

    //initializae the .bss section to zero in SRAM

    // call init function of std library

    /// call main()
}