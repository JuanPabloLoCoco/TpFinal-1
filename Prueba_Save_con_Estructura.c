#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getnum.c"
#define BORRA_BUFFER while (getchar() != '\n')
#define MAX_DIM 80

typedef struct{
    int jugadores;
    int turno;
    int dim;
    int score1;
    int score2;
    char **tablero;
}tPartida;

char** crearMatriz(int n)
{
    int flag=1;
    char** tablero=NULL;

    //Crear tantos arreglos como dimension
    tablero=malloc(sizeof(*tablero)*n);
    if(tablero!=NULL)
    {
        for (int i = 0; i < n  &&  flag; ++i)
        {
            //Para cada elemento del arreglo, darle otro arreglo de la misma dimension
            tablero[i]=malloc(sizeof(**tablero)*n);

            //Si no hay memoria, cancelar todo el proceso.
            if (tablero[i] == NULL)
            {
                flag=0;
                for (int j = 0; j >= 0; j--)
                    free(tablero[j]);
                free(tablero);
            }
        }
    }
    return tablero;
}

//cargar con struct
void GuardarPartida(const char* filename, tPartida* partida)
{
    //Sumo 3 para asegurarme de que entren el "./" y el 0
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "wb");

    // 0 = 2 players
    // 1 = CPU
    fwrite(&partida->jugadores, sizeof(partida->jugadores), 1, archivo);


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


void ImprimirTablero(int N, char** board)
{
    printf("\n\n\n");
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '0')
                printf("\t%c", ' ');
            else
                printf("\t%c", board[i][j]);
        }
        printf("\n\n\n");
    }
    printf("\n\n\n");
}


int main(){
    char * nombre = "hola";
    tPartida partida;
    partida.jugadores=2;
    partida.turno=2;
    partida.dim=5;
    partida.tablero=crearMatriz(partida.dim);
    partida.tablero[0]="ABCDE";
    partida.tablero[1]="BA0ED";
    partida.tablero[2]="CAEDE";
    partida.tablero[3]="A0ABC";
    partida.tablero[4]="K0K0K";

    GuardarPartida(nombre, &partida);
    ImprimirTablero(partida.dim, partida.tablero);

    return 0;
}
