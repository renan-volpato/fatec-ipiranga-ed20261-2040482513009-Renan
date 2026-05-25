/*  RA: 2040482513009 - Renan Volpato Santos

Exercicio02.c
Estrutura de Dados - N2-3 */

#include <stdio.h>

//Calcula e retorna a média aritmética do vetor.
float calcularMedia(float *vet, int n)
{
    float soma = 0.0f;

    //ptr começa apontando para o primeiro elemento do vetor
    float *ptr = vet;

    //Percorre o vetor usando incremento de ponteiro
    for (; ptr < vet + n; ptr++)
    {
        //*ptr acessa o valor armazenado no endereço atual
        soma += *ptr;
    }
    return soma / n;
}

/*
Encontra o maior e o menor valor do vetor.
Os resultados são gravados diretamente nos endereços
recebidos pelos ponteiros maior e menor.
*/
void encontrarExtremos(float *vet, int n, float *maior, float *menor)
{
    float *ptr = vet;

    //Inicializa maior e menor com o primeiro valor do vetor
    *maior = *ptr;
    *menor = *ptr;

    //Avança para o próximo elemento
    ptr++;

    for (; ptr < vet + n; ptr++)
    {
        //Se o valor atual for maior que o maior encontrado
        if (*ptr > *maior)
        {
            //Armazena o novo maior valor
            *maior = *ptr;
        }

        //Se o valor atual for menor que o menor encontrado
        if (*ptr < *menor)
        {
            //Armazena o novo menor valor
            *menor = *ptr;
        }
    }
}

/*
Normaliza o vetor.
Cada elemento é dividido pelo maior valor do vetor.
*/
void normalizar(float *vet, int n)
{
    float maior;
    float menor;
    
    //Descobre o maior valor do vetor
    encontrarExtremos(vet, n, &maior, &menor);

    //ptr percorre o vetor original
    float *ptr = vet;

    for (; ptr < vet + n; ptr++)
    {
        //Altera diretamente o conteúdo do vetor original
        *ptr = *ptr / maior;
    }
}

//Imprime o vetor formatado.
void imprimirVetor(float *vet, int n, const char *titulo)
{
    printf("%s\n", titulo);

    float *ptr = vet;

    for (; ptr < vet + n; ptr++)
    {
        printf("%.2f ", *ptr);
    }

    printf("\n\n");
}

int main()
{
    //Vetor original de notas
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    int tamanho = sizeof(notas) / sizeof(notas[0]);

    float media;
    float maior;
    float menor;

    printf("=== EXERCICIO 02 ===\n\n");

    //Exibe o vetor antes da normalização
    imprimirVetor(notas, tamanho, "Vetor original:");

    //Calcula média
    media = calcularMedia(notas, tamanho);

    //Encontra maior e menor valor
    encontrarExtremos(notas, tamanho, &maior, &menor);

    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n\n", menor);

    //Normaliza o vetor original
    normalizar(notas, tamanho);

    //Exibe o vetor após a normalização
    imprimirVetor(notas, tamanho, "Vetor normalizado:");

    /*
       A função normalizar altera o vetor original porque
       arrays em C são passados para funções por meio de
       ponteiros. Assim, a função recebe o endereço real
       da memória onde os elementos estão armazenados.
       Portanto, qualquer alteração feita usando *ptr
       modifica diretamente os dados originais.
    */

    return 0;
}
