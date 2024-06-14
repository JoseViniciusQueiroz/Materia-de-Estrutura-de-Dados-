#include <stdio.h>
#include "buscas.h"

int main(){
    int idades[] = {18,19,23,25,26,27,29,30,40,41};
    int tamanho = sizeof(idades)/sizeof(idades[0]);
    while(1){
        printf("Digite a chave que deseja buscar ou -1 para sair\n");
        int chave;
        scanf("%d",&chave);
        if(chave == -1)
           break;
        int resultado = buscaBinaria(idades,tamanho,chave);
        if(resultado==-1)
           printf("Nao foi encontrado a idade\n");
        else
           printf("A chave foi encontrada na posicao %d\n",resultado);
    }

}

