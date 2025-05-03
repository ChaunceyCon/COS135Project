// Header guard to prevent multiple inclusion of this header file
#ifndef COUNTRY_H
#define COUNTRY_H

// Constant to define maximum number of hints per country
#define MAX_HINTS 3

// Struct to represent a country with its name, continent, and hints
typedef struct {
    char *name;         // Pointer to the country name string
    char *continent;    // Pointer to the continent name string
    char *hints[MAX_HINTS]; // Array of 3 strings for hints about the country
} Country;

// Function declarations to be implemented in country.c

// Allocates and initializes a new Country structure with provided data
Country *create_country(const char *name, const char *continent, const char *hint1, const char *hint2, const char *hint3);

// Frees memory allocated for a Country structure
void free_country(Country *country);

// Prints the country name and its hints 
void print_country(const Country *country);

#endif

