#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "librerias.h"
#include "rlutil.h"

void lanzardado(int dados[],const int cant);
void armardado(char dado[],int cant,int posx,int posy);
void cargarnombres(string nombre[],string appelido[],const int cant);
int quienempieza(int dados[], int cant,string nombre[],string apellido[]);
void pantalla_de_juego(string nombre,int jugador,int trufas_x_jug[],int nro_ronda,int trufasronda,int nro_lanzamiento);
void centrartexto(string texto,int posy);
void cerditos(void);


///lanzamiento del dado
void lanzardado(int dados[],const int cant){
    srand(time(NULL));

    for(int i=0;i<cant;i++){
        dados[i] = rand() % 6 + 1;
    }
}
///armado dados(visual)
void armardado (int dados[],int cant,int posx,int posy){
    const char x=254,ia=218,da=191,ib=192,db=217,l=196, c=179;
    for(int i=0;i<cant;i++){
        rlutil :: locate(posx+1,posy+1);
        cout << ia << l << l << l << l << l << l << l << l << l << da;
        rlutil :: locate(posx+1,posy+2);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+3);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+4);
        cout << c << "         " << c;
        rlutil :: locate(posx+1,posy+5);
        cout << ib << l << l << l << l << l << l << l << l << l << db;
        switch (dados[i])
        {
        case 1:
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            break;
        case 2:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 3:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
            /* code */
        case 4:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 5:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+6,posy+3);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        case 6:
            rlutil :: locate(posx+4,posy+2);
            cout << x;
            rlutil :: locate(posx+8,posy+2);
            cout << x;
            rlutil :: locate(posx+4,posy+3);
            cout << x;
            rlutil :: locate(posx+8,posy+3);
            cout << x;
            rlutil :: locate(posx+4,posy+4);
            cout << x;
            rlutil :: locate(posx+8,posy+4);
            cout << x;
            break;
        }
        posx += 13;
    }
}
///carga nombre y apellido y lo almacena en los vectores
void cargarnombres(string nombre[],const int cant){
    for(int i=0;i<cant;i++){
        rlutil :: cls();
        rlutil :: locate(1,1);
        cout << "JUGADOR " << i+1;
        rlutil :: locate(1,4);
        cout << "Nombre: ";
        rlutil :: locate(9,4);
        getline(cin, nombre[i]);
        cin.ignore();
    }
}
///se define quien empieza.
int quienempieza(int dados[],int cant,string nombre[]){
    int dadomasalto;
    rlutil :: cls();

    if(dados[0] == 0 && dados[1] == 0){
    cout << "Comienza el jugador que saque el dado mas alto!" << endl;
    cout << "Precione una tecla para continuar" << endl;
    rlutil :: getkey();
    }
    cout << "Lanzando dados!" << endl;
    rlutil :: msleep(500);
    rlutil :: cls();
    lanzardado(dados,2);
    armardado(dados,2,1,1);
    
    if (dados[0] > dados[1]){
        dadomasalto=0;
    }
    else {
        if (dados[0] == dados[1]){
            dadomasalto=3;
        }
        else {
            dadomasalto=1;
        }
    }
    return dadomasalto;
}
///funcion para centrar texto >>> creditos Brian Lara
void centrartexto(string texto, int posy){
    int posx = rlutil :: tcols() / 2 - texto.size() / 2;
    rlutil :: locate(posx,posy);
    cout << texto;
}
///esta es la pantalla de juego con las estadisticas y demas
void pantalla_de_juego(string nombre[],int jugador,int trufas_x_jug[],int nro_ronda,int trufasronda,int nro_lanzamiento,int dados[],int cant){
    rlutil :: cls();
    int posx=1;
    if(jugador == 1){
        posx = 30;
    }
    centrartexto("> GRAN CERDO <",1);
    centrartexto("-------------------------------------",2);
    rlutil :: locate(posx,3);
    cout << nombre[jugador] << ": ";
    int postrufas = nombre[jugador].size() + 2;
    rlutil :: locate(postrufas,3);
    cout << trufas_x_jug[jugador] << " Trufas acumuladas";
    rlutil :: locate(posx,4);
    cout << "Rondas #" << nro_ronda;
    rlutil :: locate(posx,5);
    cout << "Trufas de la ronda: " << trufasronda;
    rlutil :: locate(posx,8);
    cout << "Lanzamiento #" << nro_lanzamiento;
    armardado(dados,cant,posx,10);
    rlutil :: locate(posx,16);
    cout << "Sumaste " << dados[0]+dados[1] << " trufas!";
    
    trufasronda += dados[0]+dados[1];
    trufas_x_jug[jugador] += dados[0] + dados[1];
}

///*CREDITOS DEL JUEGO*///

void cerditos(void){
    rlutil::cls();
    centrartexto("IDEA ORIGINAL CREADA POR ANGEL SIMON",1);
    centrartexto("Codigo creado por:",3);
    centrartexto("27235 - Mariano Stoessel",4);
    centrartexto("26885 - Elias Garcia",5);
    centrartexto("26232 - Tomas Manfredi",6);
    centrartexto("26911 - Brian Galeano",7);
    centrartexto("GRACIAS POR JUGAR!",9);

}
#endif // FUNCIONES_H_INCLUDED
