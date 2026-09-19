#include <stdint.h>
#include "drivers/io/io.h"
#include "drivers/logic/itoa.h"
#include "drivers/screen/printing.h"
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



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void _start(int BOOT_STORAGE_AMOUNT) {
    print("Kernel loaded", 1, 0);
    print("Welcome to NXI os kernel", 3, 0);




    msleep(5000);// sleep 3 sec here
    cls(); // clear screen
    load(1); // loading
    cls();

    print("Initialising System...", 1, 0);
    msleep(1000);
    enable_cursor(0,3); // parameters change cursors size
    print("Cursor enabled", 2, 0);
    int BOOT_STORAGE_AMOUNT_BYTES = BOOT_STORAGE_AMOUNT * 512; // convert to bytes
    const char* STORAGE_AMOUNT_CHAR = itoa(BOOT_STORAGE_AMOUNT_BYTES, 10);
    print("Storage amount in Bytes: ", 3, 0);
    print(STORAGE_AMOUNT_CHAR, 3, 25); // using itoa to properly print the storage amount
    const char* BOOT_SECTOR_AMOUNT = itoa(BOOT_STORAGE_AMOUNT, 10);
    print("Amount of disk sectors used: ", 4, 0);
    print(BOOT_SECTOR_AMOUNT, 4, 29);

}






