#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Censista.h"
#include "ZonaCenso.h"

#ifndef INFORMES_H_
#define INFORMES_H_


int printZonasCensoExt(ZonaCenso *zonasCenso, Censista *censistas, int largo);


int informar1(Censista *censistas, ZonaCenso *zonasCenso, int largo);
int informar3(ZonaCenso *zonasCenso, int largo);
int informar4(ZonaCenso *zonasCenso, Censista *censistas, int largo);

#endif /* INFORMES_H_ */
