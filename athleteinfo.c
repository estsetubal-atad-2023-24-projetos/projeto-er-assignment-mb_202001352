#include <stdio.h>
#include <string.h>

#include "input.h"
#include "athleteinfo.h"

void athleteInfo(PtList athleteList, MedalList medalList) {
    char athleteId[MAX_ID_LENGTH];
    printf("Enter the athlete ID: ");
    readString(athleteId, 50);

    // Procura o atleta na lista de atletas
    int athleteCount;
    listSize(athleteList, &athleteCount);
    for (int i = 0; i < athleteCount; i++) {
        Athlete athlete;
        listGet(athleteList, i, &athlete);
        if (strcmp(athlete.athleteID, athleteId) == 0) {
            // Procura a primeira medalha ganha pelo atleta para obter o país
            char country[MAX_COUNTRY_LENGTH] = "";
            for (int j = 0; j < medalList.size; j++) {
                if (strcmp(medalList.medals[j].athleteID, athleteId) == 0) {
                    strcpy(country, medalList.medals[j].country);
                    break;
                }
            }

            printf("Country: %s\n", country);
            printf("Number of participations: %d\n", athlete.gamesParticipations);
            printf("Year of birth: %d\n", athlete.athleteBirth);

            // Procura as medalhas ganhas pelo atleta
            int medalCount = 0;
            for (int j = 0; j < medalList.size; j++) {
                if (strcmp(medalList.medals[j].athleteID, athleteId) == 0) {
                    if (medalCount == 0) {
                        printf("Editions where they won medals:\n");
                    }
                    printf("  - %s: %c medal in %s\n", medalList.medals[j].game, medalList.medals[j].medalType, medalList.medals[j].discipline);
                    medalCount++;
                }
            }

            if (medalCount == 0) {
                printf("Athlete %s did not win any medals.\n", athleteId);
            }

            return;
        }
    }

    printf("Athlete %s not found.\n", athleteId);
}