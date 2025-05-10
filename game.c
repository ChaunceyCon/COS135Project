#include <stdio.h>
#include <string.h>

#define MAX_HINTS 3
#define MAX_COUNTRIES 100

// Define a structure to hold country data
struct Country {
    char name[100];
    char hints[MAX_HINTS][255];  // 3 hints for each country
};

// Function to read country data from a file
int load_country_data(const char *filename, struct Country countries[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 0;
    }

    int country_count = 0;
    while (fscanf(file, "%99[^\n]\n", countries[country_count].name) == 1) {
        for (int i = 0; i < MAX_HINTS; i++) {
            if (fscanf(file, "%255[^\n]\n", countries[country_count].hints[i]) != 1) {
                break;
            }
        }
        country_count++;
    }

    fclose(file);
    return country_count;
}

// Function to start the guessing game
void start_game() {
    struct Country countries[MAX_COUNTRIES];
    
    // Load country data from the file
    int country_count = load_country_data("data.txt", countries);
    if (country_count == 0) {
        return; // If no data is loaded, exit the game
    }
    
    // Pick a random country index 
    int country_index = 0;
    struct Country country = countries[country_index];
    
    char user_guess[100];
    int correct_guess = 0;
    int hint_index = 0;
    
    printf("Welcome to Guess the Country!\n\n");
    
    // Loop to give hints and take user input
    while (hint_index < 3 && !correct_guess) {
        printf("Hint %d: %s\n", hint_index + 1, country.hints[hint_index]);
        printf("Your guess: ");
        fgets(user_guess, sizeof(user_guess), stdin);
        
        // Remove trailing newline from fgets input
        user_guess[strcspn(user_guess, "\n")] = 0;
        
        // Check if the guess is correct
        if (strcasecmp(user_guess, country.name) == 0) {
            printf("Correct! The country is %s.\n", country.name);
            correct_guess = 1;
        } else {
            printf("Sorry, that's incorrect. Let's move to the next hint.\n\n");
        }
        
        hint_index++;
    }
    
    // If the user didn't guess correctly, reveal the country
    if (!correct_guess) {
        printf("Sorry, you couldn't guess the country. The correct answer is %s.\n", country.name);
    }
}

// Main function to run the game
int main() {
    start_game();
    return 0;
}
