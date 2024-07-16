#include <stdio.h>
#include <string.h>
#include "medals.h"

Medal medalCreate(char *discipline, char *game, char *eventTitle, char *gender, char medalType, char participantType, char *athleteID, char *country) {
    Medal medal;
    strncpy(medal.discipline, discipline, MAX_DISC_LENGTH);
    strncpy(medal.game, game, MAX_GAME_LENGTH);
    strncpy(medal.eventTitle, eventTitle, MAX_EVENT_LENGTH);
    strncpy(medal.gender, gender, MAX_GENDER);
    medal.medalType = medalType;
    medal.participantType = participantType;

    if (participantType == 'A' && athleteID[0] == '\0')
        strncpy(medal.athleteID, "MISSING", MAX_ID_A_LENGTH);
    else
        strncpy(medal.athleteID, athleteID, MAX_ID_A_LENGTH);
    strncpy(medal.country, country, MAX_COUNTRY_LENGTH);
    return medal;
}

void medalPrint(Medal medal) {
    printf("Discipline: %s, Game: %s, Event: %s, Gender: %s, Medal: %c, Participant: %c, AthleteID: %s, Country: %s\n",
           medal.discipline, medal.game, medal.eventTitle, medal.gender, medal.medalType,
           medal.participantType, medal.athleteID, medal.country);
}