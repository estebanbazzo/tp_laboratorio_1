/*
================================================================================
Biblioteca  : utn.h
Autor       : Esteban Bazzo (DNI 37.066.587)
A�o         : 1�
Divisi�n    : E
Turno       : Noche
Materia     : Laboratorio de Computaci�n I
Profesores  : Gaston Argibay y Camila Iglesias Guerrero
Fecha       : 1� cuatrimestre de 2022
Descripci�n : Biblioteca general de Laboratorio de Computaci�n I
              Tecnicatura Universitaria en Programaci�n en UTN-FRA
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef UTN_H_
#define UTN_H_
/* Definiciones propias */
#define FALSO 0
#define VERDADERO 1

/* Funciones de obtenci�n de valores */
int utn_obtenerEntero(int *pIngreso, char *mensaje, char *mensajeError, int ingresoMinimo, int ingresoMaximo, int reintento);
int utn_obtenerRacional(float *pIngreso, char *mensaje, char *mensajeError, float ingresoMinimo, float ingresoMaximo, int reintento);

/* Funciones generales */
int utn_presionarCualquierTecla();

/* Funciones de c�lculo */
int utn_operarPorcentajeEntero(float *pResultado, float *pNumeroPorcentaje, float *pNumero, int *pPorcentaje);
int utn_intercambiarValor(float *pValorEquivalente, float *pValor, float *pTasaCambio);
int utn_calcularValorUnitario(float *pNumeroUnidad, float *pNumero, int *pUnidad);
int utn_calcularResta(float *pResultado, float *pNumeroUno, float *pNumeroDos);

#endif /* UTN_H_ */
