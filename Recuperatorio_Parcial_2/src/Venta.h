#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"

#ifndef VENTA_H_
#define VENTA_H_
#define VARIABLES_QUANTITY 6
#define NOMBREPELICULA_LENGHT 37
#define DIA_LENGHT 10
#define HORARIO_LENGHT 6
#define DOMINGO 6
#define LUNES 1
#define MARTES 2
#define MIERCOLES 3
#define JUEVES 4
#define VIERNES 5
#define SABADO 6


struct Venta {
	int id_venta;
	char nombre_pelicula[NOMBREPELICULA_LENGHT];
	int dia;
	char horario[HORARIO_LENGHT];
	int sala;
	int cantidad_entradas;
} typedef Venta;

Venta* venta_new(void);
Venta* venta_newParameters(char* id_venta, char* nombre_pelicula, char* dia, char* horario, char* sala, char* cantidad_entradas);
void venta_delete(Venta* this);

int venta_setId(Venta* this, int id_venta);
int venta_getId(Venta* this, int* id_venta);
int venta_setNombre(Venta* this, char* nombre_pelicula);
int venta_getNombre(Venta* this, char* nombre_pelicula);
int venta_setDia(Venta* this, int dia);
int venta_getDia(Venta* this, int* dia);
int venta_setHorario(Venta* this, char* horario);
int venta_getHorario(Venta* this, char* horario);
int venta_setSala(Venta* this, int sala);
int venta_getSala(Venta* this, int* sala);
int venta_setEntradas(Venta* this, int cantidad_entradas);
int venta_getEntradas(Venta* this, int* cantidad_entradas);

int venta_sala1(void* element);
int venta_sala2(void* element);
int venta_sala3(void* element);
int venta_sala4(void* element);
int venta_sala5(void* element);


#endif /* VENTA_H_ */
