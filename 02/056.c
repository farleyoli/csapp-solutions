#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main(void) {
    unsigned int x = 314;
    int y = -314;
    float z = 359.0;
    byte_pointer px = (byte_pointer) &x;
    byte_pointer py = (byte_pointer) &y;
    byte_pointer pz = (byte_pointer) &z;
    show_bytes(px, sizeof(unsigned int));
    show_bytes(py, sizeof(int));
    show_bytes(pz, sizeof(float));
}
