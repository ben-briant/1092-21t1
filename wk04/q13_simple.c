#include <stdio.h>

int main(void){
    int n;

    scanf("%d",&n);

    int i = 0;

start_1:
    if (i >= n) goto end_1;

    int j = 0;

start_2:
    if (j >= n) goto end_2;

    printf("*");
    j++;

    goto start_2;

end_2:
    printf("\n");
    i++;

    goto start_1;

end_1:
    return 0;
}
