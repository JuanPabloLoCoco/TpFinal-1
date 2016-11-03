int hacerjugada(**matriz, int dim, int F1, int C1, int F2, int C2 )
{
  int dx,dy,x=F1,y=C1, cont=0 ;
  dx=(F2-F1)/fabs(F2-F1);
  dy=(C2-C1)/fabs(C2-C1);

  while(F2!=x &&C2!=y)
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
