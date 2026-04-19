#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//list all the possible colors in vga mode
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

//function for setting the color in the terminal in the vga mode
//returns a size_t with the value of the foreground and background
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | (bg << 4);
}

uint16_t vga_entry(unsigned char c, uint8_t color)
{
    return (uint16_t) c | (uint16_t)(color << 8);
}

//macros for vga width and height and the memory
//where we write the text
#define VGA_WIDTH   80
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xB8000 

//global variables that determines the rows, columns, the terminal color and
//a pointer to the adress to the vga video memory
size_t terminal_row = 0;
size_t terminal_column = 0;
uint8_t terminal_color;
volatile uint16_t* terminal_buffer = (volatile uint16_t*)VGA_MEMORY;

//function to initialize the terminal with no characters
void terminal_initialize(void)
{

    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    uint16_t caractere = vga_entry(' ', terminal_color);
    for (size_t i = 0; i < VGA_HEIGHT; i++)
    {
        for (size_t j = 0; j< VGA_WIDTH; j++)
        {
            size_t index = i * VGA_WIDTH + j;
            terminal_buffer[index] = caractere;
        }
    }
}

//function that returns the size of a string
size_t strlen(const char* str)
{
    size_t size = 0;
    while(str[size])
    {
        size++;
    }
    return size;

}

void terminal_setcolor(uint8_t color)
{
    terminal_color = color;
}

//function that writes in the screen and go to the next line
//when find the '\n' character
void vga_write(const char* info, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (info[i] == '\n')
        {
            terminal_row++;
            terminal_column = 0;

            if (terminal_row == VGA_HEIGHT)
                terminal_row = 0;

            continue;
        }

        size_t index = terminal_row * VGA_WIDTH + terminal_column;
        terminal_buffer[index] = vga_entry(info[i],terminal_color);
        terminal_column++;
        if (terminal_column == VGA_WIDTH)
        {
            terminal_column = 0;
            terminal_row++;
        }

        if (terminal_row == VGA_HEIGHT)
        {
            size_t total = VGA_HEIGHT * VGA_WIDTH;
            for(size_t i = 0; i < total; i++)
            {
                if (terminal_buffer[i] != ' ')
                {
                    terminal_buffer[i-VGA_WIDTH] = terminal_buffer[i];
                }
            }
        }
    }
}

void kernel_main(void)
{
    char word[] = "test\n";
    terminal_initialize();
    terminal_setcolor(vga_entry_color(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK));
    vga_write(word,strlen(word));
    vga_write("hi\n",strlen("hi"));
    for (int i = 0; i< 25; i++)
    {
        vga_write("\n",1);
    }

    while(1);
}