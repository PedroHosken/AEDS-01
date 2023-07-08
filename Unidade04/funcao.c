// 816561 - Aed1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int somainv(int quantidade)
{
    // definir dados
    int x = 0;
    double soma = 0.0;
    double denominador = 4.0;
    double numerador = 1.0;
    double numero = 0.0;
    // ação
    for (x = 0; x < quantidade; x = x + 1)
    {
        denominador = denominador + 2.0;
        printf("\n%d-%lf/%lf", x, numerador, denominador);
        numero = numerador / denominador;
        printf("\n%lf", numero);
        soma = soma + numero;
        printf("\n%lf", soma);
    }
    return (soma);
}

int main()
{
    // definir dados
    int quantidade = 0;
    double soma = 0.0;
    // ação
    printf("Entre com a quantidade de dados desejada:\n");
    scanf("%d", &quantidade);
    getchar();
    soma = somainv(quantidade);

    return (0);
}