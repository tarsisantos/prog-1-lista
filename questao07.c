#include <stdio.h>
//questão 7
int main() {
    int N;
    do {
        printf("Digite o valor do tamanho da matriz (deve ser maior ou igual a 3): ");
        if (scanf("%d", &N) != 1) {
            while (getchar() != '\n'); 
            N = 0; 
        }
        if (N < 3) {
            printf("O valor inserido é inválido. a matriz deve ser obrigatoriamente maior ou igual a 3.\n\n");
        }
    } while (N < 3);

    int matriz[N][N];
    int valor = 1;
    int max_valor = N * N;
    
    int topo = 0, base = N - 1;
    int esquerda = 0, direita = N - 1;

    while (valor <= max_valor) {
        for (int i = esquerda; i <= direita; i++) {
            matriz[topo][i] = valor++;
        }
        topo++; 
        for (int i = topo; i <= base; i++) {
            matriz[i][direita] = valor++;
        }
        direita--; 
        if (topo <= base) {
            for (int i = direita; i >= esquerda; i--) {
                matriz[base][i] = valor++;
            }
            base--; 
        }

        if (esquerda <= direita) {
            for (int i = base; i >= topo; i--) {
                matriz[i][esquerda] = valor++;
            }
            esquerda++; 
        }
    }
    int largura = 0,temp = max_valor;
    while (temp > 0) {
        largura++;
        temp /= 10;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%*d ", largura, matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}