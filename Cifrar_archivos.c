#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128

void menu(void);
int main(void)
{
    int opc;
    FILE * pFile;
    FILE *fp;
    char ruta[100];
    char archivo[100];
    char ar[] = ".cif";
    char text[100];
    char textC[100];
    int a;
    menu();
    scanf("%i",&opc);
    do
    {
        switch(opc)
        {
        case 1:
            printf("Ingresa ruta del archivo: ");
            scanf("%s",&ruta);
            pFile = fopen (ruta,"r");
            if (pFile == NULL)
                exit(1);
            for(int i=0;i<100;i++){
                archivo[i]=ruta[i];
                if(ruta[i+1]== '.') break;
            }
            strcat(archivo,ar);
            fp = fopen ( archivo, "w" );
            while (feof(pFile) == 0)
            {
                fgets(text,100,pFile);
                for(int i=0;i<strlen(text)+1;i++){
                    textC[i] = text[strlen(text)-i];
                    //printf("%c",textC[i]);
                    char c = textC[i];
                    a = (int)c;
                    fprintf(fp,"%d",a*211);
                }
            }
            fclose ( fp );
            system("pause");
            break;
        case 2:
            break;
        case 3:
            printf("Hasta luego...\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        system("cls");
    }
    while(opc!=3);
    fclose(pFile);
    return 0;
}

void menu(void)
{
    printf("B I E N V E N I D O\n");
    printf("1.- Cifrar archivo\n");
    printf("2.- Descrifrar archivo\n");
    printf("3.- Salir\n");
    printf("Selecciona una opcion: ");
}
