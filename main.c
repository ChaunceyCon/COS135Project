// Entry point: seeds random number generator(RNG), then launches the menu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

int main() {
    // Seed the RNG for random country selection
    srand((unsigned)time(NULL));

    // Launch the main menu loop
    show_menu();

    return 0;
}
