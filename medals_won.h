#ifndef MEDALS_WON_H
#define MEDALS_WON_H

#include "map.h"
#include "medals.h"

/**
 * @brief Display the number of medals won by a country in specific editions of the Olympic Games.
 * 
 * This function prints the number of gold, silver, and bronze medals won by a given country
 * in Olympic Games editions that match the specified season and are held on or after the specified year.
 * It prints the results for up to 5 editions.
 * 
 * @param hostsMap [in] the map containing host information of the Olympic Games
 * @param medalList [in] the list of medals awarded
 * @param country [in] the name of the country whose medals are to be counted
 * @param gameSeason [in] the season of the games (e.g., "Summer", "Winter")
 * @param firstYear [in] the first year to consider for the games
 * 
 * @return void
 */
void medals_won(PtMap hostsMap, MedalList medalList, char *country, char *gameSeason, int firstYear);

#endif