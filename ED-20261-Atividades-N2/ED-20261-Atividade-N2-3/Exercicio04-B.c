/* RA: 2040482513009 - Renan Volpato Santos

Exercicio04-B.c
Estrutura de Dados - N2-3 */

#include <stdio.h>

//Contadores de chamadas recursivas
int chamadasRapida = 0;
int chamadasIngenua = 0;

/* Potenciação rápida recursiva

   CASO BASE: exp == 0

   CASO RECURSIVO:
   se exp é par:
     b^exp = (b^(exp/2))²

   se exp é ímpar:
     b^exp = b * b^(exp-1) */
long long potenciaRapida(long long base, int exp)
{
    chamadasRapida++;

    //Caso base
    if (exp == 0)
    {
        return 1;
    }

    //Caso expoente par
    if (exp % 2 == 0)
    {
        long long metade = potenciaRapida(base, exp / 2);

        return metade * metade;
    }

    //Caso expoente ímpar
    return base * potenciaRapida(base, exp - 1);
}

//Potenciação ingênua
//b^n = b * b^(n-1)
long long potenciaIngenua(long long base, int exp)
{
    chamadasIngenua++;

    //Caso base
    if (exp == 0)
    {
        return 1;
    }

    //Caso recursivo
    return base * potenciaIngenua(base, exp - 1);
}

int main()
{
    long long resultado;

    printf("POTENCIACAO RAPIDA RECURSIVA\n\n");

    //Teste 1
    chamadasRapida = 0;
    chamadasIngenua = 0;

    resultado = potenciaRapida(2, 10);

    potenciaIngenua(2, 10);

    printf("2^10 = %lld\n", resultado);
    printf("Chamadas (rapida): %d\n", chamadasRapida);
    printf("Chamadas (ingenua): %d\n\n", chamadasIngenua);

    //Teste 2
    chamadasRapida = 0;
    chamadasIngenua = 0;

    resultado = potenciaRapida(3, 7);

    potenciaIngenua(3, 7);

    printf("3^7 = %lld\n", resultado);
    printf("Chamadas (rapida): %d\n", chamadasRapida);
    printf("Chamadas (ingenua): %d\n\n", chamadasIngenua);

    //Teste 3
    chamadasRapida = 0;
    chamadasIngenua = 0;

    resultado = potenciaRapida(5, 0);

    potenciaIngenua(5, 0);

    printf("5^0 = %lld\n", resultado);
    printf("Chamadas (rapida): %d\n", chamadasRapida);
    printf("Chamadas (ingenua): %d\n\n", chamadasIngenua);

    //Teste 4
    chamadasRapida = 0;
    chamadasIngenua = 0;

    resultado = potenciaRapida(7, 12);

    potenciaIngenua(7, 12);

    printf("7^12 = %lld\n", resultado);
    printf("Chamadas (rapida): %d\n", chamadasRapida);
    printf("Chamadas (ingenua): %d\n\n", chamadasIngenua);

    return 0;
}

/* COMPARACAO ENTRE AS ABORDAGENS

Potenciação ingênua:
Faz uma chamada para cada decremento do expoente.
Complexidade: O(n)

Potenciação rápida:
Divide o expoente pela metade quando ele é par.
Complexidade: O(log n)

Exemplo: Para calcular 2^10:

Ingênua:
10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0

Rápida:
10 -> 5 -> 4 -> 2 -> 1 -> 0

A quantidade de chamadas recursivas é muito menor. */
