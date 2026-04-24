#include "include/terminal.h"

void kernel_main(void)
{
    const char* teste[] = { "-`\n",
"                  .o+`\n",
"                 `ooo/\n",
"                `+oooo:\n",
"               `+oooooo:\n",
"               -+oooooo+:\n",
"             `/:-:++oooo+:\n",
"            `/++++/+++++++:\n",
"           `/++++++++++++++:\n",
"          `/+++ooooooooooooo/`\n",
"         ./ooosssso++osssssso+`\n",
"        .oossssso-````/ossssss+`\n",
"       -osssssso.      :ssssssso.\n",
"      :osssssss/        osssso+++.\n",
"    /ossssssss/        +ssssooo/-\n",
"   `/ossssso+/:-        -:/+osssso+-\n",
"  `+sso+:-`                 `.-/+oso:\n",
"`++:.                           `-/+/\n",
" .`                                 `"};
    terminal_initialize();

    for (int i = 0; i< 20;i++)
    {
        vga_writestring(teste[i]);
    }
    while (1)
        ;
}