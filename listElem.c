#include <stdio.h>

#include "listElem.h"

void listElemPrint(ListElem elem) {
    printf("Discipline: %s, Game: %s, Event: %s, Gender: %c, Medal: %c, Participant: %c, AthleteID: %s, Country: %s, CountryCode: %s",
           elem.discipline, elem.game, elem.eventTitle, elem.gender, elem.medalType,
           elem.participantType, elem.athleteID, elem.country, elem.countryCode);
}