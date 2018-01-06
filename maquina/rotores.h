#ifndef ROTORES_H_INCLUDED
#define ROTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <windows.h>
#include "../config/config.h"
#include "../auxiliar/punto.h"



struct sRotor
{
    char anillo[27];
    char cableado[27];
    char muesca[3];
    unsigned short num;
    char referencia[27];
};
struct sListaRotores
{
    unsigned short num;
    struct sRotor *rotor;
};


void 	avanzaRotores (struct sListaRotores * pListaRotores);
void    configRotores(struct sListaRotores * lista, struct sConfig config);
void 	dibujaRotor (struct sRotor rotor, struct sPunto coordRotor);
void 	genWalzenlage (int nrotor, unsigned short walzen[]);
void 	pasoRotor (struct sRotor * pRotor, int num);
void 	configAnillos (struct sRotor * pRotor, int pos);
unsigned short 	opRotor (unsigned short in, struct sRotor rotor, bool dir);
void    leeCfgRotor(struct sRotor * pRotor);
void 	fprintRingstellung (int nrotor, unsigned short ring[], FILE *ptr, FILE *pCfg);
void 	genRingstellung (int nrotor, unsigned short ring[]);
void 	genGrundstellung (int nrotor, char grund[]);
void 	fprintGrundstellung (int nrotor, char grund[], FILE *ptr, FILE *pCfg);
void 	fprintWalzenlage (int nrotor, unsigned short walzen[], FILE *ptr, FILE *pCfg);
void    genStecker(char stecker[]);
void    fprintStecker(char stecker[], FILE *ptr, FILE *pCfg);
void    gotoxy(int x, int y);
void    setColorTexto(WORD colors);
void    gestionMenuPrincipal();
#endif
