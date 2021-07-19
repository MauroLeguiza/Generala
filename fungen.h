#ifndef FUNGEN_H_INCLUDED
#define FUNGEN_H_INCLUDED


/**CARTEL DE BIENVENIDA*/

int hola ();

/** MODO UN JUGADOR */

int empezarjuego(int,char []);


/** PEDIR NOMBRE */

void pedir_nombre (char []);

/** MOSTRAR NOMBRE */
void mostrar_nombre (char[]);

/**COPIAR */
void copiarVector(char[15], char[15]);


/** TIRAR 5 DADOS*/

void tirar5_dados (int[],int);

/** MOSTRAR DADOS */

void mostrar_dados (int[],int);


/** MODO TEST */
void ingresar_dados (int [], int);
void cambiar_dados (int [],int[],int);


/** SELECCIONA DADOS */
void cuales_dados (int [],int);

/** TIRA LOS DADOS SELECCIONADOS ALEATORIAMENTE */

void dadoaleatorio (int [], int[],int);

/** TODAS LAS CATEGORIAS */
int generala_servida (int[]);
void ordenarVector(int, int);
int verificar_poker (int [], int);
int verificar_full__generala (int[], int);
int verificar_escalera (int[],int);
int verificar_doble(int [],int,int);
int verificar_valores_repetidos (int[], int);
int verificar_numeromayor (int[], int);
int  verificar_todas_categorias (int[],int, int);

#endif // FUNGEN_H_INCLUDED
