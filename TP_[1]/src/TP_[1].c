/*
================================================================================
Nombre      : TP_[1].c
Autor       : Esteban Bazzo (DNI 37.066.587)
A�o         : 1�
Divisi�n    : E
Turno       : Noche
Materia     : Laboratorio de Computaci�n I
Profesores  : Gaston Argibay y Camila Iglesias Guerrero
Fecha       : 7 de abril de 2022 (1� cuatrimestre)
Descripci�n : Trabajo pr�ctico n�1 de Laboratorio de Computaci�n I
              Tecnicatura Universitaria en Programaci�n en UTN-FRA
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
/* Bibliotecas propias */
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	/* referencias del nombre de variables:
	km: kil�metro
	AA: Aerol�neas Argentinas
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
	btcAArs = 4875193.66; /* cotizaci�n de CoinMarketCap al 7 de abril de 2022 a las 22:34hs */
	flagTodosCostos = FALSO;
	flagDatosForzados = FALSO;

	printf("Bienvenidx a la Calculadora de la Agencia de Viajes\n");

	do {
		/* Inicio del men� principal */
		printf("\n_____________________________________________________________________________________/ MEN� PRINCIPAL\n");
		/* Opci�n 1 */
		printf("\n1. Ingresar los kil�metros del vuelo (km = %d)\n", kmTotal);
		/* Opci�n 2 */
		printf("\n2. Ingresar el precio de los vuelos (Aerol�neas Argentinas = $%.2f, Latam Airlines = $%.2f)\n", precioTotalAA, precioTotalLA);
		/* Opci�n 3 */
		printf("\n3. Calcular todos los costos:");
		printf("\n   a) Tarjeta de d�bito (%d%% de descuento)", descuentoDebito);
		printf("\n   b) Tarjeta de cr�dito (%d%% de inter�s)", interesCredito);
		printf("\n   c) Bitcoin (BTC 1 = $%.2f)", btcAArs);
		printf("\n   d) Precio por kil�metro (unitario)");
		printf("\n   e) Diferencia de precio total entre vuelos\n");
		/* Opci�n 4 */
		printf("\n4. Informar los resultados\n");
		/* Opci�n 5 */
		printf("\n5. Cargar forzosamente los datos\n");
		/* Opci�n 6 */
		printf("\n6. Salir del programa\n");
		/* Fin del men� principal */
		printf("_____________________________________________________________________________________________________\n");

		/* Elecci�n de opci�n del men� principal */
		retornoFuncionUtn = utn_obtenerEntero(&opcionMenu, "\nIngrese una opci�n del men� principal (1-6): ", "\nError: la opci�n ingresada es inv�lida", 1, 6, -1);
		if(retornoFuncionUtn == 0) {
			switch(opcionMenu) {
			/* Opci�n 1 */
			case 1:
				/* Ingreso de kil�metros totales */
				retornoFuncionUtn = utn_obtenerEntero(&kmTotal, "\nIngrese los kil�metros totales del vuelo (entero >=1): ", "\nError: los kil�metros totales ingresados son inv�lidos", 1, -1, -1);
				if(retornoFuncionUtn == 0) {
					printf("\nLos kil�metros totales del vuelo ingresados se cargaron correctamente");
				} else {
					printf("\nError: la funci�n utn_obtenerEntero fall�. Problemas de memoria RAM o los par�metros son inv�lidos");
				}
				printf("\nPresione cualquier tecla para volver al men� principal");
				utn_presionarCualquierTecla();

				break;

			/* Opci�n 2 */
			case 2:
				do {
					/* Inicio del submen� Ingresar el precio de los vuelos */
					printf("\n__________________________________________/ men� principal > SUBMEN� INGRESAR EL PRECIO DE LOS VUELOS\n");
					/* Subopci�n 1 */
					printf("\n1. Ingresar el precio total del vuelo de Aerol�neas Argentinas ($ = %.2f)", precioTotalAA);
					/* Subopci�n 2 */
					printf("\n2. Ingresar el precio total del vuelo de Latam Airlines ($ = %.2f)\n", precioTotalLA);
					/* Subopci�n 3 */
					printf("\n3. Volver al men� principal\n");
					/* Fin del submen� Ingresar el precio de los vuelos */
					printf("_____________________________________________________________________________________________________\n");

					/* Elecci�n de opci�n del submen� Ingresar el precio de los vuelos */
					retornoFuncionUtn = utn_obtenerEntero(&opcionMenu, "\nIngrese una opci�n del submen� Ingresar el precio de los vuelos (1-3): ", "\nError: la opci�n ingresada es inv�lida", 1, 3, -1);
					if(retornoFuncionUtn == 0) {
						switch(opcionMenu) {
						/* Subopci�n 1 */
						case 1:
							/* Ingreso de precio total de vuelo de Aerol�neas Argentinas */
							retornoFuncionUtn = utn_obtenerRacional(&precioTotalAA, "\nIngrese el precio total del vuelo de Aerol�neas Argentinas (>=0.01): $", "\nError: el precio total ingresado es inv�lido", 0.01, -1, -1);
							if(retornoFuncionUtn == 0) {
								printf("\nEl precio total del vuelo de Aerol�neas Argentinas ingresado se carg� correctamente");
							} else {
								printf("\nError: la funci�n utn_obtenerRacional fall�. Problemas de memoria RAM o los par�metros son inv�lidos");
							}
							printf("\nPresione cualquier tecla para volver al submen� Ingresar el precio de los vuelos");
							utn_presionarCualquierTecla();

							break;

						/* Subopci�n 2 */
						case 2:
							/* Ingreso de precio total de vuelo de Latam Airlines */
							retornoFuncionUtn = utn_obtenerRacional(&precioTotalLA, "\nIngrese el precio total del vuelo de Latam Airlines (>=0.01): $", "\nError: el precio total ingresado es inv�lido", 0.01, -1, -1);
							if(retornoFuncionUtn == 0) {
								printf("\nEl precio total del vuelo de Latam Airlines ingresado se carg� correctamente");
							} else {
								printf("\nError: la funci�n utn_obtenerRacional fall�. Problemas de memoria RAM o los par�metros son inv�lidos");
							}
							printf("\nPresione cualquier tecla para volver al submen� Ingresar el precio de los vuelos");
							utn_presionarCualquierTecla();

							break;
						}
					} else {
						printf("\nError: la funci�n utn_obtenerEntero fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();

						break;
					}
				/* Vuelta al men� principal con opci�n 3 */
				} while(opcionMenu != 3);

				break;

			/* Opci�n 3 */
			case 3:
				/* Etiqueta para opci�n 5 */
				OPCION3:
				/* Control de valores de variables requeridos para calcular */
				if(kmTotal != 0 && precioTotalAA != 0 && precioTotalLA != 0) {
					/* Control de cambios en valores de variables */
					kmTotalOperado = kmTotal;
					precioTotalAAOperado = precioTotalAA;
					precioTotalLAOperado = precioTotalLA;
					flagTodosCostos = VERDADERO;

					/* C�lculo de precios con tarjeta de d�bito */
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioDebitoAA, &precioDescontadoAA, &precioTotalAA, &descuentoDebito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioDebitoLA, &precioDescontadoLA, &precioTotalLA, &descuentoDebito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					/* C�lculo de precios con tarjeta de cr�dito */
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioCreditoAA, &precioIncrementadoAA, &precioTotalAA, &interesCredito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_operarPorcentajeEntero(&precioCreditoLA, &precioIncrementadoLA, &precioTotalLA, &interesCredito);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa funci�n utn_operarPorcentajeEntero fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* C�lculo de precios con bitcoin */
					retornoFuncionUtn = utn_intercambiarValor(&precioBtcAA, &precioTotalAA, &btcAArs);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_intercambiarValor(&precioBtcLA, &precioTotalLA, &btcAArs);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa funci�n utn_intercambiarValor fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* C�lculo de precios unitarios */
					retornoFuncionUtn = utn_calcularValorUnitario(&precioUnitarioAA, &precioTotalAA, &kmTotal);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}
					retornoFuncionUtn = utn_calcularValorUnitario(&precioUnitarioLA, &precioTotalLA, &kmTotal);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;
					}

					if(flagTodosCostos == FALSO) {
						printf("\nLa funci�n utn_calcularValorUnitario fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();

						break;
					}

					/* C�lculo de diferencia entre precios totales */
					retornoFuncionUtn = utn_calcularResta(&diferenciaPrecioTotal, &precioTotalAA, &precioTotalLA);
					if(retornoFuncionUtn == -1) {
						flagTodosCostos = FALSO;

						printf("\nLa funci�n utn_calcularResta fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();

						break;
					}

					printf("\nTodos los costos se calcularon correctamente");
					/* Control de opci�n 5 ejecutada */
					if(flagDatosForzados == VERDADERO) {
						flagDatosForzados = FALSO;

						printf("\nPresione cualquier tecla para informar los resultados");
						utn_presionarCualquierTecla();

						/* Ejecutar autom�ticamente el informe */
						goto OPCION4;
					}
					printf("\nPresione cualquier tecla para volver al men� principal");
					utn_presionarCualquierTecla();
				} else {
					flagTodosCostos = FALSO;

					printf("\nError: debe haber kil�metros y precio de vuelos cargados para poder calcular todos los costos"
						   "\nPresione cualquier tecla para volver al men� principal");
					utn_presionarCualquierTecla();
				}

				break;

			/* Opci�n 4 */
			case 4:
				/* Etiqueta para opci�n 5 */
				OPCION4:
				if(flagTodosCostos == VERDADERO) {
					/* Control de cambios en valores de variables requerido para informar */
					if(kmTotalOperado == kmTotal && precioTotalAAOperado == precioTotalAA && precioTotalLAOperado == precioTotalLA) {
						/* Inicio del Informe de los resultados */
						printf("\n************************************* INFORME DE LOS RESULTADOS *************************************\n");
						/* Kil�metros */
						printf("\nKil�metros totales del vuelo: %d km\n", kmTotal);
						/* Aerol�neas Argentinas */
						printf("\nPrecio total del vuelo de Aerol�neas Argentinas: $%.2f", precioTotalAA);
						printf("\na) Precio con tarjeta de d�bito: $%.2f ($%.2f)", precioDebitoAA, precioDescontadoAA);
						printf("\nb) Precio con tarjeta de cr�dito: $%.2f ($+%.2f)", precioCreditoAA, precioIncrementadoAA);
						printf("\nc) Precio en bitcoins: BTC %.8f", precioBtcAA);
						printf("\nd) Precio unitario: $%.2f\n", precioUnitarioAA);
						/* Latam Airlines */
						printf("\nPrecio total del vuelo de Latam Airlines: $%.2f", precioTotalLA);
						printf("\na) Precio con tarjeta de d�bito: $%.2f ($%.2f)", precioDebitoLA, precioDescontadoLA);
						printf("\nb) Precio con tarjeta de cr�dito: $%.2f ($+%.2f)", precioCreditoLA, precioIncrementadoLA);
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

						printf("\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();
					} else {
						printf("\nError: los kil�metros y/o precio de vuelos cargados han cambiado. Debe volver a calcular los costos"
							   "\nPresione cualquier tecla para volver al men� principal");
						utn_presionarCualquierTecla();
					}
				} else {
					printf("\nError: debe calcular todos los costos para poder informar los resultados"
						   "\nPresione cualquier tecla para volver al men� principal");
					utn_presionarCualquierTecla();
				}

				break;

			/* Opci�n 5 */
			case 5:
				/* Forzar valores de variables a preestablecidos */
				kmTotal = 7090;
				precioTotalAA = 162965;
				precioTotalLA = 159339;
				flagDatosForzados = VERDADERO;

				printf("\nSe forzaron los kil�metros totales del vuelo en %d", kmTotal);
				printf("\nSe forz� el precio del vuelo de Aerol�neas Argentinas en $%.2f", precioTotalAA);
				printf("\nSe forz� el precio del vuelo de Latam Airlines en $%.2f", precioTotalLA);

				/* Ejecutar autom�ticamente los c�lculos y luego el informe */
				goto OPCION3;

			/* Opci�n 6 */
			case 6:
				printf("\nGracias por utilizar la Calculadora de la Agencia de Viajes");

				retorno = 0;
				break;
			}
		} else {
			printf("\nError: la funci�n utn_obtenerEntero fall�. Problemas de memoria RAM o los par�metros son inv�lidos"
				   "\nPresione cualquier tecla para salir del programa");
			utn_presionarCualquierTecla();

			break;
		}
	/* Salida del programa principal con opci�n 6 */
	} while(opcionMenu != 6);

	return retorno;
}
