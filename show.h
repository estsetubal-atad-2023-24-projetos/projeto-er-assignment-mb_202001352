#ifndef SHOW_H
#define SHOW_H

#include "list.h"
#include "map.h"

/**
 * @brief Paginate through a list of athletes and print them page by page.
 * 
 * This function divides the list of athletes into pages of a fixed size and 
 * allows the user to navigate through them. Each page displays a subset of athletes.
 * 
 * @param athletes [in] the list of athletes to be paginated
 * 
 * @return void
 */
void paginate(PtList athletes);

/**
 * @brief Display the details of a specific host based on the game slug.
 * 
 * This function retrieves and prints information about a particular host 
 * from a map, identified by the game slug. The details include the city, 
 * year, country, and event duration.
 * 
 * @param map [in] the map of hosts
 * @param gameSlug [in] the slug of the game to find
 * 
 * @return void
 */
void showHost(PtMap map, const char *gameSlug);

/**
 * @brief Show athletes who participated in a specific year.
 * 
 * This function filters athletes based on the year of their first participation 
 * and prints the details of those who participated in the specified year.
 * 
 * @param athleteList [in] the list of all athletes
 * @param year [in] the year to filter athletes by their first participation
 * 
 * @return void
 */
void showFirst(PtList athleteList, int year);

/**
 * @brief Show athletes who have a minimum number of participations.
 * 
 * This function filters athletes based on the minimum number of participations 
 * and displays the details of those who meet or exceed this threshold.
 * 
 * @param athletes [in] the list of all athletes
 * @param minParticipations [in] the minimum number of participations required
 * 
 * @return void
 */
void showParticipations(PtList athletes, int minParticipations);

/**
 * @brief Paginate through all athletes in a list.
 * 
 * This function paginates through the list of all athletes and displays their details.
 * 
 * @param athletes [in] the list of athletes to be paginated
 * 
 * @return void
 */
void paginateAllAthletes(PtList athletes);

/**
 * @brief Sort the list of athletes alphabetically by their names.
 * 
 * This function sorts the list of athletes in ascending order based on their names.
 * 
 * @param athletes [in] the list of athletes to be sorted
 * 
 * @return void
 */
void sortAthletes(PtList athletes);

/**
 * @brief Show all athletes in a paginated manner.
 * 
 * This function sorts all athletes by their names and then paginates through 
 * the sorted list, displaying each athlete's details.
 * 
 * @param athleteList [in] the list of athletes to be sorted and paginated
 * 
 * @return void
 */
void showAllAthletes(PtList athleteList);

#endif // SHOW_H