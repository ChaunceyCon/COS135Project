#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "country.h"
#include "menu.h"

#define MAX_GUESSES 3
#define MAX_INPUT_LEN 128

// This function gets a line of input from the user and trims newline and whitespace
void get_input(char* buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        // Trim leading spaces
        while (*buffer == ' ') buffer++;
        // Trim trailing spaces
        int len = strlen(buffer);
        while (len > 0 && buffer[len - 1] == ' ') {
            buffer[len - 1] = '\0';
            len--;
        }
    }
}

// This launches the guessing game by selecting a random country and giving up to 3 hints
void game_launcher() {
    CountryList list;
    load_countries_from_all_files(&list);

    if (list.size == 0) {
        printf("No countries loaded.\n");
        return;
    }

    srand((unsigned int)time(NULL));
    int index = rand() % list.size;
    Country selected = list.countries[index];

    printf("=== Guess The Country ===\n");

    char guess[MAX_INPUT_LEN];
    int correct = 0;

    for (int i = 0; i < MAX_HINTS; ++i) {
        printf("%s\n", selected.hints[i]);
        printf("Your guess: ");
        get_input(guess, sizeof(guess));

        // Trim and sanitize the selected country name
        char trimmed_name[MAX_NAME_LEN];
        strncpy(trimmed_name, selected.name, MAX_NAME_LEN);
        trimmed_name[strcspn(trimmed_name, "\n")] = 0;

        while (*trimmed_name == ' ') trimmed_name++;
        int len = strlen(trimmed_name);
        while (len > 0 && trimmed_name[len - 1] == ' ') {
            trimmed_name[len - 1] = '\0';
            len--;
        }

        if (strcasecmp(guess, trimmed_name) == 0) {
            printf("Correct! The country was: %s\n", selected.name);
            correct = 1;
            break;
        } else if (i < MAX_HINTS - 1) {
            printf("Sorry, that is incorrect. Next hint:\n\n");
        }
    }

    if (!correct) {
        printf("Out of hints! The correct answer was: %s\n", selected.name);
    }

    free_country_list(&list);
}

// This displays the credits for the program
void view_credits() {
    printf("\n=== Credits ===\n");
    printf("Guess The Country Game\n");
    printf("Developed by [Your Name Here]\n\n");
}

// This shows the main menu and routes to the appropriate functions
void show_menu() {
    int choice;
    char input[8];

    while (1) {
        printf("\n=== Guess The Country Game ===\n");
        printf("1. Launch Game\n");
        printf("2. View Credits\n");
        printf("3. Exit\n");
        printf("Select an option: ");

        get_input(input, sizeof(input));
        choice = atoi(input);

        switch (choice) {
            case 1:
                game_launcher();
                break;
            case 2:
                view_credits();
                break;
            case 3:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

