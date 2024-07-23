#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "medals_won.h"
#include "map.h"
#include "hosts.h"

#define MAX_COUNTRY_LENGTH 50

void medals_won(PtMap hostsMap, MedalList medalList, char *country, char *gameSeason, int firstYear) {
    int foundEditions = 0;

    int hostsSize;
    if (mapSize(hostsMap, &hostsSize) != MAP_OK) {
        printf("Couldn't obtain map size.\n");
        return;
    }

    MapKey *hostKeys = mapKeys(hostsMap);

    printf("%-25s | %-5s | %-10s | %-2s | %-2s | %-2s\n", "Edition", "Year", "Category", "G", "S", "B");
    printf("--------------------------|-------|------------|----|----|----\n");

    //Iterar pelas edições dos jogos olímpicos
    for (int i = 0; i < hostsSize && foundEditions < 5; i++) {
        Host host;
        if (mapGet(hostsMap, hostKeys[i], (MapValue *)&host) == MAP_OK) {
            if (host.gameYear >= firstYear && strcmp(host.gameSeason, gameSeason) == 0) {
                int goldMen = 0, silverMen = 0, bronzeMen = 0;
                int goldWomen = 0, silverWomen = 0, bronzeWomen = 0;
                int goldMixed = 0, silverMixed = 0, bronzeMixed = 0;

                //Iterar pelas medalhas e contar as do país
                for (int j = 0; j < medalList.size; j++) {
                    Medal medal = medalList.medals[j];
                    if (strcmp(medal.country, country) == 0 && strcmp(medal.game, host.gameSlug) == 0) {
                        if (medal.gender == 'M') {
                            switch (medal.medalType) {
                                case 'G': goldMen++; break;
                                case 'S': silverMen++; break;
                                case 'B': bronzeMen++; break;
                            }
                        } else if (medal.gender == 'W') {
                            switch (medal.medalType) {
                                case 'G': goldWomen++; break;
                                case 'S': silverWomen++; break;
                                case 'B': bronzeWomen++; break;
                            }
                        } else if (medal.gender == 'X') {
                            switch (medal.medalType) {
                                case 'G': goldMixed++; break;
                                case 'S': silverMixed++; break;
                                case 'B': bronzeMixed++; break;
                            }
                        }
                    }
                }

                if (goldMen > 0 || silverMen > 0 || bronzeMen > 0) {
                    printf("%-25s | %-5d | %-10s | %02d | %02d | %02d\n",
                           host.gameName, host.gameYear, "Men",
                           goldMen, silverMen, bronzeMen);
                }

                if (goldWomen > 0 || silverWomen > 0 || bronzeWomen > 0) {
                    printf("%-25s | %-5d | %-10s | %02d | %02d | %02d\n",
                           host.gameName, host.gameYear, "Women",
                           goldWomen, silverWomen, bronzeWomen);
                }

                if (goldMixed > 0 || silverMixed > 0 || bronzeMixed > 0) {
                    printf("%-25s | %-5d | %-10s | %02d | %02d | %02d\n",
                           host.gameName, host.gameYear, "Mixed",
                           goldMixed, silverMixed, bronzeMixed);
                }

                foundEditions++;
            }
        }
    }

    free(hostKeys);

    if (foundEditions == 0)
        printf("Editions not found from requisits.\n");
}