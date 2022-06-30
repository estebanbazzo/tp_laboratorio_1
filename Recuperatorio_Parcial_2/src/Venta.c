#include "Venta.h"


Venta* venta_new(void) {
	Venta* pV = NULL;
	if((pV = (Venta*)malloc(sizeof(Venta))) != NULL) {
		pV->id_venta = 0;
		strncpy(pV->nombre_pelicula, "\0", NOMBREPELICULA_LENGHT);
		pV->dia = 0;
		strncpy(pV->horario, "\0", HORARIO_LENGHT);
		pV->sala = 0;
		pV->cantidad_entradas = 0;
	}
	return pV;
}

Venta* venta_newParameters(char* id_venta, char* nombre_pelicula, char* dia, char* horario, char* sala, char* cantidad_entradas) {
	Venta* pV = NULL;
	Venta* auxVV = NULL;
	if(id_venta != NULL && nombre_pelicula != NULL && dia != NULL && horario != NULL && sala != NULL && cantidad_entradas != NULL) {
		if((auxVV = venta_new()) != NULL) {
			if(!venta_setId(auxVV, atoi(id_venta)) &&
			   !venta_setNombre(auxVV, nombre_pelicula) &&
			   !venta_setDia(auxVV, atoi(dia)) &&
			   !venta_setHorario(auxVV, horario) &&
			   !venta_setSala(auxVV, atoi(sala)) &&
			   !venta_setEntradas(auxVV, atoi(cantidad_entradas))) {
				pV = auxVV;
			}
			else {
				venta_delete(auxVV);
			}
		}
	}
	return pV;
}

void venta_delete(Venta* this) {
	if(this != NULL) {
		free(this);
	}
}


int venta_setId(Venta* this, int id_venta) {
	int auxReturn = -1;
	if(this != NULL && id_venta > 0) {
		this->id_venta = id_venta;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getId(Venta* this, int* id_venta) {
	int auxReturn = -1;
	if(this != NULL && id_venta != NULL) {
		*id_venta = this->id_venta;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_setNombre(Venta* this, char* nombre_pelicula) {
	int auxReturn = -1;
	if(this != NULL && !utn_isName(nombre_pelicula, sizeof(nombre_pelicula))) {
		strncpy(this->nombre_pelicula, nombre_pelicula, NOMBREPELICULA_LENGHT);
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getNombre(Venta* this, char* nombre_pelicula) {
	int auxReturn = -1;
	if(this != NULL && nombre_pelicula != NULL) {
		strncpy(nombre_pelicula, this->nombre_pelicula, NOMBREPELICULA_LENGHT);
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_setDia(Venta* this, int dia) {
	int auxReturn = -1;
	if(this != NULL && dia >= 0) {
		this->dia = dia;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getDia(Venta* this, int* dia) {
	int auxReturn = -1;
	if(this != NULL && dia != NULL) {
		*dia = this->dia;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_setHorario(Venta* this, char* horario) {
	int auxReturn = -1;
	if(this != NULL && !utn_isText(horario, sizeof(horario))) {
		strncpy(this->horario, horario, HORARIO_LENGHT);
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getHorario(Venta* this, char* horario) {
	int auxReturn = -1;
	if(this != NULL && horario != NULL) {
		strncpy(horario, this->horario, HORARIO_LENGHT);
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_setSala(Venta* this, int sala) {
	int auxReturn = -1;
	if(this != NULL && sala > 0) {
		this->sala = sala;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getSala(Venta* this, int* sala) {
	int auxReturn = -1;
	if(this != NULL && sala != NULL) {
		*sala = this->sala;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_setEntradas(Venta* this, int cantidad_entradas) {
	int auxReturn = -1;
	if(this != NULL && cantidad_entradas > 0) {
		this->cantidad_entradas = cantidad_entradas;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_getEntradas(Venta* this, int* cantidad_entradas) {
	int auxReturn = -1;
	if(this != NULL && cantidad_entradas != NULL) {
		*cantidad_entradas = this->cantidad_entradas;
		auxReturn = 0;
	}
	return auxReturn;
}

int venta_sala1(void* element) {
	int auxReturn;
	Venta* pV;
	int sala;
	if(element != NULL) {
		pV = (Venta*)element;
		if(!venta_getSala(pV, &sala) && sala == 1) {
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int venta_sala2(void* element) {
	int auxReturn;
	Venta* pV;
	int sala;
	if(element != NULL) {
		pV = (Venta*)element;
		if(!venta_getSala(pV, &sala) && sala == 2) {
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int venta_sala3(void* element) {
	int auxReturn;
	Venta* pV;
	int sala;
	if(element != NULL) {
		pV = (Venta*)element;
		if(!venta_getSala(pV, &sala) && sala == 3) {
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int venta_sala4(void* element) {
	int auxReturn;
	Venta* pV;
	int sala;
	if(element != NULL) {
		pV = (Venta*)element;
		if(!venta_getSala(pV, &sala) && sala == 4) {
			auxReturn = 1;
		}
	}
	return auxReturn;
}

int venta_sala5(void* element) {
	int auxReturn;
	Venta* pV;
	int sala;
	if(element != NULL) {
		pV = (Venta*)element;
		if(!venta_getSala(pV, &sala) && sala == 5) {
			auxReturn = 1;
		}
	}
	return auxReturn;
}
