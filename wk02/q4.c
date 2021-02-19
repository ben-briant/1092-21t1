#include <stdio.h>

int main(void) {
    int n = 1234; // &n == 0x7654
    int *p;
 
    p = &n;
    n++;
    printf("%d\n", *p); // prints: 1235
    printf("%p\n", p);  // prints: 0x7654
    p++;
    printf("%p\n", p);  // prints: 0x7658
    return 0;
}
