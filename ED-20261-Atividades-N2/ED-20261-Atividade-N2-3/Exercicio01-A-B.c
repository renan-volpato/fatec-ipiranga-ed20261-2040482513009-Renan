/*  RA: 2040482513009 - Renan Volpato Santos

Exercicio01-A-B.c
Estrutura de Dados - N2-3 */

#include <stdio.h>

/* Função que troca os valores de duas variáveis
   usando apenas ponteiros e operações aritméticas. */
   
void trocar(int *a, int *b)
{
       // *a acessa o valor armazenado no endereço apontado por a
       // *b acessa o valor armazenado no endereço apontado por b
    *a = *a + *b;

       // O valor apontado por b recebe:
       // (valor original de a + valor original de b) - valor original de b
       // resultado = valor original de a
    *b = *a - *b;

       //O valor apontado por a recebe:
       //(valor original de a + valor original de b) - valor original de a
       //resultado = valor original de b
    *a = *a - *b;
}

int main()
{

    // Parte A

    int x = 10;
    int y = 20;

    printf("Antes da troca:\n");

       //%p imprime endereços de memória
    printf("Endereco de x: %p\n", (void *)&x);
    printf("Endereco de y: %p\n", (void *)&y);

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);

       //&x envia o endereço de memória de x para a função
       //&y envia o endereço de memória de y para a função
    trocar(&x, &y);

    printf("\nDepois da troca:\n");

    printf("Endereco de x: %p\n", (void *)&x);
    printf("Endereco de y: %p\n", (void *)&y);

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);

    // Parte B

    int v[] = {10, 20, 30, 40, 50};

    //ponteiro ptr aponta para o primeiro elemento do vetor
    //o nome do vetor v já representa o endereço inicial
    int *ptr = v;
    int soma = 0;

    printf("ELEMENTOS E ENDERECOS:\n\n");

    //Percorrendo o vetor apenas com ponteiros
    for (ptr = v; ptr < v + 5; ptr++)
    {
        //*ptr acessa o valor armazenado no endereço atual
        printf("Valor: %d ", *ptr);

        //ptr já é um endereço de memória
        printf("Endereco: %p\n", (void *)ptr);

        //soma recebe o valor apontado por ptr
        soma += *ptr;
    }

    printf("\nSoma dos elementos: %d\n", soma);

    //inversão do vetor

    printf("\nInvertendo vetor...\n");

    //inicio aponta para o primeiro elemento
    int *inicio = v;

    //fim aponta para o último elemento
    //v + 4 avança 4 posições no vetor
    int *fim = v + 4;

    while (inicio < fim)
    {
        //*inicio acessa o valor do começo
        //*fim acessa o valor do final
        *inicio = *inicio + *fim;
        *fim = *inicio - *fim;
        *inicio = *inicio - *fim;

        //Avança o ponteiro do começo
        inicio++;
        
        //Retrocede o ponteiro do final
        fim--;
    }

    printf("\nVETOR INVERTIDO:\n\n");

    //Exibindo o vetor invertido
    for (ptr = v; ptr < v + 5; ptr++)
    {
        printf("%d ", *ptr);
    }

    printf("\n");

    return 0;
}
