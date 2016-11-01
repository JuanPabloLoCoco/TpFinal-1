int HayJugada(char board[N][N])
{
	int x, y;
	int i=0;
	int j=0;
	for (i = 0; i < N-1; ++i)
		{
			for (j = 0; j < N-1; ++j)
			{
				if (board[i][j] != ' ')
				{
				//Existe Movimiento Horizontal
					if (board[i][j] == board[i][j+1])
						return 1;
					else if (board[i][j+1] == ' ')
					{
						y = j+2;
						while (board[i][y] == ' '   &&   y < N-1)
							y++;
						if (board[i][j] == board[i][y])
							return 1;
					}

			//Existe Movimiento Vertical
					if (board[i][j] == board[i+1][j])
						return 2;
					else if (board[i+1][j] == ' ')
					{
						x = i+2;
						while (board[x][j] == ' '   &&   x < N-1)
							x++;
						if (board[i][j] == board[x][j])
							return 2;
					}

			//Existe Movimiento Diagonal
					if (board[i][j] == board[i+1][j+1])
						return 3;
					else if (board[i+1][j+1] == ' ')
					{
						x = i+2;
						y = j+2;
						while (board[x][y] == ' '   &&   x < N-1   &&   y < N-1)
							x++;
							y++;
						if (board[i][j] == board[x][y])
							return 3;
					}
				}
			}
		}
	return 0;
}

#define MovValido(i,j,x,y,dim) (((i+x)<0) || ((i+y)>dim) || ((j+y)<0) || ((j+y)>dim) || ((x==0) && (y!=1))?1:0;  /*i y j representan la posicion, x e y los desplazamientos*/
#define bloque 10
	

	int Minimo (char **matriz, int dim, *tabla[])
	{
	  
	  int i,j,cont=0,t,s;
	  
	  for (i=0,i<dim, i++)
	  {
	    for (j=0, j<dim, j++)
	    {
	      for (t=0, t<2, t++)
	      {
	        for (s=-1,s<2,s++)
	        {
	          if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])
	          {
	            if ((cont%bloque)==0)
	            {
	              tabla[]=realloc(tabla[],(cont+bloque)*sizeof tabla[]);
	            }
	            asignacionTabla(tabla,cont,i,j,t,s,1) 
	          }
	        }
	      }  
	    }
	  }   
	  tabla[]=realloc(tabla[],cont*sizeof(tabla[]);
	  return cont;
	}
	

	int Maximo (char **matriz, int dim, *tabla[])
	{
	  int i,j,cont=0,t,s,max=1,contmax=0;
	  
	  for (i=0,i<dim, i++)
	  {
	    for (j=0, j<dim, j++)
	    {
	      for (t=0, t<2, t++)
	      {
	        for (s=-1,s<2,s++)
	        {
	          if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])
	          {
	            cont=contarsaltos(i,j,t,s,dim)
	            if (cont>max)
	            {
	              max=cont;
	              contmax=0;
	              tabla[]=realloc(tabla[],(contmax+bloque)*sizeof (*tabla[]); /*consultar que tan bien esta esto*/
	              asignacionTabla(tabla,0,i,j,t,s,max));
	              contmax++;
	            }
	            if (cont==max)
	            {
	              if ((contmax%bloque)==0)  
	              {  
	                tabla[]=realloc(tabla[],(contmax+bloque)*sizeof(tabla[]));
	              }  
	              asignacionTabla(tabla,contmax,i,j,t,s,max);
	              contmax++;
	            }
	          }
	        }
	      }
	    }
	  }
	  tabla[]=realloc(tabla[],(contmax)*sizeof(tabla[]));
	  return contmax;
	}
	     
	

	

	asignacionTabla(char tabla[][],int pos,int fo,int co,int x,int y,int salto)
	{
	  tabla[pos][0]=i;
	  tabla[pos][1]=j;
	  tabla[pos][2]=i+(salto*x);
	  tabla[pos][3]=j+(salto*y);
	}
	

	void MovPc(char **matriz,int dim)
	{
	  int op,opciones,elegida;
	  char *tabla[4];
	  op=aleatorio(0,1);
	  if (op==0)
	    opciones=Minimo(matriz,dim, tabla);
	  else
	    opciones=Maximo(matriz, dim,tabla);
	  elegida=aleatorio(1,opciones);
	  hacermovimiento(tabla[elegida][0],tabla[elegida][1],tabla[elegida][2],tabla[elegida][3]);
	  return;
	 }
	 
	int aleatorio(int izq, int der)
	{ 
	  int num;
	  seed(time(null));
	  num= srand/((double)rand_max)*(der+izq+1)
	  return num;
	}

