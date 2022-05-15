/*********************************************************************
 * Biblioteca  : Utn.h
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

#ifndef UTN_H_
#define UTN_H_
#define FALSE 0
#define TRUE 1

void pW2MainMenu(void);
void pW2SubMenu2(Passenger *list1, Flight *list2, int lenght, int index);
void pW2SubMenu4(void);
void pW2SubMenu41(void);

void pressAnyKey(char *message);
void error(char *errorMessage, char *anyKeyMessage);

int getInt(int *entry, char *message, char *errorMessage, int minimum, int maximum, int attempts);
int getFloat(float *entry, char *message, char *errorMessage, float minimum, float maximum, int attempts);
int getWords(char *entry, int lenght, char *message, char *errorMessage, int attempts);
int getCode(char entry[], int lenght, char *message, char *errorMessage, int attempts);

int calcSubtrac(float *result, float number, float numberSubtracted);
int calcDiv(float *result, float dividend, float divisor);
int calcPercent(float *result, float number, float percentage);

#endif /* UTN_H_ */
