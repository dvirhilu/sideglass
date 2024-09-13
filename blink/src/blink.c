#include <stdint.h>
#include <regs.h>

#define LED_SHIFT 27
#define BLINK_DELAY 100000


void set_reg(uint32_t addr, uint32_t data) {
    uint32_t volatile * const p_reg = (uint32_t *) addr;
    *p_reg = data;
}

void delay(uint32_t count) {
    // do nothing for "count" number of instructions
    while (count--) {
        __asm__("nop");
    }
}

int main(void) {
    uint32_t led_pin_mask = 1 << LED_SHIFT;

    //TODO look into PMC_PCER0 peripheral clock

    set_reg(REG_ADDR(PIOB, PIO_PER), led_pin_mask); // enable PIO controller
    set_reg(REG_ADDR(PIOB, PIO_OER), led_pin_mask); // enable as output
    set_reg(REG_ADDR(PIOB, PIO_CODR), led_pin_mask); // clear existing data
    set_reg(REG_ADDR(PIOB, PIO_MDER), led_pin_mask); // enable multi driver mode
    set_reg(REG_ADDR(PIOB, PIO_PUER), led_pin_mask); // enable pull-up resistor

    while (1) {
        set_reg(REG_ADDR(PIOB, PIO_SODR), led_pin_mask); // turn on LED?
        delay(BLINK_DELAY);
        set_reg(REG_ADDR(PIOB, PIO_CODR), led_pin_mask); // turn off? TODO fix comment based on output lol
        delay(BLINK_DELAY);
    }
    
}

