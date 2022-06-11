/**********************************************************************
 * Biblioteca   : Utn.h
 * Versi�n      : 3.0
 * Autor        : Esteban Bazzo (DNI 37066587)
 * A�o          : 1
 * Divisi�n     : E
 * Turno        : noche
 * Materia      : Laboratorio de Computaci�n I
 * Profesores   : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha        : 1� cuatrimestre de 2022
 * Descripci�n  : biblioteca general de Laboratorio de Computaci�n I
                  UTN-FRA  Tecnicatura Universitaria en Programaci�n
**********************************************************************/
#include <stdio.h>
//#include <stdio_ext.h>  /* for Linux */
#include <stdlib.h>
#include <string.h>


#ifndef UTN_H_
#define UTN_H_
#define FALSE 0
#define TRUE 1


void utn_anyKey(char* message);
void utn_err(char* errorMessage, char* anyKeyMessage);

int utn_getInt(int* entry, char* message, char* errorMessage, int minimum, int maximum, int attempts);
int isInt(char* string, int lenght);

int utn_getFloat(float* entry, char* message, char* errorMessage, float minimum, float maximum, int attempts);
int isFloat(char* string, int lenght);

int utn_getIden(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int isIden(char* string, int lenght);

int utn_getName(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int isName(char* string, int lenght);

int utn_getCode(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int isCode(char* string, int lenght);

int utn_getText(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int isText(char* string, int lenght);

int utn_calcAdd(float* sum, float* addend1, float* addend2);
int utn_calcSub(float* difference, float* minuend, float* subtrahend);
int utn_calcMul(float* product, float* multiplicand, float* multiplier);
int utn_calcDiv(float* quotient, int* remainder, float* dividend, float* divisor);
int utn_calcPer(float* part, float* percentage, float* whole);


#endif /* UTN_H_ */
