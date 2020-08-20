#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <winuser.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

struct sConfig {
    int 	        dia;
    char 	        grund[5];
    char         	modeloETW;
    unsigned short 	numRotores;
    unsigned short 	ringS[4];
    char 	        stecker[27];
    unsigned short 	walzen[4];
};

#include "../auxiliar/auxiliar.h"
#include "../maquina/reflector.h"
#include "../maquina/rotores.h"

void generaLibroClaves();
void leeConfig(struct sConfig * pConfig);
void muestraConfig(struct sConfig config);
void selecModelo(struct sConfig *pConfig);
#endif

