#include <stdio.h>
#include "clear.h"

void clearData(PtList athleteList, PtMap hostsMap, MedalList *medalList) {
    int athleteCount, hostsCount, medalCount;

    listSize(athleteList, &athleteCount);
    mapSize(hostsMap, &hostsCount);
    medalCount = medalList->size; 

    listDestroy(&athleteList);
    mapDestroy(&hostsMap);
    destroyMedalList(medalList);

    printf("Records deleted from Athletes (%d) | Medals (%d) | Hosts (%d)\n", athleteCount, medalCount, hostsCount);
}