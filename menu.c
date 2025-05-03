// menu.c
// Implements the main menu and uses a switch statement to navigate user choices

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// Function to display the menu and handle user input
void display_menu() {
    int choice;

    while (1) {
        // This prints the main menu options to the terminal
        printf("\n=== Guess The Country ===\n");
        printf("1. Start Random Game\n");
        printf("2. Start Endless Mode\n");
        printf("3. Add a Country\n");
        printf("4. View Credits\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        // This reads the user's input for menu selection
        if (scanf("%d", &choice) != 1) {
            // Clears invalid input if non integer entered
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number from 1 to 5.\n");
            continue;
        }

        // This switch statement branches based on the menu selection
        switch (choice) {
            case 1:
                // Placeholder for starting a random game
                printf("Starting Random Game... (Coming soon)\n");
                break;
            case 2:
                // Placeholder for starting endless mode
                printf("Starting Endless Mode... (Coming soon)\n");
                break;
            case 3:
                // Placeholder for adding a new country
                printf("Add a Country... (Coming soon)\n");
                break;
            case 4:
                // Displays the credits
                printf("Credits:\nCreated by [Your Name]\nThanks for playing!\n");
                break;
            case 5:
                // Exits the menu loop and ends the program
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                // Handles any number not between 1 and 5
                printf("Invalid option. Please choose between 1 and 5.\n");
                break;
        }
    }
}
