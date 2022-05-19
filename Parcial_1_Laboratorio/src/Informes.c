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
				printf("Estado: ", zonasCenso[i].censadosPresencialmente, zonasCenso[i].censadosVirtualmente, zonasCenso[i].ausentes);
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
