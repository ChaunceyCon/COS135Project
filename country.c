#include <stdio.h>
#include <string.h>
#include "country.h"

// Loads countries from multiple continent files in the current directory
int load_countries(Country countries[]) {
    const char* files[] = {
        "asia.txt", "europe.txt", "africa.txt",
        "north_america.txt", "south_america.txt",
        "australia.txt", "antarctica.txt"
    };

    int country_count = 0;

    for (int f = 0; f < 7; f++) {
        FILE* fp = fopen(files[f], "r");
        if (!fp) continue;

        while (!feof(fp) && country_count < MAX_COUNTRIES) {
            Country* c = &countries[country_count];

            // Read country name
            if (!fgets(c->name, MAX_NAME_LEN, fp)) break;
            c->name[strcspn(c->name, "\n")] = 0;

            // Read 3 hints
            for (int i = 0; i < MAX_HINTS; i++) {
                if (!fgets(c->hints[i], MAX_HINT_LEN, fp)) break;
                c->hints[i][strcspn(c->hints[i], "\n")] = 0;
            }

            country_count++;
        }

        fclose(fp);
    }

    return country_count;
}

