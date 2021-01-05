#include <stdio.h>


int leftmost_one(unsigned x) {
    x |= (x >> 16);
    x |= (x >> 8);
    x |= (x >> 4);
    x |= (x >> 2);
    x |= (x >> 1);
    x ^= (x >> 1);
    return x;
}

int main(void) {
    int x = 0xFF00;
    printf("x = 0x%04X\n", leftmost_one(x));
    int y = 0x6600;
    printf("y = 0x%04X\n", leftmost_one(y));
    return 0;
}
