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

 /*
 %d: Imprime um inteiro no formato decimal.
 
%i: Equivalente a %d.
 
%f: Imprime um número de ponto flutuante no formato padrão.
 
%e: Imprime um número de ponto flutuante na notação científica.
 
%c: Imprime um único caractere.
 
%s: Imprime uma cadeia (string) de caracteres.

*/
    return 0;
}