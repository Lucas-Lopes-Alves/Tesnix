#include <stdint.h>
#include <stddef.h>
#include "interrupts/handler_functions.h"
#include "interrupts/common_handler.h"
#include "terminal/terminal.h"
#include "terminal/keyboard.h"
#include "io.h"
#include "functions.h"

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
    return;
}

//Isr 2
void non_maskable_interrupt_handler(registers_t *r)
{
    (void)r;
}

//Isr 8
void double_fault_handler(registers_t *r)
{
    char error[10];
    toStr(r->err_code, error);
    vga_writestring("Kernel panic!");
    vga_writestring("DOUBLE FAULT!\nError code: ");
    vga_writestring(error);
    vga_writestring("\n");

    for (;;)
    {
        __asm__ volatile("cli");
        __asm__ volatile("hlt");
    }
}

//IRQ 1
void keyboard_handler(registers_t* r)
{
    (void)r;
    if (inb(0x64) & 0x01)
    {
        uint8_t code = inb(0x60);
        char str = keyboard_char(code);
        if (str == '\0')
        {
            return;
        }
        vga_putchar(str);
    }
    return;
}

void generic_handler(registers_t* r)
{
    (void)r;
    vga_writestring("generic message");
    return;
}
