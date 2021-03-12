
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

int main (void) {
    print_pets("my_pets");
}

void print_pets(char *pet_file) {
}
