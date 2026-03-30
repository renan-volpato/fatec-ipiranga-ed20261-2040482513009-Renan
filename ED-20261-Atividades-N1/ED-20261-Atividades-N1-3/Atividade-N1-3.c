#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 4

typedef struct {
    float reg[TAM];
} Pilha;

void inicializar(Pilha *p) {
    for (int i = 0; i < TAM; i++)
        p->reg[i] = 0;
}

void push(Pilha *p, float valor) {
    p->reg[3] = p->reg[2];
    p->reg[2] = p->reg[1];
    p->reg[1] = p->reg[0];
    p->reg[0] = valor;
}

float pop(Pilha *p) {
    float x = p->reg[0];
    p->reg[0] = p->reg[1];
    p->reg[1] = p->reg[2];
    p->reg[2] = p->reg[3];
    return x;
}

void mostrar(Pilha *p) {
    printf("\nT: %.2f\n", p->reg[3]);
    printf("Z: %.2f\n", p->reg[2]);
    printf("Y: %.2f\n", p->reg[1]);
    printf("X: %.2f\n", p->reg[0]);
}

int ehNumero(char *str) {
    if (*str == '-' && *(str+1) != '\0') str++;
    while (*str) {
        if (!isdigit(*str) && *str != '.') return 0;
        str++;
    }
    return 1;
}

void operar(Pilha *p, char op) {
    float a, b, res;

    b = pop(p);
    a = pop(p);

    switch (op) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/':
            if (b == 0) {
                printf("Erro: divisão por zero\n");
                return;
            }
            res = a / b;
            break;
        default:
            printf("Operador inválido\n");
            return;
    }

    push(p, res);
}

int main() {
    Pilha p;
    char entrada[200];

    inicializar(&p);

    printf("Digite a expressao RPN:\n");
    fgets(entrada, sizeof(entrada), stdin);

    char *token = strtok(entrada, " \n");

    while (token != NULL) {

        if (ehNumero(token)) {
            push(&p, atof(token));
        } else if (strlen(token) == 1) {
            operar(&p, token[0]);
        } else {
            printf("Entrada invalida: %s\n", token);
            return 1;
        }

        mostrar(&p);

        token = strtok(NULL, " \n");
    }

    printf("\nResultado final: %.2f\n", p.reg[0]);

    return 0;
}
