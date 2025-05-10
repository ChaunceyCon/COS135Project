// menu.c
// ——————————————————————————————————————————————————————————————
// Handles the main menu logic for the "Guess the Country?" game.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"         // For start_game()
#include "add_country.h"  // For add_country()
#include "colors.h"       // For optional color output (if you use it)

void show_menu() {
    char input[10];

    while (1) {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Launch Game\n");
        printf("2. Add a Country\n");
        printf("3. View Credits\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Use fgets to read input safely
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error. Exiting.\n");
            break;
        }

        // Convert input to integer
        int choice = atoi(input);

        // Handle menu options
        switch (choice) {
            case 1:
                start_game();  // Launch the game
                break;
            case 2:
                add_country(); // Launch add country feature
                break;
            case 3:
                printf("Guess the Country? Game created by Your Name!\n");
                break;
            case 4:
                printf("Thanks for playing!\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}

