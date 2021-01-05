#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_short(short x) {
    byte_pointer px = (byte_pointer) &x;
    show_bytes(px, sizeof(x));
}

void show_long(long x) {
    byte_pointer px = (byte_pointer) &x;
    show_bytes(px, sizeof(x));
}

void show_double(double x) {
    byte_pointer px = (byte_pointer) &x;
    show_bytes(px, sizeof(x));
}

int main(void) {
    short x = 314;
    long y = -314;
    double z = 359.0;
    show_short(x);
    show_long(y);
    show_double(z);
}
