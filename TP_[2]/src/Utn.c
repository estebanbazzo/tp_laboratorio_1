/*********************************************************************
 * Biblioteca  : Utn.c
 * Autor       : Esteban Bazzo (DNI 37.066.587)
 * Año         : 1°
 * División    : E
 * Turno       : noche
 * Materia     : Laboratorio de Computación I
 * Profesores  : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha       : 1° cuatrimestre de 2022
 * Descripción : Biblioteca general de Laboratorio de Computación I
 *               UTN-FRA Tecnicatura Universitaria en Programación
*********************************************************************/
#include "Utn.h"

static int auxGetInt(int *entry);
static int auxGetFloat(float *entry);
static int getString(char *entry, int lenght);
static int isInt(char *string, int lenght);
static int isFloat(char *string, int lenght);

static int auxGetWords(char *entry, int lenght);
static int isWords(char *string, int lenght);
static int auxGetCode(char *entry, int lenght);
static int isCode(char *string, int lenght);

/// @brief
///
void pW2MainMenu(void) {
	printf("\n________________________________________________________________/ MENÚ PRINCIPAL\n"
		   "\n1. ALTA de pasajero"
		   "\n2. MODIFICACIÓN de pasajero"
		   "\n3. BAJA de pasajero"
		   "\n4. Imprimir INFORMES"
		   "\n5. Carga forzada"
		   "\n6. Salir del programa"
		   "\n________________________________________________________________________________\n");
}

void pW2SubMenu2(Passenger *list1, Flight *list2, int lenght, int index) {
	if(list1 != NULL && list2 != NULL && lenght > 0 && index >= 0) {
		printf("\n_____________________________/ menú principal > SUBMENÚ MODIFICACIÓN DE PASAJERO\n");
		printf("\n1. Modificar el nombre: %s", list1[index].name);
		printf("\n2. Modificar el apellido: %s", list1[index].lastName);
		printf("\n3. Modificar el tipo: ");

		if(list1[index].typePassenger == 1) {
			printf("PRIMERA");
		}
		else if(list1[index].typePassenger == 2) {
			printf("EJECUTIVA");
		}
		else if(list1[index].typePassenger == 3) {
			printf("TURISTA PREMIUM");
		}
		else if(list1[index].typePassenger == 4) {
			printf("TURISTA");
		}

		printf("\n4. Modificar el precio del vuelo: $%.2f", list1[index].price);
		printf("\n5. Modificar el código del vuelo: %s", list1[index].flyCode);

		for(int i = 0; i < lenght; i++) {
			if(strcmp(list1[index].flyCode, list2[i].flyCode) == 0) {
				printf("\n   - Estado del vuelo: ");

				if(list2[i].flightStatus == 1) {
					printf("ACTIVO\n");
				}
				else if(list2[i].flightStatus == 2) {
					printf("DEMORADO\n");
				}
				else if(list2[i].flightStatus == 3) {
					printf("CANCELADO\n");
				}

				break;
			}
		}

		printf("6. Volver al Menú principal"
			   "\n________________________________________________________________________________\n");
	}
}

void pW2SubMenu4(void) {
	printf("\n____________________________________/ menú principal > SUBMENÚ IMPRIMIR INFORMES\n"
		   "\n1. Listado de pasajeros ordenados alfabéticamente por su apellido y tipo"
		   "\n2. Total y promedio de los precios de vuelos y cantidad de pasajeros que lo superan"
		   "\n3. Listado de pasajeros con vuelos activos ordenados por código de vuelo"
		   "\n4. Volver al menú principal"
		   "\n________________________________________________________________________________\n");
}

void pW2SubMenu41() {
	printf("\n_____________________/ menú principal > submenú imprimir informes > ELEGIR ORDEN\n"
		   "\n1. Orden ascendente"
		   "\n2. Orden descendente"
		   "\n3. Volver al submenú Imprimir Informes"
		   "\n________________________________________________________________________________\n");
}

/// @brief
///
/// @param message
void pressAnyKey(char *message) {
	char anyKey;

	if(message != NULL) {
		printf("\nPresione cualquier tecla %s", message);
		fflush(stdin);
		scanf("%c", &anyKey);
	}
}

/// @brief
///
/// @param errorMessage
/// @param anyKeyMessage
void error(char *errorMessage, char *anyKeyMessage) {
	if(errorMessage != NULL && anyKeyMessage != NULL) {
		printf("\n%s", errorMessage);
		pressAnyKey(anyKeyMessage);
	}
}


/// @brief
///
/// @param entry
/// @param message
/// @param errorMessage
/// @param minimum
/// @param maximum
/// @param attempts
/// @return
int getInt(int *entry, char *message, char *errorMessage, int minimum, int maximum, int attempts) {
	int Return = -1;
	int auxEntry;

	if(entry != NULL && message != NULL && errorMessage != NULL && (minimum == -1 || minimum <= maximum || maximum == -1) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetInt(&auxEntry) == 0 && ((minimum == -1 && auxEntry <= maximum) || (maximum == -1 && auxEntry >= minimum) || (auxEntry >= minimum && auxEntry <= maximum))) {
				*entry = auxEntry;
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @return
static int auxGetInt(int *entry) {
	int Return = -1;
	char auxEntry[64];

	if(entry != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isInt(auxEntry, sizeof(auxEntry))) {
		*entry = atoi(auxEntry);
		Return = 0;
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isInt(char *string, int lenght) {
	int Return = -1;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if(i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if(string[i] < '0' || string[i] > '9') {
				Return = 0;
				break;
			}
		}
	}

	return Return;
}

/// @brief
///
/// @param entry
/// @param message
/// @param errorMessage
/// @param minimum
/// @param maximum
/// @param attempts
/// @return
int getFloat(float *entry, char *message, char *errorMessage, float minimum, float maximum, int attempts) {
	int Return = -1;
	float auxEntry;

	if(entry != NULL && message != NULL && errorMessage != NULL && (minimum == -1 || minimum <= maximum || maximum == -1) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetFloat(&auxEntry) == 0 && ((minimum == -1 && auxEntry <= maximum) || (maximum == -1 && auxEntry >= minimum) || (auxEntry >= minimum && auxEntry <= maximum))) {
				*entry = auxEntry;
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @return
static int auxGetFloat(float *entry) {
	int Return = -1;
	char auxEntry[64];

	if(entry != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isFloat(auxEntry, sizeof(auxEntry))) {
		*entry = atof(auxEntry);
		Return = 0;
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isFloat(char *string, int lenght) {
	int Return = -1;
	int flagPoint = FALSE;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if(i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if(string[i] < '0' || string[i] > '9' ) {
				if(string[i] == '.' && flagPoint == FALSE) {
					flagPoint = TRUE;
				}
				else {
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
/// @param entry
/// @param lenght
/// @return
static int getString(char *entry, int lenght) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0) {
		fflush(stdin);

		if(fgets(auxEntry, sizeof(auxEntry), stdin) != NULL) {
			if(auxEntry[strnlen(auxEntry, sizeof(auxEntry)) - 1] == '\n') {
				auxEntry[strnlen(auxEntry, sizeof(auxEntry)) - 1] = '\0';
			}
			if(strnlen(auxEntry, sizeof(auxEntry)) <= lenght) {
				strncpy(entry, auxEntry, lenght);
				Return = 0;
			}
		}
	}

	return Return;
}


/// @brief
///
/// @param entry
/// @param lenght
/// @param message
/// @param errorMessage
/// @param attempts
/// @return
int getWords(char *entry, int lenght, char *message, char *errorMessage, int attempts) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0 && message != NULL && errorMessage != NULL && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetWords(auxEntry, sizeof(auxEntry)) == 0 && strnlen(auxEntry, sizeof(auxEntry)) < lenght) {
				strncpy(entry, auxEntry, lenght);
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int auxGetWords(char *entry, int lenght) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && getString(auxEntry, sizeof(auxEntry)) == 0 && isWords(auxEntry, sizeof(auxEntry)) && strnlen(auxEntry, sizeof(auxEntry)) < lenght) {
		strncpy(entry, auxEntry, lenght);
		Return = 0;
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isWords(char *string, int lenght) {
	int Return = -1;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && string[i] != ' ') {
				Return = 0;
				break;
			}
		}
	}

	return Return;
}

/// @brief
///
/// @param entry
/// @param lenght
/// @param message
/// @param errorMessage
/// @param attempts
/// @return
int getCode(char entry[], int lenght, char *message, char *errorMessage, int attempts) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0 && message != NULL && errorMessage != NULL && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);

			if(auxGetCode(auxEntry, sizeof(auxEntry)) == 0 && strnlen(auxEntry, sizeof(auxEntry)) < lenght) {
				strncpy(entry, auxEntry, lenght);
				Return = 0;
				break;
			}
			else {
				printf("\n%s", errorMessage);

				if(attempts == 0) {
					break;
				}
				else if(attempts != -1) {
					attempts--;
				}
			}
		} while(attempts == -1 || attempts > 0);
	}

	return Return;
}
/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int auxGetCode(char *entry, int lenght) {
	int Return = -1;
	char auxEntry[4096];

	if(entry != NULL && lenght > 0) {
		if(getString(auxEntry, sizeof(auxEntry)) == 0 && isCode(auxEntry, sizeof(auxEntry)) && strnlen(auxEntry, sizeof(auxEntry)) < lenght) {
			strncpy(entry, auxEntry, lenght);
			Return = 0;
		}
	}

	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
static int isCode(char *string, int lenght) {
	int Return = -1;

	if(string != NULL && lenght > 0) {
		Return = 1;

		for(int i = 0; i < lenght && string[i] != '\0'; i++) {
			if((string[i] < '0' || string[i] > '9' ) && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z')) {
				Return = 0;
				break;
			}
		}
	}

	return Return;
}


/// @brief
///
/// @param result
/// @param number
/// @param numberSubtracted
/// @return
int calcSubtrac(float *result, float number, float numberSubtracted) {
	int Return = -1;

	if(result != NULL && numberSubtracted != 0) {
		*result = number - numberSubtracted;
		Return = 0;
	}

	return Return;
}

/// @brief
///
/// @param result
/// @param dividend
/// @param divider
/// @return
int calcDiv(float *result, float dividend, float divisor) {
	int Return = -1;

	if(result != NULL && divisor != 0) {
		*result = dividend / divisor;
		Return = 0;
	}

	return Return;
}

/// @brief
///
/// @param result
/// @param number
/// @param percentage
/// @return
int calcPercent(float *result, float number, float percentage) {
	int Return = -1;

	if(result != NULL && percentage != 0) {
		*result = number + (number * percentage / 100);
		Return = 0;
	}

	return Return;
}
