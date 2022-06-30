#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
#include "LinkedList.h"
#include "Venta.h"

#ifndef PARSER_H_
#define PARSER_H_


int parser_fromText(FILE* textFile, LinkedList* ventaList);


#endif /* PARSER_H_ */
