/*********************************************************************
 * Biblioteca  : Airline.h
 * Autor       : Esteban Bazzo (DNI 37.066.587)
 * Año         : 1°
 * División    : E
 * Turno       : noche
 * Materia     : Laboratorio de Computación I
 * Profesores  : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha       : 1° cuatrimestre de 2022
 * Descripción : Biblioteca general de Laboratorio de Computación I
 *               UTN-FRA Tecnicatura Universitaria en Programación
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "ArrayFlight.h"

#ifndef AIRLINE_H_
#define AIRLINE_H_
#define FALSE 0
#define TRUE 1

void forcedLoad(Passenger *list1, Flight *list2);

#endif /* AIRLINE_H_ */
