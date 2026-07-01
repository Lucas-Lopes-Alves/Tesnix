#include <stdint.h>
#include <stddef.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t acess;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));

struct gdt_entry gdt[5];

void get_set_entry(size_t index, uint16_t limit_low, uint16_t base,uint8_t acess, uint8_t granularity){
    gdt[index].base_low = base & 0xffff;
    gdt[index].base_middle = (base >> 16) & 0xff;
    gdt[index].base_high = (base >> 24) & 0xff;
};