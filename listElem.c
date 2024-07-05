#include <stdio.h>

#include "listElem.h"

void listElemPrint(ListElem elem) {
    printf("Athlete ID: %s, Athlete Name: %s, Games Participations: %d, Year First Participation: %d, Athlete Birth: %d",
           elem.athleteID, elem.athleteName, elem.gamesParticipations, elem.yearFirstParticipation, elem.athleteBirth);
}