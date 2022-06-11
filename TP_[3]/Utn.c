/**********************************************************************
 * Biblioteca   : Utn.c
 * Versión      : 3.0
 * Autor        : Esteban Bazzo (DNI 37066587)
 * Año          : 1
 * División     : E
 * Turno        : noche
 * Materia      : Laboratorio de Computación I
 * Profesores   : Gaston Argibay y Camila Iglesias Guerrero
 * Fecha        : 1° cuatrimestre de 2022
 * Descripción  : biblioteca general de Laboratorio de Computación I
                  UTN-FRA  Tecnicatura Universitaria en Programación
**********************************************************************/
#include "Utn.h"


static int getString(char* entry, int lenght);

static int auxGetInt(int* auxEntry);
static int auxGetFloat(float* auxEntry);
static int auxGetIden(char* auxEntry, int lenght);
static int auxGetName(char* auxEntry, int lenght);
static int auxGetCode(char* auxEntry, int lenght);
static int auxGetText(char* auxEntry, int lenght);


/// @brief
///
/// @param message
void utn_anyKey(char* message) {
	char aux;
	if(message != NULL) {
		printf("Presione cualquier tecla %s", message);
		fflush(stdin);  /* for Windows */
//		__fpurge(stdin);  /* for Linux */
		scanf("%c", &aux);
	}
}

/// @brief
///
/// @param errorMessage
/// @param anyKeyMessage
void utn_err(char* errorMessage, char* anyKeyMessage) {
	if(errorMessage != NULL && anyKeyMessage != NULL) {
		printf("\nError: %s. ", errorMessage);
		utn_anyKey(anyKeyMessage);
	}
}


/// @brief
///
/// @param entry
/// @param lenght
/// @return
static int getString(char* entry, int lenght) {
	int Return = -1;
	char buffer[1024];
	if(entry != NULL && lenght > 0) {
		fflush(stdin);  /* for Windows */
//		__fpurge(stdin);  /* for Linux */
		if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
			if(buffer[strnlen(buffer, sizeof(buffer)) -1] == '\n') {
				buffer[strnlen(buffer, sizeof(buffer)) -1] = '\0';
			}
			if(strnlen(buffer, sizeof(buffer)) <= lenght) {
				strncpy(entry, buffer, lenght);
				Return = 0;
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
int utn_getInt(int* entry, char* message, char* errorMessage, int minimum, int maximum, int attempts) {
	int Return = -1;
	int aux;
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   (minimum == -1 || maximum == -1 || minimum <= maximum) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetInt(&aux) &&
			   ((minimum == -1 && aux <= maximum) || (maximum == -1 && aux >= minimum) || (aux >= minimum && aux <= maximum))) {
				*entry = aux;
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @return
static int auxGetInt(int* auxEntry) {
	int Return = -1;
	char buffer[11];
	if(auxEntry != NULL &&
	   !getString(buffer, sizeof(buffer)) && !isInt(buffer, sizeof(buffer))) {
		*auxEntry = atoi(buffer);
		Return = 0;
	}
	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
int isInt(char* string, int lenght) {
	int Return = -1;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if(i == 0 && (*(string +i) == '-' || *(string +i) == '+')) {
				continue;
			}
			if(*(string +i) < '0' || *(string +i) > '9') {
				Return = -1;
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
int utn_getFloat(float* entry, char* message, char* errorMessage, float minimum, float maximum, int attempts) {
	int Return = -1;
	float aux;
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   (minimum == -1 || maximum == -1 || minimum <= maximum) && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetFloat(&aux) &&
			   ((minimum == -1 && aux <= maximum) || (maximum == -1 && aux >= minimum) || (aux >= minimum && aux <= maximum))) {
				*entry = aux;
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @return
static int auxGetFloat(float* auxEntry) {
	int Return = -1;
	char buffer[21];
	if(auxEntry != NULL &&
	   !getString(buffer, sizeof(buffer)) && !isFloat(buffer, sizeof(buffer))) {
		*auxEntry = atof(buffer);
		Return = 0;
	}
	return Return;
}
/// @brief
///
/// @param string
/// @param lenght
/// @return
int isFloat(char* string, int lenght) {
	int Return = -1;
	int theresPoint = FALSE;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if(i == 0 && (*(string +i) == '-' || *(string +i) == '+')) {
				continue;
			}
			if(*(string +i) < '0' || *(string +i) > '9') {
				if(*(string +i) == '.' && theresPoint == FALSE) {
					theresPoint = TRUE;
				}
				else {
					Return = -1;
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
/// @param message
/// @param errorMessage
/// @param attempts
/// @return
int utn_getIden(char* entry, int lenght, char* message, char* errorMessage, int attempts) {
	int Return = -1;
	char aux[16];
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   lenght > 0 && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetIden(aux, sizeof(aux)) && strnlen(aux, sizeof(aux)) <= lenght) {
				strncpy(entry, aux, lenght);
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @param lenght
/// @return
static int auxGetIden(char* auxEntry, int lenght) {
	int Return = -1;
	char buffer[16];
	if(auxEntry != NULL && lenght > 0) {
		if(!getString(buffer, sizeof(buffer)) && !isIden(buffer, sizeof(buffer)) &&
		   strnlen(buffer, sizeof(buffer)) <= lenght) {
			strncpy(auxEntry, buffer, lenght);
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
int isIden(char* string, int lenght) {
	int Return = -1;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if((*(string +i) < '0' || *(string +i) > '9') &&
			   *(string +i) != '.' && *(string +i) != '-') {
				Return = -1;
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
int utn_getName(char* entry, int lenght, char* message, char* errorMessage, int attempts) {
	int Return = -1;
	char aux[512];
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   lenght > 0 && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetName(aux, sizeof(aux)) && strnlen(aux, sizeof(aux)) <= lenght) {
				strncpy(entry, aux, lenght);
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @param lenght
/// @return
static int auxGetName(char* auxEntry, int lenght) {
	int Return = -1;
	char buffer[512];
	if(auxEntry != NULL && lenght > 0) {
		if(!getString(buffer, sizeof(buffer)) && !isName(buffer, sizeof(buffer)) &&
		   strnlen(buffer, sizeof(buffer)) <= lenght) {
			strncpy(auxEntry, buffer, lenght);
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
int isName(char* string, int lenght) {
	int Return = -1;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if((*(string +i) < 'A' || *(string +i) > 'Z') && (*(string +i) < 'a' || *(string +i) > 'z') &&
			   *(string +i) != ' ') {
				Return = -1;
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
int utn_getCode(char* entry, int lenght, char* message, char* errorMessage, int attempts) {
	int Return = -1;
	char aux[10];
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   lenght > 0 && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetCode(aux, sizeof(aux)) && strnlen(aux, sizeof(aux)) <= lenght) {
				strncpy(entry, aux, lenght);
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @param lenght
/// @return
static int auxGetCode(char* auxEntry, int lenght) {
	int Return = -1;
	char buffer[10];
	if(auxEntry != NULL && lenght > 0) {
		if(!getString(buffer, sizeof(buffer)) && !isCode(buffer, sizeof(buffer)) &&
		   strnlen(buffer, sizeof(buffer)) <= lenght) {
			strncpy(auxEntry, buffer, lenght);
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
int isCode(char* string, int lenght) {
	int Return = -1;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if((*(string +i) < 'A' || *(string +i) > 'Z') && (*(string +i) < 'a' || *(string +i) > 'z') &&
			   (*(string +i) < '0' || *(string +i) > '9')) {
				Return = -1;
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
int utn_getText(char* entry, int lenght, char* message, char* errorMessage, int attempts) {
	int Return = -1;
	char aux[1024];
	if(entry != NULL && message != NULL && errorMessage != NULL &&
	   lenght > 0 && (attempts == -1 || attempts > 0)) {
		do {
			printf("%s", message);
			if(!auxGetText(aux, sizeof(aux)) && strnlen(aux, sizeof(aux)) <= lenght) {
				strncpy(entry, aux, lenght);
				Return = 0;
				break;
			}
			printf("%s", errorMessage);
			if(attempts == 0) {
				break;
			}
			if(attempts != -1) {
				attempts--;
			}
		} while(attempts == -1 || attempts > 0);
	}
	return Return;
}
/// @brief
///
/// @param auxEntry
/// @param lenght
/// @return
static int auxGetText(char* auxEntry, int lenght) {
	int Return = -1;
	char buffer[1024];
	if(auxEntry != NULL && lenght > 0) {
		if(!getString(buffer, sizeof(buffer)) && !isText(buffer, sizeof(buffer)) &&
		   strnlen(buffer, sizeof(buffer)) <= lenght) {
			strncpy(auxEntry, buffer, lenght);
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
int isText(char* string, int lenght) {
	int Return = -1;
	if(string != NULL && lenght > 0) {
		Return = 0;
		for(int i = 0; i < lenght && *(string +i) != '\0'; i++) {
			if(*(string +i) < ' ' || *(string +i) > '~') {
				Return = -1;
				break;
			}
		}
	}
	return Return;
}


/// @brief
///
/// @param sum
/// @param addend1
/// @param addend2
/// @return
int utn_calcAdd(float* sum, float* addend1, float* addend2) {
	int Return = -1;
	if(sum != NULL && addend1 != NULL && addend2 != NULL) {
		*sum = *addend1 + *addend2;
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param difference
/// @param minuend
/// @param subtrahend
/// @return
int utn_calcSub(float* difference, float* minuend, float* subtrahend) {
	int Return = -1;
	if(difference != NULL && minuend != NULL && subtrahend != NULL) {
		*difference = *minuend - *subtrahend;
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param product
/// @param multiplicand
/// @param multiplier
/// @return
int utn_calcMul(float* product, float* multiplicand, float* multiplier) {
	int Return = -1;
	if(product != NULL && multiplicand != NULL && multiplier != NULL) {
		*product = *multiplicand * *multiplier;
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param quotient
/// @param remainder
/// @param dividend
/// @param divisor
/// @return
int utn_calcDiv(float* quotient, int* remainder, float* dividend, float* divisor) {
	int Return = -1;
	if(quotient != NULL && remainder != NULL && dividend != NULL && divisor != NULL && *divisor != 0) {
		*quotient = *dividend / *divisor;
		*remainder = (int)*dividend % (int)*divisor;
		Return = 0;
	}
	return Return;
}

/// @brief
///
/// @param part
/// @param percentage
/// @param whole
/// @return
int utn_calcPer(float* part, float* percentage, float* whole) {
	int Return = -1;
	if(part != NULL && percentage != NULL && whole != NULL) {
		*part = *whole * *percentage / 100;
		Return = 0;
	}
	return Return;
}
