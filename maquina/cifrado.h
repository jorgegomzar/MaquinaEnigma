#ifndef CIFRADO_H_INCLUDED
#define CIFRADO_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <winuser.h>
#include <stdbool.h>
#include "../auxiliar/auxiliar.h"
#include "../maquina/rotores.h"
#include "../maquina/enigma.h"
#include "../config/config.h"
#include "../auxiliar/punto.h"

void inicCifrado(void);
void configuracion(struct sEnigma * pEnigma);

void    procesoCifrado(struct sEnigma pEnigma);
char    leeLetra(unsigned short dx);
void    abreArchivosMensaje	(	FILE **ptPlano, FILE **ptCifrado);
void    cierraArchivosMensaje	(	FILE *ptPlano, FILE *ptCifrado );
void    dibujaInterfazM3();
void    dibujaInterfazM4();
void    gestionMenuPrincipal(void);
void    gotoxy(int x, int y);
unsigned short 	printLetraPlana (char letra, FILE *ptPlano);
void 	muestraEsquema (struct sEnigma enigma, struct sPunto coordRotor[]);
void 	avanzaRotores (struct sListaRotores * pListaRotores);
unsigned short 	opStecker (unsigned short posIn, char stecker[]);
unsigned short 	opRotor (unsigned short in, struct sRotor rotor, bool dir);
unsigned short 	opReflector (unsigned short in, struct sReflector reflector);
void 	printLetraCifrada (char letra, FILE *ptCifrado);
#endif
