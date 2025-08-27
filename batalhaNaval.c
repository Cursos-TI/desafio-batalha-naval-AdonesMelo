#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10] = {0};

    // Posiciona o número 3 na linha 3 (índice 2) nas colunas D, E, F (índices 3, 4, 5)
    // Posição horizontal
    for (int i = 3; i <= 5; i++)
        tabuleiro[2][i] = 3;

    // Posiciona o número 3 na coluna H (índice 7) nas linhas 6, 7, 8 (índices 5, 6, 7)
    // Pocição vertical
    for (int j = 5; j <= 7; j++)
        tabuleiro[j][7] = 3;

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

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
