/*
================================================================================
Biblioteca  : utn.c
Autor       : Esteban Bazzo (DNI 37.066.587)
Año         : 1°
División    : E
Turno       : Noche
Materia     : Laboratorio de Computación I
Profesores  : Gaston Argibay y Camila Iglesias Guerrero
Fecha       : 1° cuatrimestre de 2022
Descripción : Biblioteca general de Laboratorio de Computación I
              Tecnicatura Universitaria en Programación en UTN-FRA
================================================================================
*/

#include "utn.h"

/// @brief Solicita un número entero al usuario, lo valida y verifica, y devuelve el resultado
/// @param pIngreso Puntero al resultado que guarda el número entero ingresado por el usuario
/// @param mensaje Mensaje de solicitud de un número entero al usuario
/// @param mensajeError Mensaje en caso de error con el número entero ingresado por el usuario
/// @param ingresoMinimo Número entero mínimo que puede ingresar el usuario, o -1 para anularlo
/// @param ingresoMaximo Número entero máximo que puede ingresar el usuario, o -1 para anularlo
/// @param reintento Cantidad de reintentos en caso de error con el número entero ingresado por el
/// usuario, o -1 para que sean infinitos
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_obtenerEntero(int *pIngreso, char *mensaje, char *mensajeError, int ingresoMinimo, int ingresoMaximo, int reintento) {
	int retorno;
	int auxIngreso;
	int flagReintentoInfinito;

	retorno = -1;

	if(pIngreso != NULL && mensaje != NULL && mensajeError != NULL && (ingresoMinimo == -1 || ingresoMinimo <= ingresoMaximo || ingresoMaximo == -1) && reintento >= -1) {
		do {
			printf("%s", mensaje);
			scanf("%d", &auxIngreso);
			scanf("%*[^\n]"); /* parche ante ingreso de número racional */
			if((ingresoMinimo == -1 && auxIngreso <= ingresoMaximo) || (auxIngreso >= ingresoMinimo && auxIngreso <= ingresoMaximo) || (auxIngreso >= ingresoMinimo && ingresoMaximo == -1)) {
				*pIngreso = auxIngreso;

				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);

				if(reintento == -1) {
					flagReintentoInfinito = 1;
				} else {
					reintento--;
				}
			}
		} while(flagReintentoInfinito == 1 || reintento >= 0);
	}

	return retorno;
}

/// @brief Solicita un número racional al usuario, lo valida y verifica, y devuelve el resultado
/// @param pIngreso Puntero al resultado que guarda el número racional ingresado por el usuario
/// @param mensaje Mensaje de solicitud de un número racional al usuario
/// @param mensajeError Mensaje en caso de error con el número racional ingresado por el usuario
/// @param ingresoMinimo Número racional mínimo que puede ingresar el usuario, o -1 para anularlo
/// @param ingresoMaximo Número racional máximo que puede ingresar el usuario, o -1 para anularlo
/// @param reintento Cantidad de reintentos en caso de error con el número racional ingresado por el
/// usuario, o -1 para que sean infinitos
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_obtenerRacional(float *pIngreso, char *mensaje, char *mensajeError, float ingresoMinimo, float ingresoMaximo, int reintento) {
	int retorno;
	float auxIngreso;
	int flagReintentoInfinito;

	retorno = -1;

	if(pIngreso != NULL && mensaje != NULL && mensajeError != NULL && (ingresoMinimo == -1 || ingresoMinimo <= ingresoMaximo || ingresoMaximo == -1) && reintento >= -1) {
		do {
			printf("%s", mensaje);
			scanf("%f", &auxIngreso);
			if((ingresoMinimo == -1 && auxIngreso <= ingresoMaximo) || (auxIngreso >= ingresoMinimo && auxIngreso <= ingresoMaximo) || (auxIngreso >= ingresoMinimo && ingresoMaximo == -1)) {
				*pIngreso = auxIngreso;

				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);

				if(reintento == -1) {
					flagReintentoInfinito = 1;
				} else {
					reintento--;
				}
			}
		} while(flagReintentoInfinito == 1 || reintento >= 0);
	}

	return retorno;
}

/// @brief Pausa la ejecución del programa hasta que el usuario presione cualquier tecla
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_presionarCualquierTecla() {
	int retorno;
	char cualquierTecla;

	retorno = -1;

	fflush(stdin);
	scanf("%c", &cualquierTecla);

	retorno = 0;
	return retorno;
}

/// @brief Calcula un porcentaje entero de un número racional, lo descuenta o incrementa al número
/// racional operado y devuelve los resultados
/// @param pResultado Puntero al resultado que guarda el número racional operado con el descuento
/// o incremento del porcentaje entero del mismo
/// @param pNumeroPorcentaje Puntero al resultado que guarda el número racional descontado o
/// incrementado, del porcentaje entero del número racional operado
/// @param pNumero Puntero al número racional operado
/// @param pPorcentaje Puntero al porcentaje entero de descuento o incremento
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_operarPorcentajeEntero(float *pResultado, float *pNumeroPorcentaje, float *pNumero, int *pPorcentaje) {
	int retorno;

	retorno = -1;

	if(pResultado != NULL && pNumeroPorcentaje != NULL && pNumero != NULL && *pNumero != 0 && pPorcentaje != NULL && *pPorcentaje != 0) {
		*pNumeroPorcentaje = *pNumero / 100 * *pPorcentaje;
		*pResultado = *pNumero + *pNumeroPorcentaje;

		retorno = 0;
	}

	return retorno;
}

/// @brief Convierte un valor numérico racional en una unidad a su equivalente en otra
/// unidad, y devuelve  el resultado
/// @param pValorEquivalente Puntero al número racional que guarda el valor equivalente en
/// otra unidad
/// @param pValor Puntero al número racional del valor en su unidad original
/// @param pTasaCambio Puntero al número racional de la tasa o tipo de cambio
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_intercambiarValor(float *pValorEquivalente, float *pValor, float *pTasaCambio) {
	int retorno;

	retorno = -1;

	if(pValorEquivalente != NULL && pValor != NULL && *pValor != 0 && pTasaCambio != NULL && *pTasaCambio != 0) {
		*pValorEquivalente = *pValor / *pTasaCambio;

		retorno = 0;
	}

	return retorno;
}

/// @brief Calcula el valor unitario -unidades enteras- de un número racional total, y devuelve
/// el resultado
/// @param pNumeroUnidad Puntero al número racional que guarda el número racional del
/// valor unitario
/// @param pNumero Puntero al número racional del valor total
/// @param pUnidad Puntero al número entero de unidades
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_calcularValorUnitario(float *pNumeroUnidad, float *pNumero, int *pUnidad) {
	int retorno;

	retorno = -1;

	if(pNumeroUnidad != NULL && pNumero != NULL && *pNumero != 0 && pUnidad != NULL && *pUnidad != 0) {
		*pNumeroUnidad = *pNumero / *pUnidad;

		retorno = 0;
	}

	return retorno;
}

/// @brief Calcula la resta entre dos números racionales en orden, y devuelve el resultado
/// @param pResultado Puntero al número racional que guarda el resultado de la resta entre los dos
/// números racionales en orden
/// @param pNumeroUno Puntero al número racional ordenado en la primer posición de la resta
/// @param pNumeroDos Puntero al número racional ordenado en la segunda posición de la resta
/// @return 0 en caso de éxito o -1 en caso de falla
int utn_calcularResta(float *pResultado, float *pNumeroUno, float *pNumeroDos) {
	int retorno;

	retorno = -1;

	if(pResultado != NULL && pNumeroUno != NULL && *pNumeroUno != 0 && pNumeroDos != NULL && *pNumeroDos != 0) {
		*pResultado = *pNumeroUno - *pNumeroDos;

		retorno = 0;
	}

	return retorno;
}
