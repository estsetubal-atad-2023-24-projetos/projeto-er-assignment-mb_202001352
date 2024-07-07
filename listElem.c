#include <stdio.h>
#include "listElem.h"

void listElemPrint(ListElem elem) {
    printf("ID: %s, Name: %s, Participations: %d, First Participation: %d, Birth Year: %d\n",
           elem.athleteID, elem.athleteName, elem.gamesParticipations,
           elem.yearFirstParticipation, elem.athleteBirth);
}