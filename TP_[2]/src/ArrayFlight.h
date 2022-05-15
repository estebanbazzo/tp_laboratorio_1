/**************************************************************************************
 * Biblioteca  : ArrayFlight.h
 * Autor       : Esteban Bazzo (DNI 37.066.587)
 * A�o         : 1�
 * Divisi�n    : E
 * Turno       : noche
 * Materia     : Laboratorio de Computaci�n I
 * Profesores  : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha       : 1� cuatrimestre de 2022
 * Descripci�n : Biblioteca del trabajo pr�ctico n�2 de Laboratorio de Computaci�n I
 *               UTN-FRA Tecnicatura Universitaria en Programaci�n
**************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYFLIGHT_H_
#define ARRAYFLIGHT_H_
#define ACTIVE 1
#define DELAYED 2
#define CANCELLED 3

struct {
	int id;
	char flyCode[10];
	int flightStatus;
	int isEmpty;
} typedef Flight;

int initFlights(Flight *list, int lenght);

int addFlight(Flight *list, int lenght, int id, char flyCode[], int flightStatus);

int findFlightById(Flight *list, int lenght, int id);

int removeFlight(Flight *list, int lenght, int id);

#endif /* ARRAYFLIGHT_H_ */
