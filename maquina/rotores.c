#include "rotores.h"

void genWalzenlage(int nrotor, unsigned short walzen[]) {

    int i,n,num=0;
	/*GENERA 3 NUMEROS ALEATORIOS Y DISTINTOS ENTRE SI ENTRE 1 Y 8 INCLUSIVE Y SE ASIGNAN A WALZEN*/
    if(nrotor==3) {
        for (i=0; i<nrotor; i++) {
            num = 1 + rand() % 8;
            if (i>0) {
                for(n=0; n<i; n++) {
                    if (walzen[n]==num) {
                        num = 1 + rand() % 8;
                        n--;
                    }
                }
            }
            walzen[i]=num;
        }
    }
	/*GENERA 3 NUMEROS ALEATORIOS Y DISTINTOS ENTRE SI ENTRE 1 Y 8 INCLUSIVE Y UN CUARTO ROTOR ALEATORIO ENTRE BETA Y GAMMASE ASIGNAN A WALZEN*/
    if(nrotor==4) {
        for (i=0; i<nrotor-1; i++) {
            num=1+rand()%8;
            if (i>0) {
                for(n=0; n<i; n++) {
                    if (walzen[n]==num) {
                        num = 1 + rand() % 8;
                        n--;
                    }
                }
            }
            walzen[i]=num;
        }
        walzen[3] = 9 + rand() % 2;
    }
}

void fprintWalzenlage(int nrotor, unsigned short walzen[], FILE *ptr, FILE *pCfg) {
    /*DEPENDIENDO DE LOS NUMEROS QUE CONTENGA LA CADENA WALZEN, SE ASIGNAN SUS VALORES EN NUMEROS ROMANOS EN UNA CADENA AUXILIAR LLAMADA OUTPUT*/
    int i;
    char output[23];
    output[23]=0;
    if(nrotor==3) {
        for(i=0; i<15; i++)
            output[i]=' ';

        output[i]=0;
        for(i=0; i<nrotor; i++) {
            switch(walzen[i]) {
				case 1:
					/*EL PRIMER NUMERO SE GUARDA EN LA PRIMERA POSICION, DESPUES TODOS LOS DEMAS SE ASIGNAN EN UNA DISTANCIA DE 5 BYTES*/
					output[i*5]='I';
					break;
				case 2:
					output[i*5]='I';
					output[i*5+1]='I';
					break;
				case 3:
					output[i*5]='I';
					output[i*5+1]='I';
					output[i*5+2]='I';
					break;
				case 4:
					output[i*5]='I';
					output[i*5+1]='V';
					break;
				case 5:
					output[i*5]='V';
					break;
				case 6:
					output[i*5]='V';
					output[i*5+1]='I';
					break;
				case 7:
					output[i*5]='V';
					output[i*5+1]='I';
					output[i*5+2]='I';
					break;
				case 8:
					output[i*5]='V';
					output[i*5+1]='I';
					output[i*5+2]='I';
					output[i*5+3]='I';
					break;
            }
        }

		/*CORTO LA LONGITUD DE LA CADENA*/
        output[i*5]=0;
        fprintf(ptr," %s",output);
    }

	/*EN EL CASO DE HABER 4 ROTORES EL PROCEDIMIENTO SERIA PARECIDO PERO AUMENTANDO EL TAMA�O DE LA CADENA*/
    if(nrotor==4) {
        for(i=0; i<21; i++)
            output[i]=' ';

        output[i]=0;
        for(i=0; i<nrotor-1; i++) {
            switch(walzen[i]) {
				case 1:
					/*EL PRIMER NUMERO SE GUARDA EN LA SEPTIMA POSICION, DESPUES TODOS LOS DEMAS SE ASIGNAN EN UNA DISTANCIA DE 5 BYTES*/
					output[i*5+6]='I';
					break;
				case 2:
					output[i*5+6]='I';
					output[i*5+1+6]='I';
					break;
				case 3:
					output[i*5+6]='I';
					output[i*5+1+6]='I';
					output[i*5+2+6]='I';
					break;
				case 4:
					output[i*5+6]='I';
					output[i*5+1+6]='V';
					break;
				case 5:
					output[i*5+6]='V';
					break;
				case 6:
					output[i*5+6]='V';
					output[i*5+1+6]='I';
					break;
				case 7:
					output[i*5+6]='V';
					output[i*5+1+6]='I';
					output[i*5+2+6]='I';
					break;
				case 8:
					output[i*5+6]='V';
					output[i*5+1+6]='I';
					output[i*5+2+6]='I';
					output[i*5+3+6]='I';
					break;
            }
        }
		/*DEPENDIENDO DEL VALOR DEL 4 ROTOR ESCRIBO BETA O GAMMA*/
        if(walzen[3]==9) {
            output[0]='B';
            output[1]='e';
            output[2]='t';
            output[3]='a';
        } else {
            output[0]='G';
            output[1]='a';
            output[2]='m';
            output[3]='m';
            output[4]='a';
        }
        fprintf(ptr," %s",output);
    }
}

void genRingstellung(int nrotor, unsigned short ring[]) {
    int i;
    for (i=0; i<nrotor; i++)
        ring[i] = 1 + rand() % 26;
}

void fprintRingstellung(int nrotor, unsigned short ring[], FILE *ptr, FILE *pCfg) {
    int i;
    for(i=0; i<nrotor; i++)
        fprintf(ptr, "%.2d ", ring[i]);
}

void genGrundstellung (int nrotor, char grund[]) {
    /*GENERO NROTOR VECES LETRAS ALEATORIAS Y SE LAS ASIGNO A GRUND*/
    int i;
    for(i=0; i<nrotor; i++)
        grund[i]=(char)(65+rand()%26);
}

void fprintGrundstellung (int nrotor, char grund[], FILE *ptr, FILE *pCfg) {
    int i;
    for(i=0; i<nrotor; i++)
        fprintf(ptr, "%c ", grund[i]);
}

void leeCfgRotor(struct sRotor * pRotor) {
    /*DEL ARCHIVO CABLEADOROTORES.CFG ASIGNA A ROTOR UNA CADENA Y A MUESCA OTRA*/
    /*ESTA FUNCION SE LLAMA TANTAS VECES COMO NUMERO DE ROTORES HAYA*/
    FILE *ptx;
    int longitud, c;

    pRotor->anillo[26]=0;
    pRotor->cableado[26]=0;
    pRotor->referencia[26]=0;
    for(c=0; c<2; c++)
        pRotor->muesca[c]=' ';
    pRotor->muesca[c]=0;

	/**ABRO EL ARCHIVO DE LOS CABLEADOS Y SI HAY UN ERROR AVISA AL USUARIO*/
    ptx=fopen("./BASEDATOS/cableadoRotores.cfg", "rt");
    if(ptx==NULL) {
        system("cls");
        system("pause");
        gestionMenuPrincipal();
    }
	/*SI EL NUMERO DEL ROTOR ES MENOR O IGUAL QUE 5 COLOCO EL PUNTERO AL PRINCIPIO DE SU LINEA CORRESPONDIENTE*/
    if(pRotor->num<=5) {
        longitud=30*(pRotor->num-1);
        fseek(ptx,longitud,0);
    } else {
		/*SI ES MAYOR, COJO EL PUNTERO AL PRINCIPIO DE SU LINEA CORRESPONDIENTE*/
        pRotor->num=pRotor->num-6;
        longitud=((31*pRotor->num)+150);
        fseek(ptx,longitud, 0);
        pRotor->num+=6;
    }

    fgets(pRotor->cableado, 27, ptx);
    pRotor->cableado[26]=0;
    fseek(ptx,sizeof(char),SEEK_CUR);

    if(pRotor->num<9) {
        if(pRotor->num<=5) {
            fgets(pRotor->muesca, 2, ptx);
            pRotor->muesca[1]=0;
        } else {
            fgets(pRotor->muesca, 3, ptx);
            pRotor->muesca[2]=0;
        }
    }
    fclose(ptx);
}

void configRotores(struct sListaRotores * lista, struct sConfig config) {
    /**CONFIGURA LOS ROTORES*/
    int i, num;

    for(i=0; i<lista->num; i++) {
        num = config.grund[i] - 65;
        configAnillos(&lista->rotor[i], config.ringS[i]);
        pasoRotor(&lista->rotor[i], num);
    }
}

void configAnillos (struct sRotor * pRotor, int pos) {
    /*CONFIGURA LOS ANILLOS DEPENDIENDO DE RINGSTELLUNG*/
    int i,k;
    char auxiliar[26];
    auxiliar[25]=0;

	/*SUMO A TODAS LAS LETRAS DE CADA ROTOR POS-1 Y SI SOBREPASAN LA Z HAGO QUE DEN LA VUELTA AL ABECEDARIO*/
    for(i=0; i<26; i++) {
        auxiliar[i]=pRotor->anillo[i]+pos-1;
        pRotor->anillo[i]=auxiliar[i];
        if(pRotor->anillo[i]>'Z')
            pRotor->anillo[i]=auxiliar[i]-26;
    }

    /*AHORA NECESITO BAJAR ROTOR[1] Y ROTOR[2] TANTAS VECES COMO POS-1*//**MODIFICAR PARA QUE LA SINTAXIS CUADRE CON LAS ESTRUCTURAS*/
    for(i=0; i<26; i++)
        auxiliar[i]=pRotor->cableado[i];

    for(i=0; i<26; i++) {
        if((i-(pos-1))>=0)
            pRotor->cableado[i]=auxiliar[i-(pos-1)];

        if((i-(pos-1))<0) {
            k=(i-(pos-1))+26;
            pRotor->cableado[i]=auxiliar[k];
        }
    }

    for(i=0; i<26; i++)
        auxiliar[i]=pRotor->referencia[i];

    for(i=0; i<26; i++) {
        if((i-(pos-1))>=0)
            pRotor->referencia[i]=auxiliar[i-(pos-1)];

        if((i-(pos-1))<0) {
            k=(i-(pos-1))+26;
            pRotor->referencia[i]=auxiliar[k];

        }
    }
}


void pasoRotor	(struct sRotor * pRotor, int num) {
    /**ADELANTA LOS ROTORES NUM VECES(LA PRIMERA VEZ QUE ES LLAMADO MUEVE LOS ROTORES LO QUE INDICE GRUNDSTELLUNG, LA SEGUNDA ES SIEMPRE 1)*/
    int i,k;
    char aux[27];
    aux[26]=0;
    /*ADELANTO ANILLO*/
    for(i=0; i<26; i++)
        aux[i]=pRotor->anillo[i];

    for(i=0; i<26; i++) {
        k=i+num;
        if(k>25)
            k=k-26;

        pRotor->anillo[i]=aux[k];
    }

    /*ADELANTO CABLEADO*/
    for(i=0; i<26; i++)
        aux[i]=pRotor->cableado[i];

    for(i=0; i<26; i++) {
        k=i+num;
        if(k>25)
            k-=26;

        pRotor->cableado[i]=aux[k];
    }

    /*ADELANTO REFERENCIA*/
    for(i=0; i<26; i++)
        aux[i]=pRotor->referencia[i];

    for(i=0; i<26; i++) {
        k=i+num;
        if(k>25)
            k-=26;

        pRotor->referencia[i]=aux[k];
    }
}


void dibujaRotor (struct sRotor rotor, struct sPunto coordRotor) {
    /**MUESTRA LOS ROTORES POR PANTALLA*/
    int i, x=coordRotor.x,y=coordRotor.y;
    char output[5];
    gotoxy(x,y);

	/*ESCRIBO EL PRIMER CARACTER DE RINGSTELLUNG*/
    printf("%c", rotor.anillo[0]);
    x-=2;
    y+=3;
    setColorTexto(206);

	/*IMPRIME EL ANILLO EN UN COLOR DISTINTO Y MARCA LAS MUESCAS DE OTRO COLOR*/
    for(i=0; i<26; i++) {
        gotoxy(x,y);
        if(rotor.anillo[i]==rotor.muesca[0] || rotor.anillo[i]==rotor.muesca[1])
            setColorTexto(169);

        printf("%c", rotor.anillo[i]);
        setColorTexto(206);
        y++;
    }
    setColorTexto(78);

    x+=2;
    y=coordRotor.y+3;

	/*IMPRIME EL CABLEADO*/
    for(i=0; i<26; i++) {
        gotoxy(x+1,y);
        printf("%c", rotor.cableado[i]);
        y++;
    }

    y-=26;
    x++;
    
	/*IMPRIME LA REFERENCIA*/
	for(i=0; i<26; i++) {
        gotoxy(x+1,y);
        printf("%c", rotor.referencia[i]);
        y++;
    }

    x=(coordRotor.x-1);
    y=(coordRotor.y+31);

    gotoxy(x, y);
    for(i=0; i<5; i++)
        output[i]=' ';

    output[i]=0;
    output[i-1]=0;
    i=0;

    switch(rotor.num) {
		case 1:
			/*EL PRIMER NUMERO SE GUARDA EN LA PRIMERA POSICION, DESPU�S TODOS LOS DEM�S SE ASIGNAN EN LAS SIGUIENTES*/
			output[i]='I';
			break;
		case 2:
			output[i]='I';
			output[i+1]='I';
			break;
		case 3:
			output[i]='I';
			output[i+1]='I';
			output[i+2]='I';
			break;
		case 4:
			output[i]='I';
			output[i+1]='V';
			break;
		case 5:
			output[i]='V';
			break;
		case 6:
			output[i]='V';
			output[i+1]='I';
			break;
		case 7:
			output[i]='V';
			output[i+1]='I';
			output[i+2]='I';
			break;
		case 8:
			output[i]='V';
			output[i+1]='I';
			output[i+2]='I';
			output[i+3]='I';
			break;
		case 9:
			output[i]='B';
			output[i+1]='e';
			output[i+2]='t';
			output[i+3]='a';
			break;
		case 10:
			gotoxy(8,y);
			output[i]='G';
			output[i+1]='a';
			output[i+2]='m';
			output[i+3]='m';
			output[i+4]='a';
			break;
    }
    printf("%s",output);/*IMPRIMO EL NUMERO DEL ROTOR EN NUMEROS ROMANOS*/
}

void avanzaRotores (struct sListaRotores * pListaRotores) {
    /**MUEVE LOS ROTORES*/
    pasoRotor(&pListaRotores->rotor[2],1);

    if(pListaRotores->rotor[2].anillo[25]==pListaRotores->rotor[2].muesca[0] || pListaRotores->rotor[2].anillo[25]==pListaRotores->rotor[2].muesca[1])
        pasoRotor(&pListaRotores->rotor[1],1);

    if(pListaRotores->rotor[1].anillo[0]==pListaRotores->rotor[1].muesca[0] || pListaRotores->rotor[2].anillo[0]==pListaRotores->rotor[2].muesca[1]) {
        pasoRotor(&pListaRotores->rotor[1],1);
        pasoRotor(&pListaRotores->rotor[0],1);
    }
}

unsigned short opRotor (unsigned short in, struct sRotor rotor, bool dir) {
    /**DEVUELVE LA POSICION DE UN ELEMENTO DEL ROTOR*/
    unsigned short valor;
    int i;
    if(!dir)
        for(i=0; i<26; i++)
            if(rotor.anillo[i]==rotor.cableado[in])
                valor=i;
	else
        for(i=0; i<26; i++)
            if(rotor.cableado[i]==rotor.anillo[in])
                valor=i;

    return valor;
}