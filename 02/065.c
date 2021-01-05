#include <stdio.h>

int odd_ones(unsigned pattern) {
    pattern ^= (pattern >> 16);
    pattern ^= (pattern >> 8);
    pattern ^= (pattern >> 4);
    pattern ^= (pattern >> 2);
    pattern ^= (pattern >> 1);
    return (pattern & 0x01) != 0;
}

int main(void) {
    unsigned x = 0x80000000u;
    printf("(should be 1) %d\n", odd_ones(x));
    x = 0xC0000000u; 
    printf("(should be 0) %d\n", odd_ones(x));
    x = 0xC000000Cu; 
    printf("(should be 0) %d\n", odd_ones(x));
    x = 0x400C0404u; 
    printf("(should be 1) %d\n", odd_ones(x));
}
