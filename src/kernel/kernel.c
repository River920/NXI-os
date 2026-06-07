#include <stdint.h>
#include "drivers/io/io.h"
#define VGA_WIDTH 80
#define VGA_HEIGHT 25



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end){
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

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void print(const char* msg, int ln) {
    char* video_memory = (char*) 0xB8000;
    int i = 0;

    --ln; //make the first line line 1 by deducting 1 from ln

    int lnf = ln*80; //line final

    enable_cursor(0,3); // changes kernels size


    while (msg[i] != '\0') {
        video_memory[(lnf + i)*2] = msg[i];
        video_memory[(lnf + i)*2 + 1] = 0x07;
        ++i;
    }

        i = 0;

}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



// sleep func here
void msleep(uint32_t ms) {
    int i = 0;
    int t = ms*100000;

    while (i != t)
    {
        ++i;
    }
    

}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void cls(){
    char* video_memory = (char*) 0xB8000;
    int i = 0;
    int schar = VGA_WIDTH*VGA_HEIGHT; // screen characters

    while(i != schar){
        video_memory[i] = 0;
        ++i;

    }

}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void loadb(int x){

    int i = 0;



    while(i != x){
    
        print("Loading.", 1);
        msleep(1000);
        print("Loading..", 1);
        msleep(1000);
        print("Loading...", 1);
        msleep(1000);
        ++i;
        cls();

    }

}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void _start() {
    print("Kernel loaded", 1);
    print("Welcome to NXI os kernel", 3);

    msleep(3000);// sleep 1 sec here

    cls(); // clear screen

    loadb(3); // load basic


}




