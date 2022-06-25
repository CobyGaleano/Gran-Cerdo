#include <iostream>

using namespace std;
#include "librerias.h"
#include "funciones.h"

int main()
{
    //lanzamiento dados
    const int cant_dados=2;
    int dados[cant_dados]{}; 
    int opcion;
    char continuar; /// S = sigue /N = no sigue
    bool turnojugador = 0;

    const int cant_jugadores=2;
    int trufas_jugador[cant_jugadores]{},lanzamientos=0,empieza,trufasronda=0,nro_ronda=0;
    string nombre_jugador[cant_jugadores]{};
    //menu
    rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    rlutil::setColor(rlutil::WHITE);
    do{
        rlutil :: cls();
        rlutil :: locate(2, 1);
        cout<<"GRAN CERDO";
        rlutil :: locate(2, 2);
        cout<<"---------------------------------------";
        rlutil :: locate(2, 3);
        cout<<" 1 - JUGAR.";
        rlutil :: locate(2, 4);
        cout<<" 2 - ESTADISTICAS";
        rlutil :: locate(2, 5);
        cout<<" 3 - CERDITOS ";
        rlutil :: locate(2, 6);
        cout<<"---------------------------------------";
        rlutil :: locate(2, 7);
        cout<<" 0 - SALIR";
        rlutil :: locate(2, 8);
        cout << "Opcion: ";
        rlutil :: locate(9, 8);
        cin>>opcion;

        switch(opcion){
        case 0:
            cout<<"Fin."<<endl<<endl<<endl;
            rlutil :: msleep(250);
            return 0;
        break;
        case 1:{
                for(int i=0;i<6;i++){
                    if (i == 0){
                        ///se inicia el juego y si esta en la ronda 1 se cargan nombres y se decide quien comienza
                        cargarnombres(nombre_jugador,cant_jugadores);
                        empieza = quienempieza(dados,cant_dados,nombre_jugador);
                        ///si los dados salen iguales, la funcion retorna 3 y se procede a lanzar nuevamente
                        ///esto podria revisarse
                        if(empieza == 3){
                            rlutil :: locate(1,7);
                            cout << "Los dados son iguales, hay que tirar otra vez! " << endl;
                            empieza = quienempieza(dados,cant_dados,nombre_jugador);
                        }
                            rlutil :: locate(1,7);
                            cout << "Empieza el jugador " << nombre_jugador[empieza];
                            turnojugador = empieza;
                    }
                    for (int i=0;i<5;i++){
                        for (int j=0;j<2;j++){
                            int cont_lanzamiento=0,trufasronda=0;
                            
                            while (continuar != 'n' && continuar != 'N' && i != 5){
                                cont_lanzamiento ++;
                                rlutil :: cls();
                                lanzardado(dados,cant_dados);
                                trufasronda += dados[0] + dados[1];
                                pantalla_de_juego(nombre_jugador,turnojugador,trufas_jugador,i+1,trufasronda,cont_lanzamiento,dados,cant_dados);
                                rlutil :: locate(1,19);
                                cout << "Continuar?" << endl;
                                cin >> continuar;
                            }
                            if(turnojugador == 0){
                                turnojugador = 1;
                            }
                            else{
                                turnojugador = 0;
                            }
                            continuar = 's';
                        }
                    }
                }
                rlutil :: anykey();
        }
        break;
        case 2:{
                rlutil :: anykey();
        }
        break;
        case 3:{
                rlutil :: anykey();
        }
        break;
        default:
            rlutil::setBackgroundColor(rlutil::RED);
            rlutil::setColor(rlutil::WHITE);
            cout<<"ESTA OPCION ES INCORRECTA"<<endl;
            rlutil::anykey();
            rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
            rlutil::setColor(rlutil::WHITE);
        }


    }while(opcion!=0);

    rlutil :: cls();

    return 0;
}
