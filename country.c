// country.c
// ——————————————————————————————————————————————————————————————
// Implements loading country data from text files, merging them,
// and selecting a random entry.

#include "country.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Might remove what is under
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <errno.h>
// #include <string.h>  // For strerror


// loadCountriesFromFile:
//   Reads countries from a single file in the format:
//
//     CountryName
//     Hint line 1
//     Hint line 2
//     Hint line 3
//
//   (blank lines are skipped)
//
//   Returns a malloc’d array of Country and sets *outCount.

// Ensures the data/ folder exists, creates it if not
void ensure_data_directory_exists() {
    struct stat st = {0};

    if (stat("data", &st) == -1) {
        if (mkdir("data", 0700) != 0) {
            printf("Error creating data directory: %s\n", strerror(errno));
        }
    }
}


Country *loadCountriesFromFile(const char *filename, int *outCount) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror(filename);
        *outCount = 0;
        return NULL;
    }

    Country *arr = NULL;
    int count = 0, cap = 0;
    char buffer[MAX_LINE_LEN];

    while (1) {
        // Read country name (skip blank lines)
        if (!fgets(buffer, sizeof(buffer), fp)) 
            break;
        // Remove newline/carriage return
        buffer[strcspn(buffer, "\r\n")] = '\0';
        if (buffer[0] == '\0') 
            continue;

        // Grow array if needed
        if (count >= cap) {
            cap = (cap == 0 ? 3 : cap * 2);
            arr = realloc(arr, cap * sizeof(Country));
            if (!arr) {
                perror("realloc");
                fclose(fp);
                *outCount = 0;
                return NULL;
            }
        }

        // Copy the country name
        strncpy(arr[count].name, buffer, MAX_LINE_LEN);

        // Read the next three lines as hints
        for (int i = 0; i < MAX_HINTS; i++) {
            if (fgets(buffer, sizeof(buffer), fp)) {
                buffer[strcspn(buffer, "\r\n")] = '\0';
                strncpy(arr[count].hints[i], buffer, MAX_LINE_LEN);
            } else {
                // In case of missing lines, set an empty hint
                arr[count].hints[i][0] = '\0';
            }
        }

        count++;
    }

    fclose(fp);
    *outCount = count;
    return arr;
}

// -----------------------------------------------------------------------------
// loadAllCountries:
//   Calls loadCountriesFromFile for each continent file (except Antarctica),
//   merges the results into one big array, and returns it.
// -----------------------------------------------------------------------------
Country *loadAllCountries(int *outTotal) {
    const char *files[] = {
        "asia.txt", "europe.txt", "north_america.txt",
        "south_america.txt", "africa.txt", "australia.txt"
        // Antarctica.txt intentionally omitted
    };
    const int fileCount = sizeof(files) / sizeof(files[0]);

    Country *all = NULL;
    int total = 0;

    for (int f = 0; f < fileCount; f++) {
        int n = 0;
        Country *next = loadCountriesFromFile(files[f], &n);
        if (!next || n == 0) continue;

        // Grow the master array to fit the new batch
        all = realloc(all, (total + n) * sizeof(Country));
        if (!all) {
            perror("realloc in loadAllCountries");
            free(next);
            *outTotal = 0;
            return NULL;
        }

        // Copy the new countries into place
        memcpy(all + total, next, n * sizeof(Country));
        total += n;
        free(next);
    }

    *outTotal = total;
    return all;
}

// -----------------------------------------------------------------------------
// freeCountries:
//   Frees the array returned by loadCountriesFromFile or loadAllCountries.
// -----------------------------------------------------------------------------
void freeCountries(Country *countries) {
    free(countries);
}

// -----------------------------------------------------------------------------
// getRandomIndex:
//   Returns a random index in [0, totalCount).  Call srand(time(NULL)) first.
// -----------------------------------------------------------------------------
int getRandomIndex(int totalCount) {
    if (totalCount <= 0) return 0;
    return rand() % totalCount;
}

