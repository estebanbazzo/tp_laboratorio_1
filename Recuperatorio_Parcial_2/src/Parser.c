#include "Parser.h"


int parser_fromText(FILE* textFile, LinkedList* ventaList) {
	int auxReturn = -1;
	Venta* pV = NULL;
	char header[1024];
	char id_venta[1024];
	char nombre_pelicula[1024];
	char dia[1024];
	char horario[1024];
	char sala[1024];
	char cantidad_entradas[1024];
	if(textFile != NULL && ventaList != NULL) {
		fscanf(textFile, "%s", header);
		do {
			if(fscanf(textFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id_venta, nombre_pelicula, dia, horario, sala, cantidad_entradas) == VARIABLES_QUANTITY) {
				if((pV = venta_newParameters(id_venta, nombre_pelicula, dia, horario, sala, cantidad_entradas)) != NULL) {
					if(!ll_add(ventaList, pV)) {
						continue;
					}
					else {
						venta_delete(pV);
					}
				}
			}
		} while(!feof(textFile));
		fclose(textFile);
		auxReturn = 0;
	}
	return auxReturn;
}
