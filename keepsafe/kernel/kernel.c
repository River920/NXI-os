#include <stdint.h>
#include "drivers/io/io.h"
#include "drivers/io/cursor.h"
#include "drivers/logic/itoa.h"
#include "drivers/screen/printing.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


void _start(int BOOT_STORAGE_AMOUNT) {
    print("Kernel loaded", 1, 0);
    print("Welcome to NXI os kernel", 3, 0);




    msleep(3000);// sleep 3 sec here
    cls(); // clear screen

    print("Initialising System...", 1, 0);

    msleep(1000);


    enable_cursor(0,14); // parameters change cursors size
    print("Cursor enabled", 2, 0);


    print("###########################################", 3, 0);
    print("###########################################", 4, 0);
    print("Hardware info:", 6, 0);

    // print amount of disk space allocated
    print("Storage amount allocated, in Bytes: ", 8, 0);
    int BOOT_STORAGE_AMOUNT_BYTES = BOOT_STORAGE_AMOUNT * 512; // convert to bytes
    const char* STORAGE_AMOUNT_CHAR = itoa(BOOT_STORAGE_AMOUNT_BYTES, 10); // using itoa to properly print as a const char*
    print(STORAGE_AMOUNT_CHAR, 8, 36);
    
    // print amount of disk sectors allocated
    print("Amount of disk sectors allocated: ", 9, 0);
    const char* BOOT_SECTOR_AMOUNT = itoa(BOOT_STORAGE_AMOUNT, 10);
    print(BOOT_SECTOR_AMOUNT, 9, 34);

    msleep(5000);
    cls();

}






