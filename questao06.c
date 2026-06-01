#include <stdio.h>
//questão 6
int main() {
    int B, L, A;

    do {
        printf("Digite o tamanho desejado para a base ( deve ser impar e maior ou igual a 3): ");
        scanf("%d", &B);
        if (B < 3 || B % 2 == 0) {
            printf(" O valor de B deve ser impar e maior ou igual a 3.\n\n");
        }
    } while (B < 3 || B % 2 == 0);

    do {
        printf("Digite o tamanho desejado para a largura do tronco (deve ser impar maior ou igual a 1 e não ultrapassar B/2): ");
        scanf("%d", &L);
        if (L < 1 || L % 2 == 0 || L > B / 2) {
            printf(" O valor de L deve ser impar, no minimo 1, e não ultrapassar metade de B (%d).\n\n", B / 2);
        }
    } while (L < 1 || L % 2 == 0 || L > B / 2);

    do {
        printf("Digite o tamanho desejado para a altura do tronco (>= 2 e <= B/2): ");
        scanf("%d", &A);
        if (A < 2 || A > B / 2) {
            printf(" O valor de A deve ser no minimo 2 e não ultrapassar metade de B (%d).\n\n", B / 2);
        }
    } while (A < 2 || A > B / 2);

    printf("\n"); 

    int lc = (B / 2) + 1;
    for (int i = 0; i < lc; i++) {
        for (int espc = 0; espc < (B / 2) - i; espc++) {
            printf(" ");
        }
        for (int ast = 0; ast < (2 * i + 1); ast++) {
            printf("*");
        }
        printf("\n"); 
    }

    int esptr = (B / 2) - (L / 2);
    for (int i = 0; i < A; i++) {
        for (int espc = 0; espc < esptr; espc++) {
            printf(" ");
        }
        for (int ast = 0; ast < L; ast++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
