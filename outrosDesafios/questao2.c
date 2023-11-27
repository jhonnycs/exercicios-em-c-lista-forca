#include <stdio.h>
#include <stdlib.h>

/*
    receber um número do usuário e escrever
    num arquivo a tabuada desse número de 1 a 20.
*/

void receberValor(int *num);
void escreverTabuada(int num);

int main() {
    int num;

    receberValor(&num);
    escreverTabuada(num);

    return 0;
}

void receberValor(int *num) {
    printf("Digite um número:\n> ");
    scanf("%d", num);
}

void escreverTabuada(int num) {
    FILE *f = fopen("tabuada.txt", "r+");

    if (!f) {
        printf("Arquivo de tabuada não encontrado.\n");
        exit(1);
    }

    for (int i = 1; i <= 20; i++) {
        fprintf(f, "%d x %d = %d\n", num, i, num*i);
    }

    printf("Tabuada escrita no arquivo.\n");
    fclose(f);
}