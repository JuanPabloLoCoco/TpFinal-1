/*aca van los prototipos de todas las funciones del Back*/
#include<stdio.h>
#include<stdlib.h>
//genera numero aleatorio entre izq y der
int aleatorio(int izq, int der);

int Minimo (char **matriz, int dim,tMovimiento *tabla);

int Buscarmismo(char **matriz,int i, int j, int t, int s, int dim);

int Maximo (char **matriz, int dim,tMovimiento *tabla);

int contarsaltos(char **matriz,int x,int y, int desx, int desy, int dim, int *posfx, int *posfy );

asignacionTabla(movimientos tabla[],int pos,int F1,int C1,int F2,int C2);//FUNCION?

void MovPc(char **matriz,int dim);

int HayJugada(int N, char board[N][N]);

int InvalidMove(int N, char tablero[N][N], int F1, int C1, int F1, int C2);

int ExisteArchivo(const char* filename);

void GuardarPartida(const char* filename, int jugadores, int turno, int dim, char tablero[dim][dim]);

int CargarPartida(char* filename, int jugadores, int turno, int dim, char tablero[dim][dim]);

