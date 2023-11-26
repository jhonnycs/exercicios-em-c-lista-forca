#include <stdio.h>
#include <math.h>

/*
    fazer uma função que receba dois inteiros a e b,
    e calcule a^b
*/

void receberInteiros(int *a, int *b);
int calcPot(int a, int b);

int main() {
    int a, b;

    receberInteiros(&a, &b);
    int res = calcPot(a, b);
    printf("%d^%d = %d", a, b, res);

    return 0;
}

void receberInteiros(int *a, int *b) {
    printf("Digite o inteiro a:\n> ");
    scanf("%d", a);
    printf("Digite o inteiro b:\n> ");
    scanf("%d", b);
}

int calcPot(int a, int b) {
    return pow(a, b);
}