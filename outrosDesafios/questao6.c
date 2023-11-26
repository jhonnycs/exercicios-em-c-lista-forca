#include <stdio.h>

// somar todos os elementos de um array de inteiros

void receberTamanho(int *t);
void preencherArray(int *array, int tamanho);
int somarArray(int *array, int tamanho);

int main() {
    int tamanho;
    receberTamanho(&tamanho);

    int array[tamanho];
    preencherArray(array, tamanho);

    int somaArray = somarArray(array, tamanho);

    printf("A soma do array digitado é %d", somaArray);

    return 0;
}

void receberTamanho(int *t) {
    printf("Digite o tamanho do array:\n> ");
    scanf("%d", t);

    while (*t < 1) {
        printf("Por favor, digite um tamanho válido:\n> ");
        scanf("%d", t);
    }
}

void preencherArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento número %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }
}

int somarArray(int *array, int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    
    return soma;
}