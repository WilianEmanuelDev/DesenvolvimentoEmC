#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define NUM_NAVIOS 4
#define MAX_TENTATIVAS 10

// Definindo o tabuleiro
int tabuleiro1[TAM_TABULEIRO][TAM_TABULEIRO];
int tabuleiro2[TAM_TABULEIRO][TAM_TABULEIRO];

// Definindo as habilidades (Cone, Cruz, Octa)
int habilidadeCone[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1}
};

int habilidadeCruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int habilidadeOcta[3][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

// Função para limpar o tabuleiro (colocando tudo como 0)
void limparTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". "); // Marca as células vazias
            else if (tabuleiro[i][j] == 3)
                printf("X "); // Marca os navios
            else if (tabuleiro[i][j] == 2)
                printf("O "); // Marca os ataques
        }
        printf("\n");
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(int habilidade[][5], int linha, int coluna, int centroX, int centroY, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    int centroHabilidadeX = linha / 2;
    int centroHabilidadeY = coluna / 2;

    // Verificando se a habilidade se encaixa dentro do tabuleiro
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int x = centroX - centroHabilidadeX + i;
            int y = centroY - centroHabilidadeY + j;
            if (habilidade[i][j] == 1) {
                if (x < 0 || x >= TAM_TABULEIRO || y < 0 || y >= TAM_TABULEIRO) {
                    printf("Erro: a habilidade ultrapassa os limites do tabuleiro.\n");
                    return;
                }
                if (tabuleiro[x][y] == 2) {
                    printf("Já atacou essa posição antes! Tente outra.\n");
                    return;
                }
                tabuleiro[x][y] = 2; // Marca o ataque no tabuleiro
            }
        }
    }
}

// Função para verificar se um jogador venceu
bool verificarVitoria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 3) { // Se encontrar um navio
                return false; // O jogador ainda tem navios
            }
        }
    }
    return true; // Todos os navios foram destruídos
}

// Função para posicionar navios
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int numNavio) {
    int linhaNavio, colunaNavio;
    char linhaChar;
    printf("Posicionando o navio %d...\n", numNavio);
    printf("Digite a linha e a coluna para posicionar o navio (ex: A1): ");
    scanf(" %c%d", &linhaChar, &colunaNavio);

    linhaNavio = linhaChar - 'A';
    if (linhaNavio < 0 || linhaNavio >= TAM_TABULEIRO || colunaNavio < 1 || colunaNavio > TAM_TABULEIRO) {
        printf("Posição inválida! Tente novamente.\n");
        return;
    }

    tabuleiro[linhaNavio][colunaNavio - 1] = 3; // Marca o navio na posição
}

// Função para exibir o status do jogo
void exibirStatus(int ataquesJogador1, int ataquesJogador2) {
    printf("\n--- Status do Jogo ---\n");
    printf("Jogador 1 fez %d ataques.\n", ataquesJogador1);
    printf("Jogador 2 fez %d ataques.\n", ataquesJogador2);
    printf("----------------------\n");
}

// Função principal para iniciar o jogo
int main() {
    int opcao, x, y;
    int ataquesJogador1 = 0, ataquesJogador2 = 0;
    bool vitoriaJogador1 = false, vitoriaJogador2 = false;

    // Limpar os tabuleiros antes de começar
    limparTabuleiro(tabuleiro1);
    limparTabuleiro(tabuleiro2);

    // Posicionamento dos navios para o jogador 1
    printf("Jogador 1, posicione seus navios:\n");
    for (int i = 0; i < NUM_NAVIOS; i++) {
        posicionarNavio(tabuleiro1, i + 1);
    }

    // Posicionamento dos navios para o jogador 2
    printf("\nJogador 2, posicione seus navios:\n");
    for (int i = 0; i < NUM_NAVIOS; i++) {
        posicionarNavio(tabuleiro2, i + 1);
    }

    // Início do jogo
    do {
        // Jogador 1 faz seu movimento
        printf("\nJogador 1, sua vez!\n");
        exibirStatus(ataquesJogador1, ataquesJogador2);
        printf("Escolha uma habilidade (1 - Cone, 2 - Cruz, 3 - Octa): ");
        scanf("%d", &opcao);
        printf("Digite a coordenada X (linha 0-9): ");
        scanf("%d", &x);
        printf("Digite a coordenada Y (coluna 0-9): ");
        scanf("%d", &y);

        switch (opcao) {
            case 1:
                aplicarHabilidade(habilidadeCone, 3, 5, x, y, tabuleiro2);
                break;
            case 2:
                aplicarHabilidade(habilidadeCruz, 5, 5, x, y, tabuleiro2);
                break;
            case 3:
                aplicarHabilidade(habilidadeOcta, 3, 5, x, y, tabuleiro2);
                break;
            default:
                printf("Opção inválida.\n");
        }
        ataquesJogador1++;

        // Verificar se o jogador 2 perdeu
        if (verificarVitoria(tabuleiro2)) {
            printf("Jogador 1 venceu!\n");
            vitoriaJogador1 = true;
            break;
        }

        // Jogador 2 faz seu movimento
        printf("\nJogador 2, sua vez!\n");
        exibirStatus(ataquesJogador1, ataquesJogador2);
        printf("Escolha uma habilidade (1 - Cone, 2 - Cruz, 3 - Octa): ");
        scanf("%d", &opcao);
        printf("Digite a coordenada X (linha 0-9): ");
        scanf("%d", &x);
        printf("Digite a coordenada Y (coluna 0-9): ");
        scanf("%d", &y);

        switch (opcao) {
            case 1:
                aplicarHabilidade(habilidadeCone, 3, 5, x, y, tabuleiro1);
                break;
            case 2:
                aplicarHabilidade(habilidadeCruz, 5, 5, x, y, tabuleiro1);
                break;
            case 3:
                aplicarHabilidade(habilidadeOcta, 3, 5, x, y, tabuleiro1);
                break;
            default:
                printf("Opção inválida.\n");
        }
        ataquesJogador2++;

        // Verificar se o jogador 1 perdeu
        if (verificarVitoria(tabuleiro1)) {
            printf("Jogador 2 venceu!\n");
            vitoriaJogador2 = true;
            break;
        }

    } while (!vitoriaJogador1 && !vitoriaJogador2);

    // Revelando os navios no final
    printf("\nTabuleiro do Jogador 1 (final):\n");
    imprimirTabuleiro(tabuleiro1);
    printf("\nTabuleiro do Jogador 2 (final):\n");
    imprimirTabuleiro(tabuleiro2);

    return 0;
}
