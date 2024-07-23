#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "list.h"
#include "map.h"
#include "athletes.h"
#include "medals.h"
#include "hosts.h"
#include "input.h"
#include "load.h"
#include "show.h"
#include "clear.h"
#include "medals_won.h"
#include "athleteinfo.h"

void showCommands();

int main() {
    PtList athleteList = listCreate();
    PtMap hostsMap = mapCreate();

    MedalList medalList;
    medalList.medals = NULL;
    medalList.size = 0;

    char command[30];

    while (true) {
        printf("Choose a command: ");
        readString(command, 30);

        for (int i = 0; command[i]; i++)
            command[i] = toupper(command[i]);

        if (strcmp(command, "QUIT") == 0) {
            printf("Exiting the program.\n");
            clearData(athleteList, hostsMap, &medalList);
            break;
            
        } else if (strcmp(command, "LOAD_A") == 0) {
            int importedCount = loadAthletes("athletes.csv", athleteList);
            printf("%d athlete records imported.\n", importedCount);
        } else if (strcmp(command, "LOAD_M") == 0) {
            if (loadMedals("medals.csv", &medalList.medals, &medalList.size) == 0)
                printAllMedals(medalList);
        } else if (strcmp(command, "LOAD_H") == 0) {
            loadHosts("hosts.csv", hostsMap);
        } else if (strcmp(command, "CLEAR") == 0) {
            clearData(athleteList, hostsMap, &medalList);
            athleteList = listCreate();
            hostsMap = mapCreate();
           medalList.medals = NULL;
            medalList.size = 0;
            
        } else if (strcmp(command, "SHOW_ALL") == 0) {
            
        } else if (strcmp(command, "SHOW_PARTICIPATIONS") == 0) {
            int minParticipations;
            printf("Enter the minimum number of participations: ");
            scanf("%d", &minParticipations);
            showParticipations(athleteList, minParticipations);
        } else if (strcmp(command, "SHOW_FIRST") == 0) {
            int year;
            printf("Enter the year: ");
            readInteger(&year);
            showFirst(athleteList, year);
        } else if (strcmp(command, "SHOW_HOST") == 0) {
            char editionName[100];
            printf("Enter the edition name: ");
            readString(editionName, 100);
            showHost(hostsMap, editionName);
        } else if (strcmp(command, "DISCIPLINE_STATISTICS") == 0) {
            
        } else if (strcmp(command, "ATHLETE_INFO") == 0) {
            athleteInfo(athleteList, medalList);
        } else if (strcmp(command, "TOPN") == 0) {
            
        } else if (strcmp(command, "MEDALS_WON") == 0) {
            char country[100];
            char gameSeason[10];
            int firstYear;

            printf("Name of the country: ");
            readString(country, 100);

            printf("Edition Season (Winter/Summer): ");
            readString(gameSeason, 10);

            printf("First year of the 5 editions: ");
            readInteger(&firstYear);

            medals_won(hostsMap, medalList, country, gameSeason, firstYear);
        } else if (strcmp(command, "HELP") == 0)
            showCommands();
        else
            printf("Unknown command\n");
    }

    return EXIT_SUCCESS;
}

/**
 * @brief Displays the available commands.
 * This function prints a list of commands that can be used in the program.
 */
void showCommands() {
    printf("Commands:\n");
    printf("LOAD_A\n");
    printf("LOAD_M\n");
    printf("LOAD_H\n");
    printf("CLEAR\n");
    printf("QUIT\n");
    printf("SHOW_ALL\n");
    printf("SHOW_PARTICIPATIONS\n");
    printf("SHOW_FIRST\n");
    printf("SHOW_HOST\n");
    printf("DISCIPLINE_STATISTICS\n");
    printf("ATHLETE_INFO\n");
    printf("TOPN\n");
    printf("MEDALS_WON\n");
}