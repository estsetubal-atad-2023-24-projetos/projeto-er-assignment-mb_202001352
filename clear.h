#ifndef CLEAR_H
#define CLEAR_H

#include "list.h"
#include "map.h"
#include "medals.h"

/**
 * @brief Clear all data from the given lists and maps.
 * 
 * This function clears the data from the provided athlete list, hosts map, 
 * and medal list, and prints the number of records deleted from each.
 * 
 * @param athleteList [in, out] pointer to the list of athletes to be cleared
 * @param hostsMap [in, out] pointer to the map of hosts to be cleared
 * @param medalList [in, out] pointer to the list of medals to be cleared
 * 
 * @return void
 */
void clearData(PtList athleteList, PtMap hostsMap,  MedalList *medalList);

#endif