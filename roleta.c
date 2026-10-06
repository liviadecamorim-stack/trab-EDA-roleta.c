#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int numero;
    char cor[10];
    struct No* prox;
} No;

No* criarRoleta() {
    No* inicio = NULL;
    No* atual = NULL;

    for (int i = 0; i <= 20; i++) {
        No* novo = (No*) malloc(sizeof(No));
        novo->numero = i;

        if (i == 0) {
            sprintf(novo->cor, "Verde");
        } else if (i % 2 == 0) {
            sprintf(novo->cor, "Vermelho");
        } else {
            sprintf(novo->cor, "Preto");
        }

        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
    }

    atual->prox = inicio;
    return inicio;
}

No* girarRoleta(No* topo, int forcaImpulso) {
    No* aux = topo;
    for (int i = 0; i < forcaImpulso; i++) {
        aux = aux->prox; 
    }
    return aux;
}

int main() {
    srand(time(NULL));

    No* roleta = criarRoleta();

    printf("JOGO DA ROLETA\n");

    int apostaNumero;
    printf("Digite o numero em que deseja apostar (0 a 20): ");
    scanf("%d", &apostaNumero);

    int impulso = (rand() % 81) + 20;

    printf("\nGirando a roleta...\n");

    No* resultado = girarRoleta(roleta, impulso);

    printf("A bolinha parou na casa: %d (%s)\n", resultado->numero, resultado->cor);

    if (resultado->numero == apostaNumero) {
        printf("\nParabens! Voce acertou o numero e venceu!\n");
    } else {
        printf("\nQue pena, voce perdeu! Tente novamente.\n");
    }

    return 0;
}
