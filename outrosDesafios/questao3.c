#include <stdio.h>

/*
    Dado um número n e uma sequência de n inteiros,
    determinar a soma dos números pares da sequência.
*/

void receberValor(int *num);
void preencherArray(int *array, int tamanho);
int somarPares(int *array, int tamanho);

int main() {
    int n;

    receberValor(&n);

    int sequencia[n];

    preencherArray(sequencia, n);

    int soma = somarPares(sequencia, n);

    printf("A soma dos pares da sequência digitada é: %d", soma);

    return 0;
}

void receberValor(int *num) {
    printf("Digite a quantidade de números da sequência:\n> ");
    scanf("%d", num);

    while (*num < 1) {
        printf("Por favor, digite uma quantidade válida:\n> ");
        scanf("%d", num);
    }
}

void preencherArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }
}

int somarPares(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (array[i] % 2 == 0) {
            soma += array[i];
        }
    }

    return soma;
}