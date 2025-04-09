#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Inicializando a matriz do tabuleiro em 0 representando a água.
    int tabuleiro [10] [10] = {0};
    
        //Vetor com a posição do navio na horizontal (colunas 0,1,2)
        int navioHorizontal[3] = {0,1,2};

        //Vetor com a posição do navio na vertical (linhas 0,1,2)
        int navioVertical[3] = {0,1,2};
        
        //declarando a posição do navio 1
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[5][navioHorizontal[i]] = 3; //O número 2 representa a linha que vai aparecer o 3 representa aparte do navio.
        }

        //declarando o navio 2
        for (int i = 0; i < 3; i++)
        {
            //Verifica se o espaço esta vazio para evitar sobreposição
            if (tabuleiro[navioVertical[i]][5] == 0)
            {
                tabuleiro[navioVertical[i]][5] = 3;//A ordem invertida indica que esta na vertical, 5 é a linha, 3 representa parte do navio
            }
            
        }
        
        


    //Representando o tabuleiro no console usando um loop aninhado.

    printf("   ");
    for (int j = 0; j < 10; j++)
    {
        printf("%c ", colunas[j]);
    }
      printf("\n ");
    

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", linhas[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n ");//Nova linha ao final de cada linha.
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
