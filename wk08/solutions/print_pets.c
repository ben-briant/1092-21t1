
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

void print_pets(char *pet_file);
void print_index(char *pet_file, int index);

int main (void) {

    print_pets("my_pets");
}

void print_pets(char *pet_file) {
    Pet p;

    FILE *f = fopen(pet_file, "r");
    if (f == NULL) {
        perror(pet_file);
        exit(1);
    }

    while (fread(&p, sizeof(Pet), 1, f) > 0) {
        printf("%s: %d/%d/%d\n", p.name, p.dob.day, p.dob.month, p.dob.year);
    }
}
