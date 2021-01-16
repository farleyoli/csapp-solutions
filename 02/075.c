/* This code will not compile because we do not have access to a
 * int signed_high_prod(int x, int y); function */
#include <stdio.h>

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    return (unsigned) signed_high_prod((int) x, (int) y);
}

int main(void) {
    return 0;
}
