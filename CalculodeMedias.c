#include <stdio.h>


int main() {
    
    char nome[50];
    int idade;
    int matricula;
    char curso[50];
    float nota1, nota2, nota3, nota4, media;

    
    printf("Digite o nome do aluno: \n");
    scanf("%s", nome);
    printf("Digite a idade do aluno: \n");
    scanf("%d", &idade);
    printf("Digite a matricula do aluno: \n");
    scanf("%d", &matricula);
    printf("Digite o curso do aluno: \n");
    scanf("%s", curso);
    printf("Digite as notas do aluno (Nota 1, Nota 2, Nota 3 e Nota 4) \n");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    media = (nota1 + nota2 + nota3 + nota4) / 4;
    printf("O aluno %s \n Matricula %d \n tem %d, anos \n Esta cursando: %s \n Teve media de: %.2f\n",
     nome, matricula, idade, curso, media);
    
    return 0;
}