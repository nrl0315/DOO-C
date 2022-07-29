#include<iostream>
#include<string>
using namespace std ;

string palabra_original ;
string palabra_mostrar ;
int vidas ;
string palabraCorta;
string palabraIntermedia;
string palabraAvanzada;
int bonoFacil = 5;
int bonoIntermedio = 6;
int bonoAvanzado = 8;
int bono = 0;
int puntos = 0;
char *bancoFacil[] = {"carro", "perro","papa"};
char *bancoIntermedio[] = {"aeropuerto","prestamo","orientado"};
char *bancoAvanzado[] = {"parangutirimicuaro","otorrinolaringologia"};

void mostrar() ;
void ingresar(char x) ;
void inicializar() ;
void menu();
void menuAdmin();
void vidasJuego();

int main(){
    menu();
}

void vidasJuego(){
    while(vidas>0 && palabra_mostrar!=palabra_original){
        char x ;
        cin >> x ;
        ingresar(x) ;
        mostrar() ;
    }
    if(vidas>0 && palabra_original.length() == palabraCorta.length()){
        cout << "ganaste!, tienes un punto " << endl ;
        puntos = puntos + 1;
        if(bonoFacil == vidas){
            bono = bono + 1;
            cout << "Tienes un bono por adivinar la palabra completa de " << bono << " puntos" << endl;
        } else{
            cout << "No has ganado bono" << endl;
        }
    } else if(vidas > 0 && palabra_original.length() == palabraIntermedia.length()){
        cout << "Ganaste!, tienes 2 puntos" << endl;
        puntos = puntos + 2;
        if(bonoIntermedio == vidas){
            bono = bono + 1;
            cout << "Tienes un bono por adivinar la palabra completa de " << bono << " puntos" << endl;
        } else{
            cout << "No has ganado bono" << endl;
        }
    } else if(palabra_original.length() == palabraAvanzada.length()){
        cout << "Ganaste!, tienes 3 puntos" << endl;
        puntos = puntos + 3;
        if(bonoAvanzado == vidas){
            bono = bono + 2;
            cout << "Tienes un bono por adivinar la palabra completa de " << bono << " puntos" << endl;
        } else{
            cout << "No has ganado bono" << endl;
        }
    }
    else cout << "perdiste, la palabra era: " << palabra_original << endl ;
}

void mostrar(){
    cout << "vidas: " << vidas << endl ;
    cout << palabra_mostrar << endl ;
}

void inicializar(){
    if(palabra_original.length() > 0 && palabra_original.length() <= 5){
        palabraCorta = palabra_original;
        vidas = 5;
    } else if(palabra_original.length() > 5 && palabra_original.length() <= 12){
        palabraIntermedia = palabra_original;
        vidas = 6;
    } else{
        palabraAvanzada = palabra_original;
        vidas = 8;
    }


    for(int i=0 ; i<palabra_original.length() ; i++){
        if(palabra_original[i]>='A' && palabra_original[i]<='Z'){
            palabra_original[i]+=32 ;
        }
    }

    for(int i=0 ; i<palabra_original.length() ; i++){
        if(palabra_original[i]>='a' && palabra_original[i]<='z'){
            palabra_mostrar+='_' ;
        } else{
            palabra_mostrar+=palabra_original[i] ;
        }
    }
}

void ingresar (char x){

    bool perdiVidas=true ;

    for(int i=0 ; i<palabra_original.length() ; i++){
        if(x==palabra_original[i]){
            perdiVidas=false ;
            palabra_mostrar[i]=x ;
        }
    }

    if(perdiVidas) vidas-- ;

}

void menu(){
    int opcion;
    while(opcion != 5){
        cout << "**********************************************" << endl;
        cout << "1. Jugar en modo facil" << endl;
        cout << "2. Jugar en modo intermedio" << endl;
        cout << "3. Jugar en modod avanzado" << endl;
        cout << "4. Entrar en modo admin" << endl;
        cout << "5. Salir" << endl;
        cout << "**********************************************" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:{
                int posicion = 0;
                string random = bancoFacil[posicion];
                palabra_original = random;
                inicializar();
                mostrar();
                vidasJuego();
            } break;

            case 2:{
                int posicion = 0;
                string random = bancoIntermedio[posicion];
                palabra_original = random;
                inicializar();
                mostrar();
                vidasJuego();
            }break;

            case 3:{
                int posicion = 0;
                string random = bancoAvanzado[posicion];
                palabra_original = random;
                inicializar();
                mostrar();
                vidasJuego();
            } break;

            case 4:{
            } break;

            case 5:{
                system("cls");
            }
        }
    }
}
