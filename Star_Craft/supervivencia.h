#ifndef supervivencia_h
#define supervivencia_h
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "CProtoss.h"
#include "CZerg.h"
#include "CTerran.h"
using namespace std;
void personaje_elejido_Terran(CPersonaje* &a,int opcion){
    vector<vector<string>> lista_personajes;
    llenar_vector_terran(lista_personajes);
    double vida=stod(lista_personajes[opcion][1]);
    string tipo=lista_personajes[opcion][8];
    double dano_terrestre=stod(lista_personajes[opcion][3]);
    string tip_dan_terrestre=lista_personajes[opcion][4];
    double danio_aereo=stod(lista_personajes[opcion][5]);
    string tip_danio_aereo=lista_personajes[opcion][6];
    int punto_armadura=stoi(lista_personajes[opcion][2]);
    string tamanio=lista_personajes[opcion][7];
    string nombre=lista_personajes[opcion][0];
    
    a=new CTerran(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,nombre);
    
}
void personaje_elejido_protos(CPersonaje* &a,int opcion){
    vector<vector<string>> lista_personajes;
    llenar_vector_protos(lista_personajes);
    double vida=stod(lista_personajes[opcion][1]);
    string tipo=lista_personajes[opcion][9];
    double dano_terrestre=stod(lista_personajes[opcion][4]);
    string tip_dan_terrestre=lista_personajes[opcion][5];
    double danio_aereo=stod(lista_personajes[opcion][6]);
    string tip_danio_aereo=lista_personajes[opcion][7];
    int punto_armadura=stoi(lista_personajes[opcion][3]);
    string tamanio=lista_personajes[opcion][8];
    string nombre=lista_personajes[opcion][0];
    int escudo=stoi(lista_personajes[opcion][2]);
    
    a=new CProtoss(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,escudo,nombre);
    
}
void personaje_elejido_zerg(CPersonaje* &a,int opcion){
    vector<vector<string>> lista_personajes;
    llenar_vector_zerg(lista_personajes);
    double vida=stod(lista_personajes[opcion][1]);
    string tipo=lista_personajes[opcion][8];
    double dano_terrestre=stod(lista_personajes[opcion][3]);
    string tip_dan_terrestre=lista_personajes[opcion][4];
    double danio_aereo=stod(lista_personajes[opcion][5]);
    string tip_danio_aereo=lista_personajes[opcion][6];
    int punto_armadura=stoi(lista_personajes[opcion][2]);
    string tamanio=lista_personajes[opcion][7];
    string nombre=lista_personajes[opcion][0];
    int autodestruccion;
    if (lista_personajes[opcion][1]=="Si"){
        autodestruccion=1;
    }
    else
        autodestruccion=0;
    
    
    a=new CZerg(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,autodestruccion,nombre);
   
}
void menu_supervivencia(int &a){
    cout<<"Elije a tu luchador para una batalla de supervivencia: \n";
    cout<<"1)Elejir manualmente\n";
    cout<<"2)Elejir aleatoriamente\n";
    cout<<"3)Retroceder\n";
    cin>>a;

}
void elejir_planeta_sup(int &i){
    cout<<"Elija de que planeta sera su superviviente \n";
    cout<<"1)Tierra\n";
    cout<<"2)Aiur\n";
    cout<<"3)Zerus\n";
    cout<<"4)Retroceder\n";
    cin>>i;
}
void super_aleatorio(CPersonaje* &a){
    int opc_pla;
    opc_pla=rand()%3;
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
void elejir_terrans_s(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_terran(lista_personajes);
    imprimir_personaje(lista_personajes,11,"terran");
    cout<<"Elija su personaje...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
    cin>>a;
}
void elejir_protos_s(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_protos(lista_personajes);
    imprimir_personaje(lista_personajes,10,"protos");
    cout<<"Elija su personaje...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
    cin>>a;
}
void elejir_Zerg_s(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_zerg(lista_personajes);
    imprimir_personaje(lista_personajes,11,"serg");
    cout<<"Elija su personaje...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
    cin>>a;
}


#endif