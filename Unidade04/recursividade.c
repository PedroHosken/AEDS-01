// 816561 - Aed1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void method01a (int quantidade, int numero)
{
   
    if (quantidade>0)
    {
       
        printf("\n%d", numero);
        method01a(quantidade - 1, numero + 2);
       

    }
}

int main ()
{
    int numero = 6;
    int quantidade = 0;
    printf("Entrar com quantidade desejada:");
    scanf("%d", &quantidade);
    getchar();
    method01a(quantidade,numero);
}