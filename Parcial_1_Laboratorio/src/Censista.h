#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Fecha.h"
#include "Direccion.h"

#ifndef CENSISTA_H_
#define CENSISTA_H_
#define ACTIVO 2001
#define INACTIVO 2002
#define LIBERADO 2003
#define MAX_CENSISTAS 100


struct {
	int idCensista;
	char nombre[51];
	char apellido[51];
	Fecha nacimiento;
	int edad;
	Direccion domicilio;
	int estadoCensista;
	int isEmpty;
} typedef Censista;

int initCensistas(Censista *censistas, int largo);


int setId(void);


int addCensista(Censista *censistas, int largo, int id, char nombre[], char apellido[], int dia, int mes, int anio, int edad, char calle[], int altura);


int hayCensistas(Censista *censistas, int largo);
int hayCensistasActivos(Censista *censistas, int largo);
int findCensistaLiberadoById(Censista *censistas, int largo, int id);


int removeCensistaById(Censista *censistas, int largo, int id);


int printCensistas(Censista *censistas, int largo);

#endif /* CENSISTA_H_ */
