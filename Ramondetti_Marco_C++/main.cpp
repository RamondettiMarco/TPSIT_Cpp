#include <iostream>
#include <string.h>
#include <stdio.h>
#include "classGestione_Files.h"
#define DIM_STR 255
#include <stdlib.h>
#define COMUNI_2019 7914
#define DIM_CAMPI 7


using namespace std;

class comune{

private:
    char id_comune[DIM_STR];
    char anno[DIM_STR];
    char data_aggiornamento_istat[DIM_STR];
    char istat_comune[DIM_STR];
    char pop_maschile[DIM_STR];
    char pop_femminile[DIM_STR];
    char pop_totale[DIM_STR];

public:
    comune();
    void set_id_comune(char *valore);
    void set_anno(char *valore);
    void set_data_aggiornamento_istat(char *valore);
    void set_istat_comune(char *valore);
    void set_pop_maschile(char *valore);
    void set_pop_femminile(char *valore);
    void set_pop_totale(char *valore);
    char get_id_comune(char *valore);
    char get_anno(char *valore);
    char get_data_aggiornamento_istat(char *valore);
    char get_istat_comune(char *valore);
    char get_pop_maschile(char *valore);
    char get_pop_femminile(char *valore);
    char get_pop_totale(char *valore);
};

comune::comune(){
    strcpy(id_comune, "");
    strcpy(anno, "");
    strcpy(data_aggiornamento_istat, "");
    strcpy(istat_comune, "");
    strcpy(pop_maschile, "");
    strcpy(pop_femminile, "");
    strcpy(pop_totale, "");
}

void comune::set_anno(char *valore){
    strcpy(anno, valore);
}

void comune::set_id_comune(char *valore){
    strcpy(id_comune, valore);
}

void comune::set_istat_comune(char *valore){
    strcpy(istat_comune, valore);
}

void comune::set_pop_femminile(char *valore){
    strcpy(pop_femminile, valore);
}

void comune::set_pop_maschile(char *valore){
    strcpy(pop_maschile, valore);
}

void comune::set_pop_totale(char *valore){
    strcpy(pop_totale, valore);
}

void comune::set_data_aggiornamento_istat(char *valore){
    strcpy(data_aggiornamento_istat, valore);
}

char comune::get_istat_comune(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_pop_femminile(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_pop_maschile(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_pop_totale(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_data_aggiornamento_istat(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_anno(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

char comune::get_id_comune(char *valore){
    char copia[DIM_STR];
    strcpy(copia, valore);
    return *copia;
}

void selectionSort(Stringa *M)
{
    int q, j, pos;
    Stringa massimo;

	for(q = 0; q < COMUNI_2019; q++){
		strcpy(massimo.carattere, M[q].carattere);
		pos = q;
		for(j = q; j < COMUNI_2019; j++){
            int n1 = atoi(M[j].carattere);
            int n2 = atoi(massimo.carattere);
			if(n1 > n2){
				strcpy(massimo.carattere, M[j].carattere);
				pos = j;
			}
		}
		strcpy(massimo.carattere, M[q].carattere);
		strcpy(M[q].carattere, M[pos].carattere);
		strcpy(M[pos].carattere, massimo.carattere);

	}
}

int scritturaFile(char *nomeFile, Stringa *M)
{
    FILE *fOut;

    fOut = fopen(nomeFile, "w");
    if(fOut == NULL){
        printf("non sono riuscito ad aprire il file.");
        return -1;
    }
    for(int y = 0; y < 10; y++){ //inserisco soloi 10 maggiori
        fprintf(fOut, "\nCOMUNE:\n");
        fprintf(fOut, M[y].carattere);
    }

    fclose(fOut);
    return 0;
}

int main()
{
    Gestione_Files F;
    char nome[DIM_STR];
    strcpy(nome, "regpie-Limiti_amm_pop_9908-all.csv");
    F.SetNomeFile(nome);

    char anno[DIM_STR];
    strcpy(anno, "2019");
    int nR = F.ContaRigheFilePerAnno(1, anno); //1 = colonna degli anni
    printf("Numero righe Totale: %d\n", nR);

    F.SetCarSeparatore(';');

    comune static comuni[COMUNI_2019+1]; //7914 -> anno 2019

    char riga[DIM_STR];
    Stringa campi[DIM_CAMPI];

    Stringa static M[COMUNI_2019];
    Stringa static Fe[COMUNI_2019];
    Stringa static T[COMUNI_2019];

    for(int i = 1; i < COMUNI_2019+1; i++){ //+1 perché parto dalla riga 1 dato che la 0 ha i titoli

        F.LeggiRigaN(riga, i);
        printf("RIGA %d: %s \n", i, riga);

        F.split(riga, campi);

        cout << "ID COMUNE: "<< campi[0].carattere << endl;
        comuni[i].set_id_comune(campi[0].carattere);
        cout << "ANNO: "<< campi[1].carattere << endl;
        comuni[i].set_anno(campi[1].carattere);
        cout << "DATA AGGIORNAMENTO ISTAT: "<< campi[2].carattere << endl;
        comuni[i].set_data_aggiornamento_istat(campi[2].carattere);
        cout << "ISTAT COMUNE: "<< campi[3].carattere << endl;
        comuni[i].set_istat_comune(campi[3].carattere);
        cout << "POPOLAZIONE MASCHILE: "<< campi[4].carattere << endl;
        comuni[i].set_pop_maschile(campi[4].carattere);
        cout << "POPOLAZIONE FEMMINILE: "<< campi[5].carattere << endl;
        comuni[i].set_pop_femminile(campi[5].carattere);
        cout << "POPOLAZIONE TOTALE: "<< campi[6].carattere << endl;
        comuni[i].set_pop_totale(campi[6].carattere);

        //MASCHI
        strcpy(M[i].carattere, campi[4].carattere);
        //FEMMINE
        strcpy(Fe[i].carattere, campi[5].carattere);
        //TOT
        strcpy(T[i].carattere, campi[6].carattere);
    }

    //MASCHI

    selectionSort(M);

    char nomeFileM[DIM_STR];
    strcpy(nomeFileM, "Uomini.csv");

    scritturaFile(nomeFileM, M);

    //FEMMINE

    selectionSort(Fe);

    char nomeFileFe[DIM_STR];
    strcpy(nomeFileFe, "Donne.csv");

    scritturaFile(nomeFileFe, Fe);

    //TOT

    selectionSort(T);

    char nomeFileT[DIM_STR];
    strcpy(nomeFileT, "Totale.csv");

    scritturaFile(nomeFileT, T);

    return 0;
}
