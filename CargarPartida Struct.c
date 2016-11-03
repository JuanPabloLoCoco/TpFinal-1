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
    int jugadores;
    int ptsjug1;
    int ptsjug2;
    int **tablero;//falta el malloc y definirla para poder probarla
    int dim;
}tPartida;

int main(){
    char * nombre = "hola";
    tPartida partida;
    partida.jugadores=2;
    partida.turno=2;
    partida.dim=5;

    CargarPartida(nombre,&partida);
    return 0;


}

int CargarPartida(char* filename, tPartida *partida)
{
    if (!(ExisteArchivo(filename)))
    {
        printf("No existe");
        return 0;
    }
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "rb");


    fread(&partida->jugadores, sizeof(int), 1, archivo);
    fread(&partida->turno, sizeof(int), 1, archivo);
    fread(&partida->dim, sizeof(int), 1, archivo);

    for (int i = 0; i < partida->dim; ++i)
    {
   	 for (int j = 0; j < partida->dim; ++j)
   	 {
   		 fread(&(partida->tablero[i][j]), sizeof(char), 1, archivo);
   		 printf("%c\t",partida->tablero[i][j]);
   	 }
   	 printf("\n");
    }
    fclose(archivo);
    return 1;
}

int ExisteArchivo(const char* filename)
{
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo;

    if ((archivo = fopen(ubicacion, "rb")) != NULL)
    {
   	 fclose(archivo);
   	 return 1;
    }
    return 0;
}
