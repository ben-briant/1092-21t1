#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);

    printf("%d", n);

    if(n % 2 == 0) goto even;

    printf(" is odd\n");
    goto end_if;

even:
    printf(" is even\n");

end_if:
    return 0;
}