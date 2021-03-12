
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _date{
    int day;
    int month;
    int year;
} Date;

typedef struct _pet {
    char name[100];
    Date dob;	
} Pet;

void print_index(char *pet_file, int index);

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }

    print_index("Pets", atoi(argv[1]));
}

void print_index(char *pet_file, int index) {
    FILE *f = fopen(pet_file, "r");
    if (f == NULL) {
        // Then we have had an error
        perror(pet_file);
        exit(1);
    }

    int ret = fseek(f, index * sizeof(Pet), SEEK_SET);
    if (ret) {
        perror("fseek");
        exit(1);
    }

    Pet p;
    int num_read = fread(&p, sizeof(Pet), 1, f);
    if (num_read < 1) {
        perror("fread");
        exit(1);
    }

    printf("%s: %d/%d/%d\n", p.name, p.dob.day, p.dob.month, p.dob.year);

}
