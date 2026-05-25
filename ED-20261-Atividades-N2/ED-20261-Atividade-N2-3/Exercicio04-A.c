/* RA: 2040482513009 - Renan Volpato Santos

Exercicio04-A.c
Estrutura de Dados - N2-3 */

#include <stdio.h>

//Contador global de chamadas recursivas
int chamadas = 0;

/* Busca binária recursiva
   CASO BASE:
   elemento encontrado
   intervalo inválido

   CASO RECURSIVO:
   divide o vetor ao meio e continua apenas na metade necessária */
   
int buscaBinaria(int *vet, int inicio, int fim, int alvo)
{
    //Conta cada chamada recursiva
    chamadas++;

    //Caso base: elemento não encontrado
    if (inicio > fim)
    {
        return -1;
    }

    //Calcula posição central
    int meio = (inicio + fim) / 2;

    //Caso base: elemento encontrado
    if (*(vet + meio) == alvo)
    {
        return meio;
    }

    //Caso recursivo: busca na metade esquerda
    if (alvo < *(vet + meio))
    {
        return buscaBinaria(vet, inicio, meio - 1, alvo);
    }

    //Caso recursivo: busca na metade direita
    return buscaBinaria(vet, meio + 1, fim, alvo);
}

int main()
{
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};

    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int indice;

    printf("BUSCA BINARIA RECURSIVA\n");

    //Busca de valor presente
    chamadas = 0;

    indice = buscaBinaria(dados, 0, tamanho - 1, 23);

    printf("Busca do valor 23:\n");
    printf("Indice encontrado: %d\n", indice);
    printf("Chamadas recursivas: %d\n\n", chamadas);

    //Busca de valor ausente
    chamadas = 0;

    indice = buscaBinaria(dados, 0, tamanho - 1, 50);

    printf("Busca do valor 50:\n");
    printf("Indice encontrado: %d\n", indice);
    printf("Chamadas recursivas: %d\n\n", chamadas);

    //Busca do primeiro elemento
    chamadas = 0;

    indice = buscaBinaria(dados, 0, tamanho - 1, 2);

    printf("Busca do valor 2:\n");
    printf("Indice encontrado: %d\n", indice);
    printf("Chamadas recursivas: %d\n\n", chamadas);

    return 0;
}
