int hacerjugada(**matriz, int dim, int f1, int c1, int f2, int c2 )
{
  int dx,dy,x=f1,y=c1, cont=0 ;
  dx=(f2-f1)/fabs(f2-f1);
  dy=(c2-c1)/fabs(c2-c1);

  while(f2==x && c2==y)
  {
    if ( matriz[x][y]!="")
    {
        matrix[x][y]="";
        cont++;
    }
    x=x+dx;
    y=y+dy;
    }
return cont;
}
