#ifndef CZerg_h
#define CZerg_h
#include "personaje.h"

class CZerg:public CPersonaje{
private:
    int autodestruccion;//1 es si 0 es no
    string nombre;
    bool autorregeneracion=true;
public:
    CZerg()=default;
    CZerg(double _vida,string _tipo,double _daniot,string _tipo_daniot,double _danioa,string _tipo_danioa,int _armadura,string _tamanio,int _auto,string _nombre):
    CPersonaje(_vida,_tipo,_daniot,_tipo_daniot,_danioa,_tipo_danioa,_armadura,_tamanio),autodestruccion(_auto),nombre(_nombre){}
    void set_nombre(string _n){nombre=_n;}
    string get_nombre(){return nombre;}
    void recibir_daño(CPersonaje* &enemigo,fstream file){
        if (minuscula(this->tipo)=="volador"&& enemigo->get_dan_aereo()==0){
            cout<<this->nombre<<" no recibio daño porque "<<enemigo->get_nombre()<<" no tiene daño aereo \n";
            file<<this->nombre<<" no recibio daño porque "<<enemigo->get_nombre()<<" no tiene daño aereo \n";
        }
        else if (minuscula(this->tipo)=="terrestre"&& enemigo->get_dan_te()==0){
            cout<<this->nombre<<" no recibio daño porque "<<enemigo->get_nombre()<<" no tiene daño terrestre \n";
            file<<this->nombre<<" no recibio daño porque "<<enemigo->get_nombre()<<" no tiene daño terrestre \n";
        }
        else{
            if (minuscula(this->tipo)=="volador"){
                if (minuscula(enemigo->get_tip_dan_aereo())=="normal"){
                    if (this->vida<=enemigo->get_dan_aereo()-enemigo->get_armadura()){
                        this->vida=0;
                        cout<<this->nombre<<" esta muerto!!!"<<endl;
                        file<<this->nombre<<" esta muerto!!!"<<endl;
                    }
                    else if(this->vida>enemigo->get_dan_aereo()-enemigo->get_armadura()&&this->autorregeneracion){
                        this->vida-=enemigo->get_dan_aereo();
                        this->vida+=1;
                        this->autorregeneracion=false;
                        cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\ny recupero 1punto de vida\n";
                        file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\ny recupero 1punto de vida\n";
                    }
                    else{
                        this->vida-=enemigo->get_dan_aereo();
                        cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\n";
                        file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\n";
                    }
                }
                else if (minuscula(enemigo->get_tip_dan_aereo())=="explosivo"){
                    if (minuscula(this->tamanio)=="pequeño"){
                        if (this->vida<=enemigo->get_dan_aereo()/2){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_aereo()/2&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo()/2;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño explosivo\ny recupero 1 punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño explosivo\ny recupero 1 punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo()/2;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño explosivo\n";
                        }
                    }
                    else if(minuscula(this->tamanio)=="mediano"){
                        if (this->vida<=enemigo->get_dan_aereo()*3/4){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_aereo()*3/4&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo()*3/4;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()*3/4<<" de daño explosivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()*3/4<<" de daño explosivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo()*3/4;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()*3/4<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()*3/4<<" de daño explosivo\n";
                        }
                    }
                    else{
                        if (this->vida<=enemigo->get_dan_aereo()){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if(this->vida>enemigo->get_dan_aereo()&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo();
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo();
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño explosivo\n";
                        }
                    }
                }
                else{
                    if (minuscula(this->tamanio)=="pequeño"){
                        if (this->vida<=enemigo->get_dan_aereo()){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_aereo()&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo();
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo();
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()<<" de daño contusivo\n";
                        }
                    }
                    else if(minuscula(this->tamanio)=="mediano"){
                        if (this->vida<=enemigo->get_dan_aereo()/2){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_aereo()/2&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo()/2;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo()/2;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/2<<" de daño contusivo\n";
                        }
                    }
                    else{
                        if (this->vida<=enemigo->get_dan_aereo()/4){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if(this->vida>enemigo->get_dan_aereo()/4&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_aereo()/4;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/4<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/4<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_aereo()/4;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/4<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_aereo()/4<<" de daño contusivo\n";
                        }
                    }
                }
            }
            else{
                if (minuscula(enemigo->get_tip_da_ter())=="normal"){
                    if (this->vida<=enemigo->get_dan_te()){
                        this->vida=0;
                        cout<<this->nombre<<" esta muerto!!!"<<endl;
                        file<<this->nombre<<" esta muerto!!!"<<endl;
                    }
                    else if(this->vida>enemigo->get_dan_te()&&this->autorregeneracion){
                        this->vida-=enemigo->get_dan_te();
                        this->vida+=1;
                        this->autorregeneracion=false;
                        cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\ny recupero 1punto de vida\n";
                        file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\ny recupero 1punto de vida\n";
                    }
                    else{
                        this->vida-=enemigo->get_dan_te();
                        cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\n";
                        file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\n";
                    }
                }
                else if (minuscula(enemigo->get_tip_da_ter())=="explosivo"){
                    if (minuscula(this->tamanio)=="pequeño"){
                        if (this->vida<=enemigo->get_dan_te()/2){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_te()/2&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te()/2;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño explosivo\ny recupero 1 punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño explosivo\ny recupero 1 punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te()/2;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño explosivo\n";
                        }
                    }
                    else if(minuscula(this->tamanio)=="mediano"){
                        if (this->vida<=enemigo->get_dan_te()*3/4){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_te()*3/4&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te()*3/4;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()*3/4<<" de daño explosivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()*3/4<<" de daño explosivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te()*3/4;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()*3/4<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()*3/4<<" de daño explosivo\n";
                        }
                    }
                    else{
                        if (this->vida<=enemigo->get_dan_te()){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if(this->vida>enemigo->get_dan_te()&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te();
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te();
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño explosivo\n";
                        }
                    }
                }
                else{
                    if (minuscula(this->tamanio)=="pequeño"){
                        if (this->vida<=enemigo->get_dan_te()){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_te()&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te();
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te();
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()<<" de daño contusivo\n";
                        }
                    }
                    else if(minuscula(this->tamanio)=="mediano"){
                        if (this->vida<=enemigo->get_dan_te()/2){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if (this->vida>enemigo->get_dan_te()/2&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te()/2;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te()/2;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/2<<" de daño contusivo\n";
                        }
                    }
                    else{
                        if (this->vida<=enemigo->get_dan_te()/4){
                            this->vida=0;
                            cout<<this->nombre<<" esta muerto!!!"<<endl;
                            file<<this->nombre<<" esta muerto!!!"<<endl;
                        }
                        else if(this->vida>enemigo->get_dan_te()/4&&this->autorregeneracion){
                            this->vida-=enemigo->get_dan_te()/4;
                            this->vida+=1;
                            this->autorregeneracion=false;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/4<<" de daño contusivo\ny recupero 1punto de vida\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/4<<" de daño contusivo\ny recupero 1punto de vida\n";
                        }
                        else{
                            this->vida-=enemigo->get_dan_te()/4;
                            cout<<this->nombre<<" recibio "<<enemigo->get_dan_te()/4<<" de daño contusivo\n";
                            file<<this->nombre<<" recibio "<<enemigo->get_dan_te()/4<<" de daño contusivo\n";
                        }
                    }
                }
            }
        }

    }
    ~CZerg()=default;
};


#endif