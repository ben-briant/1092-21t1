#include <stdio.h>

int main(void){
    char ch;
    scanf("%c",&ch); 
    switch (ch) {                              
    case 'a':  printf("eh? "); break;          
    case 'e':  printf("eee "); break;          
    case 'i':  printf("eye "); break;        
    case 'o':  printf("ohh "); break;           
    case 'u':  printf("you "); break;         
    }                                        
    printf("\n");
    return 0; 
}
