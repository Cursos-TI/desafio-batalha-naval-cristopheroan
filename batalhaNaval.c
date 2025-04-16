#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

 //função das habilidades
 void aplicarHabilidade(int tabuleiro[10][10], int habilidade[3][3], int linhaAlvo, int colunaAlvo, int tamanhoHabilidade) {
    for (int i = 0; i < tamanhoHabilidade; i++) 
    {
        for (int j = 0; j < tamanhoHabilidade; j++)
        {
            if (habilidade[i][j] == 1){
                int linhaTabuleiro = linhaAlvo - (tamanhoHabilidade / 2) + i;
                int colunaTabuleiro = colunaAlvo - (tamanhoHabilidade / 2) + j;

                //verifica se está dentro dos limites do tabuleiro
                if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && 
                    colunaTabuleiro >= 0 && colunaTabuleiro < 10){
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 1;
                }
            }
        }
        
    }
    
};

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
        //O numero 3 representa o tamanho do navio
        int navioHorizontal[3] = {0,1,2};
        
        //Adicionando um terceiro navio
        int navioHorizontal2[3] = {4,5,6};

        //Vetor com a posição do navio na vertical (linhas 0,1,2)
        int navioVertical[3] = {0,1,2};

        int navioVertical2[3] = {3,4,5};
        
        //vetor navios na diagonal
        int navioDiagonal[3][2] = {{0,0}, {1,1}, {2,2}};

        int navioDiagonal2[3][2] = {{7,3}, {8,4}, {9,5}};
        
        //declarando a posição do navio 1
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[5][navioHorizontal[i]] = 3; //O número 5 representa a linha que vai aparecer, o 3 representa a parte do navio.
        }

        for (int j = 0; j < 3; j++)
        {
            tabuleiro[7][navioHorizontal2[j]] = 3;
        }

        //declarando o navio 2
        for (int i = 0; i < 3; i++)
        {
            //Verifica se o espaço esta vazio para evitar sobreposição
            if (tabuleiro[navioVertical[i]][5] == 0)
            {
                tabuleiro[navioVertical[i]][5] = 3;//A ordem invertida indica que esta na vertical, 5 é a coluna, 3 representa parte do navio
            }
            
        }

        // Posicionando o segundo navio
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[navioVertical2[j]][6] == 0)
            {
                tabuleiro[navioVertical2[j]][6] = 3;
            }
        }

        // Posicionando o primeiro navio diagonal
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[navioDiagonal[i][0]][navioDiagonal[i][1]] == 0) {
                tabuleiro[navioDiagonal[i][0]][navioDiagonal[i][1]] = 3;
            }
        }

        // Posicionando o segundo navio diagonal
        for (int i = 0; i < 3; i++) {
             if (tabuleiro[navioDiagonal2[i][0]][navioDiagonal2[i][1]] == 0) {
                 tabuleiro[navioDiagonal2[i][0]][navioDiagonal2[i][1]] = 3;
            }
        }

       
       //Adicionando as habilidades  
        int cone[3][3] = {
            {0,0,1},//formato da habilidade
            {0,1,1},
            {1,1,1}
        };

        int cruz[3][3] = {
            {0,1,0},
            {1,1,1},
            {0,1,0}
        };

        int octaedro[3][3] = {
            {0,0,1},
            {1,1,1},
            {0,0,1}
        };

        int tamanhoHabilidade = 3;
    int linhaAplicacao = 4; // Centro aproximado da linha (índice)
    int colunaAplicacao = 4; // Centro aproximado da coluna (índice)

    // Aplicando as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, linhaAplicacao, colunaAplicacao, tamanhoHabilidade);
    aplicarHabilidade(tabuleiro, cruz, linhaAplicacao + 2, colunaAplicacao + 2, tamanhoHabilidade); // Aplicando em outra posição pra diferenciar
    aplicarHabilidade(tabuleiro, octaedro, linhaAplicacao - 2, colunaAplicacao - 2, tamanhoHabilidade); // Aplicando em outra posição pra diferenciar



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

    return 0;
}
