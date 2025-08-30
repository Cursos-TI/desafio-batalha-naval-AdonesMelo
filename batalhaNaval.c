#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA_H 3 // Posição do navio na horizontal
#define INICIAL_NAVIO_H 3 // Posisão da coluna inicial do navio na horizontal

#define COLUNA_V 8    // Posição do navio na vertical
#define INICIAL_NAVIO_V 5 // Posisão  da coluna inicial do navio na vertical

#define TAM_NAVIO_D 3 // Tamanho do navio na diagonal

#define VALOR_NAVIO 3 // Valor que representa o navio na matriz

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int tabuleiro[10][10] = {0};
    int tamanho_navio_h = INICIAL_NAVIO_H + 2;
    int tamanho_navio_v = INICIAL_NAVIO_V + 2;

    // Valores posição do navio na diagonal esquerda para direita de cima para baixo
    int linha_inicio_diagonal_ed = 4; // índice 4 = linha 3, "ed" = esquerda para direita
    int coluna_inicio_diagonal_ed = 4; // índice 4 = coluna D, "ed" = esquerda para direita

    // Valores posição do navio na diagonal direita para esquerda de cima para baixo
    int linha_inicial_diagonal_de = 7; // índice 7 = linha 8, "de" = direita para esquerda
    int coluna_inicial_diagonal_de = 2; // índice 2 = coluna C, "de" = direita para esquerda

    // Posiciona o número 3 na linha 3 (índice 2) nas colunas D, E, F (índices 3, 4, 5)
    // Posição horizontal
    for (int i = INICIAL_NAVIO_H; i <= tamanho_navio_h; i++)
        tabuleiro[LINHA_H - 1][i] = VALOR_NAVIO;

    // Posiciona o número 3 na coluna H (índice 7) nas linhas 6, 7, 8 (índices 5, 6, 7)
    // Pocição vertical
    for (int j = INICIAL_NAVIO_V; j <= tamanho_navio_v; j++)
        tabuleiro[j][COLUNA_V - 1] = VALOR_NAVIO;

    // Diagonal esquerda -> direita de cima para baixo
    for (int i = 0; i < TAM_NAVIO_D; i++){
        tabuleiro[linha_inicio_diagonal_ed + i][coluna_inicio_diagonal_ed + i] = VALOR_NAVIO;
    }

    // Diagonal direita -> esquerda de cima para baixo
    for (int j = 0; j < TAM_NAVIO_D; j++){
        tabuleiro[linha_inicial_diagonal_de + j][coluna_inicial_diagonal_de - j] = VALOR_NAVIO;  
    }
    
    printf("##### Jogo de Batalha Naval #####\n");
    printf("\n");

    // Imprime cabeçalho com letras
    printf("   "); // Espaço para alinhar com os números da coluna
    for (int i = 0; i < 10; i++){
        printf(" %c ", 'A' + i);
    }

    printf("\n");

    // imprime cada linha com número e os valores da matriz
    for (int j = 0; j < 10; j++) {
        printf("%2d ", 1 + j); // Imprime número da linha
        for (int i = 0; i < 10; i++) {
            printf(" %d ",tabuleiro[j][i] == 0 ? 0 : tabuleiro[j][i]); // Operador ternário
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

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
