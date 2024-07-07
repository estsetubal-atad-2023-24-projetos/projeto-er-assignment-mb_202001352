#ifndef LOAD_A_H
#define LOAD_A_H

#include "list.h"

/**
 * @brief Load athletes from a CSV file.
 * 
 * @param filename Name of the CSV file.
 * @param list Pointer to the list where athletes will be loaded.
 * @return The number of athletes imported.
 */
int loadAthletes(const char *filename, PtList list);

#endif // LOAD_A_H