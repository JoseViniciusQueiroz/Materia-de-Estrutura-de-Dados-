#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"


int main(){
    struct tree* arvore = NULL;
    arvore = instala(arvore,"abril");
    arvore = instala(arvore,"fevereiro");
    arvore = instala(arvore,"julho");
    printarOrdem(arvore);
    printf("\n");
    if(buscaArvore(arvore,"fevereiro")){
        printf("A palavra foi encontrada\n");
    }
    else{
        printf("A palavra nao foi encontrada\n");
    }
    if(buscaArvore(arvore,"outubro")){
        printf("A palavra foi encontrada\n");
    }
    else{
        printf("A palavra nao foi encontrada\n");
    }
}