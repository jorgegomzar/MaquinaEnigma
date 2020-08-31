#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "../maquina/enigma.h"
#include "../auxiliar/punto.h"
void    dibujaInterfazM3();
void    dibujaInterfazM4();
void    gestionMenuPrincipal();
void 	muestraEsquema (struct sEnigma enigma, struct sPunto coordRotor[]);
void 	dibujaEstator (unsigned short dx);
unsigned short 	printLetraPlana (char letra, FILE *ptPlano);
void 	printLetraCifrada (char letra, FILE *ptCifrado);
void 	dibujaStecker (char stecker[], unsigned short dx);
void    dibujaRotor(struct sRotor rotor, struct sPunto coordRotor);
void 	dibujaReflector (struct sReflector reflector);
#endif