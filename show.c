#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "athletes.h"

#define PAGE_SIZE 10

int compareAthletesByName(Athlete a, Athlete b) {
    return strcmp(a.athleteName, b.athleteName);
}

void printFilteredList(PtList filteredList) {
    int filteredSize;
    if (listSize(filteredList, &filteredSize) != LIST_OK) {
        printf("Error getting size of filtered list\n");
        return;
    }

    if (filteredSize == 0)
        printf("No athletes found with the specified minimum participations\n");
    else {
        for (int i = 0; i < filteredSize; i++) {
            Athlete athlete;
            if (listGet(filteredList, i, &athlete) != LIST_OK) {
                printf("Error getting athlete for printing at index %d\n", i);
                return;
            }
            athletePrint(athlete);
        }
    }
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
            if (listGet(filteredList, j, &athlete1) != LIST_OK) {
                printf("Error getting athlete1 at index %d\n", j);
                return;
            }
            if (listGet(filteredList, j + 1, &athlete2) != LIST_OK) {
                printf("Error getting athlete2 at index %d\n", j + 1);
                return;
            }
            if (compareAthletesByName(athlete1, athlete2) > 0) {
                printf("Swapping %s and %s at indices %d and %d\n", athlete1.athleteName, athlete2.athleteName, j, j + 1);
                if (listSet(filteredList, j, athlete2, NULL) != LIST_OK) {
                    printf("Error setting athlete2 at index %d\n", j);
                    return;
                }
                if (listSet(filteredList, j + 1, athlete1, NULL) != LIST_OK) {
                    printf("Error setting athlete1 at index %d\n", j + 1);
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
            int filteredListSize;
            if (listSize(filteredList, &filteredListSize) != LIST_OK) {
                printf("Error getting size of filtered list\n");
                listDestroy(&filteredList);
                return NULL;
            }

            if (listAdd(filteredList, filteredListSize, athlete) != LIST_OK) {
                printf("Error adding athlete to filtered list at index %d\n", filteredListSize);
                listDestroy(&filteredList);
                return NULL;
            }
        }
    }

    return filteredList;
}

void showParticipations(PtList athleteList, int minParticipations) {
    PtList filteredList = filterAthletesByParticipation(athleteList, minParticipations);
    if (filteredList == NULL) {
        return;
    }

    int filteredSize;
    if (listSize(filteredList, &filteredSize) != LIST_OK) {
        printf("Error getting size of filtered list\n");
        listDestroy(&filteredList);
        return;
    }
    printf("Filtered list size: %d\n", filteredSize);

    printf("Starting sort\n");
    sortFilteredList(filteredList);
    printf("Sort completed\n");

    printf("Starting to print filtered list\n");
    printFilteredList(filteredList);
    printf("Completed printing filtered list\n");

    listDestroy(&filteredList);
}