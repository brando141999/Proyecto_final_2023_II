#ifndef funcionespvp_h
#define funcionespvp_h
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

void imprimir_personaje(vector<vector<string>> &lista_personajes,int iter,string a){
    if (a=="terran"){
        for (int i = 0; i < iter; i++){
        cout<<i+1<<")";
        cout<<"nombre: "<<lista_personajes[i][0]<<" ";
        cout<<"Vida: "<<lista_personajes[i][1]<<" ";
        cout<<"Blindaje: "<<lista_personajes[i][2]<<" ";
        cout<<"Daño terrestre: "<<lista_personajes[i][3]<<"("<<lista_personajes[i][4]<<") \n";
        cout<<"Daño aereo: "<<lista_personajes[i][5]<<"("<<lista_personajes[i][6]<<") ";
        cout<<"Tamaño: "<<lista_personajes[i][7]<<" ";
        cout<<"Tipo: "<<lista_personajes[i][8]<<" ";
        cout<<"\n------------------------------------------------------\n";
        } 
    }
    else if (a=="protos"){
        for (int i = 0; i < iter; i++){
        cout<<i+1<<")";
        cout<<"nombre: "<<lista_personajes[i][0]<<" ";
        cout<<"Vida: "<<lista_personajes[i][1]<<" ";
        cout<<"Escudo: "<<lista_personajes[i][2]<<" ";
        cout<<"Blindaje: "<<lista_personajes[i][3]<<" ";
        cout<<"Daño terrestre: "<<lista_personajes[i][4]<<"("<<lista_personajes[i][5]<<") \n";
        cout<<"Daño aereo: "<<lista_personajes[i][6]<<"("<<lista_personajes[i][7]<<") ";
        cout<<"Tamaño: "<<lista_personajes[i][8]<<" ";
        cout<<"Tipo: "<<lista_personajes[i][9]<<" ";
        cout<<"\n------------------------------------------------------\n";
        }
    }
    else 
        for (int i = 0; i < iter; i++){
    cout<<i+1<<")";
    cout<<"nombre: "<<lista_personajes[i][0]<<" ";
    cout<<"Vida: "<<lista_personajes[i][1]<<" ";
    cout<<"Blindaje: "<<lista_personajes[i][2]<<" ";
    cout<<"Daño terrestre: "<<lista_personajes[i][3]<<"("<<lista_personajes[i][4]<<") \n";
    cout<<"Daño aereo: "<<lista_personajes[i][5]<<"("<<lista_personajes[i][6]<<") ";
    cout<<"Tamaño: "<<lista_personajes[i][7]<<" ";
    cout<<"Tipo: "<<lista_personajes[i][8]<<" ";
    cout<<"Autodestruccion: "<<lista_personajes[i][9];
    cout<<"\n------------------------------------------------------\n";
    }
    
     
    
}
void llenar_vector_terran(vector<vector<string>> &lista_personajes){
    lista_personajes.resize(11,vector<string>(9));
    string nombreArchivo="terran.txt";
    ifstream archivo(nombreArchivo.c_str());
    int i=0;
    string linea;
    while(getline(archivo,linea)){
        
        string lectura=linea;
        stringstream input_stringstream(lectura);
        for (int j = 0; j < 9; j++){
            getline(input_stringstream,lista_personajes[i][j],';');
        }        
        i+=1;
    }
}
void llenar_vector_protos(vector<vector<string>> &lista_personajes){
    lista_personajes.resize(10,vector<string>(10));
    string nombreArchivo="Protoss.txt";
    ifstream archivo(nombreArchivo.c_str());
    int i=0;
    string linea;
    while(getline(archivo,linea)){
        
        string lectura=linea;
        stringstream input_stringstream(lectura);
        for (int j = 0; j < 10; j++){
            getline(input_stringstream,lista_personajes[i][j],';');
        }        
        i+=1;
    }
}
void llenar_vector_zerg(vector<vector<string>> &lista_personajes){
    lista_personajes.resize(11,vector<string>(10));
    string nombreArchivo="Zerg.txt";
    ifstream archivo(nombreArchivo.c_str());
    int i=0;
    string linea;
    while(getline(archivo,linea)){
        
        string lectura=linea;
        stringstream input_stringstream(lectura);
        for (int j = 0; j < 10; j++){
            getline(input_stringstream,lista_personajes[i][j],';');
        }        
        i+=1;
    }
}
void menu_inicio(int &opcion){
    cout<<"Bienvenido a STAR CRAFT\n";
    cout<<"Elija modo de juego: \n";
    cout<<"1)PVP\n";
    cout<<"2)3 VS 3\n";
    cout<<"3)Supervivencia\n";
    cout<<"4)Salir del juego\n";
    cin>>opcion;
}

void elejir_planeta_PVP(int &i){
    cout<<"Elija de que planeta sera su personaje "<<i+1<<": \n";
    cout<<"1)Tierra\n";
    cout<<"2)Aiur\n";
    cout<<"3)Zerus\n";
    cout<<"4)Retroceder\n";
}
void elejir_terrans(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_terran(lista_personajes);
    imprimir_personaje(lista_personajes,11,"terran");
    cout<<"Elija su personaje"<<a+1<<"...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
}
void elejir_protos(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_protos(lista_personajes);
    imprimir_personaje(lista_personajes,10,"protos");
    cout<<"Elija su personaje"<<a+1<<"...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
}
void elejir_Zerg(int &a){
    vector<vector<string>> lista_personajes;
    llenar_vector_zerg(lista_personajes);
    imprimir_personaje(lista_personajes,11,"serg");
    cout<<"Elija su personaje"<<a+1<<"...ingrese el numero: \n";
    cout<<"presione 0 para retroceder: ";
}

void personaje_elejido_Terran(vector<CPersonaje*> &a,int opcion){
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
    CPersonaje* guerrero1;
    guerrero1=new CTerran(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,nombre);
    a.emplace_back(guerrero1);
}
void personaje_elejido_protos(vector<CPersonaje*> &a,int opcion){
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
    CPersonaje* guerrero2;
    guerrero2=new CProtoss(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,escudo,nombre);
    a.emplace_back(guerrero2);
}
void personaje_elejido_zerg(vector<CPersonaje*> &a,int opcion){
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
    
    CPersonaje* guerrero3;
    guerrero3=new CZerg(vida,tipo,dano_terrestre,tip_dan_terrestre,danio_aereo,tip_danio_aereo,punto_armadura,tamanio,autodestruccion,nombre);
    a.emplace_back(guerrero3);
}




#endif