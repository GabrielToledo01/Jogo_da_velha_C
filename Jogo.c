#include <stdio.h>
#include "tabuleiro.h"

int main() {
    int jogar = 1; // Variável para controlar o loop principal do jogo

    while (jogar) {
        char tabuleiro[TAM][TAM] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

        escreverTabuleiro(tabuleiro);
// Pede para fazer a escolha entre X OU O para o jogar e verifica se foi inserido corretamente
       char jogador1, jogador2;
        while (1) {
            printf("Escolha quem joga primeiro (X ou O): ");
            scanf(" %c", &jogador1);
            if (jogador1 == 'X' || jogador1 == 'O') {
            break; // Sai do loop se um valor válido for fornecido
            } else {
             printf("Opcao invalida. Escolha X ou O.\n");
         }
}

// Definir o símbolo do segundo jogador
jogador2 = (jogador1 == 'X') ? 'O' : 'X';

char jogadorAtual = jogador1;
int linha, coluna;


        while (1) {
            printf("Jogador %c, informe a posicao desejada (linha coluna): ", jogadorAtual);
            scanf("%d %d", &linha, &coluna);

            // Verificar se a posição é válida
            if (linha >= 1 && linha <= TAM && coluna >= 1 && coluna <= TAM) {
                // Verificar se a posição está vazia
                if (tabuleiro[linha - 1][coluna - 1] == ' ') {
                    preencherTabuleiro(tabuleiro, linha, coluna, jogadorAtual);
                    escreverTabuleiro(tabuleiro);

                    if (verificarVitoria(tabuleiro, jogadorAtual)) {
                        printf("Jogador %c venceu!\n", jogadorAtual);
                        break;
                    }

                    if (verificarEmpate(tabuleiro)) {
                        printf("O jogo terminou em empate!\n");
                        break;
                    }

                    if (jogadorAtual == jogador1) {
                        jogadorAtual = jogador2;
                    } else {
                        jogadorAtual = jogador1;
                    }
                } else {
                    printf("Posicao ja preenchida. Tente novamente.\n");
                }
            } else {
                printf("Posicao invalida. Tente novamente.\n");
            }
        }

        jogar = jogarNovamente();
    }

    return 0;
}
