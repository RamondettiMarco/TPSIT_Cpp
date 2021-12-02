typedef struct{

    char carattere[255];

}Stringa;

class Gestione_Files {
    // Variabili di Classe)
private:
    char NomeFIle_[255];
    char Path[255];
    char CarattereSeparatore;

public:
     Gestione_Files(); // costruttore
     void SetNomeFile(char nomefile[255]); //SET -> assegna un valore x = 3
     void GetNomeFile(char *nome); // GET -> return x
     void SetCarSeparatore(char sep);
     char GetCarSeparatore();
     int AggiungiRiga(char riga[255]);
     int LeggiPrimaRiga(char *Riga);
     int LeggiRigaN(char *Riga, int pos);
     int ContaRigheFile();
     int leggiTuttoFile(Stringa *strl, int nRighe);
     void split(char *s, Stringa *strl);
     int CancellaFile();
     int LeggiPrimaRigaGets(char *Riga);
     int ContaRigheFilePerAnno(int colonna, char *valore);
};


Gestione_Files::Gestione_Files()
{
    strcpy(NomeFIle_, "");
    CarattereSeparatore = ',';
}

int Gestione_Files::CancellaFile()
{
    FILE* Fp;
    int err = -1;

    Fp = fopen(NomeFIle_, "w"); // "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fclose(Fp);
    }
    return err;
}

void Gestione_Files::SetNomeFile(char nomefile[255])
{
    strcpy(NomeFIle_, nomefile);
}


void Gestione_Files::GetNomeFile(char *nome)
{
    strcpy(nome, NomeFIle_);
}

void Gestione_Files::SetCarSeparatore(char sep)
{
    CarattereSeparatore = sep;
}

char Gestione_Files::GetCarSeparatore()
{
    return CarattereSeparatore;
}

int Gestione_Files::LeggiPrimaRiga(char *riga)
{
    FILE* Fp;
    int err = -1;
    char st1[255];
    int nCaratteri = 0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fgets(st1, 255, Fp);
        nCaratteri = strlen(st1);

        if(nCaratteri < 0)
            {
                err = -2;
            }
        else
            {
                err = strlen(st1);
                strcpy(riga, st1);
            }
        fclose(Fp);
    }
    return err;
}

int Gestione_Files::AggiungiRiga(char riga[255])
{
    FILE* Fp;
    int err = -1;


    Fp = fopen(NomeFIle_, "a"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fprintf(Fp, "%s\n", riga);
        fclose(Fp);
    }

    return err;
}

int Gestione_Files::LeggiRigaN(char Riga[255], int pos)
{
    FILE* Fp;
    int err = -1;
    int Nriga=0;
    char st1[255];
    int nCaratteri = 0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fgets(st1, 255, Fp);
        nCaratteri = strlen(st1);
        //nCaratteri = fscanf(Fp, "%s", st1);
        while((Nriga!=pos) && (nCaratteri>0)){
            //nCaratteri = fscanf(Fp, "%s", st1);
            fgets(st1, 255, Fp);
            nCaratteri = strlen(st1);
            //printf("%s\n", st1);
            Nriga++;
        }
        if(nCaratteri < 0)
            {
                err = -2;
            }
        else
            {
                err = strlen(st1);
                strcpy(Riga, st1);
            }
        fclose(Fp);
    }
    return err;
}

int Gestione_Files::ContaRigheFile(){
    FILE *fp;
    char str[255], copia[255];
    int errore = -1, i = 0, numChar = 0;

    fp = fopen(NomeFIle_, "r");

    if(fp != NULL){
        errore = 0;
        fgets(str, 255, fp);
        numChar = strlen(str);
        while(numChar > 0){
            i++;
            fgets(str, 255, fp);
            //numChar = fscanf(fp, "%s", str);
            //printf("%s\n", str);
            numChar = strlen(str);
            if(strcmp(copia, str) == 0){
                numChar = -1;
            }
            strcpy(copia, str);
        }
        errore = i;
        fclose(fp);
    }

    return errore;
}

int Gestione_Files::ContaRigheFilePerAnno(int colonna, char *valore){
    FILE *fp;
    char str[255], copia[255];
    int errore = -1, i = 0, numChar = 0;
    Stringa campi[7];
    char valorecampo[255];

    fp = fopen(NomeFIle_, "r");

    if(fp != NULL){
        errore = 0;
        fgets(str, 255, fp);
        numChar = strlen(str);
        while(numChar > 0){
            split(str, campi);
            strcpy(valorecampo, campi[colonna].carattere);

            if(strcmp(valorecampo, valore) != 0){
                //printf("\nvalore campo: %s\n", valorecampo);
                i++;
            }

            fgets(str, 255, fp);
            numChar = strlen(str);

            if(strcmp(copia, str) == 0){
                numChar = -1;
            }
            strcpy(copia, str);
        }
        errore = i;
        fclose(fp);
    }

    return errore;
}

int Gestione_Files::leggiTuttoFile(Stringa *strl, int nRighe){
    FILE* Fp;
    int err = -1;
    int Nriga=0;
    char st1[255];
    int nCaratteri=0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fgets(st1, 255, Fp);
        nCaratteri = strlen(st1);

        while(nCaratteri>0){
            strcpy(strl[Nriga].carattere,st1);
            printf("%d %s\n",Nriga,st1);
            Nriga++;
            fgets(st1, nCaratteri, Fp);
            nCaratteri = strlen(st1);
        }
        err = Nriga;
        fclose(Fp);
    }
    return err;
}
void Gestione_Files::split(char *s, Stringa *strl){
        int lun, i = 0, nc = 0, j, c = 0;
    char campo[255], copia[255];

    lun = strlen(s);

    if(s[lun - 1] != CarattereSeparatore){
        s[lun] = CarattereSeparatore;
        s[lun + 1] = '\0';
    }

    while(strlen(s) > 0){
        // printf("split %s\n", s);
        i=0;
        while(s[i] != CarattereSeparatore){
            campo[i] = s[i];
            i++;
        }

        campo[i] = '\0';
        strcpy(strl[nc].carattere, campo);
        nc++;
        c = 0;
        int n = strlen(s);
        for(j = i + 1; j < n; j++){
            copia[c] = s[j];
            c++;
        }
        copia[c] = '\0';
        //printf("split copia : %s\n", copia);
        strcpy(s, copia);
    }
}

int Gestione_Files::LeggiPrimaRigaGets(char *riga)
{
    FILE* Fp;
    int err = -1;
    char st1[255];
    int nCaratteri = 0;

    Fp = fopen(NomeFIle_, "r"); // "a" scrive sul file gia esistente al fondo, mentre "w" cancella e riscrive

    if(Fp != NULL){
        err = 0;
        fgets(st1, 255, Fp);
        nCaratteri = strlen(st1);

        if(nCaratteri < 0)
            {
                err = -2;
            }
        else
            {
                err = strlen(st1);
                strcpy(riga, st1);
            }
        fclose(Fp);
    }
    return err;
}

