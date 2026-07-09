.global idt_load
.extern idtr

idt_load:
    # movl 4(%esp), %eax
    lidt idtr
    ret
