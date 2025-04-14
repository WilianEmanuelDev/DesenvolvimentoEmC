#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
 
    //menu iterativo
    // Jogo de Jokempô (Pedra, Papel e Tesoura)
    int jogador1, jogador2, resultado, opcao = 0, opcao1=0, opcao2 = 0, pedra, papel, tesoura;
    // Pedra = 1, Papel = 2, Tesoura = 3
    while (opcao != 1) {
        //menu iterativo

        printf("Bem-vindo ao jogo de jokempo!\n");
        printf("*** Menu Principal ***\n");
        printf("Escolha uma opcao: \n");
        printf("1. Jogar\n");
        printf("2. Ver regras\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Você escolheu jogar!\n");
                printf("Escolha uma opcao:\n");
                printf("1. Pedra\n");
                printf("2. Papel\n");
                printf("3. Tesoura\n");
                printf("Digite sua escolha: ");
                scanf("%d", &jogador1);
                
                srand(time(0)); // Inicializa o gerador de números aleatórios
                jogador2 = rand() % 3 + 1; // Gera um número aleatório entre 1 e 3 para o jogador 2 (computador);
                printf("CPU escolheu: %d\n", jogador2);

                if (jogador1 == jogador2) {
                    resultado = 0; // Empate
                    printf(" Jogador 1: %d, Jogador2: %d, Empate!\n", jogador1, jogador2);
                } else if ((jogador1 == 1 && jogador2 == 3) || (jogador1 == 2 && jogador2 == 1) || (jogador1 == 3 && jogador2 == 2)) {
                    resultado = 1; // Jogador 1 ganha
                    printf(" Jogador 1: %d, Jogador2: %d, Jogador 1 ganhou!\n", jogador1, jogador2);
                } else {
                    resultado = -1; // CPU ganha
                    printf(" Jogador 1: %d, Jogador2: %d, CPU ganhou!\n", jogador1, jogador2);
                }
                // Verifica se o jogador deseja jogar novamente
                printf("Deseja jogar novamente? (1 - Sim, 0 - Não): ");
                scanf("%d", &opcao2);
                if (opcao2 == 0) {
                    printf("Saindo do jogo...\n");
                    return 0;
                } else if (opcao2 == 1){
                    printf("Retornando ao menu principal...\n");
                    opcao = 0; // joga novamente
                } else if (opcao2 != 0 && opcao2 != 1) {
                    printf("Opcao invalida! Tente novamente.\n");
                    opcao = 0; // Retorna ao menu principal
                }
                break;
            case 2:
                printf("As regras do jogo são simples: Pedra vence Tesoura, Tesoura vence Papel e Papel vence Pedra.\n");
                printf("Escolha uma opcao:\n");
                printf("1. Retornar ao menu principal\n");
                printf("2. Sair\n");
                scanf("%d", &opcao1);
                // Verifica a opção escolhida pelo jogador
                    switch (opcao1)
                    {
                    case 1:
                        printf("Retornando ao menu principal...(Digite 1 para confirmar)\n");
                        scanf("%d", &opcao1);
                        opcao = 0;
                        break;
                    case 2:
                        printf("Saindo do jogo...\n");
                        return 0;
                    default:
                        printf("Opcao invalida! Tente novamente.\n");
                        break;
                }
                break;

            case 3:
                printf("Saindo do jogo...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                printf("Escolha uma opção valida: \n");
                scanf("%d", &opcao);
        }
    }
    return 0;
}