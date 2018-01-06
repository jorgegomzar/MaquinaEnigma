#ifndef REFLECTOR_H_INCLUDED
#define REFLECTOR_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <windows.h>

struct sReflector
{
    char conexiones[27];
    char modelo;
};

unsigned short 	opReflector (unsigned short in, struct sReflector reflector);
void 	leeCfgReflector (char archivo[], struct sReflector * pRef);
void 	dibujaReflector (struct sReflector reflector);
void    gotoxy(int x, int y);
void inicCifrado();
#endif
