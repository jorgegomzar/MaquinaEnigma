#include "stecker.h"


void fprintStecker(char stecker[], FILE *ptr, FILE *pCfg)
{
    /*PRIMERO EN DISTINTOS, ASIGNO LAS POSICIONES QUE HAN SIDO CAMBIADAS CON RESPECTO AL ABECEDARIO ORIGINAL
    Y EN LIBROCLAVES IMPRIMO LAS PAREJAS DE CARACTERES QUE HAN SIDO CAMBIADOS*/
    /*A CONTINUACION EN CONFIG.CFG IMPRIMO TODO EL ABECEDARIO STECKER*/

    int i,k,j,distinto=0;
    char abcdario[27];
    int distintos[20];
    k=0;
    for(i=0; i<20; i++)
    {
        distintos[i]=0;
    }
    for(i=0; i<26; i++)
    {
        abcdario[i]=(char)(i+65);
    }
    abcdario[26]=0;

    fprintf(ptr," ");

    for(i=0; i<26; i++)/*RECORRIDO POR TODO EL ABECEDARIO NORMAL Y EL STECKER*/
    {
        distinto=0;
        if(stecker[i]!=abcdario[i])/*SI LA LETRA DE LA POSICION I ES IGUAL NO OCURRE NADA, SI NO ES IGUAL SE GUARDA SU POSICION*/
        {
            if(i==0)/*SI LA POSICION ES LA PRIMERA DE AMBAS CADENAS SE GUARDA EN DISTINTOS*/
            {
                distintos[k]=i;
                k++;
            }
            else/*SI NO ES LA PRIMERA POSICION SE HACE UN RECORRIDO POR EL VECTOR STECKER Y SE COMPRUEBA SI YA HA SALIDO ESA LETRA*/
            {
                for(j=0; j<i; j++)
                {
                    if(stecker[j]!=abcdario[i])
                    {
                        distinto=1;/*PARA INDICAR QUE NO HA SALIDO ANTES*/
                    }
                    else
                    {
                        distinto=0;/*PARA INDICAR QUE YA HA SALIDO ANTES*/
                        break;
                    }

                }
                if(distinto==1)/*SI NO HA SALIDO SE GUARDA LA POSICION*/
                {
                    distintos[k]=i;
                    k++;
                }
            }
        }
    }

    for(i=0; i<10; i++)
    {
        k=distintos[i];
        fprintf(ptr, "%c%c ",abcdario[k], stecker[k]);
    }

    fprintf(pCfg, " ");

}

void genStecker(char stecker[])
{
    int vectorElegidos[20];
    int i, j, n1,n2;

    for(j=0; j<20; j++)
        vectorElegidos[j]=27;

    for(j=0; j<26; j++)
    {
        stecker[j]=(char)(65+j);
    }

    for (i=0; i<10; i++)
    {
        n1=rand()%26;
        n2=rand()%26;
        while (n1 == vectorElegidos[0] || n1 == vectorElegidos[1] || n1 == vectorElegidos[2] || n1 == vectorElegidos[3] || n1 == vectorElegidos[4] || n1 == vectorElegidos[5] || n1 == vectorElegidos[6] || n1 == vectorElegidos[7] || n1 == vectorElegidos[8] || n1 == vectorElegidos[9] || n1 == vectorElegidos[10] || n1 == vectorElegidos[11] || n1 == vectorElegidos[12] || n1 == vectorElegidos[13] || n1 == vectorElegidos[14] || n1 == vectorElegidos[15] || n1 == vectorElegidos[16] || n1 == vectorElegidos[17] || n1 == vectorElegidos[18] || n1 == vectorElegidos[19] )
        {
            n1=rand()%26;
        }
        while (n2==n1||n2 == vectorElegidos[0] || n2 == vectorElegidos[1] || n2 == vectorElegidos[2] || n2 == vectorElegidos[3] || n2 == vectorElegidos[4] || n2 == vectorElegidos[5] || n2 == vectorElegidos[6] || n2 == vectorElegidos[7] || n2 == vectorElegidos[8] || n2 == vectorElegidos[9] || n2 == vectorElegidos[10] || n2 == vectorElegidos[11] || n2 == vectorElegidos[12] || n2 == vectorElegidos[13] || n2 == vectorElegidos[14] || n2 == vectorElegidos[15] || n2 == vectorElegidos[16] || n2 == vectorElegidos[17] || n2 == vectorElegidos[18] || n2 == vectorElegidos[19] )
        {
            n2=rand()%26;
        }

        stecker[n1]=n2+65;
        stecker[n2]=n1+65;
        vectorElegidos[i*2] = n1;
        vectorElegidos[i*2+1] = n2;

    }
}


unsigned short 	opStecker (unsigned short posIn, char stecker[])
{
    /**DEVUELVE LA POSICION EN EL STECKER*/
    unsigned short letra;
    letra=stecker[posIn];
    return letra;
}
