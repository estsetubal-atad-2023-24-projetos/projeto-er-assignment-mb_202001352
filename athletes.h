#ifndef ATHLETES_H
#define ATHLETES_H

#define MAX_ID_LENGTH 50
#define MAX_NAME_LENGTH 100
#define MAX_GAME_LENGTH 50

typedef struct athlete {
    char athleteID[MAX_ID_LENGTH]; // Identificador único do atleta
    char athleteName[MAX_NAME_LENGTH]; // Nome do atleta
    int gamesParticipations; // Número de jogos em que participou
    int yearFirstParticipation; // O ano em que participou pela primeira vez
    int athleteBirth; // Ano de nascimento
} Athlete;

/**
 * @brief Create a new Athlete structure.
 * 
 * Initializes a new Athlete structure with the provided information such as ID, name,
 * number of participations, year of first participation, and birth year.
 * 
 * @param id [in] unique identifier for the athlete
 * @param name [in] name of the athlete
 * @param participations [in] number of games the athlete has participated in
 * @param firstParticipation [in] year the athlete first participated in the games
 * @param birthYear [in] year of birth of the athlete
 * 
 * @return Athlete structure initialized with the provided data
 */
Athlete athleteCreate(char *id, char *name, int participations, int firstParticipation, int birthYear);

/**
 * @brief Print the details of an Athlete structure.
 * 
 * Prints the athlete's ID, name, number of participations, year of first participation,
 * and birth year in a formatted string.
 * 
 * @param athlete [in] Athlete structure to be printed
 * 
 * @return void
 */
void athletePrint(Athlete athlete);

#endif // ATHLETES_H