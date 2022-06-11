#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "Parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_getLastId(char* path, char* id);
int controller_lastIdPlusPlus(char* id);
int controller_refreshLastId(char* path, char* id);
