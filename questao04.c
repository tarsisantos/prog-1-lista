#include <stdio.h>
//questão 4
int main() {
    int n; 
    printf("Informe a largura do losango: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("X");
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("X");
        printf("\n");
    }
      printf("A largura da linha central é %d \n", 2*n - 1);

    return 0;
}