#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);
    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);
    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

int calcular_altura(No* no) {
    if (!no) return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    if (esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

void imprimir_nivel(No* raiz, int nivel) {
    if (raiz == NULL) return;
    if (nivel == 0)
        printf("%d ", raiz->valor);
    else {
        imprimir_nivel(raiz->esq, nivel - 1);
        imprimir_nivel(raiz->dir, nivel - 1);
    }
}

void imprimir_niveis(No* raiz) {
    int h = calcular_altura(raiz);
    for (int i = 0; i <= h; i++) {
        printf("Nivel %d: ", i);
        imprimir_nivel(raiz, i);
        printf("\n");
    }
}

int calcular_profundidade(No* raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->valor == valor) return prof;
    if (valor < raiz->valor)
        return calcular_profundidade(raiz->esq, valor, prof + 1);
    else
        return calcular_profundidade(raiz->dir, valor, prof + 1);
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL) return;
    if (raiz->valor == valor) return;

    if ((valor < raiz->valor && buscar(raiz->esq, valor)) ||
        (valor > raiz->valor && buscar(raiz->dir, valor))) {
        printf("%d ", raiz->valor);
        if (valor < raiz->valor)
            imprimir_ancestrais(raiz->esq, valor);
        else
            imprimir_ancestrais(raiz->dir, valor);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;
    if (no->esq) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }
    if (no->dir) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}


void analisar_arvore(No* raiz, int valorBusca) {
    printf("raiz: %d\n", raiz->valor);

    printf("nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    printf("folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    printf("niveis:\n");
    imprimir_niveis(raiz);

    No* alvo = buscar(raiz, valorBusca);
    if (alvo == NULL) {
        printf("não encontrado\n");
        return;
    }

    int grau = 0;
    if (alvo->esq) grau++;
    if (alvo->dir) grau++;

    printf("diagnostico do no, %d \n", valorBusca);
    printf("grau: %d\n", grau);

    printf("ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    printf("descendentes: ");
    imprimir_descendentes(alvo);
    printf("\n");

    printf("altura: %d\n", calcular_altura(alvo));
    printf("profundidade: %d\n", calcular_profundidade(raiz, valorBusca, 0));

    printf("\nSubarvore:\n");
    imprimir_niveis(alvo);
}

void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);

    free(raiz);
}
