
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
    append_pet("my_pets");
}

void append_pet(char *output_file) {
    Pet pet;

    printf("Enter pet's name: ");
    fgets(pet.name, 100, stdin);
    if (pet.name[strlen(pet.name) - 1] == '\n') {
        pet.name[strlen(pet.name) - 1] = '\0';
    } 

    printf("Enter pet's birthday: ");
    scanf("%d/%d/%d", &pet.dob.day, &pet.dob.month, &pet.dob.year);

    FILE *f = fopen(output_file, "a");
    if (f == NULL) {
        perror(output_file);
        exit(1);
    }

    size_t num_written = fwrite(&pet, sizeof(Pet), 1, f);
    if (num_written <= 0) {
        perror("Pet");
        exit(1);
    }
}
