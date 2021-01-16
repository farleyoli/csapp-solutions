#include <stdio.h>

int saturating_add (int x, int y) {
    /* This code assumes arithmetic shifts */
    /* Ugly solution follows */
    int w = sizeof(int) << 3;
    int min_int = 0x1 << (w-1);
    //printf("Min int is %d\n", min_int);
    int max_int = min_int - 1;
    //printf("Max int is %d\n", max_int);
    int mask = 0x1 << (w-1); /* for taking most significant bit MSB */
    //printf("x %04X, mask %04X, mask & x %04X\n", x, mask, mask & x);
    int msb_x = !((mask & x) == 0);
    int msb_y = !((mask & y) == 0);
    int msb_xy = !((mask & (x+y)) == 0);
    int are_both_negative = msb_x && msb_y;
    int are_both_positive = !msb_x && !msb_y;
    int is_sum_positive = (msb_xy == 0);
    int is_negative_overflow_mask = ((are_both_negative && is_sum_positive) << (w-1)) >> (w-1);
    int is_positive_overflow_mask = ((are_both_positive && (!is_sum_positive)) << (w-1)) >> (w-1);
    int is_not_overflow_mask = !(is_positive_overflow_mask || is_negative_overflow_mask) << 31 >> 31;
    /* The three conditions should be mutually exclusive */

    return (is_negative_overflow_mask & min_int) | (is_positive_overflow_mask & max_int) | (is_not_overflow_mask & (x+y)); 
}

int main(void) {
    printf("The sum of %d and %d is %d\n", 1000, 0x7FFFFFFF-500, saturating_add(1000, 0x7FFFFFFF-500)) ;
    printf("The sum of %d and %d is %d\n", 10, 20, saturating_add(10, 20)) ;
    printf("The sum of %d and %d is %d\n", -1000, -(0x7FFFFFFF-500), saturating_add(-1000, -(0x7FFFFFFF-500))) ;
    return 0;
}
