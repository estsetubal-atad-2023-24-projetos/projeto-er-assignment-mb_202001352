#ifndef MEDALS_H
#define MEDALS_H

#define MAX_DISC_LENGTH 50
#define MAX_GAME_LENGTH 50
#define MAX_EVENT_LENGTH 100
#define MAX_ID_A_LENGTH 50
#define MAX_COUNTRY_LENGTH 50
#define MAX_GENDER 20

typedef struct medal {
    char discipline[MAX_DISC_LENGTH]; // Modalidade
    char game[MAX_GAME_LENGTH]; // Nome da edição dos jogos olímpicos
    char eventTitle[MAX_EVENT_LENGTH]; // Título da prova
    char gender[MAX_GENDER]; // Género da prova
    char medalType; // G - GOLD, S - SILVER, B - BRONZE
    char participantType; // A - Athlete, G - GameTeam
    char athleteID[MAX_ID_A_LENGTH]; // Identificador de cada atleta
    char country[MAX_COUNTRY_LENGTH]; // País pelo qual o atleta competiu
} Medal;

Medal medalCreate(char *discipline, char *game, char *eventTitle, char *gender, char medalType, char participantType, char *athleteID, char *country);

void medalPrint(Medal medal);

#endif // MEDALS_H