#include "libroClaves.h"
#include "../auxiliar/auxiliar.h"

void generaLibroClaves() {
    /*GENERA EL LIBRO DE CLAVES Y EL ARCHIVO BINARIO*/
    int i,j;
    struct sConfig pConfig;
    FILE *ptr, *pCfg;
	char libro[35];
    pConfig.stecker[26] = 0;
    pConfig.grund[4] = 0;

    selecModelo(&pConfig);
    srand(time(NULL));

    for(j = 0; j < 26; j++)
        pConfig.stecker[j] = (char)(65 + j);

    pConfig.stecker[j] = 0;
    setlocale(LC_CTYPE,"C");

    if(pConfig.numRotores == 3) {
        if(pConfig.modeloETW == 'B') {
            ptr = fopen("./BASEDATOS/libro_M3_B.txt","wt");
            pCfg = fopen("./BASEDATOS/libro_M3_B.bin","wb");
            strcpy(libro,"notepad ./BASEDATOS/libro_M3_B.txt");
        } else {
            ptr = fopen("./BASEDATOS/libro_M3_C.txt","wt");
            pCfg = fopen("./BASEDATOS/libro_M3_C.bin","wb");
            strcpy(libro,"notepad ./BASEDATOS/libro_M3_C.txt");
        }
    } else {
        if(pConfig.modeloETW == 'B') {
            ptr = fopen("./BASEDATOS/libro_M4_B.txt","wt");
            pCfg = fopen("./BASEDATOS/libro_M4_B.bin","wb");
            strcpy(libro,"notepad ./BASEDATOS/libro_M4_B.txt");
        } else {
            ptr = fopen("./BASEDATOS/libro_M4_C.txt","wt");
            pCfg = fopen("./BASEDATOS/libro_M4_C.bin","wb");
            strcpy(libro,"notepad ./BASEDATOS/libro_M4_C.txt");
        }
    }
    rewind(pCfg);

    /*ENCABEZADOS PARA LOS DISTINTOS TIPOS DE ARCHIVO*/
    if(pConfig.numRotores == 3) {
        fprintf(ptr,"GEHEIM!                    SS SONDER-PROJEKT ABTEILUNG                   Januar 1942\n\n");
        fprintf(ptr,"--------------------------------------------------------------------------------------\n");
        fprintf(ptr,"|Tag |   Walzenlage   |Ringstellung|      Steckerverbindungen      |   Grundstellung  |\n");
        fprintf(ptr,"--------------------------------------------------------------------------------------\n");
    } else {
        fprintf(ptr,"GEHEIM!                        SS SONDER-PROJEKT ABTEILUNG                        Januar 1942\n\n");
        fprintf(ptr,"---------------------------------------------------------------------------------------------\n");
        fprintf(ptr,"|Tag |      Walzenlage      | Ringstellung  |      Steckerverbindungen      | Grundstellung |\n");
        fprintf(ptr,"---------------------------------------------------------------------------------------------\n");
    }

    for (i = 31; i != 0; i--) {
        if (i >= 10)
            fprintf(ptr,"| %d |",i);
        else
            fprintf(ptr,"|  %d |",i);

        pConfig.dia=i;
        for(j=0; j<pConfig.numRotores; j++)
            pConfig.walzen[j]=0;

        genGrundstellung(pConfig.numRotores,  pConfig.grund);
        genRingstellung(pConfig.numRotores, pConfig.ringS);
        genStecker(pConfig.stecker);
        genWalzenlage(pConfig.numRotores, pConfig.walzen);

        pConfig.dia=i;
        fwrite(&pConfig, 1, sizeof(struct sConfig), pCfg);

        fprintWalzenlage(pConfig.numRotores, pConfig.walzen, ptr, pCfg);
        fprintf(ptr,"|  ");
        fprintRingstellung(pConfig.numRotores, pConfig.ringS, ptr, pCfg);
        fprintf(ptr," |");
        fprintStecker(pConfig.stecker, ptr, pCfg);
        if(pConfig.numRotores==3)
            fprintf(ptr,"|       ");
        else fprintf(ptr,"|    ");

        fprintGrundstellung( pConfig.numRotores,  pConfig.grund, ptr, pCfg);

        if(pConfig.numRotores==3)
            fprintf(ptr,"     |\n");
        else fprintf(ptr,"   |\n");
    }
    if(pConfig.numRotores==3)
        fprintf(ptr,"---------------------------------------------------------------------------------------");
    else
        fprintf(ptr,"---------------------------------------------------------------------------------------------");

    fclose(ptr);
    fclose(pCfg);
	system(libro);

    gestionMenuPrincipal();
}


