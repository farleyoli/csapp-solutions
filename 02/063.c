#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int w = 8 * sizeof(int);
    unsigned int mask = (1 << (w-k)) - 1;
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    int w = 8 * sizeof(int);
    int bit = (x&(1 << (w-1))) != 0;
    unsigned int mask = ((bit) << (w-k)) - 1;
    return xsrl | ~mask;
}

int main(void) {
    int x = (unsigned) 0x40000000;
    show_bytes((byte_pointer) &x, sizeof(int));
    //x = x >> 10;
    //x = srl(x, 10);
    x = sra(x, 10);
    show_bytes((byte_pointer) &x, sizeof(int));

    return 0;
}
