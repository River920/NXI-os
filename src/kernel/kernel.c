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




    msleep(5000);// sleep 3 sec here
    cls(); // clear screen
    load(1); // loading
    cls();

    print("Initialising System...", 1, 0);

    msleep(1000);


    enable_cursor(0,14); // parameters change cursors size
    print("Cursor enabled", 2, 0);



    print("Storage amount in Bytes: ", 3, 0);
    int BOOT_STORAGE_AMOUNT_BYTES = BOOT_STORAGE_AMOUNT * 512; // convert to bytes
    const char* STORAGE_AMOUNT_CHAR = itoa(BOOT_STORAGE_AMOUNT_BYTES, 10);
    print(STORAGE_AMOUNT_CHAR, 3, 25); // using itoa to properly print the storage amount


    print("Amount of disk sectors used: ", 4, 0);
    const char* BOOT_SECTOR_AMOUNT = itoa(BOOT_STORAGE_AMOUNT, 10);
    print(BOOT_SECTOR_AMOUNT, 4, 29);

}






