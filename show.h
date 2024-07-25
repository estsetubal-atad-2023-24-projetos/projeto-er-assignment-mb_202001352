#ifndef SHOW_H
#define SHOW_H

#include "list.h"
#include "map.h"

void paginate(PtList athletes);

void showHost(PtMap map, const char *gameSlug);

void showFirst(PtList athleteList, int year);

void showParticipations(PtList athletes, int minParticipations);

void paginateAllAthletes(PtList athletes);

void sortAthletes(PtList athletes);

void showAllAthletes(PtList athleteList);

#endif // SHOW_H
