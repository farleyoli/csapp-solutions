#include <stdio.h>

int main(void) {
    int x = 0xFFFFFFFF;
    printf("x = 0x%04X\n", x);
    int a = (x != 0);

    int b = (~x != 0);

    unsigned char xlsb = (x & 0xFFu);
    int c = ((unsigned char) xlsb != 0);

    int shift_val = (sizeof(int)-1) << 3;
    unsigned char xmsbc = ~(((unsigned) x) >> shift_val);
    int d = (xmsbc != 0);
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
}
