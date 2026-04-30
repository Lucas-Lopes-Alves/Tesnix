#include "terminal.h"
#include "keyboard.h"
#include "io.h"

void kernel_main(void)
{
    terminal_initialize();
    while (1)
    {
        // if (inb(0x64) & 0x01)
        // {
        //     uint8_t code = inb(0x60);
        //     if (code & 0x80)
        //     {
        //         continue;
        //     }
        //     char str[2];
        //     str[0] = keyboard_char(code);
        //     str[1] = '\0';
        //     vga_writestring(str);
        // }
        char str[3];
        keyboard_scancode(0x60,str);
        vga_writestring(str);
        vga_writestring("\n");
    }
}