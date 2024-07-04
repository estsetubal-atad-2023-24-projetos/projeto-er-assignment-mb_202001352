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

Athlete athleteCreate(char *id, char *name, int participations, int firstParticipation, int birthYear);

void athletePrint(Athlete athlete);

#endif // ATHLETES_H