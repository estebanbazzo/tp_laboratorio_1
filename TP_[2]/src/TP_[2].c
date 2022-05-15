#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "ArrayPassenger.h"
#include "ArrayFlight.h"
#include "Airline.h"

int main(void) {
	setbuf(stdout, NULL);

	int Return = -1;
	Passenger passengers[MAX_PASSENGERS];
	Flight flights[MAX_PASSENGERS];
	int mainMenuOption = 0;
	int subMenuOption = 0;
	int auxId = 0;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[10];
	int auxFlightStatus;
	int srchId;
	int passengerIndex;
	int exist;

	printf("Bienvenidx al Administrador de Pasajeros de la Aerolínea\n");

	if(initPassengers(passengers, MAX_PASSENGERS) == 0 && initFlights(flights, MAX_PASSENGERS) == 0) {
		do {
			pW2MainMenu();

			if(getInt(&mainMenuOption, "\nIngrese una opción del menú principal: ", "Error: la opción ingresada es inválida", 1, 6, -1) == 0) {
				switch(mainMenuOption) {

				case 1:
					auxId = setId();
					if(getWords(auxName, sizeof(auxName), "\nIngrese el nombre: ", "Error: el nombre ingresado es inválido", 3) == 0) {
						if(getWords(auxLastName, sizeof(auxLastName), "Ingrese el apellido: ", "Error: el apellido ingresado es inválido", 3) == 0) {
							if(getFloat(&auxPrice, "Ingrese el precio: $", "Error: el precio ingresado es inválido", 0.01, -1, 3) == 0) {
								if(getInt(&auxTypePassenger, "Ingrese el tipo de pasajero (clase: [1]Primera/[2]Ejecutiva/[3]Turista Premium/[4]Turista): ", "Error: el tipo de pasajero ingresado es inválido", 1, 4, 3) == 0) {
									if(getCode(auxFlyCode, sizeof(auxFlyCode), "Ingrese el código del vuelo: ", "Error: el código de vuelo ingresado es inválido", 3) == 0) {
										if(getInt(&auxFlightStatus, "Ingrese el estado del vuelo ([1]Activo/[2]Demorado/[3]Cancelado): ", "Error: el estado de vuelo ingresado es inválido", 1, 3, 3) == 0) {
											if(addPassenger(passengers, MAX_PASSENGERS, auxId, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlyCode) == 0) {
												if(addFlight(flights, MAX_PASSENGERS, auxId, auxFlyCode, auxFlightStatus) == 0) {
													printf("\nEl pasajero se dió de alta con ID %d", auxId);
													pressAnyKey("para volver al Menú Principal");
												} else {
													error("Error: la función addFlight falló", "para volver al menú Principal"); break;
												}
											} else {
												error("Error: la función addPassenger falló", "para volver al menú Principal"); break;
											}
										} else {
											error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
										}
									} else {
										error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
									}
								} else {
									error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
								}
							} else {
								error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
							}
						} else {
							error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
						}
					} else {
						error("Error: demasiados intentos fallidos", "para volver al menú Principal"); break;
					}

					break;

				case 2:
					if(isThereAPassenger(passengers, MAX_PASSENGERS) == 0) {
						if(getInt(&srchId, "\nIngrese el ID del pasajero a modificar: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							if((passengerIndex = findPassengerById(passengers, MAX_PASSENGERS, srchId)) != -1) {
								do {
									pW2SubMenu2(passengers, flights, MAX_PASSENGERS, passengerIndex);

									if(getInt(&subMenuOption, "\nIngrese una opción del submenú Modificación de Pasajero: ", "Error: la opción ingresada es inválida", 1, 6, -1) == 0) {
										switch(subMenuOption) {
										case 1:
											if(getWords(auxName, sizeof(auxName), "\nIngrese el nuevo nombre: ", "Error: el nuevo nombre ingresado es inválido", 3) == 0) {
												strncpy(passengers[passengerIndex].name, auxName, sizeof(passengers[passengerIndex].name));
											} else {
												error("Error: La función getWords falló", "para volver al submenú Modificación de Pasajero");
											}
											break;

										case 2:
											if(getWords(auxLastName, sizeof(auxLastName), "\nIngrese el nuevo apellido: ", "Error: el nuevo apellido ingresado es inválido", 3) == 0) {
												strncpy(passengers[passengerIndex].lastName, auxLastName, sizeof(passengers[passengerIndex].lastName));
											} else {
												error("Error: La función getWords falló", "para volver al submenú Modificación de Pasajero");
											}
											break;

										case 3:
											if(getInt(&auxTypePassenger, "\nIngrese el nuevo tipo de pasajero (clase: [1]Primera/[2]Ejecutiva/[3]Turista Premium/[4]Turista): ", "Error: el nuevo tipo de pasajero ingresado es inválido", 1, 4, 3) == 0) {
												passengers[passengerIndex].typePassenger = auxTypePassenger;
											} else {
												error("Error: La función getInt falló", "para volver al submenú Modificación de Pasajero");
											}
											break;

										case 4:
											if(getFloat(&auxPrice, "\nIngrese el nuevo precio del vuelo: $", "Error: el nuevo precio del vuelo ingresado es inválido", 0.01, -1, 3) == 0) {
												passengers[passengerIndex].price = auxPrice;
											} else {
												error("Error: La función getFloat falló", "para volver al submenú Modificación de Pasajero");
											}
											break;

										case 5:
											if(getCode(auxFlyCode, sizeof(auxFlyCode), "\nIngrese el nuevo código del vuelo: ", "Error: el nuevo código de vuelo ingresado es inválido", 3) == 0) {
												strncpy(passengers[passengerIndex].flyCode, auxFlyCode, sizeof(passengers[passengerIndex].flyCode));

												exist = FALSE;
												for(int i = 0; i < MAX_PASSENGERS; i++) {
													if(strcmp(auxFlyCode, flights[i].flyCode) == 0 && flights[i].isEmpty == FALSE) {
														exist = TRUE;
														flights[i].flightStatus = auxFlightStatus;
														break;
													}
												}

												if(exist == FALSE) {
													if(getInt(&auxFlightStatus, "Ingrese el estado del vuelo ([1]Activo/[2]Demorado/[3]Cancelado): ", "Error: el estado de vuelo ingresado es inválido", 1, 3, 3) == 0) {
														for(int i = 0; i < MAX_PASSENGERS; i++) {
															if(flights[i].isEmpty == TRUE) {
																flights[i].id = setId();
																strncpy(flights[i].flyCode, auxFlyCode, sizeof(flights[i].flyCode));
																flights[i].flightStatus = auxFlightStatus;
																flights[i].isEmpty = 0;
																break;
															}
														}
													} else {
														error("Error: La función getInt falló", "para volver al submenú Modificación de Pasajero");
													}
												}
											} else {
												error("Error: La función getCode falló", "para volver al submenú Modificación de Pasajero");
											}
											break;
										}
									}
								} while(subMenuOption != 6);
							} else {
								error("Error: la función findPassengerById falló", "para volver al menú Principal");
							}
						} else {
							error("Error: demasiados intentos fallidos", "para volver al menú Principal");
						}
					} else {
						error("Error: debe haber al menos un pasajero cargado para ingresar esta opción", "para volver al menú Principal");
					}

					break;

				case 3:
					if(isThereAPassenger(passengers, MAX_PASSENGERS) == 0) {
						if(getInt(&srchId, "\nIngrese el ID del pasajero a dar de baja: ", "Error: el ID ingresado es inválido", 1, -1, 3) == 0) {
							if(removePassenger(passengers, MAX_PASSENGERS, srchId) == 0) {
								printf("\nEl pasajero con ID %d se dió de baja", srchId);
								pressAnyKey("para volver al Menú Principal");
							} else {
								error("Error: la función removePassenger falló", "para volver al menú Principal");
							}
						} else {
							error("Error: demasiados intentos fallidos", "para volver al menú Principal");
						}
					} else {
						error("Error: debe haber al menos un pasajero cargado para ingresar esta opción", "para volver al menú Principal"); break;
					}
					break;

				case 4:
					if(isThereAPassenger(passengers, MAX_PASSENGERS) == 0) {
						do {
							pW2SubMenu4();

							if(getInt(&subMenuOption, "\nIngrese una opción del submenú Imprimir Informes: ", "Error: la opción ingresada es inválida", 1, 4, -1) == 0) {
								switch(subMenuOption) {
								case 1:
									do {
										pW2SubMenu41();

										if(getInt(&subMenuOption, "\nIngrese una opción del submenú Imprimir Informes: ", "Error: la opción ingresada es inválida", 1, 4, -1) == 0) {
											switch(subMenuOption) {
											case 1:
												if(sortPassengers(passengers, MAX_PASSENGERS, 1) != 0) {
													error("Error: la función sortPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												if(printPassengers(passengers, MAX_PASSENGERS) != 0) {
													error("Error: la función printPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												printf("\n");
												pressAnyKey("para volver al submenú Imprimir Informes");
												break;

											case 2:
												if(sortPassengers(passengers, MAX_PASSENGERS, 0) != 0) {
													error("Error: la función sortPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												if(printPassengers(passengers, MAX_PASSENGERS) != 0) {
													error("Error: la función printPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												printf("\n");
												pressAnyKey("para volver al submenú Imprimir Informes");
												break;
											}
										} else {
											error("Error: la función getInt falló", "para volver al submenú Imprimir Informes"); break;
										}
									} while(subMenuOption != 3);
									break;
								case 2:
									printPassengerPrices(passengers, MAX_PASSENGERS);
									printf("\n");
									pressAnyKey("para volver al submenú Imprimir Informes");
									break;
								case 3:
									do {
										pW2SubMenu41();

										if(getInt(&subMenuOption, "\nIngrese una opción del submenú Imprimir Informes: ", "Error: la opción ingresada es inválida", 1, 4, -1) == 0) {
											switch(subMenuOption) {
											case 1:
												if(sortPassengersByCode(passengers, MAX_PASSENGERS, 1) != 0) {
													error("Error: la función sortPassengersByCode falló", "para volver al submenú Imprimir Informes"); break;
												}
												if(printPassengers(passengers, MAX_PASSENGERS) != 0) {
													error("Error: la función printPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												printf("\n");
												pressAnyKey("para volver al submenú Imprimir Informes");
												break;

											case 2:
												if(sortPassengersByCode(passengers, MAX_PASSENGERS, 0) != 0) {
													error("Error: la función sortPassengersByCode falló", "para volver al submenú Imprimir Informes"); break;
												}
												if(printPassengers(passengers, MAX_PASSENGERS) != 0) {
													error("Error: la función printPassengers falló", "para volver al submenú Imprimir Informes"); break;
												}
												printf("\n");
												pressAnyKey("para volver al submenú Imprimir Informes");
												break;
											}
										} else {
											error("Error: la función getInt falló", "para volver al submenú Imprimir Informes"); break;
										}
									} while(subMenuOption != 3);
									break;
								}
							} else {
								error("Error: la función getInt falló", "para volver al menú Principal"); break;
							}
						} while(subMenuOption != 4);
					}
					else {
						error("Error: debe haber al menos un pasajero cargado para ingresar esta opción", "para volver al menú Principal"); break;
					}
					break;

				case 5:
					if(initPassengers(passengers, MAX_PASSENGERS) == 0 && initFlights(flights, MAX_PASSENGERS) == 0) {
						forcedLoad(passengers, flights);
						printf("\nTodos los pasajeros y vuelos previos han sido dados de baja y 10 pasajeros y 4 vuelos han sido dados de alta");
						pressAnyKey("para volver al Menú Principal");
					}
					break;

				case 6:
					printf("\nGracias por usar el Administrador de Pasajeros de la Aerolínea");
					Return = 0;
					break;
				}
			}
			else {
				error("Error: la función getInt falló", "para reintentarlo");
			}
		} while(mainMenuOption != 6);
	}
	else {
		error("Error: la función initPassengers/Flights falló", "para salir del programa");
	}

	return Return;
}
