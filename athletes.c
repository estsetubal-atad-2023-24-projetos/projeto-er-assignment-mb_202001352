#include <stdio.h>
#include <string.h>

#include "athletes.h"

Athlete athleteCreate(char *id, char *name, int participations, int firstParticipation, int birthYear) {
    Athlete athlete;
    strncpy(athlete.athleteID, id, MAX_ID_LENGTH);
    strncpy(athlete.athleteName, name, MAX_NAME_LENGTH);
    athlete.gamesParticipations = participations;
    athlete.yearFirstParticipation = firstParticipation;
    athlete.athleteBirth = birthYear;
    return athlete;
}

void athletePrint(Athlete athlete) {
    printf("ID: %s, Name: %s, Participations: %d, First Participation: %d, Birth Year: %d\n",
           athlete.athleteID, athlete.athleteName, athlete.gamesParticipations,
           athlete.yearFirstParticipation, athlete.athleteBirth);
}