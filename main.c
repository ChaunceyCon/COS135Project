// make clean
// make
// ./guess_country


// main.c
// ——————————————————————————————————————————————————————————————
// Entry point: seeds RNG, then launches the menu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h> // For strerror

void ensure_data_directory_exists() {
    struct stat st = {0};

    if (stat("data", &st) == -1) {
        if (mkdir("data", 0700) != 0) {
            printf("Error creating data directory: %s\n", strerror(errno));
        }
    }
}




int main() {
    // Seed the RNG for random country selection
    srand((unsigned)time(NULL));

    // Launch the main menu loop
    show_menu();

    return 0;
}
