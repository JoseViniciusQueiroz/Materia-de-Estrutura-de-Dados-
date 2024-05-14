#include <stdio.h>
#include <ctype.h>

// Função auxiliar para processar números
int processNumber(const char **str) {
    int num = 0;
    enquanto (édígito(**str)) {
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    retornar num;
}

// Função recursiva para avaliar expressões
int avaliação(const char **str) {
    resultado interno = 0;
    char op = '+';

    enquanto (**str) {
        if (**str == ' ') {
            (*str)++;
            continuar;
        }
        if (**str == '(') {
            (*str)++; //pular o '('
            int subresultado = eval(str);
            if (op == '+') resultado += subresultado;
            if (op == '-') resultado -= subresultado;
        } else if (isdigit(**str)) {
            int num = processNumber(str);
            if (op == '+') resultado += num;
            if (op == '-') resultado -= num;
        } else if (**str == ')') {
            (*str)++; //pular o ')'
            resultado de retorno;
        } outro {
            op = **str; // o operador
            (*str)++;
        }
    }
    resultado de retorno;
}

// Função principal
int principal() {
    const char *expressão = "1 + (2 - (4 + 5) + (1 - 6))";
    printf("Resultado da expressão %s ", expressão);
    printf("é %d", eval(&expressão));
    retornar 0;
}