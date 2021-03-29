#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char *home = getenv("HOME");
    char diary_path[BUFSIZ];
    snprintf(diary_path, BUFSIZ, "%s/.diary", home);

    FILE *f = fopen(diary_path, "r");
    if (f == NULL) {
        perror(diary_path);
        exit(1);
    }

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }

    return 0;
}
