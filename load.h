#ifndef LOAD_H
#define LOAD_H

#include "map.h"
#include "list.h"
#include "medals.h"

/**
 * @brief Load hosts from a CSV file.
 * 
 * @param filename Name of the CSV file.
 * @param list Pointer to the list where hosts will be loaded.
 * @return The number of hosts imported.
 */
int loadHosts(const char *filename, PtMap map);

/**
 * @brief Load athletes from a CSV file.
 * 
 * @param filename Name of the CSV file.
 * @param list Pointer to the list where athletes will be loaded.
 * @return The number of athletes imported.
 */
int loadAthletes(const char *filename, PtList list);

/**
 * @brief Load medals from a CSV file.
 * 
 * @param filename Name of the CSV file.
 * @param list Pointer to the arrayList where medals will be loaded.
 * @return The number of medals imported.
 */
int loadMedals(const char* filename, Medal** medals, int* numMedals);

#endif // LOAD_H