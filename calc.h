#ifndef CALC
#define CALC
#include <stdbool.h>

typedef struct dados
{
    char *entrada;
    char **operando;
    bool *formaoperando; // 0 Retangular / 1 Polar
    bool *sinal; // 0 Positivo / 1 Negativo
    char operacao;
    int *operandoInt;
    int a;
    int b;
    int z;
    int teta;
    int realRet;
    int imaginRet;
    int realPol;
    int imaginPol;
    int real;
    int imagin;

} dados;

void calculadora(dados*);
void fazOperando(dados*);
void converteOperando(dados*);

#endif
