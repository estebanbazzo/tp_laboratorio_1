#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"

#ifndef ZONACENSO_H_
#define ZONACENSO_H_
#define ALBERTI 1000
#define BALCARCE 1001
#define CAMPANA 1002
#define DOLORES 1003
#define ENSENADA 1004
#define GUAMINI 1005
#define JUNIN 1006
#define LOBOS 1007
#define MAIPU 1008
#define NAVARRO 1009
#define PENDIENTE 3000
#define FINALIZADA 3001


struct {
	int idZona;
	char manzana[4][64];
	char localidad[64];
	int censadosPresencialmente;
	int censadosVirtualmente;
	int ausentes;
	int idCensista;
	int esadoZonaCenso;
	int isEmpty;
} typedef ZonaCenso;


int initZonasCenso(ZonaCenso *zonasCenso, int largo);


int addZonaCenso(ZonaCenso *zonasCenso, int largo, int id, char calle1[], char calle2[], char calle3[], char calle4[], int localidad);


int hayZonasCenso(ZonaCenso *zonasCenso, int largo);
int findZonaCensoPendienteById(ZonaCenso *zonasCenso, int largo, int id);

#endif /* ZONACENSO_H_ */
