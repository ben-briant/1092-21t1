#include <stdio.h>

char *str = "Hello";

int main(void){
    char c = getchar();
    char *s = str;

start_while:
    if (*s == '\0') goto end_while;
    if(*s != c) goto end_if;

    printf("Found ");
    putchar(c);
    putchar('\n');

    goto end_while;

end_if:
    s++; // move to next char
    goto start_while;
end_while:
    return 0;
}
