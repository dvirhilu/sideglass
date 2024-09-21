ENTRY(ResetHandler)

MEMORY
{
    FLASH(rx): ORIGIN=0x00080000, LENGTH=512K
    RAM(rwx): ORIGIN=0x20070000, LENGTH=96K /* SRAM0 + SRAM1 */
    ROM(rx): ORIGIN=0x00100000, LENGTH=1024K
}

SECTIONS
{
    .text:
    {
        *(.vector_table) /* Should match name with startup.c */
        *(.text) /* code segment of all input files */
        *(.rodata) /* initialized static constants of all input files */
    }> FLASH

    .data:
    {
        *(.data) /* static variables of all input files */
    }> SRAM AT > FLASH

    .bss:
    {
        *(.bss) /* uninitialized static data of all input files */
    }> SRAM
}