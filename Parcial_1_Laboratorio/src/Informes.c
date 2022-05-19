#include "Informes.h"


/// @brief
///
/// @param zonasCenso
/// @param censistas
/// @param largo
/// @return
int printZonasCensoExt(ZonaCenso *zonasCenso, Censista *censistas, int largo) {
	int retorno = -1;
	int flagCensistaEncontrado = FALSE;
	if(zonasCenso != NULL && censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE) {
				printf("\nID: %d | Manzana: %s, %s, %s, %s | Localidad: %s | Censista: ", zonasCenso[i].idZona, zonasCenso[i].manzana[0], zonasCenso[i].manzana[1], zonasCenso[i].manzana[2], zonasCenso[i].manzana[3], zonasCenso[i].localidad);
				for(int j = 0; j < MAX_CENSISTAS; j++) {
					if(censistas[j].isEmpty == FALSE && zonasCenso[i].idCensista == censistas[j].idCensista) {
						printf("%s %s", censistas[j].nombre, censistas[j].apellido);
						flagCensistaEncontrado = TRUE;
						break;
					}
				}
				if(flagCensistaEncontrado == FALSE) {
					printf("SIN ASIGNAR");
				}
				printf(" | Presenciales: %d | Virtuales: %d | Ausentes: %d | Estado: ", zonasCenso[i].censadosPresencialmente, zonasCenso[i].censadosVirtualmente, zonasCenso[i].ausentes);
				switch(zonasCenso[i].esadoZonaCenso) {
				case 3000:
					printf("PENDIENTE");
					break;
				case 3001:
					printf("FINALIZADA");
					break;
				}
			}
		}
	}
	return retorno;
}


int informar1(Censista *censistas, ZonaCenso *zonasCenso, int largo) {
	int retorno = -1;
	int contadorInforme1 = 0;
	if(censistas != NULL && zonasCenso != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE && zonasCenso[i].esadoZonaCenso == PENDIENTE) {
				for(int j = 0; j < largo; j++) {
					if(censistas[j].isEmpty == FALSE && zonasCenso[i].idCensista == censistas[j].idCensista) {
						contadorInforme1++;
					}
				}
			}
		}
		printf("\nCantidad de censistas activos con zona pendiente: %d\n", contadorInforme1);
		retorno = 0;
	}
	return retorno;
}

int informar3(ZonaCenso *zonasCenso, int largo) {
	int retorno = -1;
	int flagInforme3 = 0;
	int ausentesInforme3;
	char localidadInforme3[64];
	if(zonasCenso != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE) {
				if(flagInforme3 == 0) {
					ausentesInforme3 = zonasCenso[i].ausentes;
					strncpy(localidadInforme3, zonasCenso[i].localidad, sizeof(localidadInforme3));
					flagInforme3 = 1;
				}
				if(flagInforme3 == 1 && zonasCenso[i].ausentes > ausentesInforme3) {
					strncpy(localidadInforme3, zonasCenso[i].localidad, sizeof(localidadInforme3));
					ausentesInforme3 = zonasCenso[i].ausentes;
				}
			}
		}
		printf("Localidad con más ausentes: %s con %d\n", localidadInforme3, ausentesInforme3);
	}
	return retorno;
}

int informar4(ZonaCenso *zonasCenso, Censista *censistas, int largo) {
	int retorno = -1;
	int censadosTotal;
	int flagInforme4 = 0;
	int censadosInforme4;
	int censistaInforme4;
	if(zonasCenso != NULL && censistas != NULL && largo > 0) {
		for(int i = 0; i < largo; i++) {
			if(zonasCenso[i].isEmpty == FALSE) {
				censadosTotal = zonasCenso[i].censadosPresencialmente + zonasCenso[i].censadosVirtualmente;
				if(flagInforme4 == 0) {
					censadosInforme4 = censadosTotal;
					censistaInforme4 = zonasCenso[i].idCensista;
					flagInforme4 = 1;
				}
				if(flagInforme4 == 1 && censadosTotal > censadosInforme4) {
					censistaInforme4 = zonasCenso[i].idCensista;
					censadosInforme4 = censadosTotal;
				}
			}
		}
		for(int i = 0; i < largo; i++) {
			if(censistas[i].isEmpty == FALSE && censistas[i].idCensista == censistaInforme4) {
				printf("Censista cuya zona fue la más censada: %s %s con %d censados\n", censistas[i].nombre, censistas[i].apellido, censadosInforme4);
				break;
			}
		}
	}
	return retorno;
}
