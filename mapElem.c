#include <stdio.h>
#include <string.h>

#include "mapElem.h"

void mapKeyPrint(MapKey key) {
    printf("%s", key);
}

void mapValuePrint(MapValue value) {
    printf("Game Slug: %s, Game End Date: %s, Game Start Date: %s, Game Location: %s,  Game Name: %s, Game Season: %s, Game Year: %d",
           value.gameSlug, value.gameEndDate, value.gameStartDate,
           value.gameLocation, value.gameName, value.gameSeason, value.gameYear);
}

int mapKeyCompare(MapKey key1, MapKey key2) {
    return strcmp(key1, key2);
}