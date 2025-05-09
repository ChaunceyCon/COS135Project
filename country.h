#ifndef COUNTRY_H
#define COUNTRY_H

#define MAX_NAME_LEN 100
#define MAX_HINT_LEN 256
#define MAX_HINTS 3
#define MAX_COUNTRIES 100

// Struct to hold country and its hints
typedef struct {
    char name[MAX_NAME_LEN];
    char hints[MAX_HINTS][MAX_HINT_LEN];
} Country;

// Loads countries from continent files (asia.txt, europe.txt, etc.)
int load_countries(Country countries[]);

#endif



