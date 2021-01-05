#include <stdio.h>

/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n) {
    int w = sizeof(int) << 3;
    long mask = 1u;
    mask <<= n;
    mask -= 1;
    return (int) mask;
}

int main(void) {
    printf("0x%04X\n", lower_one_mask(6));
    printf("0x%04X\n", lower_one_mask(17));
    printf("0x%04X\n", lower_one_mask(sizeof(int) << 3));

    return 0;
}
