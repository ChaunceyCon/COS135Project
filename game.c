// game.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colors.h"

#define MAX_HINTS 3
#define MAX_COUNTRIES 100

// Define a structure to hold country data
struct Country {
    char name[100];
    char hints[MAX_HINTS][255];  // 3 hints for each country
    char continent[20];          // Store the continent name
};

// Function to read country data from all files in the data directory
int load_all_country_data(struct Country countries[]) {
    const char *filenames[] = {
        "data/Africa.txt", "data/Asia.txt", "data/Europe.txt",
        "data/NorthAmerica.txt", "data/SouthAmerica.txt",
        "data/Oceania.txt", "data/Antarctica.txt"
    };
    const char *continents[] = {
        "Africa", "Asia", "Europe", "North America", "South America", "Oceania", "Antarctica"
    };

    int country_count = 0;
    for (int i = 0; i < 7; i++) {
        FILE *file = fopen(filenames[i], "r");
        if (file == NULL) continue;

        while (fgets(countries[country_count].name, sizeof(countries[country_count].name), file)) {
            // Remove newline from name
            countries[country_count].name[strcspn(countries[country_count].name, "\n")] = 0;

            for (int j = 0; j < MAX_HINTS; j++) {
                if (!fgets(countries[country_count].hints[j], sizeof(countries[country_count].hints[j]), file)) break;
                countries[country_count].hints[j][strcspn(countries[country_count].hints[j], "\n")] = 0;
            }

            strncpy(countries[country_count].continent, continents[i], sizeof(countries[country_count].continent));
            country_count++;
        }

        fclose(file);
    }

    return country_count;
}

// Function to start the guessing game
void start_game() {
    struct Country countries[MAX_COUNTRIES];

    int country_count = load_all_country_data(countries);
    if (country_count == 0) {
        printf("No country data available. Please add countries first.\n");
        return;
    }

    srand((unsigned)time(NULL));
    int country_index = rand() % country_count;
    struct Country country = countries[country_index];

    char user_guess[100];
    int correct_guess = 0;
    int hint_index = 0;

    const char *color = get_continent_color(country.continent);

    printf("Welcome to Guess the Country!\n\n");

    while (hint_index < MAX_HINTS && !correct_guess) {
        printf("%sHint %d: %s%s\n", color, hint_index + 1, country.hints[hint_index], RESET_COLOR);
        printf("Your guess: ");
        fgets(user_guess, sizeof(user_guess), stdin);
        user_guess[strcspn(user_guess, "\n")] = 0;

        // if (strcasecmp(user_guess, country.name) == 0) {
            if (strcmp(user_guess, country.name) == 0) {
            printf("%sCorrect! The country is %s.%s\n", color, country.name, RESET_COLOR);
            correct_guess = 1;
        } else {
            printf("Sorry, that's incorrect. Let's move to the next hint.\n\n");
        }

        hint_index++;
    }

    if (!correct_guess) {
        printf("Sorry, you couldn't guess the country. The correct answer is %s%s%s.\n", color, country.name, RESET_COLOR);
    }
}

