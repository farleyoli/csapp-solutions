#include <stdio.h>

#define SIZE_BYTE 8

unsigned replace_byte (unsigned x, int i, unsigned char b) {
    unsigned mask = 0xFF;
    mask = mask << i * SIZE_BYTE;
    unsigned shifted_b = b << i * SIZE_BYTE;
    unsigned ret = (x & (~mask)) | shifted_b;
    return ret;
}

int main(void) {
    printf("%04X\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%04X\n", replace_byte(0x12345678, 0, 0xAB));
}
