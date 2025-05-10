// colors.h

#ifndef COLORS_H
#define COLORS_H

#define COLOR_YELLOW    "\033[1;33m"
#define COLOR_RED       "\033[1;31m"
#define COLOR_BLUE      "\033[1;34m"
#define COLOR_GREEN     "\033[1;32m"
#define COLOR_MAGENTA   "\033[1;35m"
#define COLOR_CYAN      "\033[1;36m"
#define COLOR_WHITE     "\033[1;37m"
#define COLOR_RESET     "\033[0m" // To reset back to default color


// ANSI escape codes for text colors by continent
#define AFRICA_COLOR     "\033[1;33m"  // Yellow
#define ASIA_COLOR       "\033[1;31m"  // Red
#define EUROPE_COLOR     "\033[1;34m"  // Blue
#define NORTH_AMERICA_COLOR "\033[1;36m" // Cyan
#define SOUTH_AMERICA_COLOR "\033[1;32m" // Green
#define OCEANIA_COLOR    "\033[1;35m"  // Magenta
#define ANTARCTICA_COLOR "\033[1;37m"  // White/Gray

#define RESET_COLOR      "\033[0m"     // Resets to default terminal color

const char* get_continent_color(const char *continent);


#endif

