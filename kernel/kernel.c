
void _start() {

    const char* kernelload = "Kernel loaded - NXI os";


    char* video_memory = (char*) 0xB8000;

    int i = 0;

    while (kernelload[i] != '\0') {
        video_memory[i*2] = kernelload[i];
        video_memory[i*2 + 1] = 0x07;
        ++i;
    }

    i = 0;


}






