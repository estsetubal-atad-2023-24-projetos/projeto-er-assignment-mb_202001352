#ifndef LOAD_H_H
#define LOAD_H_H

#include "map.h"

/**
 * @brief Carrega os dados do arquivo hosts.csv e armazena-os no mapa.
 * 
 * @param filename Nome do arquivo CSV.
 * @param map Ponteiro para o mapa onde os dados serão armazenados.
 * @return Número de registros importados ou -1 se o arquivo não for encontrado.
 */
int loadHosts(const char *filename, PtMap map);

#endif // LOAD_H_H