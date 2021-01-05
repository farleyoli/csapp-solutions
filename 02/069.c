#include <stdio.h>

/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
*
n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    int m = w - n;
    unsigned y = x;

    x >>= m;
    y <<= n;

    unsigned mask = ((1 << m) - 1) << n;

    return (x&(~mask)) | (y&mask);
}

int main(void) {
    printf("0x%04X\n", rotate_left(0x12345678, 4));
    printf("0x%04X\n", rotate_left(0x12345678, 20));
    printf("0x%04X\n", rotate_left(0x12345678, 0));
    
}
