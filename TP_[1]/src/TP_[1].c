/*
================================================================================
Nombre      : TP_[1].c
Autor       : Esteban Bazzo (DNI 37.066.587)
Año         : 1°
División    : E
Turno       : Noche
Materia     : Laboratorio de Computación I
Profesores  : Gaston Argibay y Camila Iglesias Guerrero
Fecha       : 7 de abril de 2022 (1° cuatrimestre)
Descripción : Trabajo práctico n°1 de Laboratorio de Computación I
              Tecnicatura Universitaria en Programación en UTN-FRA
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
/* Bibliotecas propias */
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	/* referencias del nombre de variables:
	km: kilómetro
	AA: Aerolíneas Argentinas
	LA: Latam Airlines
	btc: bitcoin
	Ars: peso argentino */
	int retorno;
	int kmTotal;
	float precioTotalAA;
	float precioTotalLA;
	int descuentoDebito;
	int interesCredito;
	float btcAArs;
	int opcionMenu;
	int retornoFuncionUtn;
	int kmTotalOperado;
	float precioTotalAAOperado;
	float precioTotalLAOperado;
	float precioDebitoAA;
	float precioDescontadoAA;
	float precioCreditoAA;
	float precioIncrementadoAA;
	float precioBtcAA;
	float precioUnitarioAA;
	float precioDebitoLA;
	float precioDescontadoLA;
	float precioCreditoLA;
	float precioIncrementadoLA;
	float precioBtcLA;
	float precioUnitarioLA;
	float diferenciaPrecioTotal;
	int flagTodosCostos;
	int flagDatosForzados;

	retorno = -1;
	kmTotal = 0;
	precioTotalAA = 0;
	precioTotalLA = 0;
	descuentoDebito = -10;
	interesCredito = 25;
	btcAArs = 4875193.66; /* cotización de CoinMarketCap al 7 de abril de 2022 a las 22:34hs */
	flagTodosCostos = FALSO;
	flagDatosForzados = FALSO;

	printf("Bienvenidx a la Calculadora de la Agencia de Viajes\n");

	do {
		/* Inicio del menú principal */
		printf("\n_____________________________________________________________________________________/ MENÚ PRINCIPAL\n");
		/* Opción 1 */
		printf("\n1. Ingresar los kilómetros del vuelo (km = %d)\n", kmTotal);
		/* Opción 2 */
		printf("\n2. Ingresar el precio de los vuelos (Aerolíneas Argentinas = $%.2f, Latam Airlines = $%.2f)\n", precioTotalAA, precioTotalLA);
		/* Opción 3 */
		printf("\n3. Calcular todos los costos:");
		printf("\n   a) Tarjeta de débito (%d%% de descuento)", descuentoDebito);
		printf("\n   b) Tarjeta de crédito (%d%% de interés)", interesCredito);
		printf("\n   c) Bitcoin (BTC 1 = $%.2f)", btcAArs);
		printf("\n   d) Precio por kilómetro (unitario)");
		printf("\n   e) Diferencia de precio total entre vuelos\n");
		/* Opción 4 */
		printf("\n4. Informar los resultados\n");
		/* Opción 5 */
		printf("\n5. Cargar forzosamente los datos\n");
		/* Opción 6 */
		printf("\n6. Salir del programa\n");
		/* Fin del menú principal */
		printf("_____________________________________________________________________________________________________\n");

		/* Elección de opción del menú principal */
		retornoFuncionUtn = utn_obtenerEntero(&opcionMenu, "\nIngrese una opción del menú principal (1-6): ", "\nError: la opción ingresada es inválida", 1, 6, -1);
		if(retornoFuncionUtn == 0) {
			switch(opcionMenu) {
			/* Opción 1 */
			case 1:
				/* Ingreso de kilómetros totales */
				retornoFuncionUtn = utn_obtenerEntero(&kmTotal, "\nIngrese los kilómetros totales del vuelo (entero >=1): ", "\nError: los kilómetros totales ingresados son inválidos", 1, -1, -1);
				if(retornoFuncionUtn == 0) {
					printf("\nLos kilómetros totales del vuelo ingresados se cargaron correctamente");
				} else {
					printf("\nError: la función utn_obtenerEntero falló. Problemas de memoria RAM o los parámetros son inválidos");
				}
				printf("\nPresione cualquier tecla para volver al menú principal");
				utn_presionarCualquierTecla();

				break;

			/* Opción 2 */
			case 2:
				do {
					/* Inicio del submenú Ingresar el precio de los vuelos */
					printf("\n__________________________________________/ menú principal > SUBMENÚ INGRESAR EL PRECIO DE LOS VUELOS\n");
					/* Subopción 1 */
					printf("\n1. Ingresar el precio total del vuelo de Aerolíneas Argentinas ($ = %.2f)", precioTotalAA);
					/* Subopción 2 */
					printf("\n2. Ingresar el precio total del vuelo de Latam Airlines ($ = %.2f)\n", precioTotalLA);
					/* Subopción 3 */
					printf("\n3. Volver al menú principal\n");
					/* Fin del submenú Ingresar el precio de los vuelos */
					printf("_____________________________________________________________________________________________________\n");

					/* Elección de opción del submenú Ingresar el precio de los vuelos */
					retornoFuncionUtn = utn_obtenerEntero(&opcionMenu, "\nIngrese una opción del submenú Ingresar el precio de los vuelos (1-3): ", "\nError: la opción ingresada es inválida", 1, 3, -1);
					if(retornoFuncionUtn == 0) {
						switch(opcionMenu) {
						/* Subopción 1 */
						case 1:
							/* Ingreso de precio total de vuelo de Aerolíneas Argentinas */
							retornoFuncionUtn = utn_obtenerRacional(&precioTotalAA, "\nIngrese el precio total del vuelo de Aerolíneas Argentinas (>=0.01): $", "\nError: el precio total ingresado es inválido", 0.01, -1, -1);
							if(retornoFuncionUtn == 0) {
								printf("\nEl precio total del vuelo de Aerolíneas Argentinas ingresado se cargó correctamente");
							} else {
								printf("\nError: la función utn_obtenerRacional falló. Problemas de memoria RAM o los parámetros son inválidos");
							}
							printf("\nPresione cualquier tecla para volver al submenú Ingresar el precio de los vuelos");
							utn_presionarCualquierTecla();

							break;

						/* Subopción 2 */
						case 2:
							/* Ingreso de precio total de vuelo de Latam Airlines */
							retornoFuncionUtn = utn_obtenerRacional(&precioTotalLA, "\nIngrese el precio total del vuelo de Latam Airlines (>=0.01): $", "\nError: el precio total ingresado es inválido", 0.01, -1, -1);
							if(retornoFuncionUtn == 0) {
								printf("\nEl precio total del vuelo de Latam Airlines ingresado se cargó correctamente");
							} else {
								printf("\nError: la función utn_obtenerRacional falló. Problemas de memoria RAM o los parámetros son inválidos");
							}
							printf("\nPresione cualquier tecla para volver al submenú Ingresar el precio de los vuelos");
							utn_presionarCualquierTecla();

							break;
						}
					} else {
						printf("\nError: la función utn_obtenerEntero falló. Problemas de memoria RAM o los parámetros son inválidos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();

						break;
					}
				/* Vuelta al menú principal con opción 3 */
				} while(opcionMenu != 3);

				break;

			/* Opción 3 */
			case 3:
				/* Etiqueta para opción 5 */
				OPCION3:
				/* Control de valores de variables requeridos para calcular */
				if(kmTotal != 0 && precioTotalAA != 0 && precioTotalLA != 0) {
					/* Control de cambios en valores de variables */
					kmTotalOperado = kmTotal;
					precioTotalAAOperado = precioTotalAA;
					precioTotalLAOperado = precioTotalLA;
					flagTodosCostos = VERDADERO;

					/* Cálculo de precios con tarjeta de débito */
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioDebitoAA, &precioDescontadoAA, &precioTotalAA, &descuentoDebito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioDebitoLA, &precioDescontadoLA, &precioTotalLA, &descuentoDebito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					/* Cálculo de precios con tarjeta de crédito */
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioCreditoAA, &precioIncrementadoAA, &precioTotalAA, &interesCredito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioCreditoLA, &precioIncrementadoLA, &precioTotalLA, &interesCredito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa función utn_operarPorcentajeEntero falló. Problemas de memoria RAM o los parámetros son inválidos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* Cálculo de precios con bitcoin */
					retornoFuncionUtn = utn_intercambiarValor(&precioBtcAA, &precioTotalAA, &btcAArs);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_intercambiarValor(&precioBtcLA, &precioTotalLA, &btcAArs);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa función utn_intercambiarValor falló. Problemas de memoria RAM o los parámetros son inválidos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* Cálculo de precios unitarios */
					retornoFuncionUtn = utn_calcularValorUnitario(&precioUnitarioAA, &precioTotalAA, &kmTotal);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_calcularValorUnitario(&precioUnitarioLA, &precioTotalLA, &kmTotal);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa función utn_calcularValorUnitario falló. Problemas de memoria RAM o los parámetros son inválidos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* Cálculo de diferencia entre precios totales */
					retornoFuncionUtn = utn_calcularResta(&diferenciaPrecioTotal, &precioTotalAA, &precioTotalLA);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;

						printf("\nLa función utn_calcularResta falló. Problemas de memoria RAM o los parámetros son inválidos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();

						break;
					}

					printf("\nTodos los costos se calcularon correctamente");
					/* Control de opción 5 ejecutada */
					if(flagDatosForzados == VERDADERO) {
						flagDatosForzados = FALSO;

						printf("\nPresione cualquier tecla para informar los resultados");
						utn_presionarCualquierTecla();

						/* Ejecutar automáticamente el informe */
						goto OPCION4;
					}
					printf("\nPresione cualquier tecla para volver al menú principal");
					utn_presionarCualquierTecla();
				} else {
					flagTodosCostos = FALSO;

					printf("\nError: debe haber kilómetros y precio de vuelos cargados para poder calcular todos los costos"
						   "\nPresione cualquier tecla para volver al menú principal");
					utn_presionarCualquierTecla();
				}

				break;

			/* Opción 4 */
			case 4:
				/* Etiqueta para opción 5 */
				OPCION4:
				if(flagTodosCostos == VERDADERO) {
					/* Control de cambios en valores de variables requerido para informar */
					if(kmTotalOperado == kmTotal && precioTotalAAOperado == precioTotalAA && precioTotalLAOperado == precioTotalLA) {
						/* Inicio del Informe de los resultados */
						printf("\n************************************* INFORME DE LOS RESULTADOS *************************************\n");
						/* Kilómetros */
						printf("\nKilómetros totales del vuelo: %d km\n", kmTotal);
						/* Aerolíneas Argentinas */
						printf("\nPrecio total del vuelo de Aerolíneas Argentinas: $%.2f", precioTotalAA);
						printf("\na) Precio con tarjeta de débito: $%.2f ($%.2f)", precioDebitoAA, precioDescontadoAA);
						printf("\nb) Precio con tarjeta de crédito: $%.2f ($+%.2f)", precioCreditoAA, precioIncrementadoAA);
						printf("\nc) Precio en bitcoins: BTC %.8f", precioBtcAA);
						printf("\nd) Precio unitario: $%.2f\n", precioUnitarioAA);
						/* Latam Airlines */
						printf("\nPrecio total del vuelo de Latam Airlines: $%.2f", precioTotalLA);
						printf("\na) Precio con tarjeta de débito: $%.2f ($%.2f)", precioDebitoLA, precioDescontadoLA);
						printf("\nb) Precio con tarjeta de crédito: $%.2f ($+%.2f)", precioCreditoLA, precioIncrementadoLA);
						printf("\nc) Precio en bitcoins: BTC %.8f", precioBtcLA);
						printf("\nd) Precio unitario: $%.2f\n", precioUnitarioLA);
						/* Diferencia */
						if(diferenciaPrecioTotal < 0) {
							printf("\ne) La diferencia entre los precios totales de los vuelos es: $%.2f\n", diferenciaPrecioTotal *= -1);
						} else {
							printf("\ne) La diferencia entre los precios totales de los vuelos es: $%.2f\n", diferenciaPrecioTotal);
						}
						/* Fin del Informe de los resultados */
						printf("\n*****************************************************************************************************\n");

						printf("\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();
					} else {
						printf("\nError: los kilómetros y/o precio de vuelos cargados han cambiado. Debe volver a calcular los costos"
							   "\nPresione cualquier tecla para volver al menú principal");
						utn_presionarCualquierTecla();
					}
				} else {
					printf("\nError: debe calcular todos los costos para poder informar los resultados"
						   "\nPresione cualquier tecla para volver al menú principal");
					utn_presionarCualquierTecla();
				}

				break;

			/* Opción 5 */
			case 5:
				/* Forzar valores de variables a preestablecidos */
				kmTotal = 7090;
				precioTotalAA = 162965;
				precioTotalLA = 159339;
				flagDatosForzados = VERDADERO;

				printf("\nSe forzaron los kilómetros totales del vuelo en %d", kmTotal);
				printf("\nSe forzó el precio del vuelo de Aerolíneas Argentinas en $%.2f", precioTotalAA);
				printf("\nSe forzó el precio del vuelo de Latam Airlines en $%.2f", precioTotalLA);

				/* Ejecutar automáticamente los cálculos y luego el informe */
				goto OPCION3;

			/* Opción 6 */
			case 6:
				printf("\nGracias por utilizar la Calculadora de la Agencia de Viajes");

				retorno = 0;
				break;
			}
		} else {
			printf("\nError: la función utn_obtenerEntero falló. Problemas de memoria RAM o los parámetros son inválidos"
				   "\nPresione cualquier tecla para salir del programa");
			utn_presionarCualquierTecla();

			break;
		}
	/* Salida del programa principal con opción 6 */
	} while(opcionMenu != 6);

	return retorno;
}
