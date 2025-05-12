#include <stdio.h>

// Definindo constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10  // Tamanho fixo do tabuleiro: 10x10
#define TAMANHO_NAVIO 3       // Cada navio ocupa 3 posições
#define NAVIO 3               // Valor usado para marcar partes de navio no tabuleiro
#define AGUA 0                // Valor usado para representar água no tabuleiro

// Função para inicializar todo o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se é possível posicionar um navio horizontalmente
int podeColocarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio ultrapassaria os limites do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    // Verifica se as posições já estão ocupadas (não pode haver sobreposição)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA)
            return 0;
    }

    return 1; // Pode posicionar
}

// Verifica se é possível posicionar um navio verticalmente
int podeColocarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA)
            return 0;
    }

    return 1;
}

// Posiciona um navio horizontalmente no tabuleiro
void colocarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Posiciona um navio verticalmente no tabuleiro
void colocarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Cabeçalho com os números das colunas
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro com os valores (0 para água, 3 para navio)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal do programa
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Declara a matriz do tabuleiro

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas iniciais dos navios (posição fixa no código)
    int linhaH = 2, colunaH = 4; // Navio horizontal começa na linha 2, coluna 4
    int linhaV = 5, colunaV = 1; // Navio vertical começa na linha 5, coluna 1

    // Verifica se é possível posicionar o navio horizontal e posiciona se possível
    if (podeColocarHorizontal(tabuleiro, linhaH, colunaH)) {
        colocarNavioHorizontal(tabuleiro, linhaH, colunaH);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica se é possível posicionar o navio vertical e posiciona se possível
    if (podeColocarVertical(tabuleiro, linhaV, colunaV)) {
        colocarNavioVertical(tabuleiro, linhaV, colunaV);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Mostra o tabuleiro completo no console
    printf("\nTabuleiro Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

