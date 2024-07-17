#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hosts.h"
#include "athletes.h"
#include "medals.h"
#include "list.h"
#include "map.h"
#include "load.h"

#define BUFFER_SIZE 1024
#define INITIAL_CAPACITY 10
#define MAX_LINE_LENGTH 1024
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
    int lineNumber = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        char athleteID[MAX_ID_LENGTH] = "";
        char athleteName[MAX_NAME_LENGTH] = "";
        int gamesParticipations = 0;
        char firstGame[MAX_GAME_LENGTH] = "";
        char birthYearStr[10] = "";

        char *token = strtok(line, ";");
        if (token != NULL) strcpy(athleteID, token);
        
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(athleteName, token);
        
        token = strtok(NULL, ";");
        if (token != NULL) gamesParticipations = atoi(token);
        
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(firstGame, token);
        
        token = strtok(NULL, ";");
        if (token != NULL) strcpy(birthYearStr, token);

        if (strlen(athleteID) == 0 || strlen(athleteName) == 0) {
            printf("Error parsing line %d: %s\n", lineNumber, line);
            continue;
        }

        int yearFirstParticipation = 0;
        if (strlen(firstGame) > 0)
            sscanf(firstGame, "%*[^0-9]%d", &yearFirstParticipation);

        int athleteBirth = 0;
        if (strlen(birthYearStr) > 0)
            athleteBirth = atoi(birthYearStr);

        Athlete athlete = athleteCreate(athleteID, athleteName, gamesParticipations, yearFirstParticipation, athleteBirth);

        int addResult = listAdd(list, athleteCount, athlete);
        if (addResult != LIST_OK) {
            printf("Failed to add athlete at line %d to the list, error code: %d\n", lineNumber, addResult);
            continue;
        }

        athleteCount++;
    }

    fclose(file);
    return athleteCount;
}

int loadMedals(const char* filename, Medal** medals, int* numMedals) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found.\n");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int capacity = INITIAL_CAPACITY;
    *numMedals = 0;
    *medals = (Medal*) malloc(capacity * sizeof(Medal));

    fgets(line, MAX_LINE_LENGTH, file); // Skip header

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (*numMedals >= capacity) {
            capacity *= 2;
            *medals = (Medal*) realloc(*medals, capacity * sizeof(Medal));
        }

        Medal* currentMedal = &(*medals)[*numMedals];

        char *token = strtok(line, ";");

        if (token != NULL) {
            strncpy(currentMedal->discipline, token, sizeof(currentMedal->discipline) - 1);
            currentMedal->discipline[sizeof(currentMedal->discipline) - 1] = '\0';
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            strncpy(currentMedal->game, token, sizeof(currentMedal->game) - 1);
            currentMedal->game[sizeof(currentMedal->game) - 1] = '\0';
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            strncpy(currentMedal->eventTitle, token, sizeof(currentMedal->eventTitle) - 1);
            currentMedal->eventTitle[sizeof(currentMedal->eventTitle) - 1] = '\0';
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            currentMedal->gender = token[0];
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            currentMedal->medalType = token[0];
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            currentMedal->participantType = token[0];
            token = strtok(NULL, ";");
        }
        
        if (token != NULL) {
            if (strlen(token) == 0) {
                strcpy(currentMedal->athleteID, "MISSING");
            } else {
                strncpy(currentMedal->athleteID, token, sizeof(currentMedal->athleteID) - 1);
                currentMedal->athleteID[sizeof(currentMedal->athleteID) - 1] = '\0';
            }
            token = strtok(NULL, ";");
        }
        
        if (token != NULL) {
            strncpy(currentMedal->country, token, sizeof(currentMedal->country) - 1);
            currentMedal->country[sizeof(currentMedal->country) - 1] = '\0';
            token = strtok(NULL, ";");
        }
        if (token != NULL) {
            strncpy(currentMedal->countryCode, token, sizeof(currentMedal->countryCode) - 1);
            currentMedal->countryCode[sizeof(currentMedal->countryCode) - 1] = '\0';
        }

        // Ajuste final: Se participantType for 'A' e athleteID estiver vazio, atribuir "MISSING"
        if (currentMedal->participantType == 'A' && strcmp(currentMedal->athleteID, "MISSING") == 0) {
            strcpy(currentMedal->athleteID, "MISSING");
        }

        (*numMedals)++;
    }

    fclose(file);
    printf("%d medals records imported.\n", *numMedals);
    return 0;
}