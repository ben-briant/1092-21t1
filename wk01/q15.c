#include <stdio.h>

int main (void) {

    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);


    printf("=== a ===\n");
    if (x == 0) {
        printf("zero\n");
    }


    printf("=== b ===\n");
    if (x == 0)
        printf("zero\n");


    printf("=== c ===\n");
    if (x == 0) {
        printf("zero\n");
        printf("after\n");
                
    }


    printf("=== d ===\n");
    if (x == 0)
        printf("zero\n");
        printf("after\n");
}
