#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Controller.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Parser.h"

#define BIN_FILE "data.bin"
#define CSV_FILE "data.csv"


int main(void) {
	setbuf(stdout, NULL);

	int Return = -1;
	int option;
	int flagLoadedFile = FALSE;
	int flagLoadedPassenger = FALSE;
	int flagSavedFile = TRUE;
	LinkedList* passengers = ll_newLinkedList();

	printf("Bienvenidx al Administrador de Pasajeros de la Aerolínea\n");

	do {
		if(!utn_getInt(&option, "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)\n3. Alta de pasajero\n4. Modificación de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n10. Salir del programa\n\nIngrese una opción del menú principal: ", "\nError: la opción ingresada es inválida", 1, 10, -1)) {
			switch(option) {
			case 1:
				if(flagLoadedFile == FALSE) {
					if(!controller_loadFromText(CSV_FILE, passengers)) {
						flagLoadedFile = TRUE;
						flagSavedFile = FALSE;
						printf("\nArchivo data.csv cargado correctamente. ");
						utn_anyKey("para continuar");
					}
					else {
						printf("\nError: el archivo data.csv no existe o no pudo cargarse. ");
						utn_anyKey("para continuar");
					}
				}
				else {
					printf("\nError: los datos de los pasajeros ya fueron cargados desde el archivo data.csv. ");
					utn_anyKey("para continuar");
				}
				break;

			case 2:
				if(flagLoadedFile == FALSE) {
					if(!controller_loadFromBinary(BIN_FILE, passengers)) {
						flagLoadedFile = TRUE;
						flagSavedFile = FALSE;
						printf("\nArchivo data.bin cargado correctamente. ");
						utn_anyKey("para continuar");
					}
					else {
						printf("\nError: el archivo data.bin no existe o no pudo cargarse. ");
						utn_anyKey("para continuar");
					}
				}
				else {
					printf("\nError: los datos de los pasajeros ya fueron cargados desde el archivo data.csv. ");
					utn_anyKey("para continuar");
				}
				break;

			case 3:
				if(passengers != NULL) {
					controller_addPassenger(passengers);
					flagLoadedPassenger = TRUE;
					flagSavedFile = FALSE;
					printf("\n");
					utn_anyKey("para continuar");
				}
				break;

			case 4:
				if(passengers != NULL && !ll_isEmpty(passengers)) {
					controller_editPassenger(passengers);
					printf("\n");
					utn_anyKey("para continuar");
				}
				break;

			case 5:
				if(passengers != NULL && !ll_isEmpty(passengers)) {
					controller_removePassenger(passengers);
					printf("\n");
					utn_anyKey("para continuar");
				}
				break;

			case 6:
				if(passengers != NULL && (flagLoadedFile == TRUE || flagLoadedPassenger == TRUE)) {
					controller_ListPassenger(passengers);
					printf("\n");
					utn_anyKey("para continuar");
				}
				else {
					printf("\nError: debe correr la opción 1, 2 o 3 primero. ");
					utn_anyKey("para continuar");
				}
				break;

			case 7:
				if(passengers != NULL && (flagLoadedFile == TRUE || flagLoadedPassenger == TRUE) && !ll_isEmpty(passengers)) {
					controller_sortPassenger(passengers);
					printf("\n");
					utn_anyKey("para continuar");
				}
				break;

			case 8:
				if(passengers != NULL && (flagLoadedFile == TRUE || flagLoadedPassenger == TRUE)) {
					if(!controller_saveAsText(CSV_FILE, passengers)) {
						controller_saveAsBinary(BIN_FILE, passengers);
						flagSavedFile = TRUE;
						printf("\nArchivo data.csv creado correctamente. ");
						utn_anyKey("para continuar");
					}
					else {
						printf("\nError: el archivo data.csv no pudo crearse. ");
						utn_anyKey("para continuar");
					}
				}
				else {
					printf("\nError: debe correr la opción 1, 2 o 3 primero. ");
					utn_anyKey("para continuar");
				}
				break;

			case 9:
				if(passengers != NULL && (flagLoadedFile == TRUE || flagLoadedPassenger == TRUE)) {
					if(!controller_saveAsBinary(BIN_FILE, passengers)) {
						controller_saveAsText(CSV_FILE, passengers);
						flagSavedFile = TRUE;
						printf("\nArchivo data.bin creado correctamente. ");
						utn_anyKey("para continuar");
					}
					else {
						printf("\nError: el archivo data.bin no pudo crearse. ");
						utn_anyKey("para continuar");
					}
				}
				else {
					printf("\nError: debe correr la opción 1, 2 o 3 primero. ");
					utn_anyKey("para continuar");
				}
				break;

			case 10:
				if(flagSavedFile == FALSE) {
					option = -1;
					printf("\nDebe guardar los cambios antes de salir del programa. ");
					utn_anyKey("para continuar");
				}
				else {
					printf("\nGracias por usar el Administrador de Pasajeros de la Aerolínea");
					Return = 0;
					break;
				}
			}
		}
	} while(option != 10);

	return Return;
}
