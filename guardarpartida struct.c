
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "getnum.c"
#define BORRA_BUFFER while (getchar() != '\n')
#define MAX_DIM 80

//cargar con struct
 void GuardarPartida(filename,partida);

typedef struct{
    int turno;
    int ptsjug1;
    int ptsjug2;
    char **tablero;
    int jugadores;
    int dim;
}tPartida;

int main(){
    char * nombre = "hola";
    tPartida partida;
    partida.jugadores=2;partida.turno=2;
    partida.dim=5;

    GuardarPartida(nombre,&partida);
    return 0;


}
void GuardarPartida(const char* filename, tPartida* partida)
{
    //Sumo 3 para asegurarme de que entren el "./" y el 0
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "wb");


    // 0 = 2 players
    // 1 = CPU
    fwrite(&partida->jugadores, sizeof(int), 1, archivo);


    // 1 = Le toca a P1
    // 2 = Le toca a P2 o CPU
    fwrite(&partida->turno, sizeof(partida->turno), 1, archivo);


    // Dimension del tablero
    fwrite(&partida->dim, sizeof(partida->dim), 1, archivo);


    // Tablero
    for (int i = 0; i < (partida->dim); ++i)
   	 for (int j = 0; j < (partida->dim); ++j)
   	 {
   		 fwrite((&partida->tablero[i][j]), sizeof(char), 1, archivo);
   	 }

    fclose(archivo);
}


