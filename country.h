// Defines the Country struct and functions for loading,
// managing, and randomly selecting country data from text files.

#ifndef COUNTRY_H
#define COUNTRY_H

#include <stddef.h>   // for size_t

// How many hints each country has
#define MAX_HINTS 3

// Maximum length for name or hint lines
#define MAX_LINE_LEN 256

// Struct representing a single country and its three hints
typedef struct {
    char name[MAX_LINE_LEN];
    char hints[MAX_HINTS][MAX_LINE_LEN];
} Country;

// Loads all countries from one continent file.
//   filename: path to e.g. "asia.txt"
//   outCount: pointer to int to receive how many were loaded
// Returns a malloc’d array of Country; caller must free it.
Country *loadCountriesFromFile(const char *filename, int *outCount);

// Loads countries from all continent files (excluding Antarctica).
//   outTotal: pointer to int to receive total countries loaded
// Returns a malloc’d array of Country; caller must free it.
Country *loadAllCountries(int *outTotal);

// Frees the array returned by loadCountriesFromFile or loadAllCountries
void freeCountries(Country *countries);

// Returns a random index in [0, totalCount). Call once after srand().
int getRandomIndex(int totalCount);

#endif // COUNTRY_H




