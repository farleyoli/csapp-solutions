#include <stdio.h>

typedef int T;

int main(void) {
    T x = 0x89ABCDEF;
    T y = 0x76543210;
    T mask = 0xFFu;
    T expression = (mask&x) | ((~mask)&y);
    printf("%04X\n", expression);
}
