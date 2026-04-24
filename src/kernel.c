#include "terminal.h"

void kernel_main(void)
{
    terminal_initialize();

    for (int i = 0; i< 25;i++)
    {
        vga_writestring("Hello kernel world\n");
    }
    while (1)
        ;
}