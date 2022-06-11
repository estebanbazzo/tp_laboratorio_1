#include "Controller.h"


static int controller_getLastId(char* path, char* id);
static int controller_lastIdPlusPlus(char* id);
static int controller_refreshLastId(char* path, char* id);


/// @brief
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger) {
	int Return = -1;
	FILE* pTxtFile = NULL;
	if(path != NULL && pArrayListPassenger != NULL) {
		if((pTxtFile = fopen(path, "r")) != NULL) {
			if(!parser_PassengerFromText(pTxtFile, pArrayListPassenger)) {
				fclose(pTxtFile);
				Return = 0;
			}
		}
	}
	return Return;
}

/// @brief
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger) {
	int Return = -1;
	FILE* pBinFile = NULL;
	if(path != NULL && pArrayListPassenger != NULL) {
		if((pBinFile = fopen(path, "rb")) != NULL) {
			if(!parser_PassengerFromBinary(pBinFile, pArrayListPassenger)) {
				fclose(pBinFile);
				Return = 0;
			}
		}
	}
	return Return;
}

/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_addPassenger(LinkedList* pArrayListPassenger) {
	int Return = -1;
	char auxId[128];
	char auxName[NAME_LENGHT];
	char auxLastName[LASTNAME_LENGHT];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[FLYCODE_LENGHT];
	int auxFlightStatus;
	Passenger* pP = NULL;
	if(pArrayListPassenger != NULL) {
		if (!controller_getLastId("lastId.csv", auxId) && !controller_lastIdPlusPlus(auxId)) {
			if(!utn_getName(auxName, NAME_LENGHT, "\nIngrese el nombre: ", "\nError: el nombre ingresado es inválido", 3) &&
			   !utn_getName(auxLastName, LASTNAME_LENGHT, "Ingrese el apellido: ", "\nError: el apellido ingresado es inválido", 3) &&
			   !utn_getFloat(&auxPrice, "Ingrese el precio: ", "\nError: el precio ingresado es inválido", 0.01, -1, 3) &&
			   !utn_getInt(&auxTypePassenger, "Ingrese el tipo (1-FirstClass/2-ExecutiveClass/3-EconomyClass): ", "\nError: el tipo ingresado es inválido", 1, 3, 3) &&
			   !utn_getCode(auxFlyCode, FLYCODE_LENGHT, "Ingrese el código: ", "\nError: el código ingresado es inválido", 3) &&
			   !utn_getInt(&auxFlightStatus, "Ingrese el estado (1-En Vuelo/2-En Horario/3-Demorado/4-Aterrizado): ", "\nError: el estado ingresado es inválido", 1, 4, 3)) {
				if((pP = Passenger_new()) != NULL) {
					if(!Passenger_setId(pP, atoi(auxId)) &&
					   !Passenger_setNombre(pP, auxName) &&
					   !Passenger_setApellido(pP, auxLastName) &&
					   !Passenger_setPrecio(pP, auxPrice) &&
					   !Passenger_setTipoPasajero(pP, auxTypePassenger) &&
					   !Passenger_setCodigoVuelo(pP, auxFlyCode) &&
					   !Passenger_setEstadoVuelo(pP, auxFlightStatus)) {
						if(!controller_refreshLastId("lastId.csv", auxId)) {
							ll_add(pArrayListPassenger,pP);
							Return = 0;
						}
					}
				}
				else {
					Passenger_delete(pP);
				}
			}
		}
	}
	return Return;
}
/// @brief
///
/// @param path
/// @param id
/// @return
static int controller_getLastId(char* path, char* id) {
	int Return = -1;
	FILE* idFile = NULL;
	if(id != NULL && (idFile = fopen(path, "r")) != NULL) {
		fscanf(idFile, "%[^\n]\n", id);
		fclose(idFile);
		Return = 0;
	}
	return Return;
}
/// @brief
///
/// @param id
/// @return
static int controller_lastIdPlusPlus(char* id) {
	int idToIncrease;
	int Return = -1;
	if(id != NULL) {
		idToIncrease = atoi(id);
		idToIncrease++;
		itoa(idToIncrease, id, 128);
		Return = 0;
	}
	return Return;
}
/// @brief
///
/// @param path
/// @param id
/// @return
static int controller_refreshLastId(char* path, char* id) {
	FILE* idFile = NULL;
	int Return = -1;
	if(id != NULL && (idFile = fopen(path, "w")) != NULL) {
		fprintf(idFile, "%s\n", id);
		fclose(idFile);
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_editPassenger(LinkedList* pArrayListPassenger) {
	int Return = -1;
	int id;
	int auxId;
	char auxName[NAME_LENGHT];
	char auxLastName[LASTNAME_LENGHT];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[FLYCODE_LENGHT];
	int auxFlightStatus;
	Passenger* pP = NULL;
	if(pArrayListPassenger != NULL) {
		if(!utn_getInt(&auxId, "\nIngrese el ID del pasajero a modificar: ", "\nError: el ID ingresado es inválido", 1, -1, 3)) {
			for(int i = 0; i < ll_len(pArrayListPassenger); i++) {
				pP = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pP, &id);
				Passenger_getNombre(pP, auxName);
				Passenger_getApellido(pP, auxLastName);
				Passenger_getPrecio(pP, &auxPrice);
				Passenger_getTipoPasajero(pP, &auxTypePassenger);
				Passenger_getCodigoVuelo(pP, auxFlyCode);
				Passenger_getEstadoVuelo(pP, &auxFlightStatus);
				if(auxId == id) {
					if(!utn_getName(auxName, NAME_LENGHT, "Ingrese el nuevo nombre: ", "\nError: el nuevo nombre ingresado es inválido", 3) &&
					   !utn_getName(auxLastName, LASTNAME_LENGHT, "Ingrese el nuevo apellido: ", "\nError: el nuevo apellido ingresado es inválido", 3) &&
					   !utn_getFloat(&auxPrice, "Ingrese el nuevo precio: ", "\nError: el nuevo precio ingresado es inválido", 0.01, -1, 3) &&
					   !utn_getInt(&auxTypePassenger, "Ingrese el nuevo tipo (1-FirstClass/2-ExecutiveClass/3-EconomyClass): ", "\nError: el nuevo tipo ingresado es inválido", 1, 3, 3) &&
					   !utn_getCode(auxFlyCode, FLYCODE_LENGHT, "Ingrese el nuevo código: ", "\nError: el nuevo código ingresado es inválido", 3) &&
					   !utn_getInt(&auxFlightStatus, "Ingrese el nuevo estado (1-En Vuelo/2-En Horario/3-Demorado/4-Aterrizado): ", "\nError: el nuevo estado ingresado es inválido", 1, 4, 3)) {
						if(!Passenger_setNombre(pP, auxName) &&
						   !Passenger_setApellido(pP, auxLastName) &&
						   !Passenger_setPrecio(pP, auxPrice) &&
						   !Passenger_setTipoPasajero(pP, auxTypePassenger) &&
						   !Passenger_setCodigoVuelo(pP, auxFlyCode) &&
						   !Passenger_setEstadoVuelo(pP, auxFlightStatus)) {
							Return = 0;
							break;
						}
					}
				}
			}
		}
	}
	return Return;
}

/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_removePassenger(LinkedList* pArrayListPassenger) {
	int Return = -1;
	int id;
	int auxId;
	Passenger* pP = NULL;
	if(pArrayListPassenger != NULL) {
		if(!utn_getInt(&auxId, "\nIngrese el ID del pasajero a eliminar: ", "\nError: el ID ingresado es inválido", 1, -1, 3)) {
			for(int i = 0; i < ll_len(pArrayListPassenger); i++) {
				pP = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pP, &id);
				if(auxId == id) {
					ll_remove(pArrayListPassenger, i);
					Passenger_delete(pP);
					Return = 0;
					break;
				}
			}
		}
	}
	return Return;
}

/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_ListPassenger(LinkedList* pArrayListPassenger) {
	int Return = -1;
	Passenger* pP = NULL;
	int id;
	char name[NAME_LENGHT];
	char lastName[LASTNAME_LENGHT];
	float price;
	int typePassenger;
	char auxTypePassenger[TYPE_LENGHT];
	char flyCode[FLYCODE_LENGHT];
	int flightStatus;
	char auxFlightStatus[FLIGHTSTATUS_LENGHT];
	if(pArrayListPassenger != NULL) {
		printf("\nID      NOMBRE           APELLIDO          PRECIO       TIPO              CÓDIGO     ESTADO    \n\n");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++) {
			pP = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(pP, &id);
			Passenger_getNombre(pP, name);
			Passenger_getApellido(pP, lastName);
			Passenger_getPrecio(pP, &price);
			Passenger_getTipoPasajero(pP, &typePassenger);
			Passenger_getCodigoVuelo(pP, flyCode);
			Passenger_getEstadoVuelo(pP, &flightStatus);
			switch(typePassenger) {
				case FIRST:
					strncpy(auxTypePassenger, "FirstClass", TYPE_LENGHT);
					break;
				case EXECUTIVE:
					strncpy(auxTypePassenger, "ExecutiveClass", TYPE_LENGHT);
					break;
				case ECONOMY:
					strncpy(auxTypePassenger, "EconomyClass", TYPE_LENGHT);
					break;
			}
			switch(flightStatus) {
				case AIRBORNE:
					strncpy(auxFlightStatus, "En Vuelo", FLIGHTSTATUS_LENGHT);
					break;
				case ONTIME:
					strncpy(auxFlightStatus, "En Horario", FLIGHTSTATUS_LENGHT);
					break;
				case DELAYED:
					strncpy(auxFlightStatus, "Demorado", FLIGHTSTATUS_LENGHT);
					break;
				case LANDED:
					strncpy(auxFlightStatus, "Aterrizado", FLIGHTSTATUS_LENGHT);
					break;
			}
			printf("%-4d    %-13s    %-14s    $%-5.2f    %-14s    %-7s    %-10s\n", id, name, lastName, price, auxTypePassenger, flyCode, auxFlightStatus);
		}
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_sortPassenger(LinkedList* pArrayListPassenger) {
	int Return = -1;
	int option;
	int subOption;
	if(pArrayListPassenger != NULL) {
		do {
			printf("\n1. Ordenar por ID"
				   "\n2. Ordenar por nombre"
				   "\n3. Ordenar por apellido"
				   "\n4. Ordenar por tipo"
				   "\n5. Ordenar por precio"
				   "\n6. Ordenar por código de vuelo"
				   "\n7. Ordenar por estado del vuelo"
				   "\n8. Volver al menú principal\n");
			if(!utn_getInt(&option, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 1, 8, -1)) {
				switch(option) {
				case 1:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortById, subOption);
						}
					} while(subOption != 2);
					break;

				case 2:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByName, subOption);
						}
					} while(subOption != 2);
					break;

				case 3:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByLastName, subOption);
						}
					} while(subOption != 2);
					break;

				case 4:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByTypePassenger, subOption);
						}
					} while(subOption != 2);
					break;

				case 5:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByPrice, subOption);
						}
					} while(subOption != 2);
					break;

				case 6:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByFlyCode, subOption);
						}
					} while(subOption != 2);
					break;

				case 7:
					do {
						printf("\n0. Descendentemente"
							   "\n1. Ascendentemente"
							   "\n2. Volver al submenú modificar\n");
						if(!utn_getInt(&subOption, "\nIngrese una opción del submenú modificar: ", "\nError: la opción ingresada es inválida", 0, 2, -1)) {
							ll_sort(pArrayListPassenger, passenger_sortByFlightStatus, subOption);
						}
					} while(subOption != 2);
					break;

				case 8:
					Return = 0;
					break;
				}
			}
		} while(option != 8);
	}
	return Return;
}

/// @brief
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger) {
	int Return = -1;
	FILE* pTxtFile = NULL;
	Passenger* pP = NULL;
	int id;
	char name[NAME_LENGHT];
	char lastName[LASTNAME_LENGHT];
	float price;
	int typePassenger;
	char auxTypePassenger[TYPE_LENGHT];
	char flyCode[FLYCODE_LENGHT];
	int flightStatus;
	char auxFlightStatus[FLIGHTSTATUS_LENGHT];
	if(path != NULL && pArrayListPassenger != NULL) {
		if((pTxtFile = fopen(path, "w")) != NULL) {
			fprintf(pTxtFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i = 0; i < ll_len(pArrayListPassenger); i++) {
				if((pP = (Passenger*)ll_get(pArrayListPassenger, i)) != NULL) {
					if(!Passenger_getId(pP, &id) &&
					   !Passenger_getNombre(pP, name) &&
					   !Passenger_getApellido(pP, lastName) &&
					   !Passenger_getPrecio(pP, &price) &&
					   !Passenger_getTipoPasajero(pP, &typePassenger) &&
					   !Passenger_getCodigoVuelo(pP, flyCode) &&
					   !Passenger_getEstadoVuelo(pP, &flightStatus)) {
						switch(typePassenger) {
							case FIRST:
								strncpy(auxTypePassenger, "FirstClass", TYPE_LENGHT);
								break;
							case EXECUTIVE:
								strncpy(auxTypePassenger, "ExecutiveClass", TYPE_LENGHT);
								break;
							case ECONOMY:
								strncpy(auxTypePassenger, "EconomyClass", TYPE_LENGHT);
								break;
						}
						switch(flightStatus) {
							case AIRBORNE:
								strncpy(auxFlightStatus, "En Vuelo", FLIGHTSTATUS_LENGHT);
								break;
							case ONTIME:
								strncpy(auxFlightStatus, "En Horario", FLIGHTSTATUS_LENGHT);
								break;
							case DELAYED:
								strncpy(auxFlightStatus, "Demorado", FLIGHTSTATUS_LENGHT);
								break;
							case LANDED:
								strncpy(auxFlightStatus, "Aterrizado", FLIGHTSTATUS_LENGHT);
								break;
						}
						fprintf(pTxtFile, "%d,%s,%s,%d,%s,%s,%s\n", id, name, lastName, (int)price, auxTypePassenger, flyCode, auxFlightStatus);
					}
				}
			}
			fclose(pTxtFile);
			Return = 0;
		}
	}
	return Return;
}

/// @brief
///
/// @param path
/// @param pArrayListPassenger
/// @return
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) {
	int Return = -1;
	FILE* pBinFile = NULL;
	Passenger* pP = NULL;
	if(path != NULL && pArrayListPassenger != NULL) {
		if((pBinFile = fopen(path, "wb")) != NULL) {
			for(int i = 0; i < ll_len(pArrayListPassenger); i++) {
				if((pP = (Passenger*)ll_get(pArrayListPassenger, i)) != NULL) {
					fwrite(pP, sizeof(Passenger), 1, pBinFile);
				}
			}
			fclose(pBinFile);
			Return = 0;
		}
	}
	return Return;
}
