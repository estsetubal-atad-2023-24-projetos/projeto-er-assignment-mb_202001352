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

/**
 * @brief Create a new Medal structure.
 * 
 * This function initializes a `Medal` structure with the provided values. It sets all fields 
 * in the `Medal` structure based on the input parameters.
 * 
 * @param discipline [in] the name of the discipline (e.g., "Athletics")
 * @param game [in] the slug of the game (e.g., "tokyo-2020")
 * @param eventTitle [in] the title of the event (e.g., "4 x 400m Relay Mixed")
 * @param gender [in] the gender category (e.g., 'M' for men, 'W' for women, 'X' for mixed)
 * @param medalType [in] the type of medal (e.g., 'G' for gold, 'S' for silver, 'B' for bronze)
 * @param participantType [in] the type of participant (e.g., 'A' for athlete, 'G' for game team)
 * @param athleteID [in] the ID of the athlete (e.g., "jane-doe")
 * @param country [in] the name of the country (e.g., "USA")
 * @param countryCode [in] the 3-letter country code (e.g., "USA")
 * 
 * @return Medal a new `Medal` structure initialized with the provided values
 */
Medal createMedal(const char* discipline, const char* game, const char* eventTitle, char gender, char medalType, char participantType, const char* athleteID, const char* country, const char* countryCode);

/**
 * @brief Print the details of a Medal structure.
 * 
 * This function prints the details of a `Medal` structure in a readable format, including 
 * discipline, game, event title, gender, medal type, participant type, athlete ID, country, 
 * and country code.
 * 
 * @param medal [in] the `Medal` structure to be printed
 * 
 * @return void
 */
void medalPrint(Medal medal);

/**
 * @brief Print all medals in a MedalList.
 * 
 * This function iterates over all medals in a `MedalList` and prints each medal's details
 * using the `medalPrint` function.
 * 
 * @param medalList [in] the list of medals to be printed
 * 
 * @return void
 */
void printAllMedals(MedalList medalList);

/**
 * @brief Free the memory allocated for a MedalList.
 * 
 * This function deallocates the memory used by the `MedalList`, setting the pointer to `NULL`
 * and resetting the size to 0.
 * 
 * @param medalList [in, out] the list of medals to be deallocated
 * 
 * @return void
 */
void destroyMedalList(MedalList *medalList);

#endif // MEDAL_H