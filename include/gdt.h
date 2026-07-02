#include <stdint.h>
#include <stddef.h>

void gdt_init(void);
void gdt_set_entry(size_t index, uint32_t limit, uint32_t base, uint8_t acess, uint8_t flags);
