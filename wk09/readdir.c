// Print out a list of all files in the current directory
// and their type (regular file, directory, etc.)

// Add any needed #includes here
#include <sys/types.h>
#include <dirent.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_dir_info(char *dir_name);

int main (void) {
    print_dir_info(".");
}

void print_dir_info(char *dir_name) {

    DIR *d = opendir(dir_name);
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *e;
    while ((e = readdir(d)) != NULL) {
        if (strcmp(".", e->d_name) == 0 || 
            strcmp("..", e->d_name) == 0) {
            continue;
        }

        if (e->d_type & DT_REG) {
            printf("reg: ");
        } else if (e->d_type & DT_DIR) {
            printf("dir: ");
        } else {
            printf("oth: ");
        }
        printf("%s\n", e->d_name);

        if (e->d_type & DT_DIR) {
            print_dir_info(e->d_name);
        }
    }
}
