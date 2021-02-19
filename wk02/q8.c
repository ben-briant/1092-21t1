#include <stdio.h>

int main (void) {

    int ch;
    printf("Enter the ch: ");
    ch = getchar();

    // S1                                      
    printf("First switch statement outputs:\n");
    switch (ch) {                              
        case 'a':  printf("eh? "); break;          
        case 'e':  printf("eee "); break;          
        case 'i':  printf("eye "); break;          
        case 'o':  printf("ohh "); break;          
        case 'u':  printf("you "); break;          
    }                                          
    printf("\n");                              

    // S2
    printf("Second switch statement outputs:\n");
    switch (ch) {
        case 'a':  printf("eh? ");
        case 'e':  printf("eee ");
        case 'i':  printf("eye ");
        case 'o':  printf("ohh ");
        case 'u':  printf("you ");
    }
    printf("\n");
}
