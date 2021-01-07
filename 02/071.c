#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
into an unsigned */
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    return (((int) word << ((3 - bytenum) << 3)) >> (3 << 3));
}


int main(void) {
    packed_t x = 0x01FF02FE;
    printf("%d\n", xbyte(x, 0));
    printf("%d\n", xbyte(x, 1));
    printf("%d\n", xbyte(x, 2));
    printf("%d\n", xbyte(x, 3));
    return 0;
}
