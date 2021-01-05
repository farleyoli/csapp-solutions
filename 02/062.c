#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int int_shifts_are_arithmetic() {
    int x = -2;
    // show_bytes((byte_pointer) &x, sizeof(int));
    int sx = x >> 1;
    if ((unsigned) sx > (unsigned) x) {
        return 1;
    }
    return 0;
}

int main(void) {
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}
