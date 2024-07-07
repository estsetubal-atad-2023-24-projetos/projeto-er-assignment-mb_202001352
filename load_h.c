#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hosts.h"
#include "map.h"
#include "load_a.h"
#include "load_h.h"

#define BUFFER_SIZE 1024

int loadHosts(const char *filename, PtMap map) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int count = 0;

    fgets(buffer, BUFFER_SIZE, file);

    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *gameSlug = strtok(buffer, ";");
        char *gameEndDate = strtok(NULL, ";");
        char *gameStartDate = strtok(NULL, ";");
        char *gameLocation = strtok(NULL, ";");
        char *gameName = strtok(NULL, ";");
        char *gameSeason = strtok(NULL, ";");
        char *gameYearStr = strtok(NULL, ";");
        int gameYear = atoi(gameYearStr);

        Host host = hostCreate(gameSlug, gameEndDate, gameStartDate, gameLocation, gameName, gameSeason, gameYear);

        mapPut(map, host.gameSlug, host);
        count++;
    }

    fclose(file);
    printf("%d hosts records imported\n", count);
    return count;
}