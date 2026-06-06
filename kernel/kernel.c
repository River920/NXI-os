#include <stdint.h>
#include "drivers/io/io.h"
#define VGA_WIDTH 80
#define VGA_HEIGHT 25



void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}


void update_cursor(int x, int y) {

        

    uint16_t pos = y * VGA_WIDTH + x;

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void print(const char* msg) {



    char* video_memory = (char*) 0xB8000;

    int i = 0;

    enable_cursor(0,3);


    while (msg[i] != '\0') {
        video_memory[i*2] = msg[i];
        video_memory[i*2 + 1] = 0x07;
        ++i;
    }

        i = 0;

}


void _start() {
    print("Kernel loaded - NXI os");
}




