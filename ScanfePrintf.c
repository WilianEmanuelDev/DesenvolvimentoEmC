#include <stdio.h>

int main() {

    int idade;
    float altura;
    char nome[50];

    // Exemplo de uso do scanf para ler dados do usuário
    printf("Digite Seu Nome: \n");
    scanf("%s", nome);
    printf("Digite Sua Idade: \n");
    scanf("%d", &idade);
    printf("Digite Sua Altura: \n");
    scanf("%f", &altura);
    printf("A Idade do %s é: %d\n", nome, idade);
    printf("A Altura do %s é: %.2f\n", nome, altura);

    return 0;
}
