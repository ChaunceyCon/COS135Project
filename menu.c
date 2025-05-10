// Implements the main menu and the game launcher function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "country.h"
#include "colors.h" // Added for color definitions

// game_launcher:
//   Loads all countries from the continent files, picks one at random,
//   then gives the user three hints to guess the country.  After the round,
//   frees the country array and returns to the menu.

void game_launcher() {
    int countryCount;
    Country *countries = loadAllCountries(&countryCount);

    // If no countries were loaded, alert and return
    if (countryCount == 0 || countries == NULL) {
        printf(RED "No countries available to play. Please check continent files.\n" RESET);
        return;
    }

    // Pick a random country index
    int randomIndex = getRandomIndex(countryCount);
    Country selected = countries[randomIndex];

    printf("\n" BLUE "=== Guess The Country ===\n" RESET);

    // Give up to MAX_HINTS hints
    for (int i = 0; i < MAX_HINTS; i++) {
        printf(GREEN "Hint %d: %s\n" RESET, i + 1, selected.hints[i]);

        // Prompt for the user's guess
        char guess[MAX_LINE_LEN];
        printf(WHITE "Your guess: " RESET);
        if (fgets(guess, sizeof(guess), stdin) == NULL) {
            // Input error, break out
            break;
        }
        // Remove newline
        guess[strcspn(guess, "\r\n")] = '\0';

        // Check the guess 
        if (strcmp(guess, selected.name) == 0) {
            printf(GREEN "Correct! The country is %s.\n\n" RESET, selected.name);
            freeCountries(countries);
            return;
        } else {
            if (i < MAX_HINTS - 1) {
                printf(RED "Sorry, that's incorrect. Here's the next hint.\n\n" RESET);
            } else {
                printf(RED "Out of hints! The correct answer was %s.\n\n" RESET, selected.name);
            }
        }
    }

    // Clean up the dynamically allocated countries array
    freeCountries(countries);
}

//   Displays the menu in a loop, handling user input via a switch statement.
void show_menu() {
    int choice;

    do {
        printf(BLUE "=== MAIN MENU ===\n" RESET);
        printf(YELLOW "1. Launch Game\n" RESET);
        printf(YELLOW "2. View Credits\n" RESET);
        printf(YELLOW "3. Exit\n" RESET);
        printf(WHITE "Enter your choice: " RESET);
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf(RED "Invalid input. Please enter a number 1–3.\n\n" RESET);
            continue;
        }
        // Clear trailing newline from stdin
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                game_launcher();
                break;
            case 2:
                printf(BLUE "Credits:\n" RESET);
                printf("  Created by Chauncey O'Connell\n\n");
                break;
            case 3:
                printf(GREEN "Thanks for playing! Goodbye.\n" RESET);
                break;
            default:
                printf(RED "Invalid option. Please choose 1–3.\n\n" RESET);
        }
    } while (choice != 3);
}