#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "../auxiliar/auxiliar.h"
#include "../config/config.h"
#include "../maquina/rotores.h"
#include "../maquina/reflector.h"
struct sEnigma
{
    struct sConfig config;
    struct sListaRotores listaRotores;
    struct sReflector reflector;

};
void    configuracion (struct sEnigma * pEnigma);

#endif
