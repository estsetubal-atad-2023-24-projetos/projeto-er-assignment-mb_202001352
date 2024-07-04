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

Host hostCreate(char *slug, char *endDate, char *startDate, char *location, char *name, char *season, int year);

void hostPrint(Host host);

#endif // HOSTS_H