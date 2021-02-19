#include <stdio.h>

int main(void) {
    int start, end;
    scanf("%d",&start);
    scanf("%d",&end);

    while (start <= end) {
        printf("%d\n",start);
        start++;
    }
    return 0;
}