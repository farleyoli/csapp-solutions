#include <stdio.h>

int is_little_endian() {
    int x = 0xF;
    char *p = (char *) &x;
    if (*p) {
        return 1;
    }
    return 0;
}

int main(void) {
    if(is_little_endian()) {
        printf("This machine is Little Endian.\n");
    } else {
        printf("This machine is NOT Little Endian.\n");
    }
}
