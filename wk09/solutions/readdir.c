#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main (void) {
    DIR *curr_dir = opendir(".");
    struct dirent *curr_entry;
    while ((curr_entry = readdir(curr_dir)) != NULL) {
        if (curr_entry->d_type & DT_DIR) {
            printf("dir: ");
        } else if (curr_entry->d_type & DT_REG) {
            printf("reg: ");
        } else {
            printf("oth: ");
        }
        printf("%s\n", curr_entry->d_name);
    }
}
