#include "reflector.h"
unsigned short 	opReflector (unsigned short in, struct sReflector reflector)
{
    /**DEVUELVE LA POSICION DEL REFLECTOR*/
    unsigned short valor;

    valor=reflector.conexiones[in];

    return valor;

}

void 	leeCfgReflector (char archivo[], struct sReflector * pRef)
{
    /**LEE EL ARCHIVO CON LAS CONFIGURACIONES DE LOS REFLECTORES B Y C*/
    FILE *pRft;

    pRft=fopen(archivo,"rt");/*ABRO EL ARCHIVO EN FORMATO DE LECTURA DE TEXTO*/
    if(pRft==NULL)
    {
        system("cls"); puts("\n\n\n\n\n\n\n\n\n\n\n   Error al abrir el archivo reflector.cfg\n"); system("pause");
        inicCifrado();
    }

    if(pRef->modelo=='B')/*SI EL REFLECTOR ES DE TIPO B LEO LA PRIMERA LINEA Y SE LA ASIGNO A CONEX*/
    {
        fseek(pRft, 2, SEEK_SET);
        fgets(pRef->conexiones,27,pRft);
        pRef->conexiones[27]=0;
    }

    if(pRef->modelo=='C')/*SI EL REFLECTOR ES DE TIPO C LEO LA SEGUNDA LINEA Y SE LA ASIGNO A CONEX*/
    {
        fseek(pRft, 32,SEEK_SET);
        fgets(pRef->conexiones, 27,pRft);
        pRef->conexiones[27]=0;
    }

    fclose(pRft);/*CIERRO EL ARCHIVO*/

}

void 	dibujaReflector (struct sReflector reflector)
{
    /**MUESTRA EL REFLECTOR POR PANTALLA*/
    int i, x=3, y=5;
    for(i=0; i<26; i++)
    {
        gotoxy(x,y);
        printf("%c",i+65);
        gotoxy(x+1,y);
        printf("%c",reflector.conexiones[i]);
        y++;

    }
    gotoxy(x,y+2);
    printf("%c", reflector.modelo);


}

