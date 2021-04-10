// Program that does the same thing as pipe.c
// except this time using 'popen' (check `man 3 popen`).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    // popen creates a pipe of the given mode ('r' or 'w').
    // Open a pipe from popen that we can read grep's output from
    FILE *grep_in = popen("grep main file.txt", "r");
    // Open a pipe to wc that we can write grep's output to
    FILE *wc_out = popen("wc", "w");

    char buffer[100];
    while (fgets(buffer, 100, grep_in) != NULL) {
        fputs(buffer, wc_out);
    }
}
