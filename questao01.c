#include <stdio.h>
//questão 1
int main(int argc, char const *argv[])
{
    int i = 0, j = 0, l =0, pc;  
    printf("Digite o tamanho da altura desejada: ");    
    scanf("%d", &l);
    if (l >= 3) {
        printf("digite se deseja:\n1-preenchido\n2-vazio\n");
    scanf("%d", &pc);
        for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (pc == 1)
            {
                printf("* ");
            }
            else if (pc == 2)
            {
                if (i == 0 || i == l - 1 || j == 0 || j == l - 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            else
            {
                printf("Opção inválida. Por favor, digite 1 ou 2.\n");
                return 0;
            }
        }
        printf("\n");

        
    }
        return 0;
    }
    else {
        printf("O valor do tamanho da altura deve ser maior ou igual a 3.\n");
    }   

    return 0;
}
