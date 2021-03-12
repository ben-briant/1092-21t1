
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

void append_pet(char *pet_file);

int main (void) {
    append_pet("Pets");
}

// Enter name: ___
// Ented DOB: __/__/__
void append_pet(char *output_file) {
    FILE *f = fopen(output_file, "a");
    if (f == NULL) {
        // Then we have had an error
        perror(output_file);
        exit(1);
    }

    Pet p;
    printf("Enter name: ");
    fgets(p.name, 100, stdin);
    if (p.name[strlen(p.name) - 1] == '\n') {
        p.name[strlen(p.name) - 1] = '\0';
    } 

    printf("Enter DOB: ");
    scanf("%d/%d/%d", &p.dob.day, &p.dob.month, &p.dob.year);

    size_t num_written = fwrite(&p, sizeof(Pet), 1, f);
    if (num_written < 1) {
        perror("fwrite");
        exit(1);
    }
}
