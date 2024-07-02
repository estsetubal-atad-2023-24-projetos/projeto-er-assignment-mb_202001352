#include <stdio.h>
#include <string.h>

#include "mapElem.h"

void mapKeyPrint(MapKey key) {
    printf("%s", key);
}

void mapValuePrint(MapValue value) {
    printf("ID: %s, Name: %s, Games: %d, First Game: %s, Birth: %d",
           value.athleteID, value.athleteName, value.gamesParticipations,
           value.firstGame, value.athleteBirth);
}

int mapKeyCompare(MapKey key1, MapKey key2) {
    return strcmp(key1, key2);
}