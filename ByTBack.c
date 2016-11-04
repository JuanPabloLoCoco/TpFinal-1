#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "getnum.c"
#define BORRA_BUFFER while (getchar() != '\n')
#define MAX_DIM 80
#define MovValido(i,j,x,y,dim) (((i+(x))<0) || ((i+(y))>dim) || ((j+(y))<0) || ((j+(y))>dim) || ((x==0) && (y!=1))?1:0;
#define bloque 10

	/*i y j representan la posicion, x e y los desplazamientos*/
	/*se analiza que no se salga de los limites de la matrix y que los movimientos sean con la L inferior*/
	/*con este procedimiento se hace mas eficiente la busqueda de movimientos*/

typedef struct{
    int F1;
    int C1;
    int F2;
    int C2;
}tMovimiento; /*estructura con posiciones iniciales y finales de movimientos*/

typedef struct{
    int turno;
    int dim;
    int score1;
    int score2;
    char **tablero;
}tPartida;

int aleatorio(int izq, int der)
{
  int num;
  seed(time(null));
  num= srand/((double)rand_max)*(der+izq+1)
  return num;
}

int Minimo (char **matriz, int dim,tMovimiento *tabla)
{
  int i,j,t,s,cont=0;
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {
          salto=Buscarmismo(matriz,i,j,t,s,dim) /*devuleve la cantidad de saltos que realizo hasta encontrar uno igual.*/
          if (salto!=0) /*Si salto es distinto de 0, significa que encontro en una cierta cantidad de saltos*/
          {
            if ((cont%bloque)==0)
            {
              tabla=realloc(tabla,(cont+bloque)*sizeof (tMovimiento));
            }
            asignacionTabla(tabla,cont,i,j,i+t*salto,j+s*salto,)
          }
        }
      }
    }
  }
  tabla=realloc(tabla,cont*sizeof(tMovimiento);
  return cont;
}

int Buscarmismo(char **matriz,int i, int j, int t, int s, int dim)
{
  int salto;
  for (salto=1, MovValido(i,j,t*salto,s*salto,dim) && (matriz[i+t*salto][j+s*salto]==""
        || matriz[i][j]==matriz[i+t*salto][j+s*salto]),salto++)
            /*cuenta la cantidad de saltos en una posicion hasta encontrar indebido*/
  {
    if matriz[i][j]==matriz[i+t*salto][j+s*salto];
      return salto;
  }
  return 0;
}

int Maximo (char **matriz, int dim,tMovimiento *tabla)
{
  int i,j,t,s,max=1,contmax=0,cont=0,posfx,posfy ; /*contmax es el contado del listado de maximos*/
                                      /*Cont, cuenta los saltos*/
	                                      /*max, señala la cantidad maxima de botones. Inicializa en 1, porque seguro que hay movimiento*/
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {
          /*if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])*/
          {
            cont=contarsaltos(matriz,i,j,t,s,dim,&posfx,&posfy)
            if (cont>max)
            {
              max=cont;
              contmax=0;
              tabla=realloc(tabla,(contmax+bloque)*sizeof (tMovimiento)); /*consultar que tan bien esta esto*/
              asignacionTabla(tabla,0,i,j,posfx,posfy));
              contmax++;
            }
            if (cont==max)
            {
              if ((contmax%bloque)==0)
              {
                tabla=realloc(tabla,(contmax+bloque)*sizeof(tMovimiento));
              }
              asignacionTabla(tabla,contmax,i,j,posfx,posfy);
              contmax++;
            }
          }
        }
      }
    }
  }
  tabla=realloc(tabla,(contmax)*sizeof(tMovimiento));
  return contmax;
}

int contarsaltos(char **matriz,int x,int y, int desx, int desy, int dim, int *posfx, int *posfy )
{
  int botones=0, saltos;
  for (saltos=1, MovValido(x,y,desx*saltos,desy*saltos,dim) && (matriz[x][y]==matriz[x+desx*saltos][y+desy*saltos]||matriz[x+desx*saltos][y+desy*saltos]==""),saltos++)
  {
    if (matriz[x][y]==matriz[x+desx*saltos][y+desy*saltos])
    {
      botones++;
      *posfx=x+desx*saltos
      *posfy=y+desy*saltos
    }
  }
 return botones;
}

asignacionTabla(movimientos tabla[],int pos,int F1,int C1,int F2,int C2)//funcion?
{
  tabla[pos].F1=i;
  tabla[pos].C1=j;
  tabla[pos].F2=F2;
  tabla[pos].C2=C2;
}

void MovPc(char **matriz,int dim)
{
  int op,opciones,elegida;
  movimento *tabla;
  op=aleatorio(0,1);
  if (op==0)
    opciones=Minimo(matriz,dim, tabla);
  else
    opciones=Maximo(matriz, dim,tabla);
  elegida=aleatorio(0,opciones-1);
  hacermovimiento(tabla[elegida].F1,tabla[elegida].C1,tabla[elegida].F2,tabla[elegida].C2);
  return;
}
int HayJugada(int N, char board[N][N])//n=dim? board=matriz
{
    int F2, C2;
    int F1;
    int C1;
    for (F1 = 0; F1 < N; ++F1)
   	 {
   		 for (C1 = 0; C1 < N; ++C1)
   		 {
   			 if (board[F1][C1] != '0')
   			 {
   			 //Existe Movimiento Horizontal
   				 if (C1 < N-1  && board[F1][C1] == board[F1][C1+1])
   					 return 1;
   				 else if (board[F1][C1+1] == '0' &&  C1 < N-2)
   				 {
   					 C2 = C1+2;
   					 while (board[F1][C2] == '0' && C2 < N-1)
   						 C2++;
   					 if (board[F1][C1] == board[F1][C2])
   						 return 1;
   				 }


   		 //Existe Movimiento Vertical
   				 if (F1 < N-1  &&  board[F1][C1] == board[F1+1][C1])
   					 return 2;
   				 else if (board[F1+1][C1] == '0'  &&  F1 < N-2)
   				 {
   					 F2 = F1+2;
   					 while (board[F2][C1] == '0'   &&   F2 < N-1)
   						 F2++;
   					 if (board[F1][C1] == board[F2][C1])
   						 return 2;
   				 }


   		 //Existe Movimiento Diagonal a la Derecha
   				 if (F1 < N-1  && C1 < N-1  && board[F1][C1] == board[F1+1][C1+1])
   					 return 3;
   				 else if (F1 < N-2  && C1 < N-2 && board[F1+1][C1+1] == '0')
   				 {
   					 F2 = F1+2;
   					 C2 = C1+2;
   					 while (board[f][c] == '0' && F2 < N-1 && C2 < N-1)
   					 {
   						 F2++;
   						 C2++;
   					 }
   					 if (board[F1][C1] == board[F2][C2])
   						 return 3;
   				 }


   		 //Existe Movimiento Diagonal a la Izquierda
   				 if (F1 < N-1  && C1 > 0  && board[F1][C1] == board[F1-1][C1-1])
   					 return 4;
   				 else if (F1 < N-2  && C1 > 1 && board[F1+1][C1-1] == '0')
   				 {
   					 F2 = F1+2;
   					C2 = C1-2;
   					 while (board[F2][C2] == '0' && F2 < N-1   &&   C2 > 0)
   					 {
   						F2++;
   						C2--;
   					 }
   					 if (board[F1][C1] == board[F2][C2])
   						 return 4;
   				 }
   			 }
   		 }
   	 }
    return 0;
}


int InvalidMove(int N, char tablero[N][N], int F1, int C1, int F2, int C2)
{
    //ERROR 1   	 Posicion inicial invalida
    //ERROR 2   	 Posicion Final invalida
    //ERROR 3   	 Necesito botones especificos
    //ERROR 4   	 No vale cortar uno solo
    //ERROR 5   	 No es una diagonal
    //ERROR 6   	 Hay botones bloqueando el camino




    //Dominio Original
    if (F1 >= N || F1 < 0 || C1 >= N || C1 < 0)
   	 return 1;


    //Dominio Final
    if (F2 >= N || F2 < 0 || C2 >= N || C2 < 0)
   	 return 2;


    if (tablero[F1][C1] == '0' || tablero[F2][C2] == '0')
   	 return 3;


    //Direccion
   	 //Se queda fijo
   	 if (F1 == F2 && C1 == C2)
   		 return 4;
   	 double my = (double)(C2-C1);
   	 double mx = (double)(F2-F1);
   	 //No es diagonal
   	 if (mx != 0     &&    	 my != 0     &&    	 abs(my/mx) != 1)
   		 return 5;


    //Blocked
   	 int x;
   	 int y;
   	 int dx = (mx < 0)? -1 : (mx > 0);
   	 int dy = (my < 0)? -1 : (my > 0);
   	 for (x = F1, y = C1;    x != F2 || y != C2   	 ;   	 x += dx, y += dy   )
   			 {
   			 if (tablero[F1][C1] != tablero[x][y]   &&  tablero[x][y] != '0')
   				 return 6;
   			 }
    return 0;
}

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

void GuardarPartida(const char* filename, int jugadores, tPartida* partida)
{
    //Sumo 3 para asegurarme de que entren el "./" y el 0
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "wb");

    // 0 = 2 players
    // 1 = CPU
    fwrite(&jugadores, sizeof(jugadores), 1, archivo);

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

int CargarPartida(char* filename, int jugadores, tPartida *partida)
{
    if (!(ExisteArchivo(filename)))
        return 0;

    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "rb");

    fread(&jugadores, sizeof(jugadores), 1, archivo);
    fread(&partida->turno, sizeof(partida->turno), 1, archivo);
    fread(&partida->dim, sizeof(partida->dim), 1, archivo);

//Por si cargo un tablero de otro tamaño, ajustarlo
    partida->tablero=crearMatriz(partida->dim);
    for (int i = 0; i < (partida->dim); ++i)
     for (int j = 0; j < (partida->dim); ++j)
        partida->tablero[i][j]=fgetc(archivo);

    fclose(archivo);
    return 1;
}
