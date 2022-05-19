#include "Censista.h"

/// @brief
///
/// @param censistas
/// @param largo
/// @return
int initCensistas(Censista *censistas, int largo) {
	int retorno = -1;
	if(censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			censistas[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


/// @brief
///
/// @return
int setId(void) {
	static int auxId = 0;
	auxId++;
	printf("\nID asignado: %d", auxId);
	return auxId;
}


/// @brief
///
/// @param censistas
/// @param largo
/// @param id
/// @param nombre
/// @param apellido
/// @param dia
/// @param mes
/// @param anio
/// @param edad
/// @param calle
/// @param altura
/// @return
int addCensista(Censista *censistas, int largo, int id, char nombre[], char apellido[], int dia, int mes, int anio, int edad, char calle[], int altura) {
	int retorno = -1;
	if(censistas != NULL && largo > 0 && id > 0 && nombre != NULL && apellido != NULL && dia > 0 && mes > 0 && anio > 0 && edad > 0 && calle != NULL && altura > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == TRUE) {
				censistas[i].idCensista = id;
				strncpy(censistas[i].nombre, nombre, sizeof(censistas[i].nombre));
				strncpy(censistas[i].apellido, apellido, sizeof(censistas[i].apellido));
				censistas[i].nacimiento.dia = dia;
				censistas[i].nacimiento.mes = mes;
				censistas[i].nacimiento.anio = anio;
				censistas[i].edad = edad;
				strncpy(censistas[i].domicilio.calle, calle, sizeof(censistas[i].domicilio.calle));
				censistas[i].domicilio.altura = altura;
				censistas[i].estadoCensista = LIBERADO;
				censistas[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param censistas
/// @param largo
/// @return
int hayCensistas(Censista *censistas, int largo) {
	int retorno = -1;
	if(censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param censistas
/// @param largo
/// @return
int hayCensistasActivos (Censista *censistas, int largo) {
	int retorno = -1;
	if(censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE && censistas[i].estadoCensista == ACTIVO) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param censistas
/// @param largo
/// @param id
/// @return
int findCensistaLiberadoById(Censista *censistas, int largo, int id) {
	int retorno = -1;
	if(censistas != NULL && largo > 0 && id > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE && censistas[i].estadoCensista == LIBERADO && censistas[i].idCensista == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param censistas
/// @param largo
/// @param id
/// @return
int removeCensistaById(Censista *censistas, int largo, int id) {
	int retorno = -1;
	if(censistas != NULL && largo > 0 && id > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE && censistas[i].idCensista == id && censistas[i].estadoCensista != ACTIVO) {
				censistas[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param censistas
/// @param largo
/// @return
int printCensistas(Censista *censistas, int largo) {
	int retorno = -1;
	if(censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE) {
				printf("\nID: %d | Nombre: %s | Apellido: %s | Nacimiento: %d/%d/%d | Edad: %d | Domicilio: %s %d | Estado: ", censistas[i].idCensista, censistas[i].nombre, censistas[i].apellido, censistas[i].nacimiento.dia, censistas[i].nacimiento.mes, censistas[i].nacimiento.anio, censistas[i].edad, censistas[i].domicilio.calle, censistas[i].domicilio.altura);
				switch(censistas[i].estadoCensista) {
				case 2001:
					printf("ACTIVO");
					break;
				case 2002:
					printf("INACTIVO");
					break;
				case 2003:
					printf("LIBERADO");
					break;
				}
			}
		}
	}
	return retorno = 0;
}
