#ifndef CTerran_h
#define CTerran_h
#include"personaje.h"
class CTerran:public CPersonaje{
private:
    string nombre;

public:
    CTerran(){}
    CTerran(double _vida,string _tipo,double _daniot,string _tipo_daniot,double _danioa,string _tipo_danioa,int _armadura,string _tamanio,string _nombre):
    CPersonaje(_vida,_tipo,_daniot,_tipo_daniot,_danioa,_tipo_danioa,_armadura,_tamanio),nombre(_nombre){}
    
    void set_nombre(string _n){nombre=_n;}
    string get_nombre(){return nombre;}
    void recibir_daño(CPersonaje* &enemigo){

    }
    ~CTerran(){}
};










#endif 