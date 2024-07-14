#ifndef SHOW_H
#define SHOW_H

#include "list.h"
#include "map.h"

void showParticipations(PtList athleteList, int minParticipations);

void showHost(PtMap map, const char *gameSlug);

void showFirst(PtList athleteList, int year);
#endif // SHOW_H