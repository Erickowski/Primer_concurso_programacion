/*
   | 8 | | 7 | | 6 |
   | 5 | | 4 | | 3 |
   | 2 | | 1 | |   |

   w
   asd
*/

#include<stdio.h>

void imprimir_tablero();

int tabla[3][3];
int x=2,y=2;

int main(){
    int i=0,j=0,contador=1;
    char caracter,enter;
    //INICIALIZAR LA MATRIZ
    while (i<3){
       j=0;
    while (j<3){
        tabla[i][j]=contador;
        //printf("[%2i]",tabla[i][j]);
        j++;
        contador++;
    }
     printf("\n");
     i++;
    }
    tabla[x][y]=0;
    imprimir_tablero();
    do{
        caracter=getchar();
        enter=getchar();
        switch(caracter){
            case 'w': //arriba
                if(y<=1){
                        //movimiento
                    tabla[y][x]=tabla[y+1][x];
                    tabla[y+1][x]=0;
                    imprimir_tablero();
                    y++;
                }else{
                    printf("Fuera del limite\n");
                }
            break;
            case 's': //abajo
                 if(y>=0){
                    tabla[y][x]=tabla[y-1][x];
                    tabla[y-1][x]=0;
                    imprimir_tablero();
                    y--;
                }else{
                    printf("Fuera del limite\n");
                }
            break;
            case 'a': //izquierda
                 if(x<=1){
                    tabla[y][x]=tabla[y][x+1];
                    tabla[y][x+1]=0;
                    imprimir_tablero();
                    x++;
                }else{
                    printf("Fuera del limite\n");
                }
            break;
            case 'd': //derecha
                 if(x>=0){
                    tabla[y][x]=tabla[y][x-1];
                    tabla[y][x-1]=0;
                    imprimir_tablero();
                    x--;
                }else{
                    printf("Fuera del limite\n");
                }
            break;
            case '0': //salida
            break;
            default:
                printf("Caracter Incorrecto");
                break;
        }
        printf("caracter: %c\n",caracter);
    }while(caracter!='0');
    return 0;
}

void imprimir_tablero(){
   int i=0,j;
    while (i<3){
       j=0;
    while (j<3){
        if(tabla[i][j] !=0){
        printf("[%1i]",tabla[i][j]);
        }
        else{
            printf("[ ]");
        }
        j++;
    }
     printf("\n");
     i++;
    }

}
