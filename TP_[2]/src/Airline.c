#include "Airline.h"

void forcedLoad(Passenger *list1, Flight *list2) {
	list1[0].id = 1;
	list1[1].id = 2;
	list1[2].id = 3;
	list1[3].id = 4;
	list1[4].id = 5;
	list1[5].id = 6;
	list1[6].id = 7;
	list1[7].id = 8;
	list1[8].id = 9;
	list1[9].id = 10;

	strncpy(list1[0].name, "Hector Domingo", sizeof(list1[0].name));
	strncpy(list1[1].name, "Marisol", sizeof(list1[1].name));
	strncpy(list1[2].name, "Jorge", sizeof(list1[2].name));
	strncpy(list1[3].name, "Mirta", sizeof(list1[3].name));
	strncpy(list1[4].name, "Mariel", sizeof(list1[4].name));
	strncpy(list1[5].name, "Guillermo", sizeof(list1[5].name));
	strncpy(list1[6].name, "Esteban", sizeof(list1[6].name));
	strncpy(list1[7].name, "Fernando", sizeof(list1[7].name));
	strncpy(list1[8].name, "Franco", sizeof(list1[8].name));
	strncpy(list1[9].name, "Sofía", sizeof(list1[9].name));

	strncpy(list1[0].lastName, "Bazzo", sizeof(list1[0].lastName));
	strncpy(list1[1].lastName, "Perez Tajes", sizeof(list1[1].lastName));
	strncpy(list1[2].lastName, "Perez Tajes", sizeof(list1[2].lastName));
	strncpy(list1[3].lastName, "Pensotti", sizeof(list1[3].lastName));
	strncpy(list1[4].lastName, "Bazzo", sizeof(list1[4].lastName));
	strncpy(list1[5].lastName, "Desimone", sizeof(list1[5].lastName));
	strncpy(list1[6].lastName, "Bazzo", sizeof(list1[6].lastName));
	strncpy(list1[7].lastName, "Bazzo", sizeof(list1[7].lastName));
	strncpy(list1[8].lastName, "Desimone", sizeof(list1[8].lastName));
	strncpy(list1[9].lastName, "Desimone", sizeof(list1[9].lastName));

	list1[0].price = 1000.00;
	list1[1].price = 20000.10;
	list1[2].price = 3000.20;
	list1[3].price = 40000.30;
	list1[4].price = 5000.40;
	list1[5].price = 60000.50;
	list1[6].price = 7000.60;
	list1[7].price = 80000.70;
	list1[8].price = 9000.80;
	list1[9].price = 100000.90;

	strncpy(list1[0].flyCode, "ABC123", sizeof(list1[0].flyCode));
	strncpy(list1[1].flyCode, "AAA111", sizeof(list1[1].flyCode));
	strncpy(list1[2].flyCode, "AAA111", sizeof(list1[2].flyCode));
	strncpy(list1[3].flyCode, "BBB222", sizeof(list1[3].flyCode));
	strncpy(list1[4].flyCode, "ABC123", sizeof(list1[4].flyCode));
	strncpy(list1[5].flyCode, "CCC333", sizeof(list1[5].flyCode));
	strncpy(list1[6].flyCode, "ABC123", sizeof(list1[6].flyCode));
	strncpy(list1[7].flyCode, "ABC123", sizeof(list1[7].flyCode));
	strncpy(list1[8].flyCode, "CCC333", sizeof(list1[8].flyCode));
	strncpy(list1[9].flyCode, "CCC333", sizeof(list1[9].flyCode));

	list1[0].typePassenger = FIRST;
	list1[1].typePassenger = BUSINESS;
	list1[2].typePassenger = PREMIUM_ECONOMY;
	list1[3].typePassenger = ECONOMY;
	list1[4].typePassenger = FIRST;
	list1[5].typePassenger = BUSINESS;
	list1[6].typePassenger = PREMIUM_ECONOMY;
	list1[7].typePassenger = ECONOMY;
	list1[8].typePassenger = FIRST;
	list1[9].typePassenger = BUSINESS;

	list1[0].isEmpty = FALSE;
	list1[1].isEmpty = FALSE;
	list1[2].isEmpty = FALSE;
	list1[3].isEmpty = FALSE;
	list1[4].isEmpty = FALSE;
	list1[5].isEmpty = FALSE;
	list1[6].isEmpty = FALSE;
	list1[7].isEmpty = FALSE;
	list1[8].isEmpty = FALSE;
	list1[9].isEmpty = FALSE;

	list2[0].id = 1;
	list2[1].id = 2;
	list2[2].id = 3;
	list2[3].id = 4;

	strncpy(list2[0].flyCode, "ABC123", sizeof(list1[0].flyCode));
	strncpy(list2[1].flyCode, "AAA111", sizeof(list1[1].flyCode));
	strncpy(list2[2].flyCode, "BBB222", sizeof(list1[2].flyCode));
	strncpy(list2[3].flyCode, "CCC333", sizeof(list1[3].flyCode));

	list2[0].flightStatus = ACTIVE;
	list2[1].flightStatus = DELAYED;
	list2[2].flightStatus = CANCELLED;
	list2[3].flightStatus = ACTIVE;

	list2[0].isEmpty = FALSE;
	list2[1].isEmpty = FALSE;
	list2[2].isEmpty = FALSE;
	list2[3].isEmpty = FALSE;
}
