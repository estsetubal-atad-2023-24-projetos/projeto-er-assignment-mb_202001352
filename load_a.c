#include <stdio.h>
#include <string.h>

#include "load_a.h"
#include "athletes.h"

int loadAthletes(char *filename, PtList list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File not found\n");
        return 0;
    }

    char line[256];
    int athleteCount = 0;

    // Ignorar a primeira linha (cabeçalho)
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
        listAdd(list, listSize(list, NULL), athlete);
        athleteCount++;
    }

    fclose(file);
    return athleteCount;
}