#include <stdio.h>
#include <ctype.h>

// Função auxiliar para processar números
int processNumber(const char **str) {
    int num = 0;
    while (isdigit(**str)) {
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return num;
}

// Função recursiva para avaliar expressões
//A funçao recebe uma expressao
int eval(const char **str) {
    //result ira armazenar a avaliaçao da expressao 
    int result = 0;
    //op ira armazenar o operador atual 
    char op = '+';
    //loop ira rodar ate o final da string 
    while (**str) {
        //se for um espaço em branco, ira ser ignorado 
        if (**str == ' ') {
            (*str)++;
            continue;
        }
        //se for encontrado um parentese
        if (**str == '(') {
            // a funçao sera chamada de novo, e resultado dentro do parentese sera armazenado
            // na variavel subresult 
            (*str)++; // pular o '('
            int subresult = eval(str);
            if (op == '+') result += subresult;
            if (op == '-') result -= subresult;
        } else if (isdigit(**str)) {
            int num = processNumber(str);
            if (op == '+') result += num;
            if (op == '-') result -= num;
        } else if (**str == ')') {
            (*str)++; // pular o ')'
            return result;
        } else {
            op = **str; // o operador
            (*str)++;
        }
    }
    return result;
}

// Função principal
int main() {
    const char *expression = "1 + (2 - (4 + 5) + (1 - 6))";
    printf("Resultado da expressão %s ", expression);
    printf("é %d", eval(&expression));
    return 0;
}