#include<iostream>
#include<string>
using namespace std ;

string palabra_original ;
string palabra_mostrar ;
int vidas ;

void mostrar() ;
void ingresar(char x) ;
void inicializar() ;

int main(){
    inicializar() ;
    mostrar() ;
    while(vidas>0 && palabra_mostrar!=palabra_original){
        char x ;
        cin >> x ;
        ingresar(x) ;
        mostrar() ;
    }
    if(vidas>0) cout << "ganaste! " << endl ;
    else cout << "perdiste, la palabra era: " << palabra_original << endl ;
}

void mostrar(){
    cout << "vidas: " << vidas << endl ;
    cout << palabra_mostrar << endl ;
}

void inicializar(){
    vidas = 5 ;
    palabra_original = "preferencial" ;

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
