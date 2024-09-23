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
* Linker symbols defined in the .ld script. 
* Used to calculate the sizes of various sections of the output ELF file 
* ----------------------------------------------------------------------------------------------
*/
extern uint32_t _etext; // end of .text section
extern uint32_t _sdata; // start of .data section
extern uint32_t _edata; // end of .data section
extern uint32_t _sbss; // start of .bss section
extern uint32_t _ebss; // end of .bss section

int main(void); // declaration of main

/*
* ----------------------------------------------------------------------------------------------
* Handler Function Defs
* ----------------------------------------------------------------------------------------------
*/

void ResetHandler(void);
/*
* These handlers will be replaced by the "DefaultHandler" alias to allow
* the programmer to implement only the required handlers later on in the
* source files. The attribute 'weak' allows programmer to override this alias
* and can re-define the function when required.
*/
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
    // copy .data section from FLASH to SRAM
    uint32_t *p_dst = (uint32_t *)&_sdata; // pointer to destination = SRAM
    uint32_t *p_src = (uint32_t *)&_etext; // pointer to source = FLASH (end of .text section)
    
    while (p_dst < &_edata) {
        *p_dst++ = *p_src++;
    }

    //initializae the .bss section to zero in SRAM
    p_dst = (uint32_t *)&_sbss;

    while (p_dst < &_ebss) {
        *p_dst++ = 0;
    }

    // call init function of std library

    // call main()
    main();
}