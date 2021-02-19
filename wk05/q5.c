#include <stdio.h>

char *str = "Hello";

int main(void){
    char c = getchar();
    char *s = str;
    while (*s != '\0') {
        if(*s == c){
            printf("Found %c\n",c);
            break;
        }
        s++; // move to next char
    }
    return 0;
}
