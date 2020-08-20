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








/*VERSION 1

void genWalzenlage(int nrotor, char rotores[]);
void fprintWalzenlage(int nrotor, char rotor[], FILE *ptr);
void genStecker(char conexiones[]);
void fprintStecker(char conex[], FILE *ptr);
void genRingstellung(int nrotor, char *ring);
void fprintRingstellung(int rotor, char ring[], FILE *ptr);
void genKenngruppen(char grupos[]);
void fprintKenngruppen(char grupos[], FILE *ptr);*/
