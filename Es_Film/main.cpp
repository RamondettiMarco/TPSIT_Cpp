#include <iostream>
#include <string.h>
#include <stdio.h>
#include "classGestione_Files.h"

using namespace std;

class film {
private:
    char id[100];
    char titolo[250];
    char anno[5];
    char genere[100];
    char stato[50];
public:
    film();
    void set_id(char *valore);
    char get_id(char *valore);
    void set_anno(char *valore);
    char get_anno(char *valore);
    void set_stato(char *valore);
    char get_stato(char *valore);
    void set_titolo(char *valore);
    char get_titolo(char *valore);
    void set_genere(char *valore);
    char get_genere(char *valore);

};

 film::film(){
    strcpy(titolo, "");
    strcpy(genere, "");
    strcpy(stato, "");
    strcpy(anno, "");
    strcpy(id, "");
}

void film::set_id(char *valore){
    strcpy(id, valore);
}
void film::set_anno(char *valore){
    strcpy(anno, valore);
}
void film::set_titolo(char *valore){
    strcpy(titolo, valore);
}
void film::set_genere(char *valore){
    strcpy(genere, valore);
}
void film::set_stato(char *valore){
    strcpy(stato, valore);
}


char film::get_id(char *valore){
    char copia[255];
    strcpy(copia, valore);
    return *copia;
}

char film::get_anno(char *valore){
    char copia[255];
    strcpy(copia, valore);
    return *copia;
}

char film::get_genere(char *valore){
    printf("VALORE: %s", valore);
    return *valore;
}

char film::get_stato(char *valore){
    return *valore;
}

char film::get_titolo(char *valore){
    char copia[255];
    strcpy(copia, valore);
    return *copia;
}


int main()
{
    /*film Movie;
    Movie.set_id(1);
    Movie.set_titolo("Tenet");
    Movie.set_anno(2020);
    Movie.set_genere("Fantascienza, thriller");
    Movie.set_stato("Disponibile");

    Movies[1].set_id(2);
    Movies[1].set_titolo("1917");
    Movies[1].set_anno(2019);
    Movies[1].set_genere("Guerra");
    Movies[1].set_stato("Esaurito");*/

    Gestione_Files F;
    F.SetNomeFile("film.csv");
    F.SetCarSeparatore(',');
    int contaRighe;
    contaRighe = F.ContaRigheFile();
    //printf("%d\n\n", contaRighe);
    film Movies[contaRighe];
    int cnt, nCar;
    char riga[255];
    Stringa campi[5];
    for(cnt=1; cnt<=contaRighe; cnt++){
        nCar = F.LeggiRigaN(riga, cnt);
        F.split(riga, campi);
        Movies[cnt-1].set_id(campi[0].carattere);
        cout << "\n\nID: " << Movies[cnt-1].get_id(campi[0].carattere) << endl;
        Movies[cnt-1].set_titolo(campi[1].carattere);
        cout << "NOME FILM: " << Movies[cnt-1].get_titolo(campi[1].carattere)<< endl;
        Movies[cnt-1].set_genere(campi[2].carattere);
        cout << "GENERE: " << Movies[cnt-1].get_genere(campi[2].carattere)<< endl;
        Movies[cnt-1].set_anno(campi[3].carattere);
        cout << "ANNO: " << Movies[cnt-1].get_anno(campi[3].carattere)<< endl;
        Movies[cnt-1].set_stato(campi[4].carattere);
        cout << "STATO: " << Movies[cnt-1].get_stato(campi[4].carattere)<< endl;

        cout << "\nID: "<< campi[0].carattere << endl;
        cout << "NOME FILM: "<< campi[1].carattere << endl;
        cout << "GENERE: "<< campi[2].carattere << endl;
        cout << "ANNO: "<< campi[3].carattere << endl;
        cout << "STATO: "<< campi[4].carattere << endl;
    }



    return 0;

}
