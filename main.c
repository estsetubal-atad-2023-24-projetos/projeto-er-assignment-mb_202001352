#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "map.h"
#include "athletes.h"
#include "medals.h"
#include "hosts.h"
#include "input.h"

void showCommands();

int main() {
    char command[30];

    while (true) {
        printf("Chose a command: ");
        readString(command, 15);

        for (int i = 0; command[i]; i++)
            command[i] = toupper(command[i]);

        if (strcmp(command, "QUIT") == 0) {
            printf("Exiting the program.\n");

            break;
        } else if (strcmp(command, "LOAD_A") == 0) {

        } else if (strcmp(command, "LOAD_M") == 0) {

        } else if (strcmp(command, "LOAD_H") == 0) {

        } else if (strcmp(command, "CLEAR") == 0) {

        } else if (strcmp(command, "SHOW_ALL") == 0) {

        } else if (strcmp(command, "SHOW_PARTICIPATIONS") == 0) {

        } else if (strcmp(command, "SHOW_FIRST") == 0) {

        } else if (strcmp(command, "SHOW_HOST") == 0) {

        } else if (strcmp(command, "DISCIPLINE_STATISTICS") == 0) {

        } else if (strcmp(command, "ATHLETE_INFO") == 0) {

        } else if (strcmp(command, "TOPN") == 0) {

        } else if (strcmp(command, "MEDALS_WON") == 0) {

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