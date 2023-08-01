// 1465660_AED1
#include <stdio.h>
#include <stdbool.h>

bool searchvalue(int n, int array[])
{
    //definir dados
     bool value = false;
     int valor = 0;
     int y = 0;
    // acao
     printf("\nQual valor voce deseja");
     scanf("%d",&valor);
    // acao2
     for( y = 0; y < n; y = y + 1)
     {
         if ( valor == array[y])
         {
             value = true;
         }
     }
     
    return(value);
}

int main ()
{
    // definir arquivo
     FILE *arquivo;
     arquivo = fopen("untitled1.txt", "r");
    // definir arranjo
     int n = 0;
     int z = 0;
     int x = 1;
     bool valor = false;
     fscanf(arquivo, "%i",&n);
     int array [n];
    // acao1ok
     for( x = 1; x <= n; x = x +1)
     {
          fscanf(arquivo, "%d",&array[z]);
         //printf ("\n%d",array[z]);
          z = z + 1;
     }
    //acao2
     valor = searchvalue(n,array);
      if ( valor == 0)
          {
             printf("Nao ha");
          }
      else 
      {
         printf("Ha");
      }
    
     
     
     
     
    return(0);
}