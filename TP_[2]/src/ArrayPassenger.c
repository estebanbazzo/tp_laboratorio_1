/**************************************************************************************
 * Biblioteca  : ArrayPassenger.c
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
#include "ArrayPassenger.h"

int initPassengers(Passenger *list, int lenght) {
	int Return = -1;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			list[i].isEmpty = 1;
		}
		Return = 0;
	}

	return Return;
}


int setId(void) {
	static int auxId = 0;

	auxId++;
	printf("\nID asignado: %d", auxId);

	return auxId;
}


int addPassenger(Passenger *list, int lenght, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]) {
	int Return = -1;

	if(list != NULL && lenght > 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flyCode != NULL) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].isEmpty == 1) {
				list[i].id = id;
				strncpy(list[i].name, name, sizeof(list[i].name));
				strncpy(list[i].lastName, lastName, sizeof(list[i].lastName));
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strncpy(list[i].flyCode, flyCode, sizeof(list[i].flyCode));
				list[i].isEmpty = 0;
				Return = 0;
				break;
			}
		}
	}

	return Return;
}


int isThereAPassenger(Passenger *list, int lenght) {
	int Return = -1;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].isEmpty == 0) {
				Return = 0;
				break;
			}
		}
	}

	return Return;
}


int findPassengerById(Passenger *list, int lenght, int id) {
	int index = -1;

	if(list != NULL && lenght > 0 && id > 0) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].isEmpty == 0 && list[i].id == id) {
				index = i;
				break;
			}
		}
	}

	return index;
}


int removePassenger(Passenger *list, int lenght, int id) {
	int Return = -1;

	if(list != NULL && lenght > 0 && id > 0) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].id == id) {
				list[i].isEmpty = 1;
				Return = 0;
				break;
			}
		}
	}

	return Return;
}


int sortPassengers(Passenger *list, int lenght, int order) {
	int Return = -1;
	int isOrdered;
	Passenger auxList;

	if(list != NULL && lenght > 0 && (order == 0 || order == 1)) {
		do {
			isOrdered = 1;
			lenght--;
			for(int i = 0; i < lenght; i++) {
				if(order == 1) {
					if(strcmp(list[i].lastName, list[i+1].lastName) > 0) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
				}

				if(order == 0) {
					if(strcmp(list[i].lastName, list[i+1].lastName) < 0) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName) == 0 && list[i].typePassenger < list[i+1].typePassenger) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
				}
			}
		} while(isOrdered == 0);
		Return = 0;
	}

	return Return;
}

int sortPassengersByCode(Passenger *list, int lenght, int order) {
	int Return = -1;
	int isOrdered;
	Passenger auxList;

	if(list != NULL && lenght > 0 && (order == 0 || order == 1)) {
		do {
			isOrdered = 1;
			lenght--;
			for(int i = 0; i < lenght; i++) {
				if(order == 1) {
					if(strcmp(list[i].lastName, list[i+1].lastName) > 0) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName) == 0 && list[i].flyCode > list[i+1].flyCode) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
				}

				if(order == 0) {
					if(strcmp(list[i].lastName, list[i+1].lastName) < 0) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
					else if(strcmp(list[i].lastName, list[i+1].lastName) == 0 && list[i].flyCode < list[i+1].flyCode) {
						auxList = list[i];
						list[i] = list[i+1];
						list[i+1] = auxList;
						isOrdered = 0;
					}
				}
			}
		} while(isOrdered == 0);
		Return = 0;
	}

	return Return;
}


int printPassengers(Passenger *list, int lenght) {
	int Return = -1;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].isEmpty == 0) {
				printf("\nID: %d | Nombre: %s | Apellido: %s | Tipo: %d | Precio: $%.2f | Código: %s", list[i].id, list[i].name, list[i].lastName, list[i].typePassenger, list[i].price, list[i].flyCode);
			}
		}
		Return = 0;
	}

	return Return;
}

int printPassengerPrices(Passenger *list, int lenght) {
	int Return = -1;
	int totalPassengers = 0;
	float totalPrice;
	float averagePrice;

	if(list != NULL && lenght > 0) {
		for(int i = 0; i < lenght; i++) {
			if(list[i].isEmpty == 0) {
				totalPassengers++;
				totalPrice += list[i].price;
			}
		}
		averagePrice = totalPrice / (float)totalPassengers;
		printf("\nPRECIOS DE LOS PASAJES:");
		printf("\nTOTAL = $%.2f", totalPrice);
		printf("\nPROMEDIO = $%.2f", averagePrice);
		Return = 0;
	}

	return Return;
}
