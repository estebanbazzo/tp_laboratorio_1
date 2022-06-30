#include "Controller.h"


int controller_loadText(char* path, LinkedList* ventaList) {
	int auxReturn = -1;
	FILE* textFile = NULL;
	if(path != NULL && ventaList != NULL) {
		if((textFile = fopen(path, "r")) != NULL) {
			if(!parser_fromText(textFile, ventaList)) {
				auxReturn = 0;
			}
			fclose(textFile);
		}
	}
	return auxReturn;
}

int controller_list(LinkedList* ventaList) {
	int auxReturn = -1;
	Venta* pV = NULL;
	int id_venta;
	char nombre_pelicula[NOMBREPELICULA_LENGHT];
	int dia;
	char auxDia[DIA_LENGHT];
	char horario[HORARIO_LENGHT];
	int sala;
	int cantidad_entradas;
	int lenght;
	if(ventaList != NULL) {
		printf("\nID      NOMBRE                                   DIA           HORARIO   SALA ENTRADAS\n\n");
		lenght = ll_lenght(ventaList);
		for(int i = 0; i < lenght; i++) {
			if((pV = (Venta*)ll_get(ventaList, i)) != NULL &&
			   !venta_getId(pV, &id_venta) &&
			   !venta_getNombre(pV, nombre_pelicula) &&
			   !venta_getDia(pV, &dia) &&
			   !venta_getHorario(pV, horario) &&
			   !venta_getSala(pV, &sala) &&
			   !venta_getEntradas(pV, &cantidad_entradas)) {
				if(dia == DOMINGO) {
					strncpy(auxDia, "Domingo", DIA_LENGHT);
				}
				else if(dia == LUNES) {
					strncpy(auxDia, "Lunes", DIA_LENGHT);
				}
				else if(dia == MARTES) {
					strncpy(auxDia, "Martes", DIA_LENGHT);
				}
				else if(dia == MIERCOLES) {
					strncpy(auxDia, "Miercoles", DIA_LENGHT);
				}
				else if(dia == JUEVES) {
					strncpy(auxDia, "Jueves", DIA_LENGHT);
				}
				else if(dia == VIERNES) {
					strncpy(auxDia, "Viernes", DIA_LENGHT);
				}
				else if(dia == SABADO) {
					strncpy(auxDia, "Sabado", DIA_LENGHT);
				}
				printf("%-4d    %-37s    %-10s    %-6s    %-1d    %-2d\n", id_venta, nombre_pelicula, auxDia, horario, sala, cantidad_entradas);
			}
		}
		printf("\n");
		auxReturn = 0;
	}
	return auxReturn;
}

int controller_saveText(char* path, LinkedList* ventaList) {
	int auxReturn = -1;
	FILE* textFile = NULL;
	Venta* pV = NULL;
	int id_venta;
	char nombre_pelicula[NOMBREPELICULA_LENGHT];
	int dia;
	char horario[HORARIO_LENGHT];
	int sala;
	int cantidad_entradas;
	float monto;
	int lenght;
	if(path != NULL && ventaList != NULL) {
		if((textFile = fopen(path, "w")) != NULL) {
			fprintf(textFile, "id_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas,monto\n");
			lenght = ll_lenght(ventaList);
			for(int i = 0; i < lenght; i++) {
				if((pV = (Venta*)ll_get(ventaList, i)) != NULL &&
				   !venta_getId(pV, &id_venta) &&
				   !venta_getNombre(pV, nombre_pelicula) &&
				   !venta_getDia(pV, &dia) &&
				   !venta_getHorario(pV, horario) &&
				   !venta_getSala(pV, &sala) &&
				   !venta_getEntradas(pV, &cantidad_entradas)) {
					if(dia == LUNES || dia == MARTES || dia == MIERCOLES) {
						if(cantidad_entradas > 3) {
							monto = 240 * cantidad_entradas * 0.90;
						}
						else {
							monto = 240 * cantidad_entradas;
						}
					}
					else {
						if(cantidad_entradas > 3) {
							monto = 350 * cantidad_entradas * 0.90;
						}
						else {
							monto = 350 * cantidad_entradas;
						}
					}
					fprintf(textFile, "%d,%s,%d,%s,%d,%d,%.2f\n", id_venta, nombre_pelicula, dia, horario, sala, cantidad_entradas, monto);
				}
			}
			fclose(textFile);
			auxReturn = 0;
		}
	}
	return auxReturn;
}

int controller_report(LinkedList* ventaList) {
	int auxReturn = 0;
	int sala;
	int total_entradas;
	if(ventaList != NULL) {
		if(!utn_getInt(&sala, "\nIngrese el número de sala: ", "\nError: no existe una sala con ese número", 1, 5, 3)) {
			switch(sala) {
			case 1:
				total_entradas = ll_count(ventaList, venta_sala1);
				printf("\nTotal de entradas vendidas para la sala 1: %d", total_entradas);
				break;

			case 2:
				total_entradas = ll_count(ventaList, venta_sala2);
				printf("\nTotal de entradas vendidas para la sala 2: %d", total_entradas);
				break;

			case 3:
				total_entradas = ll_count(ventaList, venta_sala3);
				printf("\nTotal de entradas vendidas para la sala 3: %d", total_entradas);
				break;

			case 4:
				total_entradas = ll_count(ventaList, venta_sala4);
				printf("\nTotal de entradas vendidas para la sala 4: %d", total_entradas);
				break;

			case 5:
				total_entradas = ll_count(ventaList, venta_sala5);
				printf("\nTotal de entradas vendidas para la sala 5: %d", total_entradas);
				break;
			}
		}
	}
	return auxReturn;
}
