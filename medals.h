#ifndef MEDAL_H
#define MEDAL_H

#define MAX_DISC_LENGTH 50
#define MAX_GAME_LENGTH 50
#define MAX_EVENT_LENGTH 100
#define MAX_ID_A_LENGTH 50
#define MAX_COUNTRY_LENGTH 50
#define MAX_COUNTRY_CODE_LENGTH 4

/**
 * @brief Structure representing a medal.
 * 
 * This structure represents a medal awarded in Olympic Games.
 * It includes information such as discipline, game, event title, gender, medal type,
 * participant type, athlete ID, country, and country code.
 */
typedef struct medal {
    char discipline[MAX_DISC_LENGTH]; // Modalidade
    char game[MAX_GAME_LENGTH]; // Nome da edição dos jogos olímpicos ( ex beijing-2022)
    char eventTitle[MAX_EVENT_LENGTH]; // Titulo da prova ( ex Women's Ski cross)
    char gender; // M - Men, W- Women, X – Mixed, O - Open
    char medalType; // G - GOLD, S - SILVER, B - BRONZE
    char participantType; // A - Athlete, G - GameTeam
    char athleteID[MAX_ID_A_LENGTH]; // Identificador de cada atleta
    char country[MAX_COUNTRY_LENGTH]; // País pelo qual o atleta competiu
    char countryCode[MAX_COUNTRY_CODE_LENGTH]; // Código do país
} Medal;

typedef struct medalList {
    Medal *medals;
    int size;
} MedalList;

Medal createMedal(const char* discipline, const char* game, const char* eventTitle, char gender, char medalType, char participantType, const char* athleteID, const char* country, const char* countryCode);
void medalPrint(Medal medal);
void printAllMedals(MedalList medalList);
void destroyMedalList(MedalList *medalList);

#endif // MEDAL_H