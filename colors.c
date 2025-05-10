// colors.c

#include <string.h>  // For strcmp
#include <stdio.h>
#include "colors.h"

// ANSI escape codes for text colors
const char *get_continent_color(const char *continent) {
    if (strcmp(continent, "Africa") == 0) return COLOR_YELLOW;
    if (strcmp(continent, "Asia") == 0) return COLOR_RED;
    if (strcmp(continent, "Europe") == 0) return COLOR_BLUE;
    if (strcmp(continent, "NorthAmerica") == 0) return COLOR_GREEN;
    if (strcmp(continent, "SouthAmerica") == 0) return COLOR_MAGENTA;
    if (strcmp(continent, "Oceania") == 0) return COLOR_CYAN;
    if (strcmp(continent, "Antarctica") == 0) return COLOR_WHITE;
    return COLOR_RESET; // Default color
}
