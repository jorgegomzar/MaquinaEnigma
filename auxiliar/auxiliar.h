#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
void gotoxy(int x, int y);
void setColorTexto(WORD colors);
int sondeaTeclado();
void cambiarMarco(int origen, int fin, char coordenadaCte, int constante, int numMarco, int direccion);
void dibujaLinea(int origen[], int destino[], int colorOrigen);
