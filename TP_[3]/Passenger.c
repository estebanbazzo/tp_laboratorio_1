#include "Passenger.h"


Passenger* Passenger_new() {
	Passenger* pP = NULL;
	if((pP = (Passenger*)malloc(sizeof(Passenger) *1)) != NULL) {
		pP->id = 0;
		strncpy(pP->nombre, "\0", NAME_LENGHT);
		strncpy(pP->apellido, "\0", LASTNAME_LENGHT);
		pP->precio = 0;
		pP->tipoPasajero = 0;
		strncpy(pP->codigoVuelo, "\0", FLYCODE_LENGHT);
		pP->estadoVuelo = 0;
	}
	return pP;
}

Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flyCodeStr, char* typePassengerStr, char* flightStatusStr) {
	Passenger* pP = NULL;
	Passenger* auxPP = NULL;
	int auxTypePassengerStr = 0;
	int auxFlightStatusStr = 0;
	if(idStr != NULL && nameStr != NULL && lastNameStr != NULL && priceStr != NULL && flyCodeStr != NULL && typePassengerStr != NULL && flightStatusStr != NULL) {
		if((auxPP = Passenger_new()) != NULL) {
			if(strcmp(typePassengerStr, "FirstClass") == 0) {
				auxTypePassengerStr = FIRST;
			}
			else if(strcmp(typePassengerStr, "ExecutiveClass") == 0) {
				auxTypePassengerStr = EXECUTIVE;
			}
			else if(strcmp(typePassengerStr, "EconomyClass") == 0) {
				auxTypePassengerStr = ECONOMY;
			}
			if(strcmp(flightStatusStr, "En Vuelo") == 0) {
				auxFlightStatusStr = AIRBORNE;
			}
			else if(strcmp(flightStatusStr, "En Horario") == 0) {
				auxFlightStatusStr = ONTIME;
			}
			else if(strcmp(flightStatusStr, "Demorado") == 0) {
				auxFlightStatusStr = DELAYED;
			}
			else if(strcmp(flightStatusStr, "Aterrizado") == 0) {
				auxFlightStatusStr = LANDED;
			}
			if(!Passenger_setId(auxPP, atoi(idStr)) &&
			   !Passenger_setNombre(auxPP, nameStr) &&
			   !Passenger_setApellido(auxPP, lastNameStr) &&
			   !Passenger_setPrecio(auxPP, atof(priceStr)) &&
			   !Passenger_setTipoPasajero(auxPP, auxTypePassengerStr) &&
			   !Passenger_setCodigoVuelo(auxPP, flyCodeStr) &&
			   !Passenger_setEstadoVuelo(auxPP, auxFlightStatusStr)) {
				pP = auxPP;
			}
			else {
				Passenger_delete(auxPP);
			}
		}
	}
	return pP;
}

void Passenger_delete(Passenger* this) {
	if(this != NULL) {
		free(this);
	}
}

int Passenger_setId(Passenger* this, int id) {
	int Return = -1;
	if(this != NULL && id > 0) {
		this->id = id;
		Return = 0;
	}
	return Return;
}

int Passenger_getId(Passenger* this, int* id) {
	int Return = -1;
	if(this != NULL && id != NULL) {
		*id = this->id;
		Return = 0;
	}
	return Return;
}

int Passenger_setNombre(Passenger* this, char* nombre) {
	int Return = -1;
	if(this != NULL && !isName(nombre, sizeof(nombre))) {
		strncpy(this->nombre, nombre, NAME_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_getNombre(Passenger* this, char* nombre) {
	int Return = -1;
	if(this != NULL && nombre != NULL) {
		strncpy(nombre, this->nombre, NAME_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_setApellido(Passenger* this, char* apellido) {
	int Return = -1;
	if(this != NULL && !isName(apellido, sizeof(apellido))) {
		strncpy(this->apellido, apellido, LASTNAME_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_getApellido(Passenger* this, char* apellido) {
	int Return = -1;
	if(this != NULL && apellido != NULL) {
		strncpy(apellido, this->apellido, LASTNAME_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo) {
	int Return = -1;
	if(this != NULL && !isCode(codigoVuelo, sizeof(codigoVuelo))) {
		strncpy(this->codigoVuelo, codigoVuelo, FLYCODE_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo) {
	int Return = -1;
	if(this != NULL && codigoVuelo != NULL) {
		strncpy(codigoVuelo, this->codigoVuelo, FLYCODE_LENGHT);
		Return = 0;
	}
	return Return;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero) {
	int Return = -1;
	if(this != NULL && tipoPasajero > 0) {
		this->tipoPasajero = tipoPasajero;
		Return = 0;
	}
	return Return;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero) {
	int Return = -1;
	if(this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		Return = 0;
	}
	return Return;
}

int Passenger_setPrecio(Passenger* this, float precio) {
	int Return = -1;
	if(this != NULL && precio > 0) {
		this->precio = precio;
		Return = 0;
	}
	return Return;
}

int Passenger_getPrecio(Passenger* this, float* precio) {
	int Return = -1;
	if(this != NULL && precio != NULL) {
		*precio = this->precio;
		Return = 0;
	}
	return Return;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo) {
	int Return = -1;
	if(this != NULL && estadoVuelo >= AIRBORNE) {
		this->estadoVuelo = estadoVuelo;
		Return = 0;
	}
	return Return;
}

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo) {
	int Return = -1;
	if(this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		Return = 0;
	}
	return Return;
}


int passenger_sortById(void* passenger1, void* passenger2) {
	int Return;
	Passenger* pP1;
	Passenger* pP2;
	int id1;
	int id2;
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getId(pP1, &id1);
		Passenger_getId(pP2, &id2);
		if(id1 > id2) {
			Return = 1;
		}
		else if(id1 < id2) {
			Return = -1;
		}
	}
	return Return;
}

int passenger_sortByName(void* passenger1, void* passenger2) {
	int Return = -1;
	Passenger* pP1;
	Passenger* pP2;
	char name1[NAME_LENGHT];
	char name2[NAME_LENGHT];
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getNombre(pP1, name1);
		Passenger_getNombre(pP2, name2);
		Return = strcmp(name1, name2);
	}
	return Return;
}

int passenger_sortByLastName(void* passenger1, void* passenger2) {
	int Return = -1;
	Passenger* pP1;
	Passenger* pP2;
	char lastName1[LASTNAME_LENGHT];
	char lastName2[LASTNAME_LENGHT];
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getApellido(pP1, lastName1);
		Passenger_getApellido(pP2, lastName2);
		Return = strcmp(lastName1, lastName2);
	}
	return Return;
}

int passenger_sortByTypePassenger(void* passenger1, void* passenger2) {
	int Return;
	Passenger* pP1;
	Passenger* pP2;
	int typePassenger1;
	int typePassenger2;
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getTipoPasajero(pP1, &typePassenger1);
		Passenger_getTipoPasajero(pP2, &typePassenger2);
		if(typePassenger1 > typePassenger2) {
			Return = 1;
		}
		else if(typePassenger1 < typePassenger2) {
			Return = -1;
		}
	}
	return Return;
}

int passenger_sortByPrice(void* passenger1, void* passenger2) {
	int Return;
	Passenger* pP1;
	Passenger* pP2;
	float price1;
	float price2;
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getPrecio(pP1, &price1);
		Passenger_getPrecio(pP2, &price2);
		if(price1 > price2) {
			Return = 1;
		}
		else if(price1 < price2) {
			Return = -1;
		}
	}
	return Return;
}

int passenger_sortByFlyCode(void* passenger1, void* passenger2) {
	int Return = -1;
	Passenger* pP1;
	Passenger* pP2;
	char flyCode1[FLYCODE_LENGHT];
	char flyCode2[FLYCODE_LENGHT];
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getCodigoVuelo(pP1, flyCode1);
		Passenger_getCodigoVuelo(pP2, flyCode2);
		Return = strcmp(flyCode1, flyCode2);
	}
	return Return;
}

int passenger_sortByFlightStatus(void* passenger1, void* passenger2) {
	int Return;
	Passenger* pP1;
	Passenger* pP2;
	int flightStatus1;
	int flightStatus2;
	if(passenger1 != NULL && passenger2 != NULL) {
		pP1 = (Passenger*)passenger1;
		pP2 = (Passenger*)passenger2;
		Passenger_getEstadoVuelo(pP1, &flightStatus1);
		Passenger_getEstadoVuelo(pP2, &flightStatus2);
		if(flightStatus1 > flightStatus2) {
			Return = 1;
		}
		else if(flightStatus1 < flightStatus2) {
			Return = -1;
		}
	}
	return Return;
}
