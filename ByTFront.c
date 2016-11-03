#include "ByT.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "getnum.c"
#define BORRA_BUFFER while (getchar() != '\n')
#define MAX_DIM 80

int main(){
    int error=-1;
    printf("----------BIENVENIDO AL JUEGO BOTONES Y TIJERAS----------\n\n\n");
    menu();
    ingrese_comando();
    return 0;
}

void menu(){
    int opcion[2]={0};
    printf("Que desea hacer?\n\n\t1.Juego dos jugadores\n\t2.Juego contra computadora\n\t3.Recuperar juego grabado\n\t4.Salir\n\n");
    printf("Ingrese su opcion: ");
    scanf("%d%c",&opcion[0],&opcion[1]);
	while (opcion[0]<1 || opcion[0]>4 || opcion[1]!='\n')
    {
        BORRA_BUFFER;//problemas
        printf("\nOpcion incorrecta, ingrese opcion valida: ");
        scanf("%d%c",&opcion[0],&opcion[1]);
    }
    switch(opcion[0]){
        case(1):pedirDim();
                break;
        case(2):pedirDim();
                break;
        case(3):printf("Ingrese nombre de juego que desea recuperar: ");
                //scanf("%s",nombre_partida);
                //load_game(nombre_partida);
                break;
        case(4):printf("\n\nSaliendo...Gracias por jugar.\n\n");
                exit(9);
                break;
    }

}

void ingrese_comando(){
    //ver por longitud cuando ponfo el nombre
    char comando[MAX_DIM]={0},nuevalinea=0;
    char*nombre_partida=NULL;
    int terminado=0,i,f0,c0,f1,c1;
    printf("\nIngrese comando: ");
    fgets(comando,17,stdin);
    while(terminado==0)
    {
      if((comando[16]!='[') && (comando[15]!=0))
        {
              BORRA_BUFFER;
               printf("Comando incorrecto, ingrese nuevamente: ");
               fgets(comando,17,stdin);
               for(i=0;i<MAX_DIM;i++)
                comando[i]=0;
        }
        else{
            if(strncmp(comando, "save", 4)==0)
            {
                printf("entro save\n");
                sscanf(comando,"save %s",nombre_partida);
                printf("Nombre partida:%p.\n",*nombre_partida);
                terminado=1;
                save_game(*nombre_partida);
            }
            else if (strncmp(comando, "quit", 4)==0)
            {
                quit();
                terminado=1;
            }
            else if((sscanf(comando,"[%d,%d][%d,%d]%c", &f0, &c0, &f1, &c1, &nuevalinea))==5 && nuevalinea=='\n')
            {
                printf("f0=%d, c0=%d, f1=%d, c1=%d\n", f0, c0, f1, c1);
                terminado=1;
            }
            else
            {
                printf("Comando incorrecto2, ingrese nuevamente: ");
                for(i=0;i<MAX_DIM;i++)
                    comando[i]=0;
                fgets(comando,17,stdin);
                nuevalinea=0;
            }
        }
    }
}

void pedirDim(){
    int nivel[2]={0};
    char nombre_partida[MAX_DIM]={0};
	printf("Ingrese nivel/dimesion en la que desea jugar(entre 5 y 30): ");
    scanf("%d%c",&nivel[0],&nivel[1]);
    while (nivel[0]<5 || nivel[0]>30 || nivel[1]!='\n')
    {
        fflush(stdin);
        printf("\nNivel incorrecto, ingrese un nivel valido: ");
        scanf("%d%c",&nivel[0],&nivel[1]);

    }
    printf("%dx%d\n",nivel[0],nivel[0]);//guardar numxnum en un puntero y pasarselo a la fun existe archivo

    return 0;
}

void quit(){
    char*nombre_partida=NULL;
    int rta,rta2,error=0,error2=0;
    printf("Esta seguro que desea salir (Y/N)?: ");
    rta=getchar();
    while(error==0)
    {
        if ('Y'==toupper(rta))
        {
            printf("Desea guardar el archivo (Y/N)?: ");
            BORRA_BUFFER;
            error==1;
            rta2=getchar();
            while(error2==0)
            {
                if('Y'==toupper(rta2))
                {
                    printf("Ingrese nombre del archivo: ");
                    BORRA_BUFFER;
                    error2==1;
                    scanf("%s",nombre_partida);
                    printf("%p\n",nombre_partida);
                    save_game(nombre_partida);
                }
                else if('N'==toupper(rta2))
                {
                    error2=1;
                    printf("Saliendo....gracias por jugar.\n\n");
                    exit(9);
                }
                else
                {
                    BORRA_BUFFER;
                    printf("Ingrese una opcion correcta: ");
                    rta2=getchar();
                }
            }

        }
        else if ('N'==toupper(rta))
        {
            error=1;
            BORRA_BUFFER;
            ingrese_comando();
        }
        else
        {
            BORRA_BUFFER;
            printf("Ingrese una opcion correcta: ");
            rta=getchar();
        }
    }
}
