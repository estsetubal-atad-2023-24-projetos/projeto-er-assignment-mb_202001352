#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input.h"
#include "list.h"
#include "map.h"
#include "hosts.h"
#include "athletes.h"
#include "show.h"

#define PAGE_SIZE 20

void paginate(PtList athletes) {
    int size;
    if (listSize(athletes, &size) != LIST_OK) {
        printf("Error getting size of athlete list\n");
        return;
    }

    printf("Number of records found: %d\n", size);
    if (size == 0)
        return;

    int totalPages = (size + PAGE_SIZE - 1) / PAGE_SIZE;
    for (int page = 0; page < totalPages; page++) {
        printf("Page %d/%d\n", page + 1, totalPages);
        for (int i = 0; i < PAGE_SIZE && (page * PAGE_SIZE + i) < size; i++) {
            Athlete athlete;
            if (listGet(athletes, page * PAGE_SIZE + i, &athlete) == LIST_OK)
                athletePrint(athlete);
        }

        if (page < totalPages - 1) {
            char next;
            printf("Press 'n' for next page, or any other key to stop: ");
            scanf(" %c", &next);
            if (next != 'n' && next != 'N')
                break;
        }
    }
}

//SHOW_PARTICIPATIONS
int compareAthletesByName(Athlete a, Athlete b) {
    return strcasecmp(a.athleteName, b.athleteName);
}

void printFilteredList(PtList filteredList) {
    paginate(filteredList);
}

void sortFilteredList(PtList filteredList) {
    int filteredSize;
    if (listSize(filteredList, &filteredSize) != LIST_OK) {
        printf("Error getting size of filtered list\n");
        return;
    }

    for (int i = 0; i < filteredSize - 1; i++) {
        for (int j = 0; j < filteredSize - i - 1; j++) {
            Athlete athlete1, athlete2;
            if (listGet(filteredList, j, &athlete1) != LIST_OK || listGet(filteredList, j + 1, &athlete2) != LIST_OK) {
                printf("Error getting athletes at index %d and %d\n", j, j + 1);
                return;
            }

            if (compareAthletesByName(athlete1, athlete2) > 0) {
                Athlete oldElem;
                if (listSet(filteredList, j, athlete2, &oldElem) != LIST_OK || listSet(filteredList, j + 1, athlete1, &oldElem) != LIST_OK) {
                    printf("Error swapping athletes at index %d and %d\n", j, j + 1);
                    return;
                }
            }
        }
    }
}

PtList filterAthletesByParticipation(PtList athleteList, int minParticipations) {
    int size;
    if (listSize(athleteList, &size) != LIST_OK) {
        printf("Error getting size of athlete list\n");
        return NULL;
    }

    PtList filteredList = listCreate();
    if (filteredList == NULL) {
        printf("Error creating filtered list\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        Athlete athlete;
        if (listGet(athleteList, i, &athlete) != LIST_OK) {
            printf("Error getting athlete from list at index %d\n", i);
            listDestroy(&filteredList);
            return NULL;
        }

        if (athlete.gamesParticipations >= minParticipations) {
            printf("Adding athlete: %s, Participations: %d\n", athlete.athleteName, athlete.gamesParticipations);
            int filteredSize;
            if (listSize(filteredList, &filteredSize) != LIST_OK) {
                printf("Error getting size of filtered list\n");
                listDestroy(&filteredList);
                return NULL;
            }
            if (listAdd(filteredList, filteredSize, athlete) != LIST_OK) {
                printf("Error adding athlete to filtered list\n");
                listDestroy(&filteredList);
                return NULL;
            }
        }
    }

    return filteredList;
}

void showParticipations(PtList athleteList, int minParticipations) {
    PtList filteredList = filterAthletesByParticipation(athleteList, minParticipations);
    if (filteredList == NULL)
        return;

    int filteredSize;
    if (listSize(filteredList, &filteredSize) != LIST_OK) {
        printf("Error getting size of filtered list\n");
        listDestroy(&filteredList);
        return;
    }

    if (filteredSize == 0) {
        printf("No athletes found with at least %d participations\n", minParticipations);
        listDestroy(&filteredList);
        return;
    }

    printf("Filtered list size: %d\n", filteredSize);

    printf("Starting sort\n");
    sortFilteredList(filteredList);
    printf("Sort completed\n");

    printf("Starting to print filtered list\n");
    paginate(filteredList);
    printf("Completed printing filtered list\n");

    listDestroy(&filteredList);
}

//SHOW_HOST
void showHost(PtMap map, const char *gameSlug) {
    Host host;
    int result = mapGet(map, (char*)gameSlug, &host);

    if (result == MAP_OK) {
        char city[100];
        sscanf(host.gameName, "%99[^0-9]", city);

        struct tm startDate = {0}, endDate = {0};
        strptime(host.gameStartDate, "%Y-%m-%dT%H:%M:%SZ", &startDate);
        strptime(host.gameEndDate, "%Y-%m-%dT%H:%M:%SZ", &endDate);
        time_t start = mktime(&startDate);
        time_t end = mktime(&endDate);
        double seconds = difftime(end, start);
        int days = seconds / (60 * 60 * 24);

        printf("----------------------\n");
        printf("City of hosting: %s\n", city);
        printf("Year: %d\n", host.gameYear);
        printf("Country of hosting: %s\n", host.gameLocation);
        printf("Event duration in days: %d\n", days);
        printf("----------------------\n");
    } else
        printf("No edition found\n");
}

//SHOW_FIRST
PtList filterAthletesByFirstYear(PtList athleteList, int year) {
    int size;
    if (listSize(athleteList, &size) != LIST_OK) {
        printf("Error getting size of athlete list\n");
        return NULL;
    }

    PtList filteredList = listCreate();
    if (filteredList == NULL) {
        printf("Error creating filtered list\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        Athlete athlete;
        if (listGet(athleteList, i, &athlete) != LIST_OK) {
            printf("Error getting athlete from list at index %d\n", i);
            listDestroy(&filteredList);
            return NULL;
        }

        if (athlete.yearFirstParticipation == year) {
            int filteredSize;
            if (listSize(filteredList, &filteredSize) != LIST_OK) {
                printf("Error getting size of filtered list\n");
                listDestroy(&filteredList);
                return NULL;
            }
            if (listAdd(filteredList, filteredSize, athlete) != LIST_OK) {
                printf("Error adding athlete to filtered list\n");
                listDestroy(&filteredList);
                return NULL;
            }
        }
    }

    return filteredList;
}

void showFirst(PtList athleteList, int year) {
    PtList filteredList = filterAthletesByFirstYear(athleteList, year);
    if (filteredList == NULL)
        return;

    int filteredSize;
    if (listSize(filteredList, &filteredSize) != LIST_OK) {
        printf("Error getting size of filtered list\n");
        listDestroy(&filteredList);
        return;
    }

    if (filteredSize == 0) {
        printf("No athletes whose first participation was at %d\n", year);
        listDestroy(&filteredList);
        return;
    }

    sortFilteredList(filteredList);
    paginate(filteredList);
    listDestroy(&filteredList);
}