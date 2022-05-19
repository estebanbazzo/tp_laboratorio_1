#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Censista.h"
#include "Fecha.h"
#include "Direccion.h"
#include "ZonaCenso.h"
#include "Informes.h"

void menuPrincipal(void);
void submenuModificar(void);
void submenuModificarNacimiento(void);
void submenuModificarDomicilio(void);
void submenuInformar(void);
void submenuInformar2(void);
void submenuInformar5(void);

int main(void) {
	setbuf(stdout, NULL);
	int retorno = -1;
//	int localidades[10] = {ALBERTI, BALCARCE, CAMPANA, DOLORES, ENSENADA, GUAMINI, JUNIN, LOBOS, MAIPU, NAVARRO};
	Censista censistas[100];
	ZonaCenso zonasCenso[100];
	int opcion;
	int auxId;
	char auxNombre[51];
	char auxApellido[51];
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxEdad;
	char auxCalle[64];
	int auxAltura;
	int idBuscado;
	int posicionCensistaEncontrada;
	int posicionZonaCensoEncontrada;
	char auxCalle1[64];
	char auxCalle2[64];
	char auxCalle3[64];
	char auxCalle4[64];
	int auxLocalidad;
	int auxCensadosPresencialmente;
	int auxCensadosVirtualmente;
	int auxAusentes;

	printf("Bienvenidx al programa\n");

	if(initCensistas(censistas, MAX_CENSISTAS) == 0 && initZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
		do {
			menuPrincipal();
			if(getInt(&opcion, "\nIngrese una opción del menú principal: ", "Error: la opción ingresada es inválida", 1, 10, -1) == 0) {
				switch(opcion) {
				case 1:
					auxId = setId();
					if(getWords(auxNombre, sizeof(auxNombre), "\nIngrese el nombre: ", "Error: el nombre ingresado es inválido", 3) == 0) {
						if(getWords(auxApellido, sizeof(auxApellido), "Ingrese el apellido: ", "Error: el apellido ingresado es inválido, 3", 3) == 0) {
							if(getInt(&auxDia, "Ingrese el día de nacimiento: ", "Error: el día de nacimiento ingresado es inválido", 1, 31, 3) == 0) {
								if(getInt(&auxMes, "Ingrese el mes de nacimiento: ", "Error: el mes de nacimiento ingresado es inválido", 1, 12, 3) == 0) {
									if(getInt(&auxAnio, "Ingrese el año de nacimiento: ", "Error: el año de nacimiento ingresado es inválido", 1922, 2004, 3) == 0) {
										if(getInt(&auxEdad, "Ingrese la edad: ", "Error: la edad ingresada es inválida", 18, 100, 3) == 0) {
											if(getWords(auxCalle, sizeof(auxCalle), "Ingrese la calle del domicilio: ", "Error: la calle del domicilio ingresada es inválida", 3) == 0) {
												if(getInt(&auxAltura, "Ingrese la altura del domicilio: ", "Error: la altura del domicilio ingresado es inválido", 1, 15000, 3) == 0) {
													addCensista(censistas, MAX_CENSISTAS, auxId, auxNombre, auxApellido, auxDia, auxMes, auxAnio, auxEdad, auxCalle, auxAltura);
												}
											}
										}
									}
								}
							}
						}
					}
					break;

				case 2:
					if(hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						if(getInt(&idBuscado, "\nIngrese el ID del censista a modificar: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							if((posicionCensistaEncontrada = findCensistaLiberadoById(censistas, MAX_CENSISTAS, idBuscado)) != -1) {
								do {
									submenuModificar();
									if(getInt(&opcion, "\nIngrese una opción del submenú modificación: ", "Error: la opción ingresada es inválida", 1, 6, -1) == 0) {
										switch(opcion) {
										case 1:
											if(getWords(auxNombre, sizeof(auxNombre), "\nIngrese el nuevo nombre: ", "Error: el nuevo nombre ingresado es inválido", 3) == 0) {
												strncpy(censistas[posicionCensistaEncontrada].nombre, auxNombre, sizeof(censistas[posicionCensistaEncontrada].nombre));
											}
											break;
										case 2:
											if(getWords(auxApellido, sizeof(auxApellido), "\nIngrese el nuevo apellido: ", "Error: el nuevo apellido ingresado es inválido", 3) == 0) {
												strncpy(censistas[posicionCensistaEncontrada].apellido, auxApellido, sizeof(censistas[posicionCensistaEncontrada].apellido));
											}
											break;
										case 3:
											do {
												submenuModificarNacimiento();
												if(getInt(&opcion, "\nIngrese la opción del submenú modificar fecha de nacimiento: ", "Error: la opción ingresada es inválida", 1, 4, -1) == 0) {
													switch(opcion) {
													case 1:
														if(getInt(&auxDia, "\nIngrese el nuevo día de nacimiento: ", "Error: el nuevo día de nacimiento ingresado es inválido", 1, 31, 3) == 0) {
															censistas[posicionCensistaEncontrada].nacimiento.dia = auxDia;
														}
														break;
													case 2:
														if(getInt(&auxMes, "\nIngrese el nuevo mes de nacimiento: ", "Error: el nuevo mes de nacimiento ingresado es inválido", 1, 12, 3) == 0) {
															censistas[posicionCensistaEncontrada].nacimiento.mes = auxMes;
														}
														break;
													case 3:
														if(getInt(&auxAnio, "\nIngrese el nuevo año de nacimiento: ", "Error: el nuevo año de nacimiento ingresado es inválido", 1922, 2004, 3) == 0) {
															censistas[posicionCensistaEncontrada].nacimiento.anio = auxAnio;
														}
														break;
													}
												}
											} while(opcion != 4);
											break;
										case 4:
											if(getInt(&auxEdad, "\nIngrese la nueva edad: ", "Error: la nueva edad ingresada es inválida", 18, 100, 3) == 0) {
												censistas[posicionCensistaEncontrada].edad = auxEdad;
											}
											break;
										case 5:
											do {
												submenuModificarDomicilio();
												if(getInt(&opcion, "\nIngrese la opción del submenú modificar domicilio: ", "Error: la opción ingresada es inválida", 1, 3, -1) == 0) {
													switch(opcion) {
													case 1:
														if(getWords(auxCalle, sizeof(auxCalle), "\nIngrese la nueva calle del domicilio: ", "Error: la nueva calle del domicilio ingresada es inválida", 3) == 0) {
															strncpy(censistas[posicionCensistaEncontrada].domicilio.calle, auxCalle, sizeof(censistas[posicionCensistaEncontrada].domicilio.calle));
														}
														break;
													case 2:
														if(getInt(&auxAltura, "\nIngrese la nueva altura del domicilio: ", "Error: la nueva altura del domicilio ingresada es inválida", 1, 15000, 3) == 0) {
															censistas[posicionCensistaEncontrada].domicilio.altura = auxAltura;
														}
														break;
													}
												}
											} while(opcion != 3);
											break;
										}
									}
								} while(opcion != 6);
							}
						}
					}
					break;

				case 3:
					if(hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						if(getInt(&idBuscado, "\nIngrese el ID del censista a dar de baja: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							removeCensistaById(censistas, MAX_CENSISTAS, idBuscado);
						}
					}
					break;

				case 4:
					auxId = setId();
					if(getWords(auxCalle1, sizeof(auxCalle1), "\nIngrese la 1° calle: ", "Error: la calle ingresada es inválida", 3) == 0) {
						if(getWords(auxCalle2, sizeof(auxCalle2), "Ingrese la 2° calle: ", "Error: la calle ingresada es inválida", 3) == 0) {
							if(getWords(auxCalle3, sizeof(auxCalle3), "Ingrese la 3° calle: ", "Error: la calle ingresada es inválida", 3) == 0) {
								if(getWords(auxCalle4, sizeof(auxCalle4), "Ingrese la 4° calle: ", "Error: la calle ingresada es inválida", 3) == 0) {
									printf("\n[1000] Alberti"
										   "\n[1001] Balcarce"
										   "\n[1002] Campana"
										   "\n[1003] Dolores"
										   "\n[1004] Ensenada"
										   "\n[1005] Guamini"
										   "\n[1006] Junin"
										   "\n[1007] Lobos"
										   "\n[1008] Maipu"
										   "\n[1009] Navarro");
									if(getInt(&auxLocalidad, "\nIngrese la localidad: ", "Error: la localidad ingresada es inválida", 1000, 1009, 3) == 0) {
										addZonaCenso(zonasCenso, MAX_CENSISTAS, auxId, auxCalle1, auxCalle2, auxCalle3, auxCalle4, auxLocalidad);
									}
								}
							}
						}
					}
					break;

				case 5:
					if(hayCensistas(censistas, MAX_CENSISTAS) == 0 && hayZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
						if(getInt(&idBuscado, "\nIngrese el ID de la zona a asignar: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							if((posicionZonaCensoEncontrada = findZonaCensoPendienteById(zonasCenso, MAX_CENSISTAS, idBuscado)) != -1) {
								if(getInt(&idBuscado, "Ingrese el ID del censista asignado: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
									if((posicionCensistaEncontrada = findCensistaLiberadoById(censistas, MAX_CENSISTAS, idBuscado)) != -1) {
										zonasCenso[posicionZonaCensoEncontrada].idCensista = censistas[posicionCensistaEncontrada].idCensista;
										censistas[posicionCensistaEncontrada].estadoCensista = ACTIVO;
									}
								}
							}
						}
					}
					break;

				case 6:
					if(hayCensistasActivos(censistas, MAX_CENSISTAS) == 0 && hayZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
						if(getInt(&idBuscado, "\nIngrese el ID de la zona a finalizar: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							if((posicionZonaCensoEncontrada = findZonaCensoPendienteById(zonasCenso, MAX_CENSISTAS, idBuscado)) != -1) {
								if(getInt(&auxCensadosPresencialmente, "Ingrese la cantidad de censados presencialmente: ", "Error: la cantidad ingresada es inválida", 0, -1, 3) == 0) {
									if(getInt(&auxCensadosVirtualmente, "Ingrese la cantidad de censados virtualmente: ", "Error: la cantidad ingresada es inválida", 0, -1, 3) == 0) {
										if(getInt(&auxAusentes, "Ingrese la cantidad de ausentes: ", "Error: la cantidad ingresada es inválida", 0, -1, 3) == 0) {
											zonasCenso[posicionZonaCensoEncontrada].censadosPresencialmente = auxCensadosPresencialmente;
											zonasCenso[posicionZonaCensoEncontrada].censadosVirtualmente = auxCensadosVirtualmente;
											zonasCenso[posicionZonaCensoEncontrada].ausentes = auxAusentes;
											zonasCenso[posicionZonaCensoEncontrada].esadoZonaCenso = FINALIZADA;
											for(int i = 0; i < MAX_CENSISTAS; i++) {
												if(censistas[i].isEmpty == FALSE && zonasCenso[posicionZonaCensoEncontrada].idCensista == censistas[i].idCensista) {
													censistas[i].estadoCensista = LIBERADO;
													break;
												}
											}
										}
									}
								}
							}
						}
					}
					break;

				case 7:
					if(hayCensistas(censistas, MAX_CENSISTAS) == 0) {
						printCensistas(censistas, MAX_CENSISTAS);
						printf("\n");
						pressAnyKey("para volver al Menú Principal");
					}
					break;

				case 8:
					if(hayZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
						printZonasCensoExt(zonasCenso, censistas, MAX_CENSISTAS);
						printf("\n");
						pressAnyKey("para volver al Menú Principal");
					}
					break;

				case 9:
					if(hayCensistas(censistas, MAX_CENSISTAS) == 0 && hayZonasCenso(zonasCenso, MAX_CENSISTAS) == 0) {
						do {
							submenuInformar();
							if(getInt(&opcion, "\nIngrese una opción del menú Informes: ", "Error: la opción ingresada es inválida", 1, 6, -1) == 0) {
								switch(opcion) {
								case 1:
									informar1(censistas, zonasCenso, MAX_CENSISTAS);
									break;
								case 2:
									do {
										submenuInformar2();
										if(getInt(&opcion, "\nIngrese una opción del menú Informes: ", "Error: la opción ingresada es inválida", 1, 5, -1) == 0) {
											switch(opcion) {
											case 1:
												break;
											case 2:
												break;
											case 3:
												break;
											case 4:
												break;
											}
										}
									} while(opcion != 5);
									break;
								case 3:
									informar3(zonasCenso, MAX_CENSISTAS);
									break;
								case 4:
									informar4(zonasCenso, censistas, MAX_CENSISTAS);
									break;
								case 5:
									do {
										submenuInformar5();
										if(getInt(&opcion, "\nIngrese una opción del menú Informes: ", "Error: la opción ingresada es inválida", 1, 3, -1) == 0) {
											switch(opcion) {
											case 1:
												break;
											case 2:
												break;
											}
										}
									} while(opcion != 3);
									break;
								}
							}
						} while(opcion != 6);
					}
					break;

				case 10:
					printf("\nGracias por usar el programa");
					retorno = 0;
					break;
				}
			}
		} while(opcion != 10);
	}

	return retorno;
}

void menuPrincipal(void) {
	printf("\n1. Cargar censista"
		   "\n2. Modificar censista"
		   "\n3. Dar de baja censista"
		   "\n4. Cargar zona"
		   "\n5. Asignar zona a censar"
		   "\n6. Carga de datos"
		   "\n7. Mostrar censistas"
		   "\n8. Mostrar zonas"
		   "\n9. Informes"
		   "\n10. Salir del programa\n");
}

void submenuModificar(void) {
	printf("\n1. Modificar el nombre"
		   "\n2. Modificar el apellido"
		   "\n3. Modificar la fecha de nacimiento"
		   "\n4. Modificar la edad"
		   "\n5. Modificar el domicilio"
		   "\n6. Volver al menú principal\n");
}

void submenuModificarNacimiento(void) {
	printf("\n1. Modificar el día de nacimiento"
		   "\n2. Modificar el mes de nacimiento"
		   "\n3. Modificar el año de nacimiento"
		   "\n4. Volver al submenú modificación de censista\n");
}

void submenuModificarDomicilio(void) {
	printf("\n1. Modificar la calle del domicilio"
		   "\n2. Modificar la altura del domicilio"
		   "\n3. Volver al submenú modificación de censista\n");
}

void submenuInformar(void) {
	printf("\n1. Cantidad de censistas activos con zona pendiente"
		   "\n2. Listado de censistas ordenados alfabéticamente por apellido y nombre"
		   "\n3. Localidad con más ausentes"
		   "\n4. Censista cuya zona fue la más censada"
		   "\n5. Promedio de censos"
		   "\n6. Volver al menú principal\n");
}

void submenuInformar2(void) {
	printf("\n1. Alberti"
		   "\n2. Balcarce"
		   "\n3. Campana"
		   "\n4. Dolores"
		   "\n5. Volver al submenú Informes\n");
}

void submenuInformar5(void) {
	printf("\n1. Por censista"
		   "\n2. Por zona"
		   "\n3. Volver al submenú Informes\n");
}
