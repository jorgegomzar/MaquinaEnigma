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
#include "../auxiliar/auxiliar.h"


struct sConfig
{
    int 	        dia;
    char 	        grund[5];
    char         	modeloETW;
    unsigned short 	numRotores;
    unsigned short 	ringS[4];
    char 	        stecker[27];
    unsigned short 	walzen[4];
};
#include "../maquina/reflector.h"
#include "../maquina/rotores.h"

void    gestionMenuPrincipal();
void 	leeConfig (struct sConfig * pConfig);
void    muestraConfig	(struct sConfig config);
void    inicCifrado();
void    gestionMenuPrincipal(void);
int     sondeaTeclado();
void 	leeCfgReflector (char archivo[], struct sReflector * pRef);
void    generaLibroClaves();
void    selecModelo(struct sConfig *pConfig);
#endif

