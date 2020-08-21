#include "auxiliar.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}


void setColorTexto(WORD colors) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colors);
}

int sondeaTeclado() {
	fflush(stdin);
	if(_kbhit())
		return _getch();
	else
		return -1;
}

/* Dibuja una linea entre dos puntos de la consola */
void dibujaLinea(int origen[], int destino[], int colorOrigen) {
	int i, color;
	if(colorOrigen == 159)
		color = 0;
	if(colorOrigen == 207)
		color = 255;
		
	setColorTexto(color);

	if(origen[1] != destino[1]) {
		for(i = 0; i <= fabs(destino[1] - origen[1]); i++) {
			gotoxy(origen[0] - 1, 5 + origen[1] + i * ((origen[1] < destino[1]) - (origen[1] > destino[1])));
			printf("%c",179);
		}
	} else {
		gotoxy(origen[0] - 1, 5 + origen[1]);
		printf("%c",196);
	}

	setColorTexto(colorOrigen);
}
