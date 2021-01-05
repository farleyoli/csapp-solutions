#include <stdio.h>

int any_odd_one(unsigned x) {
    // Assuming w = 32, we can write out the mask directly.
    int w = 32;
    unsigned int mask = 0x55555555;
    return (x&mask) != 0;
}

int main(void) {
    int x = 10;
    printf("%d\n", any_odd_one(x));
    x = 1;
    printf("%d\n", any_odd_one(x));
}
