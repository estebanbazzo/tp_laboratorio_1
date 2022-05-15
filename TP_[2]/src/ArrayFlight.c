/**************************************************************************************
 * Biblioteca  : ArrayFlight.c
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
#include "ArrayFlight.h"

int initFlights(Flight *list, int lenght) {
	int Return = -1;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			list[i].isEmpty = 1;
		}
		Return = 0;
	}

	return Return;
}


int addFlight(Flight *list, int lenght, int id, char flyCode[], int flightStatus) {
	int Return = -1;
	int exist = 0;

	if(list != NULL && lenght > 0 && id > 0 && flyCode != NULL && flightStatus > 0) {

		for(int i = 0; i < lenght; i++) {
			if(strcmp(flyCode, list[i].flyCode) == 0 && list[i].isEmpty == 0) {
				exist = 1;
				list[i].id = id;
				list[i].flightStatus = flightStatus;
				break;
			}
		}

		if(exist == 0) {
			for(int i = 0; i < lenght; i++) {
				if(list[i].isEmpty == 1) {
					list[i].id = id;
					strncpy(list[i].flyCode, flyCode, sizeof(list[i].flyCode));
					list[i].flightStatus = flightStatus;
					list[i].isEmpty = 0;
					break;
				}
			}
		}

		Return = 0;
	}

	return Return;
}


int findFlightById(Flight *list, int lenght, int id) {
	int Return = -1;
	return Return;
}


int removeFlight(Flight *list, int lenght, int id) {
	int Return = -1;
	return Return;
}
