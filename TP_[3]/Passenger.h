#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define NAME_LENGHT 51
#define LASTNAME_LENGHT 51
#define TYPE_LENGHT 15
#define FLYCODE_LENGHT 10
#define FLIGHTSTATUS_LENGHT 11
#define FIRST 10
#define EXECUTIVE 20
#define ECONOMY 30
#define AIRBORNE 100
#define ONTIME 200
#define DELAYED 300
#define LANDED 400

typedef struct {
	int id;
	char nombre[NAME_LENGHT];
	char apellido[LASTNAME_LENGHT];
	float precio;
	int tipoPasajero;
	char codigoVuelo[FLYCODE_LENGHT];
	int estadoVuelo;
} Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flyCodeStr, char* typePassengerStr, char* flightStatusStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this, char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);


int passenger_sortById(void* passenger1, void* passenger2);
int passenger_sortByName(void* passenger1, void* passenger2);
int passenger_sortByLastName(void* passenger1, void* passenger2);
int passenger_sortByTypePassenger(void* passenger1, void* passenger2);
int passenger_sortByPrice(void* passenger1, void* passenger2);
int passenger_sortByFlyCode(void* passenger1, void* passenger2);
int passenger_sortByFlightStatus(void* passenger1, void* passenger2);


#endif /* PASSENGER_H_ */
