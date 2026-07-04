#include "interrupts/isr.h"

__attribute__((noreturn))
void exception_handler(void){
    __asm__ volatile("cli\n\t hlt\n\t");
}