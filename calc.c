#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "calc.h"

void fazOperando(dados *dado)
{
    int i, j, aux;

    // Come�o do primeiro operando

    if(dado->entrada[0] == '-')
    {
        dado->sinal[0] = 1; //se sinal for negativo => 1
        aux = 1;
    }

    else
    aux = 0; // se sinal for positivo => 0
//TODO teste
    if(dado->sinal[0] == 0)
        printf("sinal:Positivo\n");
    else
        printf("sinal:Negativo\n");

    for(i = 0, j = aux; !(dado->entrada[j] == '+' || dado->entrada[j] == '-'); i++, j++) //expressao � varrida pra detecta��o do primeiro numero
        dado->operando[0][i] = dado->entrada[j];

//TODO teste
        printf("primeiro operando:%s\n", dado->operando[0]);

    // Fim do primeiro operando

    // Come�ando do segundo operando

    if(dado->entrada[j] == '-')
    {
        dado->sinal[1] = 1;
        aux = j+1;
    }

    else
    aux = j+1;

    //TODO teste
    if(dado->sinal[1] == 0)
        printf("sinal:Positivo\n");
    else
        printf("sinal:Negativo\n");

    for(i = 0, j = aux; !(dado->entrada[j] == 'p' || dado->entrada[j] == 'i'); i++, j++)
        dado->operando[1][i] = dado->entrada[j];

//TODO teste
        printf("segundo operando:%s\n", dado->operando[1]);

    // Fim do segundo operando

    if(dado->entrada[j] == 'i')
        dado->formaoperando[0] = 0;

    else if(dado->entrada[j] == 'p')
        dado->formaoperando[0] = 1;

    //TODO teste
    if(dado->formaoperando[0] == 0)
        printf("forma:Retangular\n");
    else
        printf("forma:Polar\n");

    j++;

    dado->operacao = dado->entrada[j];

    // TODO teste
    printf("operacao:%c\n", dado->operacao);

    j++;


    // Come�o do terceiro operando

    if(dado->entrada[j] == '-')
    {
        dado->sinal[2] = 1;
        aux = j+1;
    }

    else
        aux = j;
//TODO teste
    if(dado->sinal[2] == 0)
        printf("sinal:Positivo\n");
    else
        printf("sinal:Negativo\n");

    for(i = 0, j = aux; !(dado->entrada[j] == '+' || dado->entrada[j] == '-'); i++, j++)
        dado->operando[2][i] = dado->entrada[j];

//TODO teste
    printf("terceiro operando:%s\n", dado->operando[2]);

    // Fim do terceiro operando

    // Come�ando do quarto operando

    if(dado->entrada[j] == '-')
    {
        dado->sinal[3] = 1;
        aux = j+1;
    }

    else
    aux = j+1;

    //TODO teste
    if(dado->sinal[3] == 0)
        printf("sinal:Positivo\n");
    else
        printf("sinal:Negativo\n");

    for(i = 0, j = aux; !(dado->entrada[j] == 'p' || dado->entrada[j] == 'i'); i++, j++)
    dado->operando[3][i] = dado->entrada[j];

//TODO teste
    printf("quarto operando:%s\n", dado->operando[3]);

    // Fim do quarto operando

    if(dado->entrada[j] == 'i')
        dado->formaoperando[1] = 0;

    else if(dado->entrada[j] == 'p')
        dado->formaoperando[1] = 1;

//TODO teste
    if(dado->formaoperando[1] == 0)
        printf("forma:Retangular\n");
    else
        printf("forma:Polar\n");
}

void converteOperando(dados *dado)
{
    int i;

    for(i = 0; dado->operando[0][i] != '\0'; i++)
    {
        dado->operandoInt[0] *= 10;
        dado->operandoInt[0] += (int)(dado->operando[0][i] - '0');
    }
    //printf("%i\n", dado->operandoInt[0]);

    for(i = 0; dado->operando[1][i] != '\0'; i++)
    {
        dado->operandoInt[1] *= 10;
        dado->operandoInt[1] += (int)(dado->operando[1][i] - '0');
    }
   // printf("%i\n", dado->operandoInt[1]);

    for(i = 0; dado->operando[2][i] != '\0'; i++)
    {
        dado->operandoInt[2] *= 10;
        dado->operandoInt[2] += (int)(dado->operando[2][i] - '0');
    }
   // printf("%i\n", dado->operandoInt[2]);

    for(i = 0; dado->operando[3][i] != '\0'; i++)
    {
        dado->operandoInt[3] *= 10;
        dado->operandoInt[3] += (int)(dado->operando[3][i] - '0');
    }
    //printf("%i\n", dado->operandoInt[3]);
}

void calculadora(dados *dado)
{
    int i, j;
    bool *forma;
    FILE *resultados;

    forma = (bool*) calloc(2,sizeof(bool));

    dado->entrada[strlen(dado->entrada)+1] = '\0';
    dado->entrada[strlen(dado->entrada)] = '=';

    dado->operando = (char**) calloc(10,sizeof(char**));
    for(i = 0; i < 10; i++)
        dado->operando[i] = (char*) calloc(4,sizeof(char*));
    dado->sinal = (bool*) calloc(4,sizeof(bool));
    dado->formaoperando = (bool*) calloc(2,sizeof(bool));
    dado->operandoInt = (int*) calloc(4,sizeof(int));

    for(i = 0; dado->entrada[i] != '\0';) //enquanto a expressao nao chegar ao final (\0)
    {
        if(dado->entrada[i] == ' ') // se for detectado um espa�o
        {
            for(j = i; dado->entrada[j] != '\0'; j++)
                dado->entrada[j] = dado->entrada[j+1]; // pula para a proxima posi��o ignorando os espa�os
        }

        else
            i++;
    }

    // Parte da impressão no arquivo de saida
    resultados = fopen("resultados.txt", "a");
    fprintf(resultados, "%s*aqui ficará a resposta*\n", dado->entrada);
    fclose(resultados);
    // Fim da impressão no arquivo de saida

//TODO teste
    //printf("%s\n", dado->entrada);

    for(i = 0; dado->entrada[i] != '\0'; i++) // enquanto a expressao lida nao chegar ao final
    {
        if(dado->entrada[i] == 'p') // se um 'p'(polar) for identificado => forma[0] = 1
            forma[0] = 1;

        else if(dado->entrada[i] == 'i') //se um 'i' for identificado => forma[1] = 1
            forma[1] = 1;
    }
    /*Dessa forma se forma[0] = 1 e forma [1] = 1, saberemos que a expressao � mista
      Se forma [0] = 1 e forma[1] = 0, saberemos que ambas as partes da expressap sao polares
      E se forma[0] = 0 e forma[1] = 1, saberemos que ambas as partes da expressao sao retangulares */

//TODO teste
   // printf("polar:%d || retangular:%d\n", forma[0], forma[1]);

    fazOperando(dado);

    converteOperando(dado);

    /*EXPRESS�ES MISTAS: CONVERS�ES E OPERA��ES*/
    if (forma[0] == 1 && forma[1] == 1){ //expressao mista
        if (dado->formaoperando[0] == 0 && dado->formaoperando[1] == 1){ //primeira expressao retangular e segunda polar

        /*CONVERS�O RETANGULAR PARA POLAR*/
            dado->teta= atan(dado->operandoInt[1]/dado->operandoInt[0]);
            dado->z = sqrt(dado->operandoInt[1]*dado->operandoInt[1] + dado->operandoInt[0]*dado->operandoInt[0]);

            //dado->operandoInt[0] PARTE REAL
           // dado->operandoInt[1] PARTE IMAGINARIA

            //printf("teta: %d\n z: %d\n", dado->teta, dado->z);

        /*CONVERS�O POLAR PARA RETANGULAR*/
            dado->a = dado->operandoInt[2] * cos(dado->operandoInt[3]);
            dado->b = dado->operandoInt[2] * sin(dado->operandoInt[3]);

             //dado->operandoInt[2] PARTE REAL
           // dado->operandoInt[3] PARTE IMAGINARIA

           // printf("a: %d\n b: %d\n", dado->a, dado->b);

            /*OPERA��ES*/
            if (dado->operacao == '-'){
            /*TUDO RETANGULAR*/
                dado->realRet = dado->operandoInt[0] - dado->a;
                dado->imaginRet = dado->operandoInt[1] - dado->b;
                //printf("%d e %d", dado->realRet, dado->imaginRet);
            /*TUDO POLAR*/
                dado->realPol = dado->z - dado->operandoInt[2];
                dado->imaginPol = dado->teta - dado->operandoInt[3];
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '+'){
            /*TUDO RETANGULAR*/
                dado->realRet = dado->operandoInt[0] + dado->a;
                dado->imaginRet = dado->operandoInt[1] + dado->b;
                //printf("%d %d", dado->realRet, dado->imaginRet);
            /*TUDO POLAR*/
                dado->realPol = dado->z + dado->operandoInt[2];
                dado->imaginPol = dado->teta + dado->operandoInt[3];
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '*'){
            /*TUDO RETANGULAR*/
                dado->realRet = dado->operandoInt[0] * dado->a;
                dado->imaginRet = dado->operandoInt[1] * dado->b;
                //printf("%d %d", dado->realRet, dado->imaginRet);
            /*TUDO POLAR*/
                dado->realPol = dado->z * dado->operandoInt[2];
                dado->imaginPol = dado->teta * dado->operandoInt[3];
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '/'){
            /*TUDO RETANGULAR*/
                dado->realRet = dado->operandoInt[0] / dado->a;
                dado->imaginRet = dado->operandoInt[1] /dado->b;
               // printf("%d %d", dado->realRet, dado->imaginRet);
            /*TUDO POLAR*/
                dado->realPol = dado->z / dado->operandoInt[2];
                dado->imaginPol = dado->teta / dado->operandoInt[3];
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
        }

        else if(dado->formaoperando[0] == 1 && dado->formaoperando[1] == 0){ //primeira expressao polar e segunda expressao retangular

        /*CONVERS�O RETANGULAR PARA POLAR*/
            dado->teta = atan(dado->operandoInt[3]/dado->operandoInt[2]);
            dado->z = sqrt(dado->operandoInt[3]*dado->operandoInt[3] + dado->operandoInt[2]* dado->operandoInt[2]);

           // dado->operandoInt[2]
            //dado->operandoInt[3]

            //printf("teta: %d\n z: %d\n", dado->teta, dado->z);

        /*CONVERS�O POLAR PARA RETANGULAR*/
            dado->a = dado->operandoInt[0] * cos(dado->operandoInt[1]);
            dado->b = dado->operandoInt[0] * sin(dado->operandoInt[1]);

            //dado->operandoInt[0]
            //dado->operandoInt[1]

            //printf("a: %d\n b: %d\n", dado->a, dado->b);

            /*OPERA��ES*/
            if (dado->operacao == '-'){
                /*TUDO RETANGULAR*/
                dado->realRet = (dado->a - dado->operandoInt[2]);
                dado->imaginRet = (dado->b - dado->operandoInt[3]);
                //printf("%d %d", dado->realRet, dado->imaginRet);
                /*TUDO POLAR*/
                dado->realPol = dado->operandoInt[0] - dado->z;
                dado->imaginPol = dado->operandoInt[1] - dado->teta;
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '+'){
                /*TUDO RETANGULAR*/
                dado->realRet = (dado->a + dado->operandoInt[2]);
                dado->imaginRet = (dado->b + dado->operandoInt[3]);
                //printf("%d %d", dado->realRet, dado->imaginRet);
                /*TUDO POLAR*/
                dado->realPol = dado->operandoInt[0] + dado->z;
                dado->imaginPol = dado->operandoInt[1] + dado->teta;
               // printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '*'){
                /*TUDO RETANGULAR*/
                dado->realRet = (dado->a * dado->operandoInt[2]);
                dado->imaginRet = (dado->b * dado->operandoInt[3]);
                //printf("%d %d", dado->realRet, dado->imaginRet);
                /*TUDO POLAR*/
                dado->realPol = dado->operandoInt[0] * dado->z;
                dado->imaginPol = dado->operandoInt[1] * dado->teta;
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
            if (dado->operacao == '/'){
                /*TUDO RETANGULAR*/
                dado->realRet = (dado->a / dado->operandoInt[2]);
                dado->imaginRet = (dado->b / dado->operandoInt[3]);
                //printf("%d %d", dado->realRet, dado->imaginRet);
                /*TUDO POLAR*/
                dado->realPol = dado->operandoInt[0] / dado->z;
                dado->imaginPol = dado->operandoInt[1] / dado->teta;
                //printf("%d %d", dado->realPol, dado->imaginPol);
            }
    }
}
    /*EXPRESS�ES HOMOG�NEAS: OPERA��ES*/
    else
         /*OPERA��ES*/
        if (dado->operacao == '-'){
            dado->real= (dado->operandoInt[0] - dado->operandoInt[2]);
            dado->imagin = (dado->operandoInt[1] - dado->operandoInt[3]);
            //printf("%d %d", dado->real, dado->imagin);
        }
        else if (dado->operacao == '+'){
            dado->real= (dado->operandoInt[0] + dado->operandoInt[2]);
            dado->imagin = (dado->operandoInt[1] + dado->operandoInt[3]);
            //printf("%d %d", dado->real, dado->imagin);
        }
        else if (dado->operacao == '*'){
            dado->real= (dado->operandoInt[0] * dado->operandoInt[2]);
            dado->imagin = (dado->operandoInt[1] * dado->operandoInt[3]);
            //printf("%d %d", dado->real, dado->imagin);
        }

        if (dado->operacao == '/'){
            if(dado->operandoInt[0] == 0 || dado->operandoInt[3] == 0)
                printf("Erro: Denominador não pode ser 0\n");
            else
            {
                dado->real= (dado->operandoInt[0] / dado->operandoInt[2]);
                dado->imagin = (dado->operandoInt[1] / dado->operandoInt[3]);
            }
            //printf("%d %d", dado->real, dado->imagin);
        }
}
