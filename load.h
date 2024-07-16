#ifndef LOAD_H
#define LOAD_H

#include "map.h"
#include "list.h"

/**
 * @brief Carrega os dados do arquivo hosts.csv e armazena-os no mapa.
 * 
 * @param filename Nome do arquivo CSV.
 * @param map Ponteiro para o mapa onde os dados serão armazenados.
 * @return Número de registros importados ou -1 se o arquivo não for encontrado.
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

int loadMedals(const char *filename, PtList list);

#endif // LOAD_H