#ifndef PROJECT_H
#define PROJECT_H

#include "list.h"
#include "athletes.h"
#include "medals.h"

/**
 * @brief Display information about a specific athlete.
 * 
 * Prompts the user to enter an athlete ID and displays information about the athlete
 * including their country, number of participations, year of birth, and the editions
 * where they won medals.
 * 
 * @param athleteList [in] list of athletes
 * @param medalList [in] list of medals
 * 
 * @return void
 */
void athleteInfo(PtList athleteList, MedalList medalList);

#endif // PROJECT_H