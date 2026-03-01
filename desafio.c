#include <stdio.h>

int main() {
    // Definição do Tabuleiro 10x10 inicializado com 0 (Água) 
    int tabuleiro[10][10] = {0};

    // --- POSICIONAMENTO DE NAVIOS ---

    // Navio Horizontal (Linha 2, Colunas 3 a 5) 
    for (int j = 3; j < 6; j++) {
        tabuleiro[2][j] = 3; 
    }

    // Navio Vertical (Coluna 1, Linhas 4 a 6)
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][1] = 3;
    }

    // Navio Diagonal 1 (Ex: tabuleiro[i][i])
    for (int i = 7; i < 10; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio Diagonal 2 (Ex: Linha cresce, coluna decresce)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][2 - i] = 3;
    }

    // --- HABILIDADES ESPECIAIS ---
    // As áreas de efeito usam o valor 5 

    // Habilidade em Cone 
    // Origem: (4, 5) - Formato de triângulo expandindo para baixo
    int origLinhaCone = 4, origColunaCone = 5;
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = -i; j <= i; j++) { // Expansão lateral
            int nl = origLinhaCone + i;
            int nc = origColunaCone + j;
            if (nl >= 0 && nl < 10 && nc >= 0 && nc < 10) {
                tabuleiro[nl][nc] = 5;
            }
        }
    }

    // Habilidade em Cruz
    // Origem: (1, 7)
    int origLinhaCruz = 1, origColunaCruz = 7;
    for (int k = -2; k <= 2; k++) {
        // Horizontal
        if (origColunaCruz + k >= 0 && origColunaCruz + k < 10)
            tabuleiro[origLinhaCruz][origColunaCruz + k] = 5;
        // Vertical
        if (origLinhaCruz + k >= 0 && origLinhaCruz + k < 10)
            tabuleiro[origLinhaCruz + k][origColunaCruz] = 5;
    }

    // Habilidade em Octaedro (Losango)
    // Origem: (7, 2)
    int origLinhaOct = 7, origColunaOct = 2;
    int raio = 2;
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (abs(i) + abs(j) <= raio) { // Lógica de distância de Manhattan para losango
                int nl = origLinhaOct + i;
                int nc = origColunaOct + j;
                if (nl >= 0 && nl < 10 && nc >= 0 && nc < 10) {
                    tabuleiro[nl][nc] = 5;
                }
            }
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO --- 
    printf("TABULEIRO BATALHA NAVAL (0: Água, 3: Navio, 5: Habilidade)\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    return 0;
}