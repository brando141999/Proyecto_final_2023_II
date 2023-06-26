#ifndef personaje_h
#define personaje_h
#include <string>
#include <iostream>
#include "funciones_ataque.h"
using namespace std;
class CPersonaje{
protected:
    double vida;
    string tipo;
    double dano_terrestre;
    string tip_dan_terrestre;
    double danio_aereo;
    string tip_danio_aereo;
    int punto_armadura;
    string tamanio;
public:
    CPersonaje(){}
    CPersonaje(double _vida,string _tipo,double _daniot,string _tipo_daniot,double _danioa,string _tipo_danioa,int _armadura,string _tamanio):
    vida(_vida),tipo(_tipo),dano_terrestre(_daniot),tip_dan_terrestre(_tipo_daniot),danio_aereo(_danioa),tip_danio_aereo(_tipo_danioa),punto_armadura(_armadura),tamanio(_tamanio){}
    CPersonaje(const CPersonaje &personaje){
        vida=personaje.vida;
        tipo=personaje.tipo;
        dano_terrestre=personaje.dano_terrestre;
        tip_dan_terrestre=personaje.tip_dan_terrestre;
        danio_aereo=personaje.danio_aereo;
        tip_danio_aereo=personaje.tip_danio_aereo;
        punto_armadura=personaje.punto_armadura;
        tamanio=personaje.tamanio;
    }
    void set_vida(double _vida){vida=_vida;}
    void set_tipo(string _tipo){tipo=_tipo;}
    void set_dan_te(double _dan_t){dano_terrestre=_dan_t;}
    void set_t_dan_t(string _t_dan_t){tip_dan_terrestre=_t_dan_t;}
    void set_dan_aer(double _dan_ae){danio_aereo=_dan_ae;}
    void set_t_dan_ae(string _t_dan_ae){tip_danio_aereo=_t_dan_ae;}
    void set_armadura(int _armadura){punto_armadura=_armadura;}
    void set_taman(string _tamanio){tamanio=_tamanio;}
    double get_vida(){return vida;}
    string get_tipo(){return tipo;}
    double get_dan_te(){return dano_terrestre;}
    string get_tip_da_ter(){return tip_dan_terrestre;}
    double get_dan_aereo(){return danio_aereo;}
    string get_tip_dan_aereo(){return tip_danio_aereo;}
    int get_armadura(){return punto_armadura;}
    string get_tamanio(){return tamanio;}
    virtual void set_nombre()=0;
    virtual string get_nombre()=0;
    virtual void recibir_daño(CPersonaje* &enemigo)=0;
    virtual void mostrar_estadisticas()=0;
    virtual void esta_vivo()=0;

    
    ~CPersonaje(){}
};

#endif