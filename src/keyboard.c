#include <io.h>
#include <stdint.h>
#include <stdbool.h>
#include "keymap.h"

void ps2_write_wait()
{
    while (inb(0x64) & 0x02)
        ;
}

void ps2_read_wait()
{
    while (!(inb(0x64) & 0x01))
        ;
}

void keyboard_scancode(uint8_t port, char *out)
{
    uint8_t key = inb(port);
    const char digits[] = "0123456789ABCDEF";
    out[0] = digits[(key >> 4) & 0xF];
    out[1] = digits[key & 0xF];
    out[2] = '\0';
}

typedef struct
{
    bool capslock;
    bool scrollock;
    bool numlock;
}locks;

locks kbd_state = {false,false,false};

bool shift = false;

const char keyboard_char(uint8_t scancode)
{
    if (scancode == 0x2A || scancode == 0x36)
    {
        if (shift)
        {
            shift = false;
        }
        else
        {
            shift = true;
        }
    }
    if (scancode == 0x3A)
    {
        if (kbd_state.capslock)
        {
            ps2_write_wait();
            outb(0x60, 0xED);
            ps2_write_wait();
            outb(0x60, 0x00);
            kbd_state.capslock = false;
        }
        else
        {
            ps2_write_wait();
            outb(0x60, 0xED);
            ps2_write_wait();
            outb(0x60, 0x04);
            kbd_state.capslock = true;
        }
    }
    else if (scancode == 0x45)
    {

    }
    
    if (kbd_state.capslock)
    {
        return charsAlt[scancode];
    }
    else
    {
        return chars[scancode];
    }
}
