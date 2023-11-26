#include <stdio.h>

/*
    Receber 2 números e calcular a soma dos
    números que são primos no intervalo.
*/

void receberNumeros(int *a, int *b);
int somarPrimosIntervalo(int num1, int num2);
int verificarPrimo(int num);

int main() {
    int num1, num2;

    receberNumeros(&num1, &num2);

    int somaPrimos = somarPrimosIntervalo(num1, num2);

    printf("A soma de todos os primos de %d a ", num1);
    printf("%d é %d ", num2, somaPrimos);

    return 0;
}

void receberNumeros(int *a, int *b) {
    printf("Digite primeiro número:\n> ");
    scanf("%d", a);

    while (*a < 1) {
        printf("Por favor, digite um inteiro positivo:\n> ");
        scanf("%d", a);
    }
    
    printf("Digite o segundo número:\n> ");
    scanf("%d", b);
    
    while (*b < 1 || *b < *a) {
        printf("Por favor, digite um inteiro positivo maior que o anterior:\n> ");
        scanf("%d", b);
    }
}

int somarPrimosIntervalo(int num1, int num2) {
    int soma = 0;
    for (int i = num1; i <= num2; i++) {
        if (verificarPrimo(i)) {
            soma += i;
        }
    }
    return soma;
}

int verificarPrimo(int num) {
    int isPrime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    if (num == 1) isPrime = 0;

    return isPrime;
}