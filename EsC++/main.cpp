#include <iostream>

using namespace std;

class Prima_Classe {
    // Variabili di Classe)
private:
     int g_,m_,a_;
     bool val(int d, int m, int y);
public:
     void out();
     void incrementa();
     int differenza(int gg, int mm, int aa);
     Prima_Classe(int gg, int mm, int aa);//costruttore
};

int Prima_Classe::differenza(int gg, int mm, int aa)
{
    int giorni = 0;
    int giorniD = 0;
    int i;
    int j;
    int d;

    for(i = 1; i < m_-1; i++){
        if(i == 4 || i == 6 || i == 9 || i == 11){
            giorni = giorni + 30;
        }else if(i == 2){
            giorni = giorni + 28;
        }else{
            giorni = giorni + 31;
        }
    }
    giorni = giorni + (a_ - 1900) * 365;
    giorni = giorni + g_;

    for(j = 1; j <= mm-1; j++){
        if(j == 4 || j == 6 || j == 9 || j == 11){
            giorniD = giorniD + 30;
        }else if(j == 2){
            giorniD = giorniD + 28;
        }else{
            giorniD = giorniD + 31;
        }
    }
    giorniD = giorniD + ((aa - 1900) * 365);
    giorniD = giorniD + gg;

    /*if(a_ > aa){
        giorni = giorni + (365 * (a_-aa));
    }else if(aa > a_){
        giorniD = giorniD+ (365 * (aa-a_));
    }*/
    if(giorni > giorniD){
            d = giorni - giorniD;
        }else{
            d = giorniD - giorni;
        }

    return d;
}

void Prima_Classe::incrementa(){
    if(m_==4 || m_==6 || m_==9 || m_==11){
        if(g_ < 30) g_++;
        else {
            g_= 1;
            m_++;
        }
    }
    else if(m_ != 2){
        if(g_ < 31) g_++;
        else {
            g_= 1;
            m_++;
        }
    }
    else if(g_ < 28) g_++;
        else {
            g_= 1;
            m_++;
        }

}

void Prima_Classe::out(){
  if(g_== 0)cout << "data non valida";
  else cout << endl << g_ << "." << m_ << "." << a_ << endl; //endl va a capo
}
Prima_Classe::Prima_Classe(int gg,int mm,int aa){
  g_ = gg;
  m_ = mm;
  a_ = aa;
}

int main()
{
    Prima_Classe d(30,9,2021); //istanzio l'oggetto d di tipo D     ISTANZA == OGGETTO
    d.out();        //richiama il metodo out dell'oggetto d
    d.incrementa();
    d.out();

    int dif = d.differenza(10,2,2021);
    cout << endl << dif << endl;


    return 0;
}
