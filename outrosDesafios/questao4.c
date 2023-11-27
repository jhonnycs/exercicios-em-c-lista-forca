#include <stdio.h>

/*
    Dizer se um número é primo ou não.
*/

void receberValor(int *num);
void verificarPrimo(int num);

int main() {
    int num;
    
    receberValor(&num);

    verificarPrimo(num);

    return 0;
}

void receberValor(int *num) {
    printf("Digite um inteiro:\n> ");
    scanf("%d", num);

    while (*num < 1) {
        printf("Por favor, digite um inteiro maior que 0:\n> ");
        scanf("%d", num);
    }
}

void verificarPrimo(int num) {
    int isPrime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    if (num == 1) isPrime = 0;

    printf("O número %d %s", num, isPrime ? "é primo" : "não é primo");
}