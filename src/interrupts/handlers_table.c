#include <stdint.h>
#include <stddef.h>
#include "interrupts/handlers_table.h"
#include "interrupts/handler_functions.h"
#include "interrupts/common_handler.h"

void (*handlers[256])(registers_t*) = {
    [0] = divide_by_zero,
    [32] = keyboard_handler
};