#include "../config/config.h"

void leeConfig (struct sConfig * pConfig) {
	char nombreArchivo[27];
	int diaUsuario, auxDia, digitos = 0, m;
	char cDia[10];
	char error1[] = "¡No existe ningún mes de ";
	char error2[] = " días!";
	char titulo[] = "MENSAJE PARA TORPES";
	FILE *pCfg;
	char error3[] = "No se ha podido encontrar el archivo.\nPuede ser que aún no haya sido generado.";
	pConfig->dia = 0;
	cDia[9] = 0;
	error1[25] = 0;
	error2[6] = 0;

	if(pConfig->numRotores == 3) {
		if(pConfig->modeloETW == 'B')
			strcpy(nombreArchivo, "./BASEDATOS/libro_M3_B.bin");
		else
			strcpy(nombreArchivo, "./BASEDATOS/libro_M3_C.bin");
	} else {
		if(pConfig->modeloETW == 'B')
			strcpy(nombreArchivo, "./BASEDATOS/libro_M4_B.bin");
		else
			strcpy(nombreArchivo, "./BASEDATOS/libro_M4_C.bin");
	}

	/*ABRE EL FICHERO BINARIO Y AVISA SI HAY ALGUN PROBLEMA*/
	pCfg=fopen(nombreArchivo, "rb");
	if(pCfg == NULL) {
		setlocale(LC_CTYPE, "Spanish");
		MessageBox(0,error3,0,MB_OK);
		setlocale(LC_CTYPE, "C");
		gestionMenuPrincipal();
	}

	/*PIDO AL USUARIO QUE INTRODUZCA UN DIA*/
	scanf("%d", &diaUsuario); fflush(stdin);

	/*MENSAJE DE ERROR SI EL VALOR INTRODUCIDO NO ES VALIDO*/
	if(diaUsuario < 1 || diaUsuario > 31) {
		m = 0;
		auxDia = diaUsuario;

		while(diaUsuario != 0) {
			digitos++;
			diaUsuario = (diaUsuario / 10);
			m++;
		}
		for(m = digitos - 1; m >= 0; m--) {
			cDia[m] = (auxDia % 10) + 48;
			auxDia = auxDia / 10;
		}
		cDia[digitos] = 0;
		if(digitos == 0) {
			cDia[0] = 0 + 48;
			cDia[1] = '\0';
		}
		strcat(error1, cDia);
		strcat(error1, error2);
		setlocale(LC_CTYPE, "Spanish");
		MessageBox(0, error1, titulo, MB_OK);
		setlocale(LC_CTYPE, "C");
		inicCifrado();
	}

	/*COLOCO EL INDICADOR DE POSICION AL PRINCIPIO DE LA ESTRUCTURA QUE QUIERO LEER*/
	fseek(pCfg, (31 - diaUsuario) * sizeof(struct sConfig) + 31 - diaUsuario, SEEK_SET);
	/*LEO LA ESTRUCTURA*/
	fread(pConfig, 1, sizeof(struct sConfig), pCfg);

	if(pConfig->numRotores == 3) {
		pConfig->walzen[pConfig->numRotores] = 0;
		pConfig->ringS[pConfig->numRotores] = 0;
	}
	/*CIERRO EL ARCHIVO*/
	fclose(pCfg);
}


void muestraConfig (struct sConfig config) {
	/*MUESTRA LA CONFIGURACION EN PANTALLA*/
	int i, x = 2, longitud;
	char output[23];
	char letraRing[5];
	int k, j;
	bool distinto = false;
	char abcdario[27];
	int distintos[20];
	char mensaje[] = "Pulsa tecla para continuar...", auxiliar[80], auxiliar2[80];
	output[23] = 0;

	/*WALZENLAGE*/
	for(i = 0; i < 22; i++)
		output[i] = ' ';

	output[i] = 0;

	/*ESCRIBO EN UNA CADENA OUTPUT AUXILIAR LOS NUMEROS DE WALZEN EN NUMEROS ROMANOS*/
	for(i=0; i<config.numRotores; i++) {
		if(config.numRotores==3) {
			switch(config.walzen[i]) {
				case 1:
				/*EL PRIMER NUMERO SE GUARDA EN LA PRIMERA POSICION,
				DESPUES TODOS LOS DEMAS SE ASIGNAN EN UNA DISTANCIA DE 5 BYTES*/
					output[i*5] = 'I';
					break;
				case 2:
					output[i*5] = 'I';
					output[i*5+1] = 'I';
					break;
				case 3:
					output[i*5] = 'I';
					output[i*5+1] = 'I';
					output[i*5+2] = 'I';
					break;
				case 4:
					output[i*5] = 'I';
					output[i*5+1] = 'V';
					break;
				case 5:
					output[i*5] = 'V';
					break;
				case 6:
					output[i*5] = 'V';
					output[i*5+1] = 'I';
					break;
				case 7:
					output[i*5] = 'V';
					output[i*5+1] = 'I';
					output[i*5+2] = 'I';
					break;
				case 8:
					output[i*5] = 'V';
					output[i*5+1] = 'I';
					output[i*5+2] = 'I';
					output[i*5+3] = 'I';
					break;
			}
		} else {
			switch(config.walzen[i]) {
				case 1:
					/*EL PRIMER NUMERO SE GUARDA EN LA PRIMERA POSICION,
					DESPUES TODOS LOS DEMAS SE ASIGNAN EN UNA DISTANCIA DE 5 BYTES*/
					output[i*5+6] = 'I';
					break;
				case 2:
					output[i*5+6] = 'I';
					output[i*5+1+6] = 'I';
					break;
				case 3:
					output[i*5+6] = 'I';
					output[i*5+1+6] = 'I';
					output[i*5+2+6] = 'I';
					break;
				case 4:
					output[i*5+6] = 'I';
					output[i*5+1+6] = 'V';
					break;
				case 5:
					output[i*5+6] = 'V';
					break;
				case 6:
					output[i*5+6] = 'V';
					output[i*5+1+6] = 'I';
					break;
				case 7:
					output[i*5+6] = 'V';
					output[i*5+1+6] = 'I';
					output[i*5+2+6] = 'I';
					break;
				case 8:
					output[i*5+6] = 'V';
					output[i*5+1+6] = 'I';
					output[i*5+2+6] = 'I';
					output[i*5+3+6] = 'I';
					break;
				case 9:
					output[0] = 'B';
					output[1] = 'e';
					output[2] = 't';
					output[3] = 'a';
					break;
				case 10:
					output[0] = 'G';
					output[1] = 'a';
					output[2] = 'm';
					output[3] = 'm';
					output[4] = 'a';
					break;
			}
		}
	}
	/*CORTO LA LONGITUD DE LA CADENA*/
	output[i*5] = 0;

	/*------------------------------------------------------------------------------*/
	/*RINGSTELLUNG*/
	for(i=0; i<config.numRotores; i++)
		letraRing[i]=(char)(config.ringS[i]+64);

	letraRing[i]=0;

	/*------------------------------------------------------------------------------*/
	/*STECKER*/

	k=0;
	for(i = 0; i < 20; i++)
		distintos[i] = 0;

	for(i = 0; i < 26; i++)
		abcdario[i] = (char)(i+65);

	abcdario[26] = 0;

	/*RECORRIDO POR TODO EL ABECEDARIO NORMAL Y EL STECKER*/
	for(i = 0; i < 26; i++) {
		distinto = false;
		/*SI LA LETRA DE LA POSICION I ES IGUAL NO OCURRE NADA, SI NO ES IGUAL SE GUARDA SU POSICION*/
		if(config.stecker[i] != abcdario[i]) {
			/*SI LA POSICION ES LA PRIMERA DE AMBAS CADENAS SE GUARDA EN DISTINTOS*/
			if(i == 0) {
				distintos[k] = i;
				k++;
			}
			/*SI NO ES LA PRIMERA POSICION SE HACE UN RECORRIDO POR EL VECTOR STECKER Y SE COMPRUEBA SI YA HA SALIDO ESA LETRA*/
			else {
				for(j = 0; j < i; j++) {
					distinto = (config.stecker[j] != abcdario[i]);
					if(!distinto) break;
				}
				/*SI NO HA SALIDO SE GUARDA LA POSICION*/
				if(distinto) {
					distintos[k]=i;
					k++;
				}
			}
		}
	}

	/*------------------------------------------------------------------------------*/


	/**DISPLAY*/

	/*PRIMER RECUADRO*/
	gotoxy(2,1);
	setlocale(LC_CTYPE, "Spanish");
	printf("Configuración de Enigma");
	setlocale(LC_CTYPE, "C");
	/*SEGUNDO RECUADRO PRIMERA LINEA*/
	gotoxy(2,4);
	printf("UKW\t\t: %c\n", config.modeloETW);
	/*SEGUNDO RECUADRO SEGUNDA LINEA*/
	gotoxy(2,5);
	printf("Walzen\t: %s\n", output);
	/*SEGUNDO RECUADRO TERCERA LINEA*/
	gotoxy(2,6);

	if(config.numRotores==3)
		printf("Ringstellung  : %c-%d %c-%d %c-%d\n", letraRing[0], config.ringS[0], letraRing[1], config.ringS[1], letraRing[2], config.ringS[2]);
	else
		printf("Ringstellung  : %c-%d %c-%d %c-%d %c-%d\n", letraRing[0], config.ringS[0], letraRing[1], config.ringS[1], letraRing[2], config.ringS[2], letraRing[3], config.ringS[3]);

	/*SEGUNDO RECUADRO CUARTA LINEA*/
	gotoxy(2,7);
	printf("Stecker\t:");
	for(i = 0; i < 10; i++) {
		k = distintos[i];
		printf(" %c%c",abcdario[k], config.stecker[k]);
	}

	printf("\n");
	/*SEGUNDO RECUADRO QUINTA LINEA*/
	gotoxy(2,8);
	if(config.numRotores==3)
		printf("Grundstellung : %c %c %c\n", config.grund[0], config.grund[1], config.grund[2]);
	else
		printf("Grundstellung : %c %c %c %c\n", config.grund[0], config.grund[1], config.grund[2], config.grund[3]);

	gotoxy(2,11);/*TERCER RECUADRO UNICA LINEA*/
	for(i = 0; i < 48; i++)
		printf(" ");
	do {
		gotoxy(x,11);
		x -= 1;
		if (x < 2)
			x += 48;
		if(x + strlen(mensaje) > 49) {
			longitud = 49 - x;
			j = strlen(mensaje) - longitud;
			for(i = 0; i < longitud; i++)
				auxiliar[i] = mensaje[i];

			auxiliar[i] = 0;


			for(i = 0; i < j; i++) {
				auxiliar2[i] = mensaje[longitud + i];
				auxiliar2[j] = 0;

				gotoxy(2,11);
				printf("%s", auxiliar2);
				gotoxy(x,11);
				printf("%s", auxiliar);
			}
		}
		else
			printf("%s", mensaje);

		for(i=0; i!=50000000; i++);

		gotoxy(2,11);
		for (i = 0; i != 48; i++)
			printf(" ");
	}
	while(sondeaTeclado() == -1);
	setlocale(LC_CTYPE, "C");
}

void selecModelo(struct sConfig *pConfig) {
	int opcion,auxOpc, m, n, digitos = 0;
	char cOpcion[10];
	char error[] = "No existe la opción ";
	char titulo[] = "MENSAJE PARA TORPES";
	pConfig->modeloETW = ' ';

	cOpcion[9] = 0;
	error[21] = 0;
	/*DIBUJO LA NUEVA VENTANA*/
	system("cls");

	setlocale(LC_CTYPE, "C");
	printf(" %c",218);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	printf("%c ",191);
	printf(" %c",179);
	for(n = 0; n < 46; n++)
		printf(" ");

	/*RECUADRO SUPERIOR*/
	printf("%c\n",179);

	printf(" %c",192);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	printf("%c ",217);

	printf(" %c",218);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	printf("%c ",191);
	for(m = 0; m < 4; m++) {
		printf(" %c",179);
		for(n = 0; n < 46; n++)
			printf(" ");

		printf("%c\n",179);
	}

	printf(" %c",192);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	/*RECUADRO INTERMEDIO*/
	printf("%c ",217);

	printf(" %c",218);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	printf("%c  %c",191,179);
	setlocale(LC_CTYPE, "Spanish");
	/*RECUADRO INFERIOR*/
	printf(" Selecciona el modelo de Enigma:  ");
	setlocale(LC_CTYPE, "C");
	printf("\t        %c ",179);
	printf(" %c",192);
	for(m = 0; m < 46; m++)
		printf("%c",196);

	printf("%c ",217);

	/*AHORA DIBUJO LAS OPCIONES*/
	gotoxy(3,4);
	printf("1. 3-rotor M3 Kriegsmarine UKW = B");
	gotoxy(3,5);
	printf("2. 3-rotor M3 Kriegsmarine UKW = C");
	gotoxy(3,6);
	printf("3. 4-rotor M4 Kriegsmarine UKW = B");
	gotoxy(3,7);
	printf("4. 4-rotor M4 Kriegsmarine UKW = C");


	/*CURSOR EN EL RECUADRO INFERIOR Y ESPERA LA RESPUESTA DEL USUARIO*/
	gotoxy(35,10);
	fflush(stdin);
	scanf("%d", &opcion);

	/*MENSAJE DE ERROR SI EL VALOR INTRODUCIDO NO ES VALIDO*/
	if(opcion<1 || opcion>4) {
		m = 0;
		auxOpc=opcion;

		while(opcion != 0) {
			digitos++;
			opcion = (opcion / 10);
			m++;
		}
		for(m = digitos - 1; m >= 0; m--) {
			cOpcion[m] = (auxOpc % 10) + 48;
			auxOpc = auxOpc / 10;
		}
		cOpcion[digitos] = 0;
		if(digitos == 0) {
			cOpcion[0] = 0 + 48;
			cOpcion[1] = '\0';
		}
		strcat(error,cOpcion);
		setlocale(LC_CTYPE,"Spanish");
		MessageBox(0,error,titulo,MB_OK);
		setlocale(LC_CTYPE,"C");
		generaLibroClaves();
	} else {
		switch(opcion) {
			case 1:
				pConfig->numRotores=3;
				pConfig->modeloETW='B';
				break;
			case 2:
				pConfig->numRotores=3;
				pConfig->modeloETW='C';
				break;
			case 3:
				pConfig->numRotores=4;
				pConfig->modeloETW='B';
				break;
			case 4:
				pConfig->numRotores=4;
				pConfig->modeloETW='C';
				break;
		}
	}
}
