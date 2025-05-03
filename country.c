#include <stdio.h>      // For printf
#include <stdlib.h>     // For malloc and free
#include <string.h>     // For strdup
#include "country.h"    // Include our custom header file for Country struct

// This function allocates memory and initializes a Country struct with given values
Country *create_country(const char *name, const char *continent, const char *hint1, const char *hint2, const char *hint3) {
    // Allocate memory for a new Country
    Country *new_country = malloc(sizeof(Country));

    // Allocate and copy the name and continent strings
    new_country->name = strdup(name);           // Duplicates the name string to store in struct
    new_country->continent = strdup(continent); // Duplicates the continent string

    // Allocate and copy each hint string
    new_country->hints[0] = strdup(hint1);
    new_country->hints[1] = strdup(hint2);
    new_country->hints[2] = strdup(hint3);

    return new_country;
}

// This function frees all memory allocated for a Country struct
void free_country(Country *country) {
    if (country != NULL) {
        // Free each string inside the struct
        free(country->name);
        free(country->continent);
        for (int i = 0; i < MAX_HINTS; i++) {
            free(country->hints[i]);
        }

        // Free the Country struct itself
        free(country);
    }
}

// This function prints the name and hints of a Country to the terminal
void print_country(const Country *country) {
    printf("Country: %s\n", country->name);
    printf("Continent: %s\n", country->continent);
    for (int i = 0; i < MAX_HINTS; i++) {
        printf("Hint %d: %s\n", i + 1, country->hints[i]);
    }
}
