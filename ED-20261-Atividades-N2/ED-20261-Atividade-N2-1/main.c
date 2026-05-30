#include <stdio.h>
#include "minhabib.h"

int main() {
    No* raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, valores[i]);

    analisar_arvore(raiz, 30);

    liberar_arvore(raiz);
  
    return 0;
}

