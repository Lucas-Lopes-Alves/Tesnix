#include <stdint.h>
#include <stddef.h>
#include "interrupts/handler_functions.h"
#include "terminal/terminal.h"
#include "terminal/keyboard.h"
#include "io.h"

//Isr 0
void divide_by_zero(registers_t* r)
{
    (void)r;
    vga_writestring("ERROR,Division by zero!\n");
    return;
}

// Isr 1
void debug_handler(registers_t* r)
{
    (void)r;
    vga_writestring("Debug");
}

//Isr 8
void double_fault_handler(registers_t *r)
{
    (void)r;
    vga_writestring("Kernel panic!");
    vga_writestring("DOUBLE FAULT!");

    for (;;)
    {
        __asm__ volatile("cli");
        __asm__ volatile("hlt");
    }
}

void keyboard_handler(registers_t* r)
{
    (void)r;
    if (inb(0x64) & 0x01)
    {
        uint8_t code = inb(0x60);
        char str[2] = {keyboard_char(code), '\0'};
        if (str[0] == '\0')
        {
            return;
        }
        vga_writestring(str);
    }
    return;
}

void generic_handler(registers_t* r)
{
    (void)r;
    vga_writestring("generic message\n");
    return;
}