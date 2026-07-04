#include <stdint.h>
#include <stddef.h>

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));

struct idt_entry {
    uint16_t isr_low;
    uint16_t selector;
    uint8_t reserved;
    uint8_t attributes;
    uint16_t isr_low;
}__attribute__((packed));

__attribute__((aligned(0x10)))
static struct idt_entry idt[256];

static struct idt_ptr idtr;