/* transição do cálculo manual para a lógica recursiva no balanceamento de Árvores Binárias de Busca, 
   implementar funções em C que calculem a altura dos nós e o Fator de Balanceamento */

#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esq;
    struct No *dir;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcularAltura(struct No* n) {
    if (n == NULL) {
        return -1;
    }
    return 1 + max(calcularAltura(n->esq), calcularAltura(n->dir));
}

int obterFB(struct No* n) {
    if (n == NULL) return 0;
    return calcularAltura(n->esq) - calcularAltura(n->dir);
}

struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

int main() {
    struct No* raiz = novoNo(20);
    raiz->esq = novoNo(10);
    raiz->esq->esq = novoNo(5);
    raiz->esq->esq->esq = novoNo(2);

    int fb = obterFB(raiz);

    printf("Altura da Raiz: %d\n", calcularAltura(raiz));
    printf("Fator de Balanceamento da Raiz: %d\n", fb);

    if (fb > 1 || fb < -1) {
        printf("desbalanceado \n");
    } else {
        printf("balanceado \n");
    }

    return 0;
}
