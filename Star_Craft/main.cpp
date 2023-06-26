#include"menus.h"
#include "funcionespvp.h"
#include "funciones3v3.h"
#include <string>
using namespace std;


int main(){
    vector<CPersonaje*> primer_equipo;
    vector<CPersonaje*> segundo_equipo;
    CPersonaje* superviviente=nullptr;
    int countp=0,cont3_1=0,cont3_2=0,cont3=0;
    int opcion_menu=0;
    menu(opcion_menu,countp,cont3_1,cont3_2,cont3,primer_equipo,segundo_equipo,superviviente);

    return 0;
}