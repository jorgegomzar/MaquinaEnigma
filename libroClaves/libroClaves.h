#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "../config/config.h"

void gestionMenuPrincipal();
void generaLibroClaves();
void genWalzenlage (int nrotor, unsigned short walzen[]);
void fprintRingstellung (int nrotor, unsigned short ring[], FILE *ptr, FILE *pCfg);
void genRingstellung (int nrotor, unsigned short ring[]);
void genGrundstellung (int nrotor, char grund[]);
void fprintGrundstellung (int nrotor, char grund[], FILE *ptr, FILE *pCfg);
void fprintWalzenlage (int nrotor, unsigned short walzen[], FILE *ptr, FILE *pCfg);
void genStecker(char stecker[]);
void fprintStecker(char stecker[], FILE *ptr, FILE *pCfg);