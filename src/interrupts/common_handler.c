#include <stdint.h>
#include <stddef.h>
#include "interrupts/handlers_table.h"
#include "interrupts/common_handler.h"

void common_handler(registers_t *interrupt)
{
    size_t vector = interrupt->int_no;
    if (handlers[vector] != NULL)
    {
        handlers[vector](interrupt);
    }

    return;
}