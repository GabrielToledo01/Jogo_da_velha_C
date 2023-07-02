#include "tabuleiro.h"
#include <stdio.h>


void escreverTabuleiro(char matriz[][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("| %c ", matriz[i][j]);
        }
        printf("|\n");
        if (i < TAM - 1) {
            printf("- - - - - - -\n");
        }
    }
    printf("\n");
}
// jogador informa a posição utilizando números de 1 a TAM( pra ficar certinho na hora de pedir a linha e coluna ao jogador))
void preencherTabuleiro(char matriz[][TAM], int linha, int coluna, char jogador) {
    matriz[linha -1][coluna -1] = jogador;
}

int verificarVitoria(char matriz[][TAM], char jogador) {
    // Verificar linhas
    for (int i = 0; i < TAM; i++) {
        if (matriz[i][0] == jogador && matriz[i][1] == jogador && matriz[i][2] == jogador) {
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < TAM; j++) {
        if (matriz[0][j] == jogador && matriz[1][j] == jogador && matriz[2][j] == jogador) {
            return 1;
        }
    }

    // Verificar diagonais
    if (matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador) {
        return 1;
    }
    if (matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador) {
        return 1;
    }

    return 0;
}

int verificarEmpate(char matriz[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int jogarNovamente() {
    char escolha;
    printf("Deseja jogar novamente? (S/N): ");
    scanf(" %c", &escolha);

    return (escolha == 'S' || escolha == 's');
}
