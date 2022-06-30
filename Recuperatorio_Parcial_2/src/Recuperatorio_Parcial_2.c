#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Venta.h"

#define DATAPARCIALCINE_FILE "DataParcialCine.csv"
#define DATAFINALCINE_FILE "DataFinalCine.csv"


void mainMenu(void);


int main(void) {
	setbuf(stdout, NULL);
	int auxReturn = -1;
	LinkedList* ventas = NULL;
	int mainMenuOption;
	int flagLoadedFile = FALSE;
	int flagSavedFile = TRUE;

	if((ventas = ll_new()) != NULL) {
		do {
			MAINMENU:
			mainMenu();
			if(!utn_getInt(&mainMenuOption, "\nIngrese una opción del menú principal: ", "\nError: la opción ingresada es inválida", 1, 5, -1)) {
				switch(mainMenuOption) {
				case 1:
					if(flagLoadedFile == FALSE) {
						if(!controller_loadText(DATAPARCIALCINE_FILE, ventas)) {
							flagLoadedFile = TRUE;
							flagSavedFile = FALSE;
							printf("\nEl archivo DataParcialCine.csv se cargó correctamente. ");
							utn_anyKey("para continuar");
						}
						else {
							utn_err("el archivo DataParcialCine.csv no existe o no pudo cargarse", "para continuar");
						}
					}
					else {
						utn_err("el archivo DataParcialCine.csv ya fue cargado", "para continuar");
					}
					break;

				case 2:
					if(ll_isEmpty(ventas) == FALSE) {
						if(!controller_list(ventas)) {
							utn_anyKey("para continuar");
						}
						else {
							utn_err("la función controller_list falló", "para continuar");
						}
					}
					else if(ll_isEmpty(ventas) == TRUE) {
						utn_err("la lista de ventas está vacía", "para continuar");
					}
					break;

				case 3:
					if(flagSavedFile == FALSE) {
						if(!controller_saveText(DATAFINALCINE_FILE, ventas)) {
							flagSavedFile = TRUE;
							printf("\nEl archivo DataFinalCine.csv se guardó correctamente. ");
							utn_anyKey("para continuar");
						}
						else {
							utn_err("el archivo DataFinalCine.csv no pudo guardarse", "para continuar");
						}
					}
					else {
						utn_err("el archivo DataFinalCine.csv ya fue guardado", "para continuar");
					}
					break;

				case 4:
					if(ll_isEmpty(ventas) == FALSE) {
						if(!controller_report(ventas)) {
							utn_anyKey("para continuar");
						}
						else {
							utn_err("la función controller_report falló", "para continuar");
						}
					}
					else if(ll_isEmpty(ventas) == TRUE) {
						utn_err("la lista de ventas está vacía", "para continuar");
					}
					break;

				case 5:
					if(flagSavedFile == TRUE) {
						if(!ll_delete(ventas)) {
							auxReturn = EXIT_SUCCESS;
						}
						else {
							utn_err("la función ll_delete falló", "para continuar");
						}
					}
					else {
						utn_err("debe guardar la lista de facturación en un archivo antes de salir del programa", "para continuar");
						goto MAINMENU;
					}
					break;
				}
			}
		} while(mainMenuOption != 5);
	}

	return auxReturn;
}

void mainMenu(void) {
	printf("\n_________________________________________________________________________________/ MENÚ PRINCIPAL"
		   "\n\n1. Cargar archivo"
		   "\n2. Imprimir ventas"
		   "\n3. Generar archivo de montos"
		   "\n4. Informes"
		   "\n5. Salir del programa"
		   "\n_________________________________________________________________________________________________\n");
}
