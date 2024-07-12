#include <stdio.h>
#include "clear.h"

void clearData(PtList athleteList, PtMap hostsMap) {
    int athleteCount, hostsCount;

    listSize(athleteList, &athleteCount);
    mapSize(hostsMap, &hostsCount);

    listDestroy(&athleteList);
    mapDestroy(&hostsMap);

    printf("Records deleted from Athletes (%d) | Hosts (%d)\n", athleteCount, hostsCount);
}
