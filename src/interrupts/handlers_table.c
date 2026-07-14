#include <stdint.h>
#include <stddef.h>
#include "interrupts/handlers_table.h"
#include "interrupts/handler_functions.h"
#include "interrupts/common_handler.h"

void (*handlers[256])(registers_t*) = {
    [0] = divide_by_zero,
    [1] = generic_handler,
    [2] = non_maskable_interrupt_handler,
    [3] = generic_handler,
    [4] = generic_handler,
    [5] = generic_handler,
    [6] = generic_handler,
    [7] = generic_handler,
    [8] = double_fault_handler,
    [9] = generic_handler,
    [10] = generic_handler,
    [11] = generic_handler,
    [12] = generic_handler,
    [13] = generic_handler,
    [14] = generic_handler,
    [15] = generic_handler,
    [16] = generic_handler,
    [17] = generic_handler,
    [18] = generic_handler,
    [19] = generic_handler,
    [20] = generic_handler,
    [21] = generic_handler,
    [22] = generic_handler,
    [23] = generic_handler,
    [24] = generic_handler,
    [25] = generic_handler,
    [26] = generic_handler,
    [27] = generic_handler,
    [28] = generic_handler,
    [29] = generic_handler,
    [30] = generic_handler,
    [31] = generic_handler,
    [33] = keyboard_handler
};
