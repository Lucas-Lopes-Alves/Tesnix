#include "terminal/terminal.h"
#include "descriptors/gdt.h"
#include "descriptors/idt.h"
#include "pic/pic.h"

void kernel_main(void)
{
    __asm__ volatile("cli");
    gdt_init();
    idt_init();
    PIC_remap(0x20,0x28);
    terminal_initialize();
    
    __asm__ volatile("sti");
    for (;;)
    {
        __asm__ volatile("hlt");
    }
    
    // while (1)
    // {
    //     if (inb(0x64) & 0x01)
    //     {
    //         uint8_t code = inb(0x60);
    //         char str[2] ={keyboard_char(code), '\0'};
    //         if (str[0] == '\0'){ continue;}
    //         vga_writestring(str);
    //     }
    //     // char str[3];
    //     // keyboard_scancode(0x60,str);
    //     // vga_writestring(str);
    //     // vga_writestring("\n");
    // }
}