#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
#include "LinkedList.h"
#include "Parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadText(char* path, LinkedList* ventaList);
int controller_list(LinkedList* ventaList);
int controller_saveText(char* path, LinkedList* ventaList);
int controller_report(LinkedList* ventaList);


#endif /* CONTROLLER_H_ */
