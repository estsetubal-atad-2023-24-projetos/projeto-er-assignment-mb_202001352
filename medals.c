#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "medals.h"

Medal createMedal(const char* discipline, const char* game, const char* eventTitle, char gender, char medalType, char participantType, const char* athleteID, const char* country, const char* countryCode) {
    Medal newMedal;
    strcpy(newMedal.discipline, discipline);
    strcpy(newMedal.game, game);
    strcpy(newMedal.eventTitle, eventTitle);
    newMedal.gender = gender;
    newMedal.medalType = medalType;
    newMedal.participantType = participantType;
    strcpy(newMedal.athleteID, athleteID);
    strcpy(newMedal.country, country);
    strcpy(newMedal.countryCode, countryCode);
    return newMedal;
}

void medalPrint(Medal medal) {
    printf("Discipline: %s, Game: %s, Event: %s, Gender: %c, Medal: %c, Participant: %c, AthleteID: %s, Country: %s, CountryCode: %s\n",
           medal.discipline, medal.game, medal.eventTitle, medal.gender, medal.medalType,
           medal.participantType, medal.athleteID, medal.country, medal.countryCode);
}

void printAllMedals(MedalList medalList) {
    for (int i = 0; i < medalList.size; i++)
        medalPrint(medalList.medals[i]);
}

void destroyMedalList(MedalList *medalList) {
    free(medalList->medals);
    medalList->medals = NULL;
    medalList->size = 0;
}