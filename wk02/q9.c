#include <stdio.h>

char *numToDay(int n) {

    char *day;
    // TODO: What is a more concise way to write the if statements?
    switch (n) {
        case 0: day = "Sun"; break;
        case 1: day = "Mon"; break;
        case 2: day = "Tue"; break;
        case 3: day = "Wed"; break;
        case 4: day = "Thu"; break;
        case 5: day = "Fri"; break;
        case 6: day = "Sat"; break;
        default: day = "Error: Invalid day specified";
    }
    return day;
}

int main (void) {
    printf("enter a number between 0-6: ");

    int n;
    scanf("%d", &n);

    printf("%s\n", numToDay(n));
}
