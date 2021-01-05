#include <stdio.h>
#include <assert.h>
/*
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
int fits_bits(int x, int n) {
    unsigned mask = ~((1 << n) - 1);
    return (x & mask) == 0;
}

int main(void) {
    printf("False? %d\n", fits_bits(-1, 10));
    printf("True? %d\n", fits_bits(300, 10));
    return 0;
}
