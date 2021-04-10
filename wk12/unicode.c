#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

int unicodeNbytes(uchar *);
int unicodeNsymbols(uchar *);

int main(void) {
   uchar s[10] = {'a','b','c','\xC2','\xA2','d','e','f','\0'};
   uchar t[10] = {'a','b','c','\xE2','\x86','\xAB','d','e','f','\0'};

   printf("#bytes = %d\n", unicodeNbytes(s));
   printf("#syms  = %d\n", unicodeNsymbols(s));
   printf("#bytes = %d\n", unicodeNbytes(t));
   printf("#syms  = %d\n", unicodeNsymbols(t));

   return 0;
}

int unicodeNbytes(uchar *str) {
    int i;
    for (i = 0; str[i] != 0; i++);
    return i;
}

// check for top-order bit
#define ASCII 0x80
// mask to extract top 4 bits
#define TOP4  0xF0
// tag for 2-byte character
#define MASK2 0xC0
// tag for 3-byte character
#define MASK3 0xE0
// tag for 4-byte character
#define MASK4 0xF0

int unicodeNsymbols(uchar *str) {
    int ns = 0;
    uchar *c = str;
    while (*c != '\0') {
        if ((*c & ASCII) == 0) {
            // 1-byte char
            c++;
        } else if ((*c & TOP4) == MASK2) {
            // 2-byte char
            c += 2;
        } else if ((*c & TOP4) == MASK3) {
            // 3-byte char
            c += 3;
        } else if ((*c & TOP4) == MASK4) {
            // 4-byte char
            c += 4;
        } else {
            // invalid char ... but we had better
            // advance pointer to avoid inf loop
            c++;
        }
        ns++;
    }
    return ns;
}
