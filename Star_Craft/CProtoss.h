#ifndef CProtoss_h
#define CProtoss_h
#include"personaje.h"

class CProtoss:public CPersonaje{
private:
    int escudo;
    string nombre;
public:
    CProtoss(){}
    CProtoss(double _vida,string _tipo,double _daniot,string _tipo_daniot,double _danioa,string _tipo_danioa,int _armadura,string _tamanio,int _escudo,string _nombre):
    CPersonaje(_vida,_tipo,_daniot,_tipo_daniot,_danioa,_tipo_danioa,_armadura,_tamanio),escudo(_escudo),nombre(_nombre){}
    
    void set_escudo(int _escudo){escudo=_escudo;}
    void set_nombre(string _n){nombre=_n;}
    int get_escudo(){return escudo;}
    string get_nombre(){return nombre;}
    ~CProtoss();
};

#endif