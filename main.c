//gcc -Wall -Wextra -g -O0 main.c calc.c -o tp && ./tp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"
#include <math.h>

int main()
{
    dados dado;
    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");
    dado.entrada = (char*) malloc(250*sizeof(char));

    while(1)
    {
        fscanf(arquivo, "%[^=]=", dado.entrada);

        if(feof(arquivo))
            break;

        printf("%s\n", dado.entrada);

        calculadora(&(dado));
    }
    return 0;
}
