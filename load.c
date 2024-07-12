#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hosts.h"
#include "athletes.h"
#include "list.h"
#include "map.h"
#include "load.h"

#define BUFFER_SIZE 1024
#define MAX_DATE_LENGTH 100
#define MAX_NAME_LENGTH 100
#define MAX_SEASON_LENGTH 100

int loadHosts(const char *filename, PtMap map) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found\n");
        return -1;
    }

    char line[BUFFER_SIZE];
    int count = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char gameSlug[MAX_GAME_SLUG_LENGTH];
        char gameEndDate[MAX_DATE_LENGTH];
        char gameStartDate[MAX_DATE_LENGTH];
        char gameLocation[MAX_LOCATION_LENGTH];
        char gameName[MAX_NAME_LENGTH];
        char gameSeason[MAX_SEASON_LENGTH];
        char gameYearStr[10];
        int gameYear;

        sscanf(line, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s",
               gameSlug, gameEndDate, gameStartDate, gameLocation,
               gameName, gameSeason, gameYearStr);

        gameYear = atoi(gameYearStr);

        Host host = hostCreate(gameSlug, gameEndDate, gameStartDate, gameLocation, gameName, gameSeason, gameYear);

        char *key = strdup(host.gameSlug);
        if (key == NULL) {
            printf("Memory allocation error for key\n");
            continue;
        }

        if (mapPut(map, key, host) != MAP_OK) {
            printf("Failed to insert host with key: %s\n", host.gameSlug);
            free(key);
        } else
            count++;
    }

    fclose(file);
    printf("%d hosts records imported\n", count);

    //mapPrint(map);

    return count;
}

int loadAthletes(const char *filename, PtList list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found\n");
        return 0;
    }

    char line[256];
    int athleteCount = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char athleteID[MAX_ID_LENGTH];
        char athleteName[MAX_NAME_LENGTH];
        int gamesParticipations;
        char firstGame[MAX_GAME_LENGTH];
        char birthYearStr[10];

        sscanf(line, "%[^;];%[^;];%d;%[^;];%[^;\n]", athleteID, athleteName, &gamesParticipations, firstGame, birthYearStr);

        int yearFirstParticipation = 0;
        if (strlen(firstGame) > 0) {
            sscanf(firstGame, "%*[^0-9]%d", &yearFirstParticipation);
        }

        int athleteBirth = 0;
        if (strcmp(birthYearStr, "") != 0)
            athleteBirth = atoi(birthYearStr);

        Athlete athlete = athleteCreate(athleteID, athleteName, gamesParticipations, yearFirstParticipation, athleteBirth);

        if (listAdd(list, athleteCount, athlete) != LIST_OK) {
            printf("Failed to add athlete to the list\n");
            fclose(file);
            return athleteCount;
        }

        athleteCount++;
    }

    //listPrint(list);

    fclose(file);
    return athleteCount;
}