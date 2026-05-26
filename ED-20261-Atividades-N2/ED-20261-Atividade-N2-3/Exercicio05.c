/* RA: 2040482513009 - Renan Volpato Santos

Exercicio05.c
Estrutura de Dados - N2-3 */

#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó
typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;

} No;

// Criar Nó
No *criarNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

// Inserir na ABB
No *inserir(No *raiz, int valor)
{
    // Caso base: posição vazia encontrada
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    // Inserção na esquerda
    if (valor < raiz->dado)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    
    // Inserção na direita
    else if (valor > raiz->dado)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

// Buscar Nó
No *buscarNo(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->dado == valor)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        return buscarNo(raiz->esq, valor);
    }

    return buscarNo(raiz->dir, valor);
}

// Altura do Nó
// Requisito: retornar -1 para ponteiro nulo
int alturaNo(No *no)
{
    // Caso base
    if (no == NULL)
    {
        return -1;
    }

    int alturaEsq = alturaNo(no->esq);
    int alturaDir = alturaNo(no->dir);

    // Retorna a maior altura + 1
    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

// Profundidade do Nó
// Retorna -1 se o valor não existir
int profundidadeNo(No *raiz, int valor, int prof)
{
    // Valor não encontrado
    if (raiz == NULL)
    {
        return -1;
    }

    // Valor encontrado
    if (raiz->dado == valor)
    {
        return prof;
    }

    // Busca na esquerda
    if (valor < raiz->dado)
    {
        return profundidadeNo(raiz->esq, valor, prof + 1);
    }

    // Busca na direita
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Grau do Nó
int grauNo(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    int grau = 0;

    if (no->esq != NULL)
    {
        grau++;
    }

    if (no->dir != NULL)
    {
        grau++;
    }

    return grau;
}

// Imprimir graus em ordem
void imprimirGraus(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirGraus(raiz->esq);

        printf("Nó %d - Grau: %d\n",
               raiz->dado,
               grauNo(raiz));

        imprimirGraus(raiz->dir);
    }
}

// Liberar mémoria
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

/* ASCII ART DA ABB

                50
              /    \
            30      70
           /  \    /  \
         20   40  60   80
        / \     \   \
      10  25    45  65


Verificação manual

No 50:
Altura = 3
Profundidade = 0
Grau = 2

No 30:
Altura = 2
Profundidade = 1
Grau = 2

No 10:
Altura = 0
Profundidade = 3
Grau = 0 */

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int tamanho = sizeof(valores) / sizeof(valores[0]);

    int i;

    // Construção da ABB
    for (i = 0; i < tamanho; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    printf("ARVORE BINARIA DE BUSCA\n\n");

    // Altura dos Nós
    int nosAltura[] = {50, 30, 70, 20, 10};

    printf("ALTURA DOS NÓS:\n\n");

    for (i = 0; i < 5; i++)
    {
        No *no = buscarNo(raiz, nosAltura[i]);

        printf("Nó %d - Altura: %d\n",
               nosAltura[i],
               alturaNo(no));
    }

    // Profunidade dos Nós
    int nosProf[] = {50, 30, 70, 45, 10};

    printf("\nPROFUNDIDADE DOS NÓS:\n\n");

    for (i = 0; i < 5; i++)
    {
        printf("Nó %d - Profundidade: %d\n",
               nosProf[i],
               profundidadeNo(raiz, nosProf[i], 0));
    }

    // Grau dos Nós
    printf("\nGRAU DOS NOS:\n\n");

    imprimirGraus(raiz);

    // Altura total
    printf("\nALTURA TOTAL DA ARVORE: %d\n",
           alturaNo(raiz));

    // Liberar Mémoria
    liberarArvore(raiz);

    return 0;
}
