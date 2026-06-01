#include <stdio.h>
//questão 5
int main(int argc, char const *argv[])
{
    int a = 0;
    printf("Informe a altura do Triangulo de Pascal: ");
    scanf("%d", &a);
    int pascal[a][a];
    for (int i = 0; i < a; i++)
    { for (int j = 0; j <= i; j++)
        { if (j == 0 || j == i)
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    printf("\n");
    for (int i = 0; i < a; i++)
    { for (int e = 0; e < a - i - 1; e++) {
            printf("  "); 
        } for (int j = 0; j <= i; j++)
        {  printf("%4d", pascal[i][j]);
        } 
        printf("\n");
    }

    return 0;
}