#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main(void) {
    unsigned int x = 0xABCDEF;
    byte_pointer px = (byte_pointer) &x;
    show_bytes(px, 3);
}

/* Running the above in my system shows that it uses Little Endian
 * byte orderings */
