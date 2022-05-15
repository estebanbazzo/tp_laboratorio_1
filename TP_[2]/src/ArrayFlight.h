/**************************************************************************************
 * Biblioteca  : ArrayFlight.h
 * Autor       : Esteban Bazzo (DNI 37.066.587)
 * Año         : 1°
 * División    : E
 * Turno       : noche
 * Materia     : Laboratorio de Computación I
 * Profesores  : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha       : 1° cuatrimestre de 2022
 * Descripción : Biblioteca del trabajo práctico n°2 de Laboratorio de Computación I
 *               UTN-FRA Tecnicatura Universitaria en Programación
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
