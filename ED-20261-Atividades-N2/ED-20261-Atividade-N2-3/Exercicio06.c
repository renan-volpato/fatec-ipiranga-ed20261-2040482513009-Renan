/* RA: 2040482513009 - Renan Volpato Santos

Exercicio06.c
Estrutura de Dados - N2-3 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;

} No;

No *criarNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de alocacao.\n");
        exit(1);
    }

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->dado)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No *buscarNo(No *raiz, int valor)
{
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);

    return buscarNo(raiz->dir, valor);
}

int alturaNo(No *no)
{
    if (no == NULL) return -1;

    int esq = alturaNo(no->esq);
    int dir = alturaNo(no->dir);

    if (esq > dir) return esq + 1;

    return dir + 1;
}

int profundidadeNo(No *raiz, int valor, int prof)
{
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado) return profundidadeNo(raiz->esq, valor, prof + 1);

    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no)
{
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

// Imprimir Ancestrais
void imprimirAncestral(No *raiz, int valor)
{
    if (raiz == NULL) return;

    // Se o valor estiver na esquerda
    if (valor < raiz->dado)
    {
        printf("%d ", raiz->dado);
        imprimirAncestral(raiz->esq, valor);
    }

    // Se o valor estiver na direita
    else if (valor > raiz->dado)
    {
        printf("%d ", raiz->dado);
        imprimirAncestral(raiz->dir, valor);
    }
}


// Imprimir Descendentes
void imprimirDescendentesAux(No *no)
{
    if (no != NULL)
    {
        imprimirDescendentesAux(no->esq);
        printf("%d ", no->dado);
        imprimirDescendentesAux(no->dir);
    }
}

void imprimirDescendentes(No *raiz, int valor)
{
    No *no = buscarNo(raiz, valor);

    if (no == NULL) return;

    // Imprime apenas descendentes
    if (no->esq != NULL) imprimirDescendentesAux(no->esq);
    if (no->dir != NULL) imprimirDescendentesAux(no->dir);
}

// Contar Descendentes
int contarDescendentes(No *no)
{
    if (no == NULL) return 0;

    return 1
           + contarDescendentes(no->esq)
           + contarDescendentes(no->dir);
}

// Relatório completo do Nó
void relatorioNo(No *raiz, int valor)
{
    No *no = buscarNo(raiz, valor);

    // Valor inexistente
    if (no == NULL)
    {
        printf("\nerro: valor %d nao encontrado.\n", valor);
        return;
    }

    printf("\n------------------------------------\n");
    printf("| RELATORIO DO NO: %-14d |\n", valor);
    printf("------------------------------------\n");

    printf("| Profundidade : %-16d |\n",
           profundidadeNo(raiz, valor, 0));

    printf("| Altura       : %-16d |\n",
           alturaNo(no));

    printf("| Grau         : %-16d |\n",
           grauNo(no));

    // Ancestrais
    printf("| Ancestrais   : ");

    imprimirAncestral(raiz, valor);

    printf("\n");

    // Descendentes
    printf("| Descendentes : ");

    imprimirDescendentes(raiz, valor);

    printf("\n");

    // Quantidade de descendentes
    // -1 remove o próprio nó da contagem
    printf("| Qtd Descend. : %-16d |\n",
           contarDescendentes(no) - 1);

    printf("------------------------------------\n");
}

// Liberar Mémoria
void liberarArvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{
    No *raiz = NULL;

/* ABB UTILIZADA
                50
              /    \
            30      70
           /  \    /  \
         20   40  60   80
        / \     \   \
      10  25    45  65             */

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int tamanho = sizeof(valores) / sizeof(valores[0]);
    int i;

    // Construção da árvore
    for (i = 0; i < tamanho; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    printf("RELATORIOS DOS NOS\n");

    // Testes
    relatorioNo(raiz, 50);
    relatorioNo(raiz, 30);
    relatorioNo(raiz, 10);
    relatorioNo(raiz, 70);

    // Teste de erro
    relatorioNo(raiz, 999);

    // Liberar Mémoria
    liberarArvore(raiz);

    return 0;
}
