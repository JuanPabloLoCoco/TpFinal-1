
#define MovValido(i,j,x,y,dim) (((i+(x))<0) || ((i+(y))>dim) || ((j+(y))<0) || ((j+(y))>dim) || ((x==0) && (y!=1))?1:0;
#define bloque 10

	/*i y j representan la posicion, x e y los desplazamientos*/
	/*se analiza que no se salga de los limites de la matrix y que los movimientos sean con la L inferior*/
	/*con este procedimiento se hace mas eficiente la busqueda de movimientos*/

typedef struct{
    int fi;
    int ci;
    int ff;
    int cf;
}movimiento; /*estructura con posiciones iniciales y finales de movimientos*/


int aleatorio(int izq, int der)
{
  int num;
  seed(time(null));
  num= srand/((double)rand_max)*(der+izq+1)
  return num;
}

int Minimo (char **matriz, int dim,movimiento *tabla)
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
              tabla=realloc(tabla,(cont+bloque)*sizeof (movimiento));
            }
            asignacionTabla(tabla,cont,i,j,i+t*salto,j+s*salto,)
          }
        }
      }
    }
  }
  tabla=realloc(tabla,cont*sizeof(movimiento);
  return cont;
}

int Buscarmismo(char **matriz,int i, int j, int t, int s, int dim)
{
  int salto;
  for (salto=1, MovValido(i,j,t*salto,s*salto,dim) && (matriz[i+t*salto][j+s*salto]=="" || matriz[i][j]==matriz[i+t*salto][j+s*salto]),salto++) /*cuenta la cantidad de saltos en una posicion hasta encontrar indebido*/
  {
    if matriz[i][j]==matriz[i+t*salto][j+s*salto];
      return salto;
  }
  return 0;
}

int Maximo (char **matriz, int dim,movimiento *tabla)
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
              tabla=realloc(tabla,(contmax+bloque)*sizeof (movimiento)); /*consultar que tan bien esta esto*/
              asignacionTabla(tabla,0,i,j,posfx,posfy));
              contmax++;
            }
            if (cont==max)
            {
              if ((contmax%bloque)==0)
              {
                tabla=realloc(tabla,(contmax+bloque)*sizeof(movimiento));
              }
              asignacionTabla(tabla,contmax,i,j,posfx,posfy);
              contmax++;
            }
          }
        }
      }
    }
  }
  tabla=realloc(tabla,(contmax)*sizeof(movimiento));
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

asignacionTabla(movimientos tabla[],int pos,int fo,int co,int ff,int cf)
{
  tabla[pos].fi=i;
  tabla[pos].ci=j;
  tabla[pos].ff=ff;
  tabla[pos].cf=cf;
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
  hacermovimiento(tabla[elegida].fi,tabla[elegida].ci,tabla[elegida].ff,tabla[elegida].cf);
  return;
}
int HayJugada(int N, char board[N][N])
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
   				 if (C1 < N-1   	 &&   	 board[F1][C1] == board[F1][C1+1])
   					 return 1;
   				 else if (board[F1][C1+1] == '0'    &&    C1 < N-2)
   				 {
   					 C2 = C1+2;
   					 while (board[F1][C2] == '0'   &&   C2 < N-1)
   						 C2++;
   					 if (board[F1][C1] == board[F1][C2])
   						 return 1;
   				 }


   		 //Existe Movimiento Vertical
   				 if (F1 < N-1   	 &&    board[F1][C1] == board[F1+1][C1])
   					 return 2;
   				 else if (board[F1+1][C1] == '0'    &&    F1 < N-2)
   				 {
   					 F2 = F1+2;
   					 while (board[F2][C1] == '0'   &&   F2 < N-1)
   						 F2++;
   					 if (board[F1][C1] == board[F2][C1])
   						 return 2;
   				 }


   		 //Existe Movimiento Diagonal a la Derecha
   				 if (F1 < N-1   	 &&   	 C1 < N-1   	 &&   	 board[F1][C1] == board[F1+1][C1+1])
   					 return 3;
   				 else if (F1 < N-2   	 &&   	 C1 < N-2   	 &&   	 board[F1+1][C1+1] == '0')
   				 {
   					 F2 = F1+2;
   					 C2 = C1+2;
   					 while (board[f][c] == '0'   &&   F2 < N-1   &&   C2 < N-1)
   					 {
   						 F2++;
   						 C2++;
   					 }
   					 if (board[F1][C1] == board[F2][C2])
   						 return 3;
   				 }


   		 //Existe Movimiento Diagonal a la Izquierda
   				 if (F1 < N-1   	 &&   	 C1 > 0         &&    	 board[F1][C1] == board[F1-1][C1-1])
   					 return 4;
   				 else if (F1 < N-2   	 &&   	 C1 > 1         &&    	 board[F1+1][C1-1] == '0')
   				 {
   					 F2 = F1+2;
   					C2 = C1-2;
   					 while (board[F2][C2] == '0'   &&   F2 < N-1   &&   C2 > 0)
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


int InvalidMove(int N, char tablero[N][N], int F1, int C1, int F1, int C2)
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
   	 double my = (float)(C2-C1);
   	 double mx = (float)(F2-F1);
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


void GuardarPartida(const char* filename, int jugadores, int turno, int dim, char tablero[dim][dim])
{
    //Sumo 3 para asegurarme de que entren el "./" y el 0
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "wb");


    // 0 = 2 players
    // 1 = CPU
    fwrite(&jugadores, sizeof(int), 1, archivo);


    // 1 = Le toca a P1
    // 2 = Le toca a P2 o CPU
    fwrite(&turno, sizeof(turno), 1, archivo);


    // Dimension del tablero
    fwrite(&dim, sizeof(dim), 1, archivo);


    // Tablero
    for (int i = 0; i < dim; ++i)
   	 for (int j = 0; j < dim; ++j)
   	 {
   		 fwrite(&(tablero[i][j]), sizeof(char), 1, archivo);
   	 }

    fclose(archivo);
}


int CargarPartida(char* filename, int jugadores, int turno, int dim, char tablero[dim][dim])
{
    if (!(ExisteArchivo(filename)))
    {
   	 return 0;
    }
    char ubicacion[strlen(filename)+3];
    snprintf(ubicacion, sizeof(ubicacion), "./%s", filename);
    FILE* archivo = fopen(ubicacion, "rb");


    fread(&jugadores, sizeof(int), 1, archivo);
    fread(&turno, sizeof(int), 1, archivo);
    fread(&dim, sizeof(int), 1, archivo);

    for (int i = 0; i < dim; ++i)
    {
   	 for (int j = 0; j < dim; ++j)
   	 {
   		 fread(&(tablero[i][j]), sizeof(char), 1, archivo);
   	 }
    }
    fclose(archivo);
    return 1;
}
