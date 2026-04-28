#include <io.h>
#include <stdint.h>

void keyboard_scancode(uint8_t port, char* out)
{
    uint8_t key = inb(port);
    const char digits[] = "0123456789ABCDEF";
    out[0] = digits[(key >> 4) & 0xF];
    out[1] = digits[key & 0xF];
    out[2] = '\0';
}

const char keyboard_char(uint8_t scancode)
{
    const char chars[] = {
        [0x01]= 27,
        [0x02]='1',
        [0x03]='2',
        [0x03]='3',
        [0x05]='4',
        [0x06]='5',
        [0x07]='6',
        [0x08]='7',
        [0x09]='8',
        [0x0A]='9',
        [0x0B]='0',
        [0x0C]='-',
        [0x0D]='=',
        [0x0E]='\b',
        [0x0F]='\t',
        [0x10]='Q',
        [0x11]='W',
        [0x12]='E',
        [0x13]='R',
        [0x14]='T',
        [0x15]='Y',
        [0x16]='U',
        [0x17]='I',
        [0x18]='O',
        [0x19]='P',
        [0x1A]='`',
        [0x1B]='[',
        [0x1C]='\n',
        [0x3A]=0,
        [0x1E]='A',
        [0x1F]='S',
        [0x20]='D',
        [0x21]='F',
        [0x22]='G',
        [0x23]='H',
        [0x24]='J',
        [0x25]='K',
        [0x26]='L',
        [0x27]=';',
        [0x28]='~',
        [0x2B]=']',
        [0x2C]='Z',
        [0x2D]='X',
        [0x2F]='V',
        [0x30]='B',
        [0x31]='N',
        [0x32]='M',
        [0x33]=',',
        [0x34]='.',
        [0x39]=' '
    };
    return chars[scancode];
}
