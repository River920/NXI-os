extern "C" void main() {
    char* video_memory = (char*) 0xB8000;

    const char* kernelload = "Kernel loaded!";

    int i = 0;

    while (kernelload[i] != '\0') {
        video_memory[i*2] = kernelload[i];
        video_memory[i*2 + 1] = 0x07;
        ++i;
    }
}