/**************************************************************************************
 * Biblioteca  : ArrayPassenger.c.h
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

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define MAX_PASSENGERS 2000
#define FIRST 1
#define BUSINESS 2
#define PREMIUM_ECONOMY 3
#define ECONOMY 4

struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int isEmpty;
} typedef Passenger;

int initPassengers(Passenger *list, int lenght);

int setId(void);

int addPassenger(Passenger *list, int lenght, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]);

int isThereAPassenger(Passenger *list, int lenght);

int findPassengerById(Passenger *list, int lenght, int id);

int removePassenger(Passenger *list, int lenght, int id);

int sortPassengers(Passenger *list, int lenght, int order);
int sortPassengersByCode(Passenger *list, int lenght, int order);

int printPassengers(Passenger *list, int lenght);
int printPassengerPrices(Passenger *list, int lenght);

#endif /* ARRAYPASSENGER_H_ */
