#ifndef __HANDLER_FUNCTIONS__
#define __HANDLER_FUNCTIONS__

#include "interrupts/common_handler.h"

void divide_by_zero(registers_t *r);

void debug_handler(registers_t *r);

void double_fault_handler(registers_t *r);

void keyboard_handler(registers_t *r);

void generic_handler(registers_t *r);

#endif