#ifndef menus_h
#define menus_h
#include"funcionespvp.h"
#include"funciones3v3.h"
#include"supervivencia.h"

void menu(int opcion_menu,int &countp,int &cont3_1,int &cont3_2,int &cont3,vector<CPersonaje*> &primer_equipo,vector<CPersonaje*> &segundo_equipo,CPersonaje* &superviviente){
    while (opcion_menu!=4){
        menu_inicio(opcion_menu);
        if (opcion_menu==1){
            int opcion1;
            while (countp<2){
                elejir_planeta_PVP(countp);
                cin>>opcion1;
                int opciona;
                if (opcion1==1){
                    elejir_terrans(countp);
                    cin>>opciona;
                    if (opciona==0){
                        continue;
                    }
                    else{
                        if (countp==0){
                            personaje_elejido_Terran(primer_equipo,opciona-1);
                            countp+=1;
                        }
                        else{
                            personaje_elejido_Terran(segundo_equipo,opciona-1);
                            countp+=1;
                            break;
                        }
                    }
                    
                }
                else if(opcion1==2){
                    elejir_protos(countp);
                    cin>>opciona;
                    if (opciona==0){
                        continue;
                    }
                    else{
                        if (countp==0){
                            personaje_elejido_protos(primer_equipo,opciona-1);
                            countp+=1;
                            }
                        else{
                            personaje_elejido_protos(segundo_equipo,opciona-1);
                            countp+=1;
                            break;
                        }
                    }
                }
                else if (opcion1==3){
                    elejir_Zerg(countp);
                    cin>>opciona;
                    if (opciona==0){
                        continue;
                    }
                    else{
                        if (countp==0){
                            personaje_elejido_zerg(primer_equipo,opciona-1);
                            countp+=1;
                        }
                        else{
                            personaje_elejido_zerg(segundo_equipo,opciona-1);
                            countp+=1;
                            break;
                        }
                    }
                }
                else{
                    countp=2;
                    primer_equipo.clear();
                }
            }
            if (primer_equipo.size()!=0){
                break;
            }
            else{
                countp=0;
                continue;
            }
        }
        else if (opcion_menu==2){
            int op3;
            while (op3!=4){
                menuPvp(op3);
                if (op3==1){
                    int op3v3;
                    while (cont3<2){
                        fomar_equipo(cont3_1,cont3);
                        cin>>op3v3;
                        if (op3v3==1){
                            int opcionb;
                            elejir_terrans(cont3_1);
                            cin>>opcionb;
                            if (opcionb==0){
                            continue;
                            }
                            else{
                                if (cont3==0){
                                    personaje_elejido_Terran(primer_equipo,opcionb-1);
                                    if (cont3_1==2){
                                        cont3+=1;
                                        cont3_1=0;
                                    }
                                    else
                                        cont3_1+=1;
                                
                                }
                                else{
                                    personaje_elejido_Terran(segundo_equipo,opcionb-1);
                                    if (cont3_1==2){
                                            cont3+=1;
                                            break;
                                        }
                                        else
                                            cont3_1+=1; 
                                }
                                
                            }
                        }
                        else if (op3v3==2){
                            int opcionb;
                            elejir_protos(cont3_1);
                            cin>>opcionb;
                            if (opcionb==0){
                            continue;
                            }
                            else{
                                if (cont3==0){
                                    personaje_elejido_protos(primer_equipo,opcionb-1);
                                    if (cont3_1==2){
                                        cont3+=1;
                                        cont3_1=0;
                                    }
                                    else
                                        cont3_1+=1;
                                
                                }
                                else{
                                    personaje_elejido_protos(segundo_equipo,opcionb-1);
                                    if (cont3_1==2){
                                            cont3+=1;
                                            break;
                                        }
                                        else
                                            cont3_1+=1; 
                                }
                                
                            }
                        }
                        else if(op3v3==3){
                            int opcionb;
                            elejir_Zerg(cont3_1);
                            cin>>opcionb;
                            if (opcionb==0){
                            continue;
                            }
                            else{
                                if (cont3==0){
                                    personaje_elejido_zerg(primer_equipo,opcionb-1);
                                    if (cont3_1==2){
                                        cont3+=1;
                                        cont3_1=0;
                                    }
                                    else
                                        cont3_1+=1;
                                
                                }
                                else{
                                    personaje_elejido_zerg(segundo_equipo,opcionb-1);
                                    if (cont3_1==2){
                                            cont3+=1;
                                            break;
                                        }
                                        else
                                            cont3_1+=1; 
                                }
                                
                            }
                        }
                        else{
                            primer_equipo.clear();
                            segundo_equipo.clear();
                            cont3=2;
                            
                        }
                        }
                    if (primer_equipo.size()==3&&segundo_equipo.size()==3){
                    break;
                    }
                    else{
                        cont3_1=0;
                        cont3=0;
                        cont3=0;
                    }
                }
                else if (op3==2){
                    int opc_al;
                    while (opc_al!=3){
                        menu_formar_equipo_aleatorio();
                        cin>>opc_al;
                        if (opc_al==1){
                            while (cont3<2){
                                if (cont3==0){
                                    formar_equipo_de_un_planeta1(cont3_1);
                                    if (cont3_1==1){
                                        srand(time(NULL));
                                        formar_equipo_terrans_al(primer_equipo);
                                        cont3+=1;
                                    }
                                    else if (cont3_1==2){
                                        srand(time(NULL));
                                        formar_equipo_protos_al(primer_equipo);
                                        cont3+=1;
                                    }
                                    else if(cont3_1==3){
                                        srand(time(NULL));
                                        formar_equipo_zergs_al(primer_equipo);
                                        cont3+=1;
                                    }
                                    else{
                                        cont3=2;
                                    } 
                                    
                                }
                                else{
                                    formar_equipo_de_un_planeta2(cont3_1);
                                    if (cont3_1==1){
                                        srand(time(NULL));
                                        formar_equipo_terrans_al(segundo_equipo);
                                        cont3+=1;
                                    }
                                    else if (cont3_1==2){
                                        srand(time(NULL));
                                        formar_equipo_protos_al(segundo_equipo);
                                        cont3+=1;
                                    }
                                    else if(cont3_1==3){
                                        srand(time(NULL));
                                        formar_equipo_zergs_al(segundo_equipo);
                                        cont3+=1;
                                    }
                                    else{
                                        cont3=2;
                                    }
                                }
                            }
                            if (primer_equipo.size()==3&&segundo_equipo.size()==3){
                                break;
                            }
                            else{
                                primer_equipo.clear();
                                segundo_equipo.clear();
                                cont3=0;
                                continue;
                            }
                            
                        }
                        else if (opc_al==2){
                            srand(time(NULL));
                            formar_equipo_aleatorio(primer_equipo,segundo_equipo);
                            break;
                        }
                        else{
                            if (primer_equipo.size()==3&&segundo_equipo.size()==3){
                                break;
                            }
                            else{
                                primer_equipo.clear();
                                segundo_equipo.clear();
                                cont3=0;
                    
                            }

                        }
                    }
                    if (primer_equipo.size()==3&&segundo_equipo.size()==3){
                            break;
                    }
                    else{
                        primer_equipo.clear();
                        segundo_equipo.clear();
                        cont3=0;
                    
                    }
                }
                else{
                    primer_equipo.clear();
                    segundo_equipo.clear();
                    op3=4;
                }
            }
            if (primer_equipo.size()==3&&segundo_equipo.size()==3){
                    break;
                    }
                    else{
                        cont3_1=0;
                        cont3=0;
                        cont3=0;
                        op3=0;
                    }
            
        }
        else if (opcion_menu==3){
            while(cont3!=3){
                menu_supervivencia(cont3);
                if (cont3==1){
                    while(cont3_1!=4){
                        elejir_planeta_sup(cont3_1);
                        if (cont3_1==1){
                            elejir_terrans_s(cont3_2);
                            if (cont3_2==0){
                                continue;
                            }
                            else{
                                personaje_elejido_Terran(superviviente,cont3_2-1);
                                break;
                            }
                            
                        }
                        else if (cont3_1==2){
                            elejir_protos_s(cont3_2);
                            if (cont3_2==0){
                                continue;
                            }
                            else{
                                personaje_elejido_protos(superviviente,cont3_2-1);
                                break;
                            }
                        }
                        else if (cont3_1==3){
                            elejir_Zerg_s(cont3_2);
                            if (cont3_2==0){
                                continue;
                            }
                            else{
                                personaje_elejido_Terran(superviviente,cont3_2-1);
                                break;
                            }
                        }
                    }
                    if (superviviente!=nullptr){
                    break;
                    }
                    else{
                    superviviente=nullptr;
                    cont3=0;
                    cont3_1=0;
                    cont3_2=0;
                    }

                }
                else if (cont3==2){
                    srand(time(NULL));
                    super_aleatorio(superviviente);
                    break;
                }
                    
                    
            }
            if (superviviente!=nullptr){
                break;
            }
            else{
                superviviente=nullptr;
                cont3=0;
                cont3_1=0;
                cont3_2=0;
            }
                
        }
            
        
        else{
            if (opcion_menu==4){
                continue;
            }
            else
                cout<<"Ingrese una opcion valida!!!\n";}
    } 
}
#endif