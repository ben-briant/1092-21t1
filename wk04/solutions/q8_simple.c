#include <stdio.h>

int main(void){
    char ch;
    scanf("%c",&ch); 

    char *str;

    str = "eh? ";
    if (ch == 'a') goto print;
    str = "eee ";
    if (ch == 'e') goto print;
    str = "eye ";
    if (ch == 'i') goto print;
    str = "ohh ";
    if (ch == 'o') goto print;
    str = "you ";
    if (ch == 'u') goto print;
    str = "";

print:
    printf("%s", str);
    printf("\n");
    return 0; 
}
