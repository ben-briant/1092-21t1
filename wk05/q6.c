#include <stdio.h>

int a[] = {4, 3, 4, 1, 9, 7};
int len = 6;

int main(void){
    int max = a[0];
    int i = 1;
    while (i < len) {
        if(a[i] > max){
            max = a[i];
        }
        i++;
    }
    printf("Max is %d\n",max);
    return 0;
}
