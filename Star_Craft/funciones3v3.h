#ifndef funciones3v3_h
#define funciones3v3_h
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include<stdlib.h>
#include<time.h>
#include "CProtoss.h"
#include "CZerg.h"
#include "CTerran.h"
#include "funcionespvp.h"
using namespace std;

void menuPvp(int &op3){
    cout<<"1)Formar equipos manualmente\n";
    cout<<"2)Formar equipos aleatoriamente\n";
    cout<<"3)Retroceder\n";
    cout<<"Elija una opcion: ";
    cin>>op3;
}

void fomar_equipo(int &i,int &n){
    cout<<"Formando equipo"<<n+1<<"...";
    cout<<"Elija de que planeta sera su personaje "<<i+1<<": \n";
    cout<<"1)Tierra\n";
    cout<<"2)Aiur\n";
    cout<<"3)Zerus\n";
    cout<<"4)Retroceder\n";
}
void menu_formar_equipo_aleatorio(){
    cout<<"1)Personajes aleatorios de un mismo planeta: \n";
    cout<<"2)Personajes aleatorios de diferentes planetas: \n";
    cout<<"3)Retroceder\n";
}

void formar_equipo_de_un_planeta1(int &cont){
    cout<<"Elija de que planeta sera su primer equipo: \n";
    cout<<"1)Tierra\n";
    cout<<"2)Aiur\n";
    cout<<"3)Zerus\n";
    cout<<"4)Retroceder\n";
    cin>>cont;
}
void formar_equipo_de_un_planeta2(int &cont){
    cout<<"Elija de que planeta sera su segundo equipo: \n";
    cout<<"1)Tierra\n";
    cout<<"2)Aiur\n";
    cout<<"3)Zerus\n";
    cout<<"4)Retroceder\n";
    cin>>cont;
}
void formar_equipo_aleatorio(vector<CPersonaje*>&a,vector<CPersonaje*>&b){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            int opc_pla;
            opc_pla=rand()%3;
            if (i==0){
                if (opc_pla==0){
                int opcion=rand()%11;
                personaje_elejido_Terran(a,opcion);
                }
                else if (opc_pla==1){
                    int opcion=rand()%10;
                    personaje_elejido_protos(a,opcion);
                }
                else{
                    int opcion=rand()%11;
                    personaje_elejido_zerg(a,opcion);
                }
            }
            else{
                if (opc_pla==0){
                int opcion=rand()%11;
                personaje_elejido_Terran(b,opcion-1);
                }
                else if (opc_pla==1){
                    int opcion=rand()%10;
                    personaje_elejido_protos(b,opcion);
                }
                else{
                    int opcion=rand()%11;
                    personaje_elejido_zerg(b,opcion);
                }
            }
            
            
        }
        
    }
    
    
}
void formar_equipo_terrans_al(vector<CPersonaje*>&a){
    for (int i = 0; i < 3; i++){
        int opcion=rand()%11;
        personaje_elejido_Terran(a,opcion);
    }
    
}
void formar_equipo_protos_al(vector<CPersonaje*>&a){
    for (int i = 0; i < 3; i++){
        int opcion=rand()%10;
        personaje_elejido_protos(a,opcion);
    }
    
}
void formar_equipo_zergs_al(vector<CPersonaje*>&a){
    for (int i = 0; i < 3; i++){
        int opcion=rand()%11;
        personaje_elejido_zerg(a,opcion);
    }
    
}

#endif