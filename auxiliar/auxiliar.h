#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void gotoxy(int x, int y);
void setColorTexto(WORD colors);
int sondeaTeclado();
void dibujaLinea(int origen[], int destino[], int colorOrigen);
