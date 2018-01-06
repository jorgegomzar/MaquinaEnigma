#include "cifrado.h"


void inicCifrado()
{
    /**INICIALIZA EL CIFRADO Y REDIBUJA LA INTERFAZ*/

    struct sEnigma pEnigma;
    system("mode con cols=50 lines=12");


    configuracion(&pEnigma);

    configRotores(&pEnigma.listaRotores, pEnigma.config);
    /**----------------------------------CONTINUAR DESDE AQUI----------------------------------*/
    if(pEnigma.config.numRotores==3)
        dibujaInterfazM3();
    else dibujaInterfazM4();
    procesoCifrado(pEnigma);
}


void procesoCifrado(struct sEnigma pEnigma)
{
    char tecla;
    struct sPunto *coordRotor;
    int i, contadorTexto=0, contadorGrupos=0, salida=0,x=46, y1=8, y2=23, dx=0;
    int origen[2], destino[2];
    unsigned short posIn=0;
    FILE **ptPlano, **ptCifrado, *ptPlano1, *ptCifrado1;

    coordRotor=calloc(sizeof(struct sPunto),pEnigma.config.numRotores);
    coordRotor[0].x=10;
    coordRotor[0].y=2;
    for(i=1; i<pEnigma.config.numRotores; i++)
    {
        coordRotor[i].x=8+coordRotor[i-1].x;
        coordRotor[i].y=2;
    }
    if(pEnigma.config.numRotores==4)
        dx=8;

    ptPlano1=fopen("./BASEDATOS/MensajePlano.txt","wt");
    ptCifrado1=fopen("./BASEDATOS/MensajeCifrado.txt","wt");
    ptPlano=&ptPlano1;
    ptCifrado=&ptCifrado1;
    fclose(ptPlano1);
    fclose(ptCifrado1);
    abreArchivosMensaje(ptPlano, ptCifrado);
    setColorTexto(78);
    muestraEsquema(pEnigma, coordRotor);


    do /*BUCLE QUE SE REPITE MIENTRAS NO SE PULSE LA TECLA ESCAPE Y SOLO LEE CARACTERES ALFABETICOS*/
    {
        do
        {

            if(pEnigma.config.numRotores==3)
                tecla=leeLetra(0);
            else tecla=leeLetra(8);

            if(tecla==27)
                salida=27;
        }
        while((tecla==-1));/*SE REPITE MIENTRAS LA TECLA PULSADA NO SEA ALFABETICA O EL ESCAPE*/
        if(salida==27)/*SI LA TECLA ESCAPE ES PULSADA, SALIDA TOMA VALOR DE 27 Y SALE DEL BUCLE*/
        {
            break;
        }

        avanzaRotores(&pEnigma.listaRotores);
        muestraEsquema(pEnigma, coordRotor);
        origen[0]=38+dx,
                  origen[1]=5;

        for(i=0; i<26; i++) /*BUCLE PARA BORRAR LAS LINEAS*/
        {

            gotoxy(origen[0], origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-1, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-12, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-13, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-20, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-21, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-28, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-29, origen[1]+i);
            printf(" ");
            gotoxy(origen[0]-36, origen[1]+i);
            printf(" ");
            if(pEnigma.config.numRotores==4)
            {
                gotoxy(origen[0]-37, origen[1]+i);
                printf(" ");
                gotoxy(origen[0]-44, origen[1]+i);
                printf(" ");
            }

        }
        gotoxy(x+dx,y1);
        contadorTexto=contadorTexto+printLetraPlana(tecla, ptPlano1);
        if(contadorTexto==250)/*MENSAJE DE ALERTA SI EL MENSAJE EXCEDE LAS 250 LETRAS*/
        {
            salida=27;
            MessageBox(0,"El mensaje excede las 250 letras",0,MB_OK);

        }

        posIn=tecla-65;

        origen[0]=39+dx;
        origen[1]=posIn;

        setColorTexto(12);
        gotoxy(40+dx,5+posIn);
        printf("%c",tecla);
        gotoxy(39+dx,5+posIn);
        printf("%c",pEnigma.config.stecker[posIn]);


        Sleep(100);

        tecla=opStecker(posIn, pEnigma.config.stecker);/*SE CAMBIA LA TECLA PULSADA POR SU PAREJA EN EL STECKER*/
        posIn=tecla-65;

        destino[0]=origen[0]-2;
        destino[1]=posIn;

        dibujaLinea(origen, destino, 159);/**ESTE COMANDO ES UNA FUNCION CREADA POR MI EN AUXILIAR.C PARA DIBUJAR LAS LINEAS*/

        setColorTexto(12);
        origen[0]=origen[0]-12;
        origen[1]=destino[1];
        destino[0]=origen[0];

        gotoxy(36+dx,5+posIn);
        printf("%c",tecla);

        Sleep(100);

        gotoxy(32+dx,5+posIn);
        printf("%c",tecla);
        gotoxy(28+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].referencia[posIn]);
        gotoxy(27+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].cableado[posIn]);

        Sleep(100);

        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[2],0);/*SE CAMBIA LA TECLA DEVUELTA POR STECKER POR SU PAREJA EN EL PRIMER ROTOR*/
        posIn=tecla;
        destino[1]=posIn;

        dibujaLinea(origen, destino,159);

        setColorTexto(12);
        origen[0]=origen[0]-8;
        origen[1]=destino[1];
        destino[0]=origen[0];

        gotoxy(24+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].anillo[posIn]);
        gotoxy(20+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].referencia[posIn]);
        gotoxy(19+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].cableado[posIn]);

        Sleep(100);

        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[1],0);/*SE CAMBIA LA TECLA DEVUELTA POR EL PRIMER ROTOR POR SU PAREJA EN EL SEGUNDO ROTOR*/
        posIn=tecla;

        destino[1]=posIn;

        dibujaLinea(origen, destino, 159);

        setColorTexto(12);
        origen[0]=origen[0]-8;
        origen[1]=destino[1];
        destino[0]=origen[0];

        gotoxy(16+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].anillo[posIn]);
        gotoxy(12+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].referencia[posIn]);
        gotoxy(11+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].cableado[posIn]);

        Sleep(100);


        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[0],0);/*SE CAMBIA LA TECLA DEVUELTA POR EL SEGUNDO ROTOR POR SU PAREJA EN EL TERCER ROTOR*/
        posIn=tecla;

        destino[1]=posIn;

        dibujaLinea(origen, destino, 159);

        setColorTexto(12);
        origen[0]=origen[0]-8+dx;
        origen[1]=destino[1];
        destino[0]=origen[0];


        gotoxy(8+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].anillo[posIn]);




        if(pEnigma.config.numRotores==4)
        {
            gotoxy(12,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].referencia[posIn]);
            gotoxy(11,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].cableado[posIn]);

            Sleep(100);

            tecla=opRotor(posIn, pEnigma.listaRotores.rotor[3],0);/*SE CAMBIA LA TECLA DEVUELTA POR EL TERCER ROTOR POR SU PAREJA EN EL CUARTO ROTOR*/
            posIn=tecla;

            origen[0]=destino[0]-dx,
            destino[0]=destino[0]-dx;
            destino[1]=posIn;

            dibujaLinea(origen, destino, 159);

            setColorTexto(12);
            origen[0]=origen[0]-8;
            origen[1]=destino[1];
            destino[0]=origen[0];


            gotoxy(8,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].anillo[posIn]);

        }


        gotoxy(4,5+posIn);
        printf("%c",pEnigma.reflector.conexiones[posIn]);
        gotoxy(3,5+posIn);
        printf("%c",posIn+65);

        Sleep(100);

        tecla=opReflector(posIn, pEnigma.reflector);
        posIn=tecla-65;


        destino[1]=posIn;

        dibujaLinea(origen, destino, 159);

        setColorTexto(252);
        origen[0]=origen[0]+7;
        origen[1]=destino[1];
        destino[0]=origen[0];


        gotoxy(3,5+posIn);
        printf("%c",posIn+65);
        gotoxy(4,5+posIn);
        printf("%c",pEnigma.reflector.conexiones[posIn]);
        if(pEnigma.config.numRotores==4)
        {
            gotoxy(8,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].anillo[posIn]);

            tecla=opRotor(posIn, pEnigma.listaRotores.rotor[3],1);/*SE CAMBIA LA TECLA DEVUELTA POR EL REFLECTOR POR SU PAREJA EN EL CUARTO ROTOR*/
            posIn=tecla;

            destino[1]=posIn;

            dibujaLinea(origen, destino, 207);

            setColorTexto(252);
            origen[0]=origen[0]+8;
            origen[1]=destino[1];
            destino[0]=origen[0];

            gotoxy(11,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].cableado[posIn]);
            gotoxy(12,5+posIn);
            printf("%c",pEnigma.listaRotores.rotor[3].referencia[posIn]);

        }
        gotoxy(8+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].anillo[posIn]);

        Sleep(100);

        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[0],1);/*SE CAMBIA LA TECLA DEVUELTA POR EL REFLECTOR (o el 4 rotor) POR SU PAREJA EN EL PRIMER ROTOR*/
        posIn=tecla;

        destino[1]=posIn;

        dibujaLinea(origen, destino, 207);

        setColorTexto(252);
        origen[0]=origen[0]+8;
        origen[1]=destino[1];
        destino[0]=origen[0];

        gotoxy(11+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].cableado[posIn]);
        gotoxy(12+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[0].referencia[posIn]);
        gotoxy(16+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].anillo[posIn]);

        Sleep(100);

        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[1],1);/*SE CAMBIA LA TECLA DEVUELTA POR EL PRIMER ROTOR POR SU PAREJA EN EL SEGUNDO ROTOR*/
        posIn=tecla;

        destino[1]=posIn;

        dibujaLinea(origen, destino, 207);

        setColorTexto(252);
        origen[0]=origen[0]+8;
        origen[1]=destino[1];
        destino[0]=origen[0];

        gotoxy(19+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].cableado[posIn]);
        gotoxy(20+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[1].referencia[posIn]);
        gotoxy(24+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].anillo[posIn]);

        Sleep(100);

        tecla=opRotor(posIn, pEnigma.listaRotores.rotor[2],1);/*SE CAMBIA LA TECLA DEVUELTA POR EL SEGUNDO ROTOR POR SU PAREJA EN EL TERCER ROTOR*/
        posIn=tecla;

        destino[1]=posIn;

        dibujaLinea(origen, destino, 207);

        setColorTexto(252);
        origen[0]=origen[0]+12;
        origen[1]=destino[1];
        destino[0]=origen[0];


        gotoxy(27+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].cableado[posIn]);
        gotoxy(28+dx,5+posIn);
        printf("%c",pEnigma.listaRotores.rotor[2].referencia[posIn]);
        gotoxy(32+dx,5+posIn);
        printf("%c",posIn+65);
        gotoxy(36+dx,5+posIn);
        printf("%c",posIn+65);
        gotoxy(40+dx,5+posIn);
        printf("%c",posIn+65);

        Sleep(100);

        tecla=opStecker(posIn, pEnigma.config.stecker);

        dibujaLinea(origen, destino, 207);
        setColorTexto(252);
        gotoxy(39+dx,5+posIn);
        printf("%c",pEnigma.config.stecker[posIn]);
        Sleep(100);





        /*AHORA IMPRIMO LA TECLA CIFRADA*/

        gotoxy(x+dx,y2);
        setColorTexto(78);
        printLetraCifrada(tecla, ptCifrado1);
        setColorTexto(78);


        if((contadorTexto%5)==0)
        {
            contadorGrupos++;
            fprintf(ptPlano1, " ");
            fprintf(ptCifrado1, " ");
            x++;
        }
        if((contadorGrupos%5)==0 && contadorGrupos!=0)
        {
            y1++;
            x=45;
            contadorGrupos=0;
            fprintf(ptPlano1, "\n");
            y2++;
            fprintf(ptCifrado1, "\n");
        }
        x++;


    }
    while(salida!=27);/*SE REPITE MIENTRAS LA TECLA PULSADA NO SEA EL ESC*/

    cierraArchivosMensaje(ptPlano1, ptCifrado1);/*CIERRA LOS ARCHIVOS*/

    setlocale(LC_CTYPE,"C");
    gestionMenuPrincipal();/*REGRESA AL MENU PRINCIPAL*/




}


void abreArchivosMensaje(FILE **ptPlano, FILE **ptCifrado)/*ABRE MENSAJEPLANO.TXT Y MENSAJECIFRADO.TXT Y SALTA UNA ALERTA SI HAY PROBLEMAS EN LA APERTURA DE LOS ARCHIVOS*/
{
    if((*ptPlano=fopen("./BASEDATOS/MensajePlano.txt","wt"))==NULL)
    {
        MessageBox(0,"No se pudo abrir el archivo MensajePlano.txt.",0,MB_OK);
    }
    if((*ptCifrado=fopen("./BASEDATOS/MensajeCifrado.txt","wt"))==NULL)
    {
        MessageBox(0,"No se pudo abrir el archivo MensajeCifrado.txt.",0,MB_OK);
    }
}

char leeLetra(unsigned short dx)
{
    char letra;
    gotoxy(63+dx,2);
    letra=getch();
    if(letra>=97 && letra<=122)/*LEE POR TECLADO UNA LETRA, SI ES MINUSCULA LA CONVIERTE A MAYUSCULA Y SI NO ES UN CARACTER NUMÉRICO DEVUELVE -1*/
    {
        letra=letra-32;
    }
    else
    {
        if(letra!=27)
        {
            letra=-1;
        }
    }
    gotoxy(63+dx,2);


    return letra;
}

void    cierraArchivosMensaje	(	FILE *ptPlano, FILE *ptCifrado )/*CIERRA LOS ARCHIVOS*/
{
    fclose(ptPlano);
    fclose(ptCifrado);
}



