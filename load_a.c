#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "load_a.h"
#include "athletes.h"

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
        int yearFirstParticipation;
        int athleteBirth;
        char birthYearStr[10];

        sscanf(line, "%[^;];%[^;];%d;%d;%[^;\n]", athleteID, athleteName, &gamesParticipations, &yearFirstParticipation, birthYearStr);

        if (strcmp(birthYearStr, "") == 0)
            athleteBirth = 0;
        else
            athleteBirth = atoi(birthYearStr);

        Athlete athlete = athleteCreate(athleteID, athleteName, gamesParticipations, yearFirstParticipation, athleteBirth);

        if (listAdd(list, athleteCount, athlete) != LIST_OK) {
            printf("Failed to add athlete to the list\n");
            fclose(file);
            return athleteCount;
        }

        athleteCount++;
    }

    fclose(file);
    return athleteCount;
}