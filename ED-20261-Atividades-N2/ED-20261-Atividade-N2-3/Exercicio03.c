/* RA: 2040482513009 - Renan Volpato Santos

Exercicio03.c
Estrutura de Dados - N2-3 */

#include <stdio.h>

//Contador global de movimentos
long long movimentos = 0;

/* Função recursiva das Torres de Hanói

   n        -> quantidade de discos
   origem   -> haste de origem
   destino  -> haste de destino
   auxiliar -> haste auxiliar
   nivel    -> profundidade da recursão */
void hanoi(int n, char origem, char destino, char auxiliar, int nivel)
{
    int i;
    
    // CASO BASE: quando existe apenas 1 disco
    if (n == 1)
    {
        //Indentação proporcional ao nível da recursão
        for (i = 0; i < nivel * 2; i++)
        {
            printf(" ");
        }

        printf("[Nivel %d] Mover disco 1 de %c para %c\n",
               nivel, origem, destino);

        movimentos++;
        return;
    }

    //CASO RECURSIVO:
    //Passo 1: mover n-1 discos da origem para auxiliar
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    //Indentação da profundidade atual
    for (i = 0; i < nivel * 2; i++)
    {
        printf(" ");
    }

    //Move o maior disco
    printf("[Nivel %d] Mover disco %d de %c para %c\n",
           nivel, n, origem, destino);

    movimentos++;

    //Passo 2: mover n-1 discos da auxiliar para destino
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main()
{
    int n;

    printf("TORRES DE HANOI - RECURSIVO\n\n");

    //Teste com n = 1
    n = 1;

    movimentos = 0;

    printf("========== TESTE n = %d ==========\n\n", n);

    hanoi(n, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n", movimentos);

    printf("Esperado: %d\n\n", (1 << n) - 1);

    //Teste com n = 3
    n = 3;

    movimentos = 0;

    printf("========== TESTE n = %d ==========\n\n", n);

    hanoi(n, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n", movimentos);

    printf("Esperado: %d\n\n", (1 << n) - 1);

    //Teste com n = 4
    n = 4;

    movimentos = 0;

    printf("========== TESTE n = %d ==========\n\n", n);

    hanoi(n, 'A', 'C', 'B', 0);

    printf("\nTotal de movimentos: %lld\n", movimentos);

    printf("Esperado: %d\n\n", (1 << n) - 1);

    return 0;
}

/*
========================================================
TABELA DE COMPLEXIDADE
========================================================

n    |Movimentos (contado)    |2^n - 1 (esperado)
     |                        |
1    |1                       |1
2    |3                       |3
3    |7                       |7
4    |15                      |15
5    |31                      |31
6    |63                      |63


ANÁLISE:

A quantidade de movimentos cresce exponencialmente.

A recorrência do algoritmo é:

T(n) = 2*T(n-1) + 1

Sua solução fechada é:

T(n) = 2^n - 1

Complexidade de tempo:
O(2^n)

Complexidade de espaço:
O(n)

pois a pilha de chamadas recursivas cresce conforme
a profundidade da recursão.
*/
