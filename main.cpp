#include <iostream>
#include <cstdlib>
#include "fungen.h"
#include "windows.h"
#include <ctime>
using namespace std;
int main () {
int opcion,puntosganador=0,mayorpuntaje=0;
char nombreganador [15],ganadormayor [15];




do {

//*MENU PRINCIPAL//*

opcion=hola();



switch (opcion){
            case 1:

            puntosganador=empezarjuego(opcion,nombreganador);
            if (mayorpuntaje<puntosganador){
                mayorpuntaje=puntosganador;
            copiarVector(nombreganador, ganadormayor);

            }

            break;

            case 2:
            if (puntosganador==0){
                cout << "DEBE INICIAR UNA PARTIDA PARA PODER VER LOS PUNTAJES"<< endl;
                system ("pause");
                system ("cls");
            }
            else{

            cout << "Ultimo puntaje: " << puntosganador << " (" <<nombreganador<<") "<<endl;
            cout <<"-----------------------------"<< endl;
             cout << "El mayor puntaje es de : " << ganadormayor << endl<< " con un total de: "<<mayorpuntaje<<endl;
             system ("pause");
             system ("cls");
            }

            break;










            case 3:
            cout << "BIENVENIDO AL MODO PRUEBA"<< endl;
            cout << "En este modo podra elegir los valores de los dados." << endl;
              cout << "_____________________________________________________________" << endl<< endl;
            Sleep(1500);
            puntosganador=empezarjuego(opcion,nombreganador);
              if (mayorpuntaje<puntosganador){
                mayorpuntaje=puntosganador;
            copiarVector(nombreganador, ganadormayor);

            }
            break;


            case 4:
            cout << "CHAU!" << endl;
            system ("pause");
            system ("cls");
            break;

            default: cout << "ERROR DE INGRESO" << endl;
 }
}while (opcion!=4);





return 0;
}
