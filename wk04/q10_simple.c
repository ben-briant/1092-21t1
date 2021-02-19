#include <stdio.h>

int main(void) {
    int start, end;
    scanf("%d", &start);
    scanf("%d", &end);

start_while:
    if (start > end) goto end_while;

    printf("%d\n", start);
    start++;

    goto start_while;


end_while:
    return 0;
}