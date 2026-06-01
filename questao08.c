#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//questão 8
#define PI 3.14159265358979323846
#define MAX_POINTS 2000
typedef struct {
    double x, y;
} Point;

Point pontos[MAX_POINTS];
int num_pontos = 0;

void registrar_ponto(double x, double y) {
    if (num_pontos < MAX_POINTS) {
        pontos[num_pontos].x = x;
        pontos[num_pontos].y = y;
        num_pontos++;
    }
}

void gerar_koch(double x1, double y1, double x2, double y2, int nivel) {
    if (nivel == 0) {
        registrar_ponto(x2, y2);
        return;
    }
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    double p1x = x1 + dx / 3.0;
    double p1y = y1 + dy / 3.0;
    double p3x = x1 + 2.0 * dx / 3.0;
    double p3y = y1 + 2.0 * dy / 3.0;
    double angulo = PI / 3.0; 
    double vx = p3x - p1x;
    double vy = p3y - p1y;
    double p2x = p1x + vx * cos(angulo) - vy * sin(angulo);
    double p2y = p1y + vx * sin(angulo) + vy * cos(angulo);
    
    gerar_koch(x1, y1, p1x, p1y, nivel - 1);
    gerar_koch(p1x, p1y, p2x, p2y, nivel - 1);
    gerar_koch(p2x, p2y, p3x, p3y, nivel - 1);
    gerar_koch(p3x, p3y, x2, y2, nivel - 1);
}

int main() {
    int N;
    do {
        printf("Digite o nivel N do floco de neve de Koch (1 a 3): ");
        if (scanf("%d", &N) != 1) {
            while (getchar() != '\n'); 
            N = 0;
        }
        if (N < 1 || N > 3) {
            printf(" O nivel deve ser obrigatoriamente entre 1 e 3.\n\n");
        }
    } while (N < 1 || N > 3);
    double lado = 54.0; 
    double altura_tri = lado * sqrt(3.0) / 2.0;
    double v1x = -lado / 2.0, v1y = -altura_tri / 3.0; 
    double v2x = 0.0,         v2y = 2.0 * altura_tri / 3.0; 
    double v3x = lado / 2.0,  v3y = -altura_tri / 3.0; 
    
    num_pontos = 0;
    registrar_ponto(v1x, v1y); 
    
    gerar_koch(v1x, v1y, v2x, v2y, N);
    gerar_koch(v2x, v2y, v3x, v3y, N);
    gerar_koch(v3x, v3y, v1x, v1y, N);
    
    double min_x = pontos[0].x * 2.0, max_x = pontos[0].x * 2.0;
    double min_y = pontos[0].y, max_y = pontos[0].y;

    for (int i = 0; i < num_pontos; i++) {
        pontos[i].x *= 2.0; 
        if (pontos[i].x < min_x) min_x = pontos[i].x;
        if (pontos[i].x > max_x) max_x = pontos[i].x;
        if (pontos[i].y < min_y) min_y = pontos[i].y;
        if (pontos[i].y > max_y) max_y = pontos[i].y;
    }
    
    int offset_x = floor(min_x) - 2;
    int offset_y = floor(min_y) - 2;
    int largura = ceil(max_x) - offset_x + 4;
    int altura = ceil(max_y) - offset_y + 4;
    
    char **grade = (char **)malloc(altura * sizeof(char *));
    for (int i = 0; i < altura; i++) {
        grade[i] = (char *)malloc((largura + 1) * sizeof(char));
        for (int j = 0; j < largura; j++) grade[i][j] = ' ';
        grade[i][largura] = '\0';
    }
    
    for (int i = 0; i < num_pontos - 1; i++) {
        int x0 = round(pontos[i].x) - offset_x;
        int y0 = round(pontos[i].y) - offset_y;
        int x1 = round(pontos[i+1].x) - offset_x;
        int y1 = round(pontos[i+1].y) - offset_y;
        
        y0 = altura - 1 - y0;
        y1 = altura - 1 - y1;
        
        int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
        int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
        int err = dx + dy, e2;
     
        for(;;) {
            if (x0 >= 0 && x0 < largura && y0 >= 0 && y0 < altura) {
                grade[y0][x0] = '*';
            }
            if (x0 == x1 && y0 == y1) break;
            e2 = 2 * err;
            if (e2 >= dy) { err += dy; x0 += sx; }
            if (e2 <= dx) { err += dx; y0 += sy; }
        }
    }
    
    printf("\n--- Floco de Neve de Koch (Nivel %d) ---\n\n", N);
    for (int i = 0; i < altura; i++) {
        printf("%s\n", grade[i]);
        free(grade[i]);
    }
    free(grade);
    
    return 0;
}
//tive que usar ia, n teve jeito