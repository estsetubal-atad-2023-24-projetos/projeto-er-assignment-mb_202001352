#ifndef CLEAR_H
#define CLEAR_H

#include "list.h"
#include "map.h"
#include "medals.h"

// Declaration of the clearData function. This function takes two arguments: a pointer to an athlete list (PtList athleteList)
// and a pointer to a hosts map (PtMap hostsMap).
// The function is used to clear (i.e., remove all elements from) the athlete list and the hosts map.

void clearData(PtList athleteList, PtMap hostsMap,  MedalList *medalList);

#endif