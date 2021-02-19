#include <stdio.h>

int a[] = {4, 3, 4, 1, 9, 7};
int len = 6;

int main(void){
    int max = a[0];
    int i = 1;

start_while:
    if (i >= len) goto end_while;
    if(a[i] <= max) goto end_if;

    max = a[i];

end_if:
    i++;

    goto start_while;

end_while:
    printf("Max is %d\n",max);
    return 0;
}
