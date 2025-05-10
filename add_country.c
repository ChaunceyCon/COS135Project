// add_country.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

#define MAX_NAME_LEN 100
#define MAX_HINT_LEN 255

void add_country() {
    const char *continents[] = {
        "Africa", "Asia", "Europe",
        "NorthAmerica", "SouthAmerica",
        "Oceania", "Antarctica"
    };

    printf("\n=== Add a New Country ===\n");
    for (int i = 0; i < 7; i++) {
        printf("%d. %s\n", i + 1, continents[i]);
    }

    printf("Select a continent (1–7): ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);

    if (choice < 1 || choice > 7) {
        printf("Invalid continent selection.\n");
        return;
    }

    const char *selected_continent = continents[choice - 1];

    char country_name[MAX_NAME_LEN];
    char hints[3][MAX_HINT_LEN];

    printf("Enter the country name: ");
    fgets(country_name, sizeof(country_name), stdin);
    country_name[strcspn(country_name, "\n")] = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter hint %d: ", i + 1);
        fgets(hints[i], sizeof(hints[i]), stdin);
        hints[i][strcspn(hints[i], "\n")] = 0;
    }

    char filepath[256];
    snprintf(filepath, sizeof(filepath), "data/%s.txt", selected_continent);

    FILE *file = fopen(filepath, "a");
    if (!file) {
        printf("Failed to open file for appending: %s\n", filepath);
        return;
    }

    fprintf(file, "%s\n", country_name);
    for (int i = 0; i < 3; i++) {
        fprintf(file, "%s\n", hints[i]);
    }

    fclose(file);

    // Confirmation message with color
    printf("%sSuccessfully added %s to %s.txt!%s\n",
           get_continent_color(selected_continent),
           country_name,
           selected_continent,
           COLOR_RESET);
}
