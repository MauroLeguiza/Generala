#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
using namespace std;

/**CARTEL DE BIENVENIDA*/

int hola (){
int opcion;
cout << "BIENVENIDO"<< endl;
cout << "--------------------------------"<< endl;
cout << "Presione 1 para empezar"<< endl;
cout << "Presione 2 para PUNTUACION"<< endl;
cout << "Presione 3 para PROBAR EL JUEGO"<< endl;
cout << "Presione 4 para salir" << endl<< endl;
cout << "--------------------------------"<< endl;
cin >> opcion;
system ("cls");
return opcion;

}




/**TIRAR DADOS*/

void tirar5_dados (int v[],int cantidad_dados){
int i;
srand (time(NULL));
for (i=0;i<cantidad_dados;i++){
    v[i]=rand()%6+1;
}

}


/** INGRESAR DADOS PARA PRUEBA */
void ingresar_dados (int v[], int cantidad_dados){
int i;

for (i=0;i<cantidad_dados;i++){
    cout << "Ingrese valores para los dados: "; cin >> v [i];
    cout << endl;

}
 system ("cls");
cout << "_____________________________________________________________" << endl;
}

/** CAMBIAR EL VALOR DE UN DADOS */
void cambiar_dados (int v[],int dados [],int cantidad_dados){
int i;

for (i=0;i<cantidad_dados;i++){
    cout << "Ingrese el nuevo valor para el dado: "<< endl;
    cin >> dados [v[i]-1];
    }
}






/** MOSTRAR DADOS */

void mostrar_dados (int v[],int cantidad_dados){
int i,j;

cout << "TIRANDO DADOS POR FAVOR ESPERE";
for (j=0;j<3;j++){
    Sleep(1000);
    cout<< ".";
}
Sleep(2000);
cout << endl << endl;
for (i=0;i<cantidad_dados;i++)

    cout << v[i]<<"\t";
    cout << endl << endl;


return;
}


/** PEDIR NOMBRES */

void pedir_nombre(char nombre [15]){


 cin >>nombre;


}

/**MOSTRAR NOMBRES */

void mostrar_nombre (char nombre [15]){
cout << nombre << endl;

}

/** SELECCIONA LOS DADOS */

void cuales_dados (int v[],int cantidad_dados){
int i;
for (i=0;i<cantidad_dados;i++){
    cout << "cual: "; cin >> v[i];

   }


}

/** COPIAR */
void copiarVector(char v[15], char v2[15]){
    int i;
    for(i=0;i<15;i++){
        v2[i]=v[i];
    }

}


/** TIRA LOS DADOS SELECCIONADOS ALEATORIAMENTE */

void dadoaleatorio (int v[],int dados [],int cantidad_dados){
int i;
srand (time(NULL));
for (i=0;i<cantidad_dados;i++){
    dados [v[i]-1]=rand()%6+1;
    }
}


/** VERIFICA DOBLE*/

int verificar_doble (int dados [], int cantidad_dados,int jugada ){
int c=0,j,i;

  for (i=0;i<cantidad_dados-1;i++){
       for (j=i+1;j<cantidad_dados;j++){
          if (dados[i]==dados [j])
            c++;

       } }
    if (c==2){
        if (jugada==1){
            return 15;
        }
        else {
            return 10;
        }
    }
       else {
        return 0;
       }
  }

/** VEROFICA LA CATEGORIA POKER */
int verificar_poker (int dados [], int cantidad_dados){

int c=0,j,i;

  for (i=0;i<cantidad_dados-1;i++){
       for (j=i+1;j<cantidad_dados;j++){
          if (dados[i]==dados [j])
            c++;

       } }

    if (c==6) {return 40;
}
    else {
    return 0;
}
}

 /** ORDENO MI VECTOR DE MENOR A MAYOR PARA VERIFICAR SI HAY ESCALERA */
void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}



/** GENERALA SERVIDA */

int generala_servida(int dados [5]){
int i;
int servida=1;
for (i=1;i<5;i++){
    if (dados [0]!= dados [i])
        servida= 0;

}

return servida;
}





     /** VERIFICA CATEGORIA ESCALERA */

  int verificar_escalera (int dados [],int cantidad_dados){
      int c=0,i;

ordenarVector(dados,cantidad_dados);

  for (i=0;i<cantidad_dados-1;i++){

          if (dados[i]==dados [i+1]-1)
            c++;

       }
       if (c==4){

        return 25;
       }
       else {
        return 0;
       }

  }


  /** VERIFICA CATEGORIA FULL O DE GENERALA*/

  int verificar_full_generala (int dados [], int cantidad_dados){
 int c=0,j,i;

  for (i=0;i<cantidad_dados-1;i++){
       for (j=i+1;j<cantidad_dados;j++){
          if (dados[i]==dados [j])
            c++;
       } }
if (c==4){
    return 30;
}
else {
if (c==10){


        return 50;

}
else {
    return 0;
}
  }
  }


  /** VERIFICAR VALORES REPETIDOS */

int verificar_valores_repetidos (int dados [], int cantidad_dados){
   int c=0,j,i,numerorepetido;

  for (i=0;i<cantidad_dados-1;i++){
       for (j=i+1;j<cantidad_dados;j++){
          if (dados[i]==dados [j]){
            c++;
           numerorepetido=dados [i];}

           }}




   if (c==1){
            return numerorepetido * 2;}
   else {
    if (c==3){
        return 20;
    }
    else {
        return 0;
    }
   }

  return 0;
  }


  /** VERIFICAR NUMERO MAYOR */

  int verificar_numeromayor (int dados [], int cantidad_dados){
int i, posMax=0,mayor=0;

    for(i=1;i<cantidad_dados;i++){
        if(dados[i]>dados[posMax]) {
                posMax=i;
                mayor=dados [posMax];
}

  }


  return mayor;
  }




  /** /////////////////// */
  /** FUNCIONES GENERALES */


  /** VERIFICACIONES DE CATEGORIAS */

int  verificar_todas_categorias (int dados [],int cantidad_dados, int jugada){

int mivector[6],i;



mivector[0]=verificar_full_generala (dados,cantidad_dados);
mivector[1]=verificar_poker (dados,cantidad_dados);
mivector[2]=verificar_escalera (dados,cantidad_dados);
mivector[3]=verificar_doble(dados,cantidad_dados ,jugada);
mivector[4]=verificar_valores_repetidos (dados,cantidad_dados );
mivector[5]=verificar_numeromayor (dados,cantidad_dados);

int valormayor=0;
for (i=0;i<6;i++){
    if (mivector[i]>valormayor){

      valormayor =mivector[i];}
}
/** uso el for para probar los valores que esta comparando
for (i=0;i<6;i++)cout << "valor de v:" << i << "es: " << mivector[i]<<endl;*/

return valormayor;
  }




/** MODO PARA UN SOLO JUGADOR */
  int empezarjuego (int opcion,char nombreganador []){
int cantidad_dados=5,jugadores, jugada,rondas,puntos=0,puntos2=0,puntosganados=0,turno,tamrondas,puntosganador=0;
int dados[5],v[cantidad_dados];
char nombre [15],nombre2[15],seguir_tirando,personalizar;
int servida,empate=1;
bool servidaban=false;

  cout << "Presione 1 para un jugador " << endl; cout << "Presione 2 para dos jugadores "<< endl ;
  cout << "--------------------------------" << endl << endl;
            cin >> jugadores;
            system ("cls");


            switch (jugadores){
            case 1:
                /** PIDO EL INGRESO DEL NOMBRE */

                cout << "Ingrese nombre de jugador 1: ";
                pedir_nombre(nombre);
                system ("cls");
                cout << "_____________________________________________________________" << endl;

                cout << "Desea personalizar la cantidad de rondas?(DEFAULT 10) (s/n): "; cin >> personalizar;
                if (personalizar=='s'){
                    cout << "Ingrese la cantidad de rondas: ";
                    cin>>tamrondas;
                    system ("cls");
                }
                else {
                    tamrondas =10;
                    system ("cls");
                }

                /** FOR PARA LA CANTIDAD DE RONDAS EN EL JUEGO */
                for (rondas=1;rondas<=tamrondas;rondas++){

                 if (opcion==1){
                 tirar5_dados(dados,cantidad_dados);}
                 else {ingresar_dados(dados,cantidad_dados);}

                       /** FOR PARA LA CANTIDAD DE TIROS EN EL JUEGO */
                        for(jugada=1;jugada<=3;jugada++){
                     cantidad_dados=5;

                cout << "RONDA " << rondas << "|" << "\t" << "TIRO "<<jugada<<"|"<<"\t"<< " TURNO DE "<<nombre<<"|"<<"\t"<< "PUNTOS: "<<puntos<<endl;
                cout << "_____________________________________________________________" << endl<< endl;

                /** MUESTRA SIEMPRE 5 DADOS */
                mostrar_dados(dados,cantidad_dados);

                 cout << "_____________________________________________________________" << endl;



                            /** SIGUE TIRANDO? */

                            if (jugada<3){cout << "Seguir tirando?(s/n) "; cin >> seguir_tirando;}
                            else {



                                puntosganados= verificar_todas_categorias (dados,cantidad_dados,jugada);
                                puntos+=puntosganados;

                 cout <<"Cantidad de puntos sumados: "<< puntosganados << endl;
                  system ("pause");
                  system ("cls");
                            }

                  if (seguir_tirando=='n' ){
              /** Aca voy a verificar si los dados finales califican a una puntuacion*/
               servida=generala_servida(dados);
               if (servida==1 && jugada==1) {
                                rondas=tamrondas;
                                jugada=3;
                                system ("cls");
                                cout << "GENERALA SERVIDA! FELICIDADES!"<< endl;
                                cout << "GANO EL JUGADOR: " << nombre<< endl;
                                servidaban=true;
                                system ("pause");
                                system ("cls");
                                }
              else {
               puntosganados=verificar_todas_categorias (dados,cantidad_dados,jugada);
            puntos+=puntosganados;


                 cout <<"Cantidad de puntos sumados: "<<  puntosganados << endl;

                  system ("pause");
                  system ("cls");
                  jugada=3;
                }}
                else {

                   /** SI ELIGE SEGUIR TIRANDO ACA SE LE PREGUNTA CUANTOS Y CUALES */
                    if (seguir_tirando=='s' && jugada < 3 ){
                        cout << "Cuantos dados seguis tirando?: "; cin >> cantidad_dados;
                        cuales_dados(v,cantidad_dados);
                        if (opcion==1){
                        dadoaleatorio(v,dados,cantidad_dados);}
                        else {cambiar_dados(v,dados,cantidad_dados);}




                        system ("pause");
                        system ("cls");
                cout << "_____________________________________________________________" << endl;
} }}
                }



if (servida==false){
                  cout << "EL GANADOR ES " << nombre << " EN " << rondas -1<< " RONDAS"<< "||"<< " Sus PUNTOS: "<< puntos <<endl;
                  puntosganador=puntos;
                  copiarVector(nombre,nombreganador);
                 system ("pause");
                 system ("cls");



                system ("cls");}
                 break;

/////////////////////////////////////////////** ACA COMIENZA EL MODO PARA 2 JUGADORES *//////////////////////////////////////////////////////////////////////

            case 2:
 /** PIDO DE LOS NOMBRES */

                cout << "Ingrese nombre de jugador 1: ";
                pedir_nombre(nombre);
                system ("cls");
                cout << "Ingrese nombre de jugador 2: ";
                pedir_nombre(nombre2);
                system ("cls");
                cout << "_____________________________________________________________" << endl;

                  cout << "Desea personalizar la cantidad de rondas?(DEFAULT 10) (s/n): "; cin >> personalizar;
                if (personalizar=='s'){
                    cout << "Ingrese la cantidad de rondas: ";
                    cin>>tamrondas;
                    system ("cls");
                }
                else {
                    tamrondas =10;
                    system ("cls");
                }



                /** FOR PARA LA CANTIDAD DE RONDAS EN EL JUEGO */
                for (rondas=1;rondas<=tamrondas;rondas++){


                 /** DE ACA CONTROLO DE QUIEN ES EL TURNO */
                 for (turno=1;turno<=2;turno++){



                 if (opcion==1){
                 tirar5_dados(dados,cantidad_dados);}
                 else {ingresar_dados(dados,cantidad_dados);}

                       /** FOR PARA LA CANTIDAD DE TIROS EN EL JUEGO */


                        for(jugada=1;jugada<=3;jugada++){
                     cantidad_dados=5;




                cout << "RONDA " << rondas << "|" << "\t" << "TIRO "<<jugada<<"|"<<"\t"<< " TURNO DE ";

                if (turno==1){cout << nombre<<"|"<<"\t"<< "PUNTOS: "<<puntos<<endl;}
                else {cout << nombre2<<"|"<<"\t"<< "PUNTOS: "<<puntos2<<endl;}


                cout << "_____________________________________________________________" << endl<< endl;

                /** MUESTRA SIEMPRE 5 DADOS */
                mostrar_dados(dados,cantidad_dados);

                 cout << "_____________________________________________________________" << endl;

                            /** SIGUE TIRANDO? */

                            if (jugada<3){cout << "Seguir tirando?(s/n) "; cin >> seguir_tirando;}
                            else {



                               if (turno==1){





                                puntosganados= verificar_todas_categorias (dados,cantidad_dados,jugada);
                                puntos+=puntosganados;


                                }

                                else {



                                puntosganados= verificar_todas_categorias (dados,cantidad_dados,jugada);
                                puntos2+=puntosganados;



                                }

             if (servida==0){
                 cout <<"Cantidad de puntos sumados: "<<  puntosganados << endl;
                  system ("pause");
                  system ("cls");}
                            }

                  if (seguir_tirando=='n' ){
              /** Aca voy a verificar si los dados finales califican a una puntuacion*/
                     if (turno==1){



                                    servida=generala_servida(dados);
                                if (servida==1 && jugada==1) {
                                rondas=tamrondas;
                                jugada=3;
                               /* turno=2;*/
                                system ("cls");
                                cout << "GENERALA SERVIDA! FELICIDADES!"<< endl;
                                copiarVector(nombre,nombreganador);
                                empate++;
                                /*cout << "GANO EL JUGADOR: " << nombre << endl;*/
                                system ("pause");
                                system ("cls");
                                servidaban=true;
                                }

                                else {puntosganados= verificar_todas_categorias (dados,cantidad_dados,jugada);
                                puntos+=puntosganados;}



                                     }



                                else {



                                     servida=generala_servida(dados);
                                if (servida==1 && jugada==1) {
                                rondas=tamrondas;
                                jugada=3;
                                system ("cls");
                                cout << "GENERALA SERVIDA! FELICIDADES!"<< endl;
                                copiarVector(nombre2,nombreganador);
                               /* cout << "GANO EL JUGADOR: " << nombre2 << endl;*/
                                system ("pause");
                                system ("cls");
                                servidaban=true;
                                }

                                      else {  puntosganados= verificar_todas_categorias (dados,cantidad_dados,jugada);
                                puntos2+=puntosganados;}




                                }



                if (servidaban==false){



                 cout <<"Cantidad de puntos sumados: ";

                    cout <<puntosganados << endl;


                  system ("pause");
                  system ("cls");
                  jugada=3;}
            }
                else {

                   /** SI ELIGE SEGUIR TIRANDO ACA SE LE PREGUNTA CUANTOS Y CUALES */
                    if (seguir_tirando=='s' && jugada < 3 ){
                        cout << "Cuantos dados seguis tirando?: "; cin >> cantidad_dados;
                        cuales_dados(v,cantidad_dados);
                        if (opcion==1){
                        dadoaleatorio(v,dados,cantidad_dados);}
                        else {cambiar_dados(v,dados,cantidad_dados);}




                        system ("pause");
                        system ("cls");
                cout << "_____________________________________________________________" << endl;
} }                            }
                }




                }

/////////////////////* UNA VEZ TERMINADO EL JUEGO MUESTRO EL GANADOR O EMPATE *//////////////////////////////

                system ("cls");

        if (servida==0){
          if (puntos>puntos2){
                cout << "EL GANADOR ES " << nombre << " EN " << rondas -1<< " RONDAS"<< "||"<< " Sus PUNTOS: "<< puntos <<endl;
            puntosganador=puntos;
        copiarVector(nombre,nombreganador);
           system ("pause");
           system ("cls");



          }

          else {

            cout << "EL GANADOR ES " << nombre2 << " EN " << rondas-1 <<" RONDAS"<< "||"<< " Sus PUNTOS: "<< puntos2 <<endl;
            puntosganador=puntos2;
        copiarVector(nombre2,nombreganador);
           system ("pause");
           system ("cls");

          }}

           else {
            if (empate==2  || puntos==puntos2){
             system ("cls");
             cout << "EMPATE!" << endl;
             system ("pause");
             system ("cls");
           }
             else {
                system ("cls");
                cout << "EL GANADOR CON GENERALA SERVIDA FUE: " << nombreganador << endl;
                system ("pause");
                system ("cls");
             }


            break;






          }


          }
          return puntosganador;
  }


