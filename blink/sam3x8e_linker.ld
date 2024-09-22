ENTRY(ResetHandler)

MEMORY
{
    FLASH(rx) : ORIGIN =0x00080000, LENGTH =512K
    RAM(rwx) : ORIGIN =0x20070000, LENGTH =96K /* SRAM0 + SRAM1 */
    ROM(rx) : ORIGIN =0x00100000, LENGTH =1024K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table)) /* Should match name with startup.c */
        *(.text) /* Code segment of all input files */
        *(.rodata) /* Initialized static constants of all input files */
        . = ALIGN(4); /* Align location counter to the next word boundary */
        _etext = .; /* _end_of_text. Store the updated location counter value with '.' */
    }> FLASH /* This section never gets relocated. VMA = LMA */

    .data :
    {
        _sdata = .; /* _start_of_data */
        KEEP(*(.data)) /* Static variables of all input files */
        . = ALIGN(4); /* Align location counter to the next word boundary */
        _edata = .; /* _end_of_data */
    }> RAM AT > FLASH

    .bss :
    {
        _sbss = .; /* _start_of_bss */
        KEEP(*(.bss)) /* Uninitialized static data of all input files */
        . = ALIGN(4); /* Align location counter to the next word boundary */
        _ebss = .; /* _end_of_bss */
    }> RAM
}