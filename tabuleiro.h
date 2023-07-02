
#define TAM 3

// Função para escrever o tabuleiro na tela
void escreverTabuleiro(char matriz[][TAM]);

// Função para preencher uma posição do tabuleiro com o símbolo do jogador atual
void preencherTabuleiro(char matriz[][TAM], int linha, int coluna, char jogador);

// Função para verificar se o jogador atual venceu o jogo
int verificarVitoria(char matriz[][TAM], char jogador);

// Função para verificar se o jogo terminou em empate
int verificarEmpate(char matriz[][TAM]);

// Função para perguntar ao jogador se deseja jogar novamente
int jogarNovamente();

