#include <stdio.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) {
    int diff = x + (-y);
    int w = sizeof(int) << 3;
    int mask = 0x1 << (w-1); /* for taking MSB */
    int is_x_negative = ((x & mask) != 0);
    int is_my_negative = (((-y) & mask) != 0);
    int is_diff_negative = ((diff & mask) != 0);
    return !((is_x_negative && is_my_negative && (!is_diff_negative)) ||
              ((!is_x_negative) && (!is_my_negative) && is_diff_negative));
}

int main(void) {
    printf("no overflow: %d\n", tsub_ok(10, 5));
    printf("no overflow: %d\n", tsub_ok(-10, 5));
    printf("no overflow: %d\n", tsub_ok(10, -5));
    printf("no overflow: %d\n", tsub_ok(-10, -5));
    printf("no overflow: %d\n", tsub_ok(-10, -5));
    printf("overflow: %d\n", tsub_ok(-2147483645, 1000));
    printf("overflow: %d\n", tsub_ok(2147483645, -1000));
    return 0;
}
