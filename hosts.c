#include <stdio.h>
#include <string.h>

#include "hosts.h"

Host hostCreate(char *slug, char *endDate, char *startDate, char *location, char *name, char *season, int year) {
    Host host;
    strncpy(host.gameSlug, slug, MAX_GAME_SLUG_LENGTH);
    strncpy(host.gameEndDate, endDate, MAX_GAME_SLUG_LENGTH);
    strncpy(host.gameStartDate, startDate, MAX_GAME_SLUG_LENGTH);
    strncpy(host.gameLocation, location, MAX_LOCATION_LENGTH);
    strncpy(host.gameName, name, MAX_GAME_SLUG_LENGTH);
    strncpy(host.gameSeason, season, MAX_GAME_SLUG_LENGTH);
    host.gameYear = year;
    return host;
}

void hostPrint(Host host) {
    printf("Slug: %s, Start Date: %s, End Date: %s, Location: %s, Name: %s, Season: %s, Year: %d\n",
           host.gameSlug, host.gameStartDate, host.gameEndDate, host.gameLocation, host.gameName, host.gameSeason, host.gameYear);
}