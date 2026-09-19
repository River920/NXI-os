#ifndef PRINTING_H
#define PRINTING_H

#include <stdint.h>
#include <stddef.h>
#define VGA_WIDTH 80
#define VGA_HEIGHT 25


void print(const char* msg, int ln, int clm) {
    char* video_memory = (char*) 0xB8000;
    int clm_index = 0;

    --ln; //make the first line line 1 by deducting 1 from ln

    int lnf = ln*80; //line final


    while (msg[clm_index] != '\0') {
        video_memory[(lnf + clm)*2] = msg[clm_index];
        video_memory[(lnf + clm)*2 + 1] = 0x07;
        ++clm;
        ++clm_index;
    }

        clm = 0;

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

void load(int x){

    int i = 0;



    while(i != x){
    
        print("Loading..", 1, 0);
        msleep(800);
        print(".Loading.", 1, 0);
        msleep(800);
        print("..Loading", 1, 0);
        msleep(800);
        print("...Loadin", 1, 0);
        msleep(800);
        print("....Loadi", 1, 0);
        msleep(800);
        print(".....Load", 1, 0);
        msleep(800);
        print("......Loa", 1, 0);
        msleep(800);
        print(".......Lo", 1, 0);
        msleep(800);
        print("........L", 1, 0);
        msleep(800);
        print(".........", 1, 0);
        msleep(800);
        print("g........", 1, 0);
        msleep(800);
        print("ng.......", 1, 0);
        msleep(800);
        print("ing......", 1, 0);
        msleep(800);
        print("ding.....", 1, 0);
        msleep(800);
        print("ading....", 1, 0);
        msleep(800);
        print("oading...", 1, 0);
        msleep(800);
        print("Loading..", 1, 0);
        msleep(800);
        cls();
        ++i;
    }

}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
#endif