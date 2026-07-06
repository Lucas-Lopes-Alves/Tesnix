#include <stdint.h>
#include <stddef.h>
#include "interrupts/handlers_table.h"
#include "interrupts/common_handler.h"
#include "pic/pic.h"

void common_handler(registers_t *interrupt)
{
    size_t irq = interrupt->int_no;
    if (handlers[irq] != NULL)
    {
        handlers[irq](interrupt);
    }

    PIC_sendEOI(irq);
    return;
}