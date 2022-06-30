/**********************************************************************
 * Biblioteca   : Utn.h
 * Versión      : 3.0
 * Autor        : Esteban Bazzo (DNI 37066587)
 * Año          : 1
 * División     : E
 * Turno        : noche
 * Materia      : Laboratorio de Computación I
 * Profesores   : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha        : 1° cuatrimestre de 2022
 * Descripción  : biblioteca general de Laboratorio de Computación I
                  UTN-FRA  Tecnicatura Universitaria en Programación
**********************************************************************/
#include <stdio.h>
//#include <stdio_ext.h>  /* for Linux */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef UTN_H_
#define UTN_H_
#define FALSE 0
#define TRUE 1


void utn_anyKey(char* message);
void utn_err(char* errorMessage, char* anyKeyMessage);

int utn_getInt(int* entry, char* message, char* errorMessage, int minimum, int maximum, int attempts);
int utn_isInt(char* string, int lenght);

int utn_getFloat(float* entry, char* message, char* errorMessage, float minimum, float maximum, int attempts);
int utn_isFloat(char* string, int lenght);

int utn_getIden(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int utn_isIden(char* string, int lenght);

int utn_getName(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int utn_isName(char* string, int lenght);

int utn_getCode(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int utn_isCode(char* string, int lenght);

int utn_getText(char* entry, int lenght, char* message, char* errorMessage, int attempts);
int utn_isText(char* string, int lenght);

int utn_calcAdd(float* sum, float* addend1, float* addend2);
int utn_calcSub(float* difference, float* minuend, float* subtrahend);
int utn_calcMul(float* product, float* multiplicand, float* multiplier);
int utn_calcDiv(float* quotient, int* remainder, float* dividend, float* divisor);
int utn_calcPer(float* part, float* percentage, float* whole);


#endif /* UTN_H_ */
