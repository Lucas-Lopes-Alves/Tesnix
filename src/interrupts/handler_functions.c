#include <stdint.h>
#include <stddef.h>
#include "interrupts/handler_functions.h"
#include "terminal/terminal.h"
#include "terminal/keyboard.h"
#include "io.h"

void divide_by_zero(registers_t* r)
{
    (void)r;
    vga_writestring("ERROR,Division by zero!\n");
    return;
}

void debug_handler(void)
{
    vga_writestring("Debug");
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
