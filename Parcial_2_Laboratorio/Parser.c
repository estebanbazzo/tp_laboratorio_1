#include "Parser.h"


/// @brief
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger) {
	int Return = -1;
	char header[1024];
	char id[1024];
	char name[1024];
	char lastName[1024];
	char price[1024];
	char flyCode[1024];
	char typePassenger[1024];
	char flightStatus[1024];
	Passenger* pP = NULL;
	if(pFile != NULL && pArrayListPassenger != NULL) {
		fscanf(pFile, "%s", header);
		do {
			if(fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, name, lastName, price, flyCode, typePassenger, flightStatus) == 7) {
				if((pP = Passenger_newParametros(id, name, lastName, price, flyCode, typePassenger, flightStatus)) != NULL) {
					ll_add(pArrayListPassenger, pP);
				}
			}
		} while(!feof(pFile));
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param pFile
/// @param pArrayListPassenger
/// @return
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	int Return = -1;
	Passenger* pP = NULL;
	int id;
	char name[NAME_LENGHT];
	char lastName[LASTNAME_LENGHT];
	float price;
	int typePassenger;
	char flyCode[FLYCODE_LENGHT];
	int flightStatus;
	if(pFile != NULL && pArrayListPassenger != NULL) {
		do {
			if((pP = Passenger_new()) != NULL && fread(pP, sizeof(Passenger), 1, pFile) == 1) {
				if(!Passenger_getId(pP, &id) &&
				   !Passenger_getNombre(pP, name) &&
				   !Passenger_getApellido(pP, lastName) &&
				   !Passenger_getPrecio(pP, &price) &&
				   !Passenger_getTipoPasajero(pP, &typePassenger) &&
				   !Passenger_getCodigoVuelo(pP, flyCode) &&
				   !Passenger_getEstadoVuelo(pP, &flightStatus)) {
					ll_add(pArrayListPassenger, pP);
				}
			}
			else {
				Passenger_delete(pP);
			}
		} while(!feof(pFile));
		fclose(pFile);
		Return = 0;
	}
	return Return;
}
