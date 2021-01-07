#include <stdio.h>

int saturating_add (int x, int y) {
    /* Ugly solution follows */
    int mask = 0x800000; /* for taking MSB */
    int msb_x = ((mask & x) == 0);
    int msb_y = ((mask & y) == 0);
    int msb_xy = ((mask & (x+y)) == 0);
    int are_both_negative = msb_x && msb_y;
    int are_both_positive = !msb_x && !msb_y;
    int is_sum_positive = (msb_xy == 0);
    int is_negative_overflow = are_both_negative && is_sum_positive;
    int is_positive_overflow = are_both_positive && (!is_sum_positive);
    int is_overflow = (is_positive_overflow || is_negative_overflow);
    return 0; 
}

int main(void) {
    return 0;
}
