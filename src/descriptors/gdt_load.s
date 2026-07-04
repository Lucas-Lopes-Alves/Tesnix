.global gdt_load
gdt_load:
    movl 4(%esp), %eax
    lgdt (%eax)
    ret
    