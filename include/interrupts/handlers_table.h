#ifndef HANDLES_TABLE
#define HANDLES_TABLE

#include <stdint.h>
#include <stddef.h>

extern void (*handlers[256])(registers_t*);

#endif