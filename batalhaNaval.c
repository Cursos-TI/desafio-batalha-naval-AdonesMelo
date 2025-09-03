#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Constantes para representar elementos do tabuleiro
#define VALOR_NAVIO 3         // Valor que representa uma parte do navio
#define TAMANHO_TABULEIRO 10  // Tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3       // Tamanho padrão dos navios
#define ALTURA_CONE 3         // Altura do cone de ataque
#define LARGURA_CONE (ALTURA_CONE * 2 - 1) // Largura do cone (formato pirâmide)
#define VALOR_ATAQUE 1        // Valor que representa ataque na água
#define NAVIO_AFETADO 5       // Valor que representa navio atingido

// Aplica ataque em uma posição do tabuleiro
// Se atingir navio (3), marca como 5 e exibe mensagem
// Se atingir água (0), marca como 1 e exibe mensagem
void aplicar_ataque(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO)
        return;

    if (tabuleiro[linha][coluna] == VALOR_NAVIO) {
        tabuleiro[linha][coluna] = NAVIO_AFETADO;
        printf("Parte do navio atingida em %c%d!\n", 'A' + coluna, linha + 1);
    } else if (tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = VALOR_ATAQUE; // Marca ataque na água
        printf("O ataque foi na água na posição %c%d!\n", 'A' + coluna, linha + 1);
    }
}

// Aplica ataque em formato de octaedro (diamante)
// Raio define o alcance do ataque
void posicionar_octaedro(int matriz[][TAMANHO_TABULEIRO], int centro_linha, int centro_coluna, int raio) {
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (abs(i) + abs(j) <= raio) {
                int linha = centro_linha + i;
                int coluna = centro_coluna + j;
                aplicar_ataque(matriz, linha, coluna);
            }
        }
    }
}

// Aplica ataque em formato de cruz (vertical e horizontal)
// Braço define o alcance em cada direção
void posicionar_cruz(int tabuleiro[][TAMANHO_TABULEIRO], int linha_centro, int coluna_centro, int tamanho_braço) {
    // Vertical
    for (int i = -tamanho_braço; i <= tamanho_braço; i++) {
        aplicar_ataque(tabuleiro, linha_centro + i, coluna_centro);
    }

    // Horizontal
    for (int j = -tamanho_braço; j <= tamanho_braço; j++) {
        aplicar_ataque(tabuleiro, linha_centro, coluna_centro + j);
    }
}

// Cria um cone de ataque em uma matriz auxiliar
// O cone é uma pirâmide com base larga e topo estreito
void posicionar_cone(int tabuleiro[ALTURA_CONE][LARGURA_CONE], int altura, int largura) {
    int centro = largura / 2;
    for (int i = 0; i < altura; i++){
        int deslocamento = i;
        for (int j = centro - deslocamento; j <= centro + deslocamento; j++){
            tabuleiro[i][j] = VALOR_ATAQUE;
        }
    }
}

// Sobrepõe o cone no tabuleiro principal e aplica ataques
void sobrepor_cone_no_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int cone[][LARGURA_CONE], int linha_inicio, int coluna_inicio) {
    for (int i = 0; i < ALTURA_CONE; i++) {
        for (int j = 0; j < LARGURA_CONE; j++) {
            if (cone[i][j] == 1) {
                aplicar_ataque(tabuleiro, linha_inicio + i, coluna_inicio + j);
            }
        }
    }
}

// Posiciona navio horizontalmente
void posicionar_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna_inicial, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha][coluna_inicial + i] = VALOR_NAVIO;
    }
}

// Posiciona navio vertical
void posicionar_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha_inicial + i][coluna] = VALOR_NAVIO;
    }
}

// Posiciona navio na diagonal esquerda para direita de cima para baixo
void posicionar_diagonal_ed(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha_inicial + i][coluna_inicial + i] = VALOR_NAVIO;
    }
}

// Posiciona navio na diagonal direita para esquerda de cima para baixo
void posicionar_diagonal_de(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha_inicial + i][coluna_inicial - i] = VALOR_NAVIO;
    }
}

// Imprime o tabuleiro com valores numéricos
// Pode ser adaptado para mostrar símbolos visuais
void imprimir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %c ", 'A' + i);
    }

    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Função principal: posiciona navios e aplica ataques geométricos
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Tabuleiro principal
    int tabuleiro_cone[ALTURA_CONE][LARGURA_CONE] = {0};        // Matriz auxiliar para cone

    printf("##### Jogo de Batalha Naval #####\n\n");

    // Posicionamento dos navios
    posicionar_horizontal(tabuleiro, 4, 3, TAMANHO_NAVIO); // linha 5, colunas D–F
    posicionar_vertical(tabuleiro, 5, 7, TAMANHO_NAVIO);   // coluna H, linhas 6–8
    posicionar_diagonal_ed(tabuleiro, 6, 3, TAMANHO_NAVIO); // diagonal esquerda-direita
    posicionar_diagonal_de(tabuleiro, 0, 9, TAMANHO_NAVIO); // diagonal direita-esquerda

    // Aplicação dos ataques
    posicionar_cone(tabuleiro_cone, ALTURA_CONE, LARGURA_CONE);
    sobrepor_cone_no_tabuleiro(tabuleiro, tabuleiro_cone, 0, 2); // // Aplica o cone de ataque no tabuleiro a partir da linha 0, coluna 2

    posicionar_cruz(tabuleiro, 5, 2, 2); // Ataque em cruz centrado na linha 5, coluna 2, com alcance 2
    posicionar_octaedro(tabuleiro, 8, 8, 1); // Octaedro centrado na linha 9, coluna I com raio 1

    // Exibição do tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
