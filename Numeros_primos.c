#include<stdio.h>

int suma_dig(int n);

int main(void)
{
    int b=0;
    int primos[200];
    for (int j=2; j<=1224; j++) //por definicion el 1 no es primo, se empieza en 2
    {
        int a=0;
        for(int i=1; i<=1224; i++) //divide a j entre los números del 1 al 1223
        {
            if(j%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
                a++;
        }
        if (a==2)  //si solo tiene dos números divisores entonces es primo y se imprime
        {
            primos[b] = j;
            b++;
        }
    }
    printf("%10s %10s %10s %10s %10s %10s %10s\n","Numero primo","Suma de digitos","Suma es primo","Suma es multiplo de 2","Suma es multiplo de 3","Suma es multiplo de 5","Suma es multiplo 7");
    for(b=0; b<200; b++)
    {
        printf("%6i ",primos[b]);
        printf("%14i ",suma_dig(primos[b]));
        for (int j=2; j<=1224; j++) //por definicion el 1 no es primo, se empieza en 2
        {
            int a=0;
            for(int i=1; i<=1224; i++) //divide a j entre los números del 1 al 1223
            {
                if(suma_dig(primos[b])%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
                    a++;
            }
            if (a==2)  //si solo tiene dos números divisores entonces es primo y se imprime
            {
                printf("%15s","Si");
                break;
            }
            else
            {
                printf("%15s","No");
                break;
            }
        }
        if(suma_dig(primos[b])%2 == 0)
        {
            printf("%17s","Si");
        }else{
            printf("%17s","No");
        }
        if(suma_dig(primos[b])%3 == 0)
        {
            printf("%21s","Si");
        }else{
            printf("%21s","No");
        }
        if(suma_dig(primos[b])%5 == 0)
        {
            printf("%23s","Si");
        }else{
            printf("%23s","No");
        }
        if(suma_dig(primos[b])%7 == 0)
        {
            printf("%21s","Si");
        }else{
            printf("%21s","No");
        }
        printf("\n");
    }
}

int suma_dig(int n)
{
    int suma=0;
    if (n < 0) n=-n;
    while (n!=0)
    {
        suma+=n%10;
        n=n/10;
    }
    return suma;
}
