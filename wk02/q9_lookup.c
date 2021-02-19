#include <stdio.h>

char *numToDay(int n) {
    // Approach using "lookup table"
    if (0 <= n && n <= 6) {
        char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return days[n];
    } else {
        return "Error: Invalid input";
    }
}

int main (void) {
    printf("enter a number between 0-6: ");

    int n;
    scanf("%d", &n);

    printf("%s\n", numToDay(n));
}
