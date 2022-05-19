#include "ZonaCenso.h"


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @return
int initZonasCenso(ZonaCenso *zonasCenso, int largo) {
	int retorno = -1;
	if(zonasCenso != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			zonasCenso[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @param id
/// @param calle1
/// @param calle2
/// @param calle3
/// @param calle4
/// @param localidad
/// @return
int addZonaCenso(ZonaCenso *zonasCenso, int largo, int id, char calle1[], char calle2[], char calle3[], char calle4[], int localidad) {
	int retorno = -1;
	if(zonasCenso != NULL && largo > 0 && id > 0 && calle1 != NULL && calle2 != NULL && calle3 != NULL && calle4 != NULL && localidad >= 1000) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == TRUE) {
				zonasCenso[i].idZona = id;
				strncpy(zonasCenso[i].manzana[0], calle1, sizeof(zonasCenso[i].manzana[0]));
				strncpy(zonasCenso[i].manzana[1], calle2, sizeof(zonasCenso[i].manzana[1]));
				strncpy(zonasCenso[i].manzana[2], calle3, sizeof(zonasCenso[i].manzana[2]));
				strncpy(zonasCenso[i].manzana[3], calle4, sizeof(zonasCenso[i].manzana[3]));
				switch(localidad) {
				case 1000:
					strncpy(zonasCenso[i].localidad, "ALBERTI", sizeof(zonasCenso[i].localidad));
					break;
				case 1001:
					strncpy(zonasCenso[i].localidad, "BALCARCE", sizeof(zonasCenso[i].localidad));
					break;
				case 1002:
					strncpy(zonasCenso[i].localidad, "CAMPANA", sizeof(zonasCenso[i].localidad));
					break;
				case 1003:
					strncpy(zonasCenso[i].localidad, "DOLORES", sizeof(zonasCenso[i].localidad));
					break;
				case 1004:
					strncpy(zonasCenso[i].localidad, "ENSENADA", sizeof(zonasCenso[i].localidad));
					break;
				case 1005:
					strncpy(zonasCenso[i].localidad, "GUAMINI", sizeof(zonasCenso[i].localidad));
					break;
				case 1006:
					strncpy(zonasCenso[i].localidad, "JUNIN", sizeof(zonasCenso[i].localidad));
					break;
				case 1007:
					strncpy(zonasCenso[i].localidad, "LOBOS", sizeof(zonasCenso[i].localidad));
					break;
				case 1008:
					strncpy(zonasCenso[i].localidad, "MAIPU", sizeof(zonasCenso[i].localidad));
					break;
				case 1009:
					strncpy(zonasCenso[i].localidad, "NAVARRO", sizeof(zonasCenso[i].localidad));
					break;
				}
				zonasCenso[i].esadoZonaCenso = PENDIENTE;
				zonasCenso[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @return
int hayZonasCenso(ZonaCenso *zonasCenso, int largo) {
	int retorno = -1;
	if(zonasCenso != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @brief
///
/// @param zonasCenso
/// @param largo
/// @param id
/// @return
int findZonaCensoPendienteById(ZonaCenso *zonasCenso, int largo, int id) {
	int retorno = -1;
	if(zonasCenso != NULL && largo > 0 && id > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE && zonasCenso[i].esadoZonaCenso == PENDIENTE && zonasCenso[i].idZona == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
