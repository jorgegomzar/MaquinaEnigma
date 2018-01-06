
#include "auxiliar.h"


void gotoxy(int x, int y)
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return;
}


void setColorTexto(WORD colors)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colors);
}

int sondeaTeclado()
{
    fflush(stdin);

    if(_kbhit())
        return _getch();
    else
        return -1;
}


void cambiarMarco(int origen, int fin, char coordenadaCte, int constante, int numMarco, int direccion)
{
    /*FUNCION CREADA POR MI PARA REDIBUJAR LOS MARCOS*/
    int i;
    if(coordenadaCte=='x')
    {
        if(direccion<0)
        {
            for(i=origen; i<=fin; i++)
            {
                setColorTexto(252);
                gotoxy(constante,i);
                printf("%c",numMarco);
            }

            Sleep(100);



            for(i=origen; i<=fin; i++)
            {
                setColorTexto(249);
                gotoxy(constante,i);
                printf("%c",numMarco);
            }

        }
        if(direccion>0)
        {
            for(i=fin; i>=origen; i--)
            {
                setColorTexto(252);
                gotoxy(constante,i);
                printf("%c",numMarco);

            }

            Sleep(100);



            for(i=fin; i>=origen; i--)
            {
                setColorTexto(249);
                gotoxy(constante,i);
                printf("%c",numMarco);
            }

        }

    }
    if(coordenadaCte=='y')
    {
        if(direccion>0)
        {
            for(i=origen; i<=fin; i++)
            {
                setColorTexto(252);
                gotoxy(i,constante);
                printf("%c",numMarco);

            }
            Sleep(100);


            for(i=origen; i<=fin; i++)
            {
                setColorTexto(249);
                gotoxy(i,constante);
                printf("%c",numMarco);
            }
        }
        if(direccion<0)
        {
            for(i=fin; i>=origen; i--)
            {
                setColorTexto(252);
                gotoxy(i,constante);
                printf("%c",numMarco);

            }
            Sleep(100);


            for(i=fin; i>=origen; i--)
            {
                setColorTexto(249);
                gotoxy(i,constante);
                printf("%c",numMarco);
            }
        }

    }

}


void dibujaLinea(int origen[], int destino[], int colorOrigen)/*FUNCION CREADA POR MI PARA DIBUJAR LAS LINEAS*/
{
    int i, color;
    if(colorOrigen==159)
        color=0;
    if(colorOrigen==207)
        color=255;
    setColorTexto(color);




    if(origen[1]<destino[1])
    {

        for(i=0; i<=(destino[1]-origen[1]); i++)
        {
            gotoxy(origen[0]-1,5+origen[1]+i);
            printf("%c",179);
        }
    }


    if(origen[1]>destino[1])
    {

        for(i=0; i<=(origen[1]-destino[1]); i++)
        {
            gotoxy(origen[0]-1,5+origen[1]-i);
            printf("%c",179);
        }
    }
    if(origen[1]==destino[1])
    {
        gotoxy(origen[0]-1,5+origen[1]);
        printf("%c",196);

    }

    setColorTexto(colorOrigen);



}
