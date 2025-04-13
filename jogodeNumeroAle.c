#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Jogo de Adivinhação de Números
// O jogador deve adivinhar um número entre 1 e 10. O programa informa se o palpite é muito baixo, muito alto ou correto.
int main() {
//menu iterativo
    int opcao;
    int numero, tentativas = 0, max_tentativas = 5, numero_aleatorio, jogar;



while (opcao != 1)
{
    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("Menu Principal:\n");
    printf("1. Jogar\n");
    printf("2. Ver regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

switch (opcao) {
    case 1:
        printf("Você escolheu jogar!\n");

            // Gerar um número aleatório entre 1 e 10
        srand(time(0)); // Inicializa o gerador de números aleatórios
        numero_aleatorio = rand() % 10 + 1; // Gera um número entre 1 e 10
    
        printf("Tente adivinhar o número entre 1 e 10. Você tem %d tentativas.\n", max_tentativas);
    
        while (tentativas < max_tentativas)
        {
            printf("Digite seu palpite: ");
            scanf("%d", &numero);
        
            tentativas++;
            
            if (numero < numero_aleatorio) {
                printf("Muito baixo! Tente novamente.\n");
            } else if (numero > numero_aleatorio) {
                printf("Muito alto! Tente novamente.\n");
            } else {
                printf("Parabéns! Você adivinhou o número em %d tentativas.\n", tentativas);
                break;
            }
        
        }
        // Se o jogador não adivinhou o número após as tentativas
            if (tentativas == max_tentativas) 
            {
                printf("Você esgotou suas tentativas. O número era %d.\n", numero_aleatorio);
            }
        break; 
    case 2:
        printf("As regras do jogo são simples: adivinhe um número entre 1 e 10, Você tem 5 tentativas.\n");
        break;
    
    case 3:
        printf("Saindo do jogo. Até mais!\n");
        return 0;
    default:
        printf("Opção inválida! Tente novamente.\n");  
        break;
    }
}  
    return 0;
}
