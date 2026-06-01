#include <stdio.h>
//questão 2
int main(int argc, char const *argv[])
{
     int t = 0;
    printf("informe o tamanho do triangulo:");
    scanf("%d",&t);

    if (t >= 2) {
        for (int i = 0; i < t; i++) {
        for (int j = 0; j < t - i - 1; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i + 1; k++)
        {
            printf("%d", k);
        }
        for (int k = i; k >= 1; k--)
        {
            printf("%d", k);
        }
        printf("\n");
    }
        return 0;
    } else {
        printf("O valor do tamanho do triangulo deve ser maior ou igual a 2.\n");
    }
    return 0;
}
