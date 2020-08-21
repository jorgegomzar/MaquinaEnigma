#include "enigma.h"

void configuracion(struct sEnigma * pEnigma) {
	int i, m, n;
	free(pEnigma);

	/*PIDE AL USUARIO QUE SELECCIONE EL MODELO CON EL QUE QUIERE OPERAR*/
	selecModelo(&(pEnigma->config));

	pEnigma->reflector.modelo = pEnigma->config.modeloETW;
	/*AHORA DEPENDIENDO DEL NUMERO DE ROTORES ASIGNO AL VECTOR DINAMICO EL TAMAÑO ADECUADO*/

	pEnigma->listaRotores.rotor = calloc(sizeof(struct sRotor), pEnigma->config.numRotores);
	for(n = 0; n < pEnigma->config.numRotores; n++) {
		for(i = 0; i < 26; i++) {
			pEnigma->listaRotores.rotor[n].anillo[i] = i + 65;
			pEnigma->listaRotores.rotor[n].referencia[i] = i + 65;
		}
		pEnigma->listaRotores.rotor[n].anillo[i] = 0;
		pEnigma->listaRotores.rotor[n].referencia[i] = 0;
	}

	/*DIBUJO LA NUEVA VENTANA*/
	system("cls");
	system("mode con cols=51 lines=14");
	setlocale(LC_CTYPE, "C");
	printf("%c",218);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	printf("%c",191);
	printf("%c",179);
	for(n = 0; n < 49; n++)
		printf(" ");

	/*RECUADRO SUPERIOR*/
	printf("%c\n",179);

	printf("%c",192);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	printf("%c",217);

	printf("%c",218);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	printf("%c",191);
	for(m = 0; m < 5; m++) {
		printf("%c",179);
		for(n = 0; n < 49; n++)
			printf(" ");

		printf("%c\n",179);
	}
	printf("%c",192);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	/*RECUADRO INTERMEDIO*/
	printf("%c",217); 
	printf("%c",218);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	printf("%c%c",191,179);
	setlocale(LC_CTYPE, "Spanish");
	/*RECUADRO INFERIOR*/
	printf("   Introduce dia del libro de claves: ");
	setlocale(LC_CTYPE, "C");
	printf("\t\t  %c",179);
	printf("%c",192);
	for(m = 0; m < 49; m++)
		printf("%c",196);

	printf("%c",217);
	/*CURSOR EN EL RECUADRO INFERIOR Y ESPERA LA RESPUESTA DEL USUARIO*/
	gotoxy(39,11);
	fflush(stdin);

	/*LEE EL ARCHIVO BINARIO*/
	leeConfig (&pEnigma->config);
	pEnigma->listaRotores.num = pEnigma->config.numRotores;
	pEnigma->reflector.modelo = pEnigma->config.modeloETW;

	for(i = 0; i < pEnigma->listaRotores.num; i++) {
		pEnigma->listaRotores.rotor[i].num = pEnigma->config.walzen[i];
		leeCfgRotor(&pEnigma->listaRotores.rotor[i]);
	}
	leeCfgReflector("./BASEDATOS/reflector.cfg",&pEnigma->reflector);
	muestraConfig(pEnigma->config);
}