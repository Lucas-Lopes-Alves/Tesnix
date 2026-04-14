__attribute__((section(".multiboot"), aligned(4)))
const unsigned int header[] = {
    0x1BADB002,
    0x0,
    -(0x1BADB002)
};

void main(void) {
    volatile char* video = (volatile char*)0xb8000;

    video[0] = 'B';
    video[1] = 0x07;
    video[2] = 'a';
    video[3] = 0x07;
    video[4] = 't';
    video[5] = 0x07;
    video[6] = 'a';
    video[7] = 0x07;
    video[8] = 't';
    video[9] = 0x07;
    video[10] = 'a';
    video[11] = 0x07;

    while(1);
}