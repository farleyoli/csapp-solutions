#include <stdio.h>

/* The following code does not run properly on some machines */
int bad_int_size_is_32() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;
    /* set_msb is nonzero when word size >= 32 beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
}

int b_int_size_is_32() {
    /* data type int is at least 32 bits */
    int x = 0x80000000; /* Only first bit is 1 */
    if (x < 0) 
        return 1;
    return 0;
}

int c_int_size_is_32() {
    /* data type int is at least 16 bits */
    int counter = 16;
    int x = 0x8000;
    while (x > 0) {
        x <<= 1;
        counter += 1;
    }
    if (counter == 32) {
        return 1;
    }
    return 0;
}

int main(void) {
    printf("%d\n", b_int_size_is_32());
    printf("%d\n", c_int_size_is_32());
    return 0;
}
