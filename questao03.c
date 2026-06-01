#include <stdio.h>
//questão 3
int main(int argc, char const *argv[])
{   
    int t = 0, pc;  
    printf("Digite a altura do triangulo desejada: ");    
    scanf("%d", &t);
    if (t >= 4) {
         printf("digite se deseja:\n1-preenchido\n2-vazio\n");
    scanf("%d", &pc);
    for (int i = 1; i < t; i++){
        for (int j = 0; j < i; j++){
            if (pc == 1) {
                printf("*");
            } else if (pc == 2)
            {
                if (j == 0 || j == i - 1)
                {
                    printf("*");
                }
                   if (i == t - 1)
                {
                    printf("*");
                }else
                {
                    printf(" ");
            }
                } else
                {
                    printf("opção invalida. Por favor, escolha entre 1 ou 2");
                    return 0;
                }
             
        }
    printf("\n");
    }
        return 0;
    } else
    {
        printf("A altura do triangulo deve ser maior ou igual a 4");
    }
   

    return 0;
}