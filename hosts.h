#ifndef HOSTS_H
#define HOSTS_H

#define MAX_GAME_SLUG_LENGTH 50
#define MAX_LOCATION_LENGTH 100

typedef struct host {
    char gameSlug[MAX_GAME_SLUG_LENGTH]; // Identificador do jogo
    char gameEndDate[MAX_GAME_SLUG_LENGTH]; // Data de término
    char gameStartDate[MAX_GAME_SLUG_LENGTH]; // Data de início
    char gameLocation[MAX_LOCATION_LENGTH]; // Localização do jogo
    char gameName[MAX_GAME_SLUG_LENGTH]; // Nome do jogo
    char gameSeason[MAX_GAME_SLUG_LENGTH]; // Estação do jogo
    int gameYear; // Ano do jogo
} Host;

/**
 * @brief Creates a new Host structure.
 * 
 * This function initializes a Host structure with the provided values for slug, 
 * end date, start date, location, name, season, and year.
 * 
 * @param slug [in] the unique identifier for the game
 * @param endDate [in] the end date of the game
 * @param startDate [in] the start date of the game
 * @param location [in] the location where the game is held
 * @param name [in] the name of the game
 * @param season [in] the season in which the game is held (e.g., Summer, Winter)
 * @param year [in] the year the game is held
 * 
 * @return Host the created Host structure
 */
Host hostCreate(char *slug, char *endDate, char *startDate, char *location, char *name, char *season, int year);

/**
 * @brief Prints the details of a Host structure.
 * 
 * This function prints the details of the provided Host structure, including the slug, 
 * start date, end date, location, name, season, and year.
 * 
 * @param host [in] the Host structure to print
 * 
 * @return void
 */
void hostPrint(Host host);

#endif // HOSTS_H