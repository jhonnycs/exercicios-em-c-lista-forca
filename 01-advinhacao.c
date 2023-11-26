#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TENTATIVAS_FACIL 20
#define TENTATIVAS_MEDIO 14
#define TENTATIVAS_DIFICIL 6

int main() {
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int chute;
    int acertou = 0;
    int tentativas;
    float pontos = 1000;

    int jogarNovamente = 1;
    srand(time(0));
    /*
        srand usa uma semente para aleatorizar o rand
        ao usar o time passando 0, temos os segundos que se passaram desde 
        uma data específica, deixando o valor muito próximo do aleatório
    */

    int valorMin;
    int valorMax;

    do {

        printf("\nDigite o valor mínimo que poderá ser chutado:\n> ");
        scanf("%d", &valorMin);
        printf("Digite o valor máximo que poderá ser chutado:\n> ");
        scanf("%d", &valorMax);

        while (valorMin >= valorMax) {
            printf("Você digitou um valor mínimo maior ou igual ao valor máximo\n");
            printf("Por favor, digite novamente o valor mínimo:\n> ");
            scanf("%d", &valorMin);
            printf("\nDigite novamente o valor máximo:\n> ");
            scanf("%d", &valorMax);
        }

        int intervalo = valorMax - valorMin + 1;
        int numeroSecreto = (rand() % intervalo) + valorMin;
        
        printf("Escolha a dificuldade:\n\n");
        printf("(1) Fácil   (2) Médio   (3) Difícil\n\n> ");
        int dificuldade;
        
        scanf("%d", &dificuldade);
        printf("\n");
    
        while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3) {
            printf("Por favor, digite uma dificuldade válida: ");
            scanf("%d", &dificuldade);
        }

        switch(dificuldade) {
            case 1:
                tentativas = TENTATIVAS_FACIL;
                break;
            case 2:
                tentativas = TENTATIVAS_MEDIO;
                break;
            case 3:
                tentativas = TENTATIVAS_DIFICIL;
                break;
        }

        int ultimoChute;
        do {
            printf("Você tem %d tentativas\n", tentativas);
            printf("\nChute um número:\n> ");
            scanf("%d", &chute);
            
            if (ultimoChute == chute) {
                tentativas++;
                printf("\nVocê já chutou esse número. Chute outro\n\n");
                continue;
            }
            ultimoChute = chute;
            
            if (chute < valorMin || chute > valorMax) {
                printf("Por favor, não chute um número fora da faixa de valores escolhida por você\n");
                tentativas++;
                continue;
            }
    
            acertou = numeroSecreto == chute;
    
            if (!acertou) {
                float pontosPerdidos = abs(numeroSecreto - chute) / (float)2;

                if (chute < numeroSecreto) {
                    printf("seu chute foi menor que o número secreto\n");
                } else {
                    printf("seu chute foi maior que o número secreto\n");
                }
                pontos = pontos - pontosPerdidos;
            }
        } while (tentativas > 0 && !acertou);
        printf("\n");
        if (acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\nParabéns! Você acertou!\n");
            printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
        } else {
            printf("       \\|/ ____ \\|/    \n");   
            printf("        @~/ ,. \\~@      \n");   
            printf("       /_( \\__/ )_\\    \n");   
            printf("          \\__U_/        \n");
     
            printf("\nVocê perdeu! Tente novamente!\n\n");
        }
        printf("Deseja jogar novamente?\n");
        printf("(0) não jogar   (1) jogar\n\n> ");
        scanf("%d", &jogarNovamente);
        while (jogarNovamente != 0 && jogarNovamente != 1) {
            printf("Digite um valor válido\n");
            printf("(0) não jogar   (1) jogar\n\n> ");
            scanf("%d", &jogarNovamente);
        }
    } while(jogarNovamente);
    return 0;
}